#include "SDL.h"   /* All SDL App's need this */
#include <stdio.h>
#include <stdlib.h>
#include "SDL_gfxPrimitives.h" 
#include <iostream>

using namespace std;


//The attributes of the screen 
const int SCREEN_WIDTH = 800; 
const int SCREEN_HEIGHT = 600; 
const int SCREEN_BPP = 32; //Bits Per Pixel

SDL_Surface *screen = NULL; //the pointer to the screen in memory
SDL_Surface *player = NULL; //the pointer to the image of the player
SDL_Surface *thefont = NULL; //we will use this for text

SDL_Rect sclip,dclip; //used to create clipping rectangles for moving the player image from off-screen to on screen

class FPSUtility
{
private: 
	static int lastTick;
	static int lastFrameRate;
	static int frameRate;

public:
	static int CalculateFrameRate()
	{
		if (SDL_GetTicks() - lastTick >= 1000)
		{
			lastFrameRate = frameRate;
			frameRate = 0;
			lastTick = SDL_GetTicks();
		}
		frameRate++;
		return lastFrameRate;
	}
};
int FPSUtility::frameRate=0;		
int FPSUtility::lastFrameRate=0;
int FPSUtility::lastTick=0;

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

int main(int argc, char *argv[]) {
	SDL_Event event;
	bool bgameRunning= true;
	bool keysHeld[323];
	int x1=380, x2=420, y1=280, y2=320;
	int iFrame=0, iXloc=0, iYloc=0;
	FPSUtility fps;
	char sFps[255];
	int deltaTime = 0, thisTime = 0, lastTime = 0;


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
	player = SDL_LoadBMP( "davis.bmp" ); //Setting the player to point at the image
	SDL_SetColorKey(player,SDL_SRCCOLORKEY, SDL_MapRGB(player->format, 69, 78, 91) ); 	//Black is the transparent colour

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

		sclip.x = iFrame*32; sclip.y = 0; sclip.w = 32; sclip.h = 48; //where the image is  in memory 
		dclip.x = iXloc; dclip.y = iYloc; dclip.w = 32; dclip.h = 48; //where to put the image on screen 
		SDL_BlitSurface(player, &sclip, screen, &dclip);

		thisTime = SDL_GetTicks();
		deltaTime = thisTime - lastTime;
		if(deltaTime > 200)
		{
			iFrame++;
			lastTime = thisTime;
		}
		if (iFrame>=4) {iFrame=0;}
		
		iXloc=400;
		//if(iXloc>SCREEN_WIDTH) {iXloc=10;}
		iYloc=300;
		//if(iYloc>SCREEN_HEIGHT) {iYloc=10;}

		//Using the function to draw text on the screen at 100,100
		myDrawText("IT'S OVER 9000!!!", 100, 100);

		sprintf(sFps,"Frames Per Second:%d",fps.CalculateFrameRate());
		myDrawText(sFps, 20, 300);

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

