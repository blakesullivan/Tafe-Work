//Blake Sullivan - Main.cpp
#include "SDL.h"   /* All SDL App's need this */
#include <stdio.h>
#include <stdlib.h>
#include "SDL_gfxPrimitives.h" 
#include <iostream>

#include "Level.h"

using namespace std;

//The attributes of the screen 
const int SCREEN_WIDTH = 1024; 
const int SCREEN_HEIGHT = 768; 
const int SCREEN_BPP = 32; //Bits Per Pixel

SDL_Surface *screen = NULL; //the pointer to the screen in memory

bool keysHeld[323];
bool buttonsHeld[13];

int myID;

void Update(SDL_Surface* screen, float fDeltaTime, Level* pLevel);
void Draw(SDL_Surface* screen, float fDeltaTime, Level* pLevel);

int main(int argc, char *argv[]) 
{
	SDL_Event event;
	bool bgameRunning= true;
	Level* pLevel;
	float fDeltaTime = 0;
	int iThisTime = 0, iLastTime = 0;
	for (int i=0; i<323; i++)
	{
		keysHeld[i] = false; // everything will be initialized to false
		if (i < 13) {buttonsHeld[i] = false;}
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
	pLevel = new Level();


	myID = cidBuster;

	while (bgameRunning)
	{	// check for any events from the user or the system
		SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 50, 200, 50 ) ); 

		iThisTime = SDL_GetTicks();
		fDeltaTime = (float)(iThisTime - iLastTime) / 1000;
		iLastTime = iThisTime;

		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				{bgameRunning = false;}

			if (event.type == SDL_KEYDOWN)
				{keysHeld[event.key.keysym.sym] = true;}
			if (event.type == SDL_KEYUP)
				{keysHeld[event.key.keysym.sym] = false;}

			if (event.type == SDL_MOUSEBUTTONDOWN)
				{buttonsHeld[event.button.button] = true;}
			if (event.type == SDL_MOUSEBUTTONUP)
				{buttonsHeld[event.button.button] = false;}
		}
		Update(screen, fDeltaTime, pLevel);
		Draw(screen, fDeltaTime, pLevel);

    	//Update the screen 
		if( SDL_Flip( screen ) == -1 ) { return 1; } 
	}

    SDL_Quit();
	delete pLevel;

    return 0;  
}

void Update(SDL_Surface* screen, float fDeltaTime, Level* pLevel)
{
	//static float iPTime = 0;
	pLevel->Update(fDeltaTime);
	//do something
	if (keysHeld[SDLK_UP] == true || keysHeld[SDLK_w] == true)
	{
		pLevel->GetCharacter(myID)->MoveCharacter('u', fDeltaTime);
	}
	if (keysHeld[SDLK_DOWN] == true || keysHeld[SDLK_s] == true)
	{
		pLevel->GetCharacter(myID)->MoveCharacter('d', fDeltaTime);
	}
	if (keysHeld[SDLK_LEFT] == true || keysHeld[SDLK_a] == true)
	{
		pLevel->GetCharacter(myID)->MoveCharacter('l', fDeltaTime);
	}
	if (keysHeld[SDLK_RIGHT] == true || keysHeld[SDLK_d] == true)
	{
		pLevel->GetCharacter(myID)->MoveCharacter('r', fDeltaTime);
	}
	if (keysHeld[SDLK_q] == true)
	{
		pLevel->GetCharacter(myID)->MoveCharacter('q', fDeltaTime);
	}
	if (keysHeld[SDLK_e] == true)
	{
		pLevel->GetCharacter(myID)->MoveCharacter('e', fDeltaTime);
	}

	if (keysHeld[SDLK_c] == true)
	{
		keysHeld[SDLK_c] = false;
		if (myID < cidZabat)
			{myID++;}
		else
			{myID = cidBuster;}
	}

	if (buttonsHeld[SDL_BUTTON_LEFT] == true)
	{
		pLevel->AddBullet(myID);
		buttonsHeld[SDL_BUTTON_LEFT] = false;
	}

	//iPTime += fDeltaTime;
	//if (iPTime >= 5)
	//{
	//	pLevel->AddPickup();
	//	iPTime = 0;
	//}
}
void Draw(SDL_Surface* screen, float fDeltaTime, Level* pLevel)
{
	//do something
	pLevel->Draw(screen, fDeltaTime);
}