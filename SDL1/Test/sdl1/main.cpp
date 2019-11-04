#include "SDL.h"   /* All SDL App's need this */
#include <stdio.h>
#include <stdlib.h>
#include "SDL_gfxPrimitives.h" 
#include <iostream>

using namespace std;


//The attributes of the screen 
const int SCREEN_WIDTH = 800; 
const int SCREEN_HEIGHT = 600; 
const int SCREEN_BPP = 32; 

SDL_Surface *screen = NULL; //the pointer to the screen in memory

int main(int argc, char *argv[]) {
	SDL_Event event;
	bool bgameRunning= true;
	bool keysHeld[323];
	float iX1 = 350, iY1 = 250, iX2 = 375, iY2 = 275;
	float iChangeX = 10, iChangeY = 10, iChangeY2 = -10;
	int iRed = 255, iGreen = 255, iBlue = 255, iAlpha = 255;

	for (int i=0; i<322; i++)
	{
		keysHeld[i] = false; // everything will be initialized to false
	}
    //Initialize all SDL subsystems 
	if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 ) 
	{ return 1; } 

    //Set up the screen 
	screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE ); 
	//If there was an error in setting up the screen 
	if( screen == NULL ) { return 1; } 
	//Set the window caption 
	SDL_WM_SetCaption( "SDL Test", NULL ); 

	//Fill the screen white 
	SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0, 0, 0 ) ); 
	while (bgameRunning)
	{	// check for any events from the user or the system
		SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0, 0, 0 ) ); 
		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				bgameRunning = false;
			}
			if (event.type == SDL_KEYDOWN)
			{
				keysHeld[event.key.keysym.sym] = true;

				SDLKey keyPressed = event.key.keysym.sym;
				switch (keyPressed)
				{
				case SDLK_UP:
					iChangeY2 = -5;
					break;
				case SDLK_DOWN:
					iChangeY2 = 5;
					break;
				}
				/*if (iY2 > 550)
				{iChangeY2 = -5;}
				else if (iY2 < 50)
				{iChangeY2 = 5;}*/
				iY2 += iChangeY2;
			}
			if (event.type == SDL_KEYUP)
			{
				keysHeld[event.key.keysym.sym] = false;
			}
		}

		if (iX2 > 780)
		{iChangeX = -0.1;}
		else if (iX1 < 60)
		{iChangeX = 0.1;}

		if (iY1 > 575)
		{iChangeY = -0.1;}
		else if (iY1 < 25)
		{iChangeY = 0.1;}

		iX1 += iChangeX;
		iX2 += iChangeX;
		iY1 += iChangeY;
		//iY2 += iChangeY;

		//rectangleRGBA(screen, iX1, iY1, iX2, iY2, 100, 1, 255, 100);
		filledEllipseRGBA(screen, iX1, iY1, 25, 25, iRed, iGreen, iBlue, iAlpha);
		boxRGBA(screen, 10, iY1-50, 30, iY1+50, 255, 255, 255, iAlpha);

		/*iY1 += iChangeY * -1;
		if (iY2 > 550)
		{iChangeY2 = -15;}
		else if (iY2 < 50)
		{iChangeY2 = 15;}

		if (iX1 > 400)
		{
			iY2 += iChangeY;
			//if (iY2 > iY1)
			//{iY2 -= iY2-iY1;}
			//else
			//{iY2 += iY2-iY1;}
		}
		else
		{iY2 += iChangeY2;}*/
		boxRGBA(screen, 770, iY2-50, 790, iY2+50, 255, 255, 255, iAlpha);
    	//Update the screen 
		if( SDL_Flip( screen ) == -1 ) { return 1; } 
		//SDL_Delay( 15 );
	}

    SDL_Quit(); //Always include, wipes the memory of all the sdl stuff.
    return 0;  
}