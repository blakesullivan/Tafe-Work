//Blake Sullivan - Main.cpp
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include "Player.h"
using namespace std;

//The attributes of the screen 
const int SCREEN_WIDTH = 800; 
const int SCREEN_HEIGHT = 600; 
const int SCREEN_BPP = 32; //Bits Per Pixel

SDL_Surface *screen = NULL; //the pointer to the screen in memory

int main(int argc, char *argv[]) 
{
	SDL_Event event;
	bool bgameRunning= true;
	bool keysHeld[323];
	srand( time(NULL));
	
	Player play, play2;
	play.Init(400, 300, 255, 233, 0, 5);
	//play2.Init(300, 400, 0, 152, 52, 5);
	Player BadGuy[10];
	for (int i=0; i<10; i++)
	{
		BadGuy[i].Init(rand()%790+5,rand()%590+5,rand()%255,rand()%255,rand()%255,1);
	}

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
			}
			if (event.type == SDL_KEYUP)
			{
				keysHeld[event.key.keysym.sym] = false;
			}
		}

		if (keysHeld[SDLK_ESCAPE])
		{
			bgameRunning=false;
		}
		
		if (keysHeld[SDLK_LEFT])
		{
			play.Move('l');
		}
		if (keysHeld[SDLK_RIGHT])
		{
			play.Move('r');
		}
		if (keysHeld[SDLK_UP])
		{
			play.Move('u');
		}
		if (keysHeld[SDLK_DOWN])
		{
			play.Move('v');
		}

		if (keysHeld[SDLK_a])
		{
			play2.Move('l');
		}
		if (keysHeld[SDLK_d])
		{
			play2.Move('r');
		}
		if (keysHeld[SDLK_w])
		{
			play2.Move('u');
		}
		if (keysHeld[SDLK_s])
		{
			play2.Move('v');
		}

		play.Draw();
		play2.Draw();
		for (int i=0; i<10; i++)
		{
			BadGuy[i].Face(play.GetXo(), play.GetYo());
			BadGuy[i].Move('u');
			BadGuy[i].Draw();
		}
		SDL_Delay(10);

    	//Update the scree;n 
		if( SDL_Flip( screen ) == -1 ) { return 1; }  //Sends the picture to the monitor
	}

    SDL_Quit();

    return 0;  
}

