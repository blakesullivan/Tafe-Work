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

int main(int argc, char *argv[]) {
	SDL_Event event;
	bool bgameRunning= true;
	bool keysHeld[323];

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

    	//Update the screen 
		if( SDL_Flip( screen ) == -1 ) { return 1; } 
	}

    SDL_Quit();

    return 0;  
}

