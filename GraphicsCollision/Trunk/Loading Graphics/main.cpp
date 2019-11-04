#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "FPSUtility.h"
#include <string>
#include <math.h>
using namespace std;


//The attributes of the screen 
const int SCREEN_WIDTH = 800; 
const int SCREEN_HEIGHT = 600; 
const int SCREEN_BPP = 32; //Bits Per Pixel

SDL_Surface *screen = NULL; //the pointer to the screen in memory
SDL_Surface *player = NULL; //the pointer to the image of the player
SDL_Surface *badGuy = NULL; //the pointer to the image of the bad guy
SDL_Surface *thefont = NULL; //we will use this for text
SDL_Surface *back = NULL;
SDL_Surface *blackBack = NULL;

SDL_Rect sclip, dclip, sBGclip, dBGclip, sBackClip, dBackClip, sBlackClip, dBlackClip; //used to create clipping rectangles for moving the player image from off-screen to on screen

/*
 * Return the pixel value at (x, y)
 * NOTE: The surface must be locked before calling this!
 */
Uint32 getpixel(SDL_Surface *surface, int x, int y)
{
    int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to retrieve */
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
    switch(bpp) 
	{
    case 1:
        return *p;
    case 2:
        return *(Uint16 *)p;
    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
            return p[0] << 16 | p[1] << 8 | p[2];
        else
            return p[0] | p[1] << 8 | p[2] << 16;
    case 4:
        return *(Uint32 *)p;
    default:
        return 0;       /* shouldn't happen, but avoids warnings */
    }
}

void myDrawText(char c[], int x, int y)
{
	int i;
	SDL_Rect sclip, dclip;

	for (i=0; i < strlen(c); i++)
	{
		sclip.x = 16*(int(c[i]) % 16); 
		sclip.y = 16*(int(c[i]) / 16); 
		sclip.w = 16; sclip.h = 16;
		
		dclip.x = x+(i*16); dclip.y = y; dclip.w = 16; dclip.h = 16;

		SDL_BlitSurface(thefont, &sclip, screen, &dclip);
	}
}

bool CollisionCheck(const SDL_Rect& BoxA, const SDL_Rect& BoxB)
{
   if(BoxA.x > BoxB.x + BoxB.w)
      return false;
   if(BoxA.x + BoxA.w < BoxB.x)
      return false;
   if(BoxA.y > BoxB.y + BoxB.h)
      return false;
   if(BoxA.y + BoxA.w < BoxB.y)
      return false;
   return true;
}

bool CollisionCheck(int x1,int y1, int r1, int x2, int y2, int r2)
{
	if (sqrt(pow((float)(x2-x1),2) + pow((float)(y2 - y1),2)) <= r1 + r2) 
		{return true;}
	else
		{return false;}
}

int main(int argc, char *argv[]) 
{
	SDL_Event event;
	bool bgameRunning= true;
	bool keysHeld[323];
	bool bBGAlive = true, bMove = true;
	int iFrameX=0, iFrameY=0;
	float fXloc=400, fYloc=300, fMov = 100, deltaTime = 0, fMovTime = 0;
	FPSUtility fps;
	char sFps[255]; char sText[255];
	int thisTime = 0, lastTime = 0;
	float fMaxX = 0, fMaxY = 0, px = 0, py = 0; 
	string sCharFileName;
	int iCharSelected = 0;
	int iRClear = 0, iGClear = 0, iBClear = 0;
	Uint32 xxx; // the returned colour from getpixel in hex
	Uint8 r, g, b, a; // the individual colours returned from get pixel


	sCharFileName = "Red2.bmp";
	fMaxX = 32;
	fMaxY = 32;
	iRClear = 0; iGClear = 0; iBClear = 0;

	for (int i=0; i<322; i++)
	{
		keysHeld[i] = false; // everything will be initialized to false
	}
    //Initialize all SDL subsystems 
	if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 ) 
	{ return 1; } 

    //Set up the screen 
	//screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE ); 
	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_DOUBLEBUF|SDL_SWSURFACE);

	//If there was an error in setting up the screen 
	if( screen == NULL ) { return 1; } 
	//Set the window caption 
	SDL_WM_SetCaption( "SDL Work", NULL ); 
	player = SDL_LoadBMP(sCharFileName.c_str()); //Setting the player to point at the image
	SDL_SetColorKey(player,SDL_SRCCOLORKEY, SDL_MapRGB(player->format, iRClear, iGClear, iBClear) ); //Black is the transparent colour

	badGuy = SDL_LoadBMP("guard.bmp"); //Setting the player to point at the image
	SDL_SetColorKey(badGuy,SDL_SRCCOLORKEY, SDL_MapRGB(player->format, 69, 78, 91)); //Black is the transparent colour

	back = SDL_LoadBMP("scrollingbg600.bmp"); //Setting the player to point at the image
	blackBack = SDL_LoadBMP("scrollingbgmask600.bmp"); //Setting the player to point at the image

	thefont = SDL_LoadBMP( "font1.bmp" );

	//Fill the screen white 
	SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) ); 
	while (bgameRunning)
	{	// check for any events from the user or the system
		SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) ); 
		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				bgameRunning = false;
			}
			if (event.type == SDL_KEYDOWN)
			{
				keysHeld[event.key.keysym.sym] = true;
			}
			if (event.type == SDL_KEYUP)
			{
				keysHeld[event.key.keysym.sym] = false;
			}
		}

		//rectangleRGBA(screen,x1, y1,x2,y2,255, 1, 1, 100);

		sBackClip.x = 0; sBackClip.y = 0; sBackClip.w = 800; sBackClip.h = 600; //where the image is  in memory 
		dBackClip.x = 0; dBackClip.y = 0; dBackClip.w = 800; dBackClip.h = 600; //where to put the image on screen 
		SDL_BlitSurface(back, &sBackClip, screen, &dBackClip);

		sBlackClip.x = 0; sBlackClip.y = 0; sBlackClip.w = 800; sBlackClip.h = 600; //where the image is  in memory 
		dBlackClip.x = 0; dBlackClip.y = 0; dBlackClip.w = 800; dBlackClip.h = 600; //where to put the image on screen
		//SDL_BlitSurface(blackBack, &sBackClip, screen, &dBackClip);

		sclip.x = 0; sclip.y = 0; sclip.w = fMaxX; sclip.h = fMaxY; //where the image is  in memory 
		dclip.x = fXloc; dclip.y = fYloc; dclip.w = fMaxX; dclip.h = fMaxY; //where to put the image on screen 

		if (bBGAlive == true)
		{
			sBGclip.x = 0; sBGclip.y = 0; sBGclip.w = 32; sBGclip.h = 32; //where the image is  in memory 
			dBGclip.x = 500; dBGclip.y = 500; dBGclip.w = 32; dBGclip.h = 32; //where to put the image on screen 
			SDL_BlitSurface(badGuy, &sBGclip, screen, &dBGclip);
			circleRGBA(screen, dBGclip.x + (dBGclip.w/2), dBGclip.y + (dBGclip.h/2),(dBGclip.w/2) - 2, 0, 0, 0, 255);
			//if (CollisionCheck(dclip, dBGclip) == true) {bBGAlive = false;}
		}
		if (CollisionCheck(dclip.x + (dclip.w/2), dclip.y + (dclip.h/2),(dclip.w/2) - 2, dBGclip.x + (dBGclip.w/2), dBGclip.y + (dBGclip.h/2),(dBGclip.w/2) - 2) == true) {bBGAlive = false;} else {bBGAlive = true;}

		px = dclip.x + (dclip.w/2); py = dclip.y + dclip.h;
		SDL_LockSurface(blackBack);	//lock the surface
		xxx=getpixel(blackBack,px,py);// get the pixel colour on the surface at the x,y coordinates
		SDL_UnlockSurface(blackBack);	//unlock the surface
		SDL_GetRGB( xxx , blackBack->format,  &r, &g,  &b);	// convert the colour to rgb values
		
		if ((r!=0)&&(g!=0)&&(b!=0))
			bMove=true;
		else
			bMove=false;

		if (bMove == true)
		{
			SDL_BlitSurface(player, &sclip, screen, &dclip);
			circleRGBA(screen, dclip.x + (dclip.w/2), dclip.y + (dclip.h/2),(dclip.w/2) - 2, 0, 0, 0, 255);
		}

		thisTime = SDL_GetTicks();
		fMovTime = (float)(thisTime - lastTime) / 1000;
		//cout << fMovTime << endl;
		deltaTime += fMovTime;
		lastTime = thisTime;
		if (deltaTime >= 0.2)
			{iFrameX++; deltaTime = 0;}
		
		if (keysHeld[SDLK_DOWN] == true)
			{iFrameY = 0; fYloc+=fMov*fMovTime;}
		else if (keysHeld[SDLK_UP] == true)
			{iFrameY = 3; fYloc-=fMov*fMovTime;}
		else if (keysHeld[SDLK_LEFT] == true)
			{iFrameY = 1; fXloc-=fMov*fMovTime;}
		else if (keysHeld[SDLK_RIGHT] == true)
			{iFrameY = 2; fXloc+=fMov*fMovTime;}
		else
			{iFrameX=0;}

		if (iFrameX>=4) {iFrameX=0;}
		
		if(fXloc>SCREEN_WIDTH-(fMaxX+1)) {fXloc=SCREEN_WIDTH-fMaxX;}
		if(fXloc<2) {fXloc=1;}
		if(fYloc>SCREEN_HEIGHT-(fMaxY+1)) {fYloc=SCREEN_HEIGHT-fMaxY;}
		if(fYloc<2) {fYloc=1;}

		//Using the function to draw text on the screen at 100,100
		if (bBGAlive == true)
			{sprintf(sText, "Bad Guy Status: Alive");}
		else
			{sprintf(sText, "Bad Guy Status: Dead");}

		myDrawText(sText, 20, 50);

		sprintf(sFps,"Frames Per Second:%d",fps.CalculateFrameRate());
		myDrawText(sFps, 20, 550);

		//SDL_Delay(50);
    	//Update the screen 
		if( SDL_Flip( screen ) == -1 ) { return 1; } 
	}
	// Clean up after your self before leaving
	SDL_FreeSurface(player);
	SDL_FreeSurface(badGuy);
	SDL_FreeSurface(back);
	SDL_FreeSurface(blackBack);
	SDL_FreeSurface(thefont);

    SDL_Quit();

    return 0;  
}

