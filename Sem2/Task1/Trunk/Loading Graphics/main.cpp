#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "FPSUtility.h"
#include <string>
using namespace std;

//The attributes of the screen 
const int SCREEN_WIDTH = 800; 
const int SCREEN_HEIGHT = 600; 
const int SCREEN_BPP = 32; //Bits Per Pixel

SDL_Surface *screen = NULL; //the pointer to the screen in memory
SDL_Surface *player = NULL; //the pointer to the image of the player
SDL_Surface *thefont = NULL; //we will use this for text

SDL_Rect sclip,dclip; //used to create clipping rectangles for moving the player image from off-screen to on screen

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

int main(int argc, char *argv[]) 
{
	SDL_Event event;
	bool bgameRunning= true;
	bool keysHeld[323];
	int iFrameX=0, iFrameY=0;
	float fXloc=400, fYloc=300, fMov = 100, deltaTime = 0, fMovTime = 0;
	FPSUtility fps;
	char sFps[255]; char sText[255];
	int thisTime = 0, lastTime = 0;
	float fMaxX = 0, fMaxY = 0; string sCharFileName;
	int iCharSelected = 0;
	int iRClear = 0, iGClear = 0, iBClear = 0;

	do
	{
		cout << "Which character do you want?\n 1. Spearguy\n 2. Giant Angel\n 3. Sephiroth\n";
		cin >> iCharSelected;
	}while (iCharSelected == 0 || iCharSelected > 3);

	switch (iCharSelected)
	{
	case 2:
		sCharFileName = "angel.bmp";
		sprintf(sText, "Character file used: angel.bmp");
		fMaxX = 140;
		fMaxY = 115;
		iRClear = 255; iGClear = 255; iBClear = 255;
	break;
	case 3:
		sCharFileName = "seph.bmp";
		sprintf(sText, "Character file used: seph.bmp");
		fMaxX = 96.25;
		fMaxY = 64;
		iRClear = 184; iGClear = 144; iBClear = 154;
	break;
	default:
		sCharFileName = "davis.bmp";
		sprintf(sText, "Character file used: davis.bmp");
		fMaxX = 32;
		fMaxY = 48;
		iRClear = 255; iGClear = 255; iBClear = 255;
	}

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
	SDL_SetColorKey(player,SDL_SRCCOLORKEY, SDL_MapRGB(player->format, iRClear, iGClear, iBClear) ); 	//Black is the transparent colour

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

		sclip.x = fMaxX*iFrameX; sclip.y = fMaxY*iFrameY; sclip.w = fMaxX; sclip.h = fMaxY; //where the image is  in memory 
		dclip.x = fXloc; dclip.y = fYloc; dclip.w = fMaxX; dclip.h = fMaxY; //where to put the image on screen 
		SDL_BlitSurface(player, &sclip, screen, &dclip);

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
		
		if(fXloc>SCREEN_WIDTH) {fXloc=0-fMaxX;}
		if(fXloc<-fMaxX) {fXloc=SCREEN_WIDTH-10;}
		if(fYloc>SCREEN_HEIGHT) {fYloc=0-fMaxY;}
		if(fYloc<-fMaxY) {fYloc=SCREEN_HEIGHT-10;}

		//Using the function to draw text on the screen at 100,100
		myDrawText(sText, 100, 100);

		sprintf(sFps,"Frames Per Second:%d",fps.CalculateFrameRate());
		myDrawText(sFps, 20, 550);

		//SDL_Delay(50);
    	//Update the screen 
		if( SDL_Flip( screen ) == -1 ) { return 1; } 
	}
	// Clean up after your self before leaving
	SDL_FreeSurface(player);
	SDL_FreeSurface(thefont);

    SDL_Quit();

    return 0;  
}

