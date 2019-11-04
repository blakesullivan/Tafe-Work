#include "SDL.h"
#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "FPS Modulator.h"

//The attributes of the screen 
const int SCREEN_WIDTH = 800; 
const int SCREEN_HEIGHT = 640; 
const int SCREEN_BPP = 32; 

SDL_Surface *screen = NULL; //the pointer to the screen in memory
SDL_Surface *square=NULL; //the pointer to the square images
SDL_Rect sclip,dclip;

int main(int argc, char *argv[]) {
	SDL_Event event;
	bool bgameRunning= true;
	bool keysHeld[323];
	bool buttonHeld[13];
	int mouse_x=0, mouse_y=0;
	bool bToggle=false;

	for (int i=0; i<322; i++)
		keysHeld[i] = false; // everything will be initialized to false
	for (int i=0; i<13; i++)
		buttonHeld[i] = false; // everything will be initialized to false
    //Initialize all SDL subsystems 
	if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 ) 
	{ return 1; } 

    //Set up the screen 
	screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE ); 
	//If there was an error in setting up the screen 
	if( screen == NULL ) { return 1; } 
	//Set the window caption 
	SDL_WM_SetCaption( "A* Test", NULL ); 

	square = SDL_LoadBMP( "Simple maze tiles32.bmp" ); //Setting the square to point at the image
	SDL_SetColorKey(square,SDL_SRCCOLORKEY, SDL_MapRGB(square->format, 0, 0, 0) ); 	//Black is the transparent colour
	
	Game game; //Creates the game object.  Must be done before the game loop but after the image is loaded
	FPS_Modulator mod;
	mod.setFPS(20);

	//Fill the screen white 
	SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );
	while (bgameRunning)
	{	// check for any events from the user or the system
		mod.CalcMod();
		SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) ); 
		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				bgameRunning = false;
			if (event.type == SDL_KEYDOWN)
				keysHeld[event.key.keysym.sym] = true;
			if (event.type == SDL_KEYUP)
				keysHeld[event.key.keysym.sym] = false;
			if (event.type==SDL_MOUSEBUTTONDOWN)
				buttonHeld[event.button.button]=true;
			if (event.type==SDL_MOUSEBUTTONUP)
				buttonHeld[event.button.button]=false;
		}

		if (keysHeld[SDLK_ESCAPE])
			bgameRunning=false;
		if (mod.getFrameChange()==true) //Any display and input functions are in here
		{
			game.Draw(); //The map has to be drawn before the player's character is
			SDL_GetMouseState(&mouse_x,&mouse_y);
			if (buttonHeld[SDL_BUTTON_LEFT])
				game.MouseInput('l',mouse_x,mouse_y);
			if (keysHeld[SDLK_g]&&!bToggle)
			{
				game.KeyInput('g');
				bToggle=!bToggle;
			}
			else if (!keysHeld[SDLK_g]&&bToggle)
				bToggle=!bToggle;
		game.Move();
	
		//Update the screen 
		if( SDL_Flip( screen ) == -1 ) { return 1; }
		}
	}

    SDL_FreeSurface(square); //Free up the image from memory
    SDL_Quit();

    	return 0;  
}