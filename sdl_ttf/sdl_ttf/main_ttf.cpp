#include "SDL.h"
#include "SDL_ttf.h"

#include <iostream>

#include "myText.h"

//The attributes of the screen 
const int SCREEN_WIDTH = 453; 
const int SCREEN_HEIGHT = 373; 
const int SCREEN_BPP = 32; 

SDL_Surface *screen = NULL; //the pointer to the screen in memory

int main(int argc, char *argv[]) {
	SDL_Event event;
	bool bgameRunning = true;
	bool abMouseButtons[9];
	myText mt;

	SDL_Surface* surf_mario = NULL;

	for (int i = 0; i < 9; i++) {
		abMouseButtons[i] = false;
	}

	float deltatime = 0;
	int thistime = 0, lasttime = 0;

    //Initialize all SDL subsystems 
	if(SDL_Init(SDL_INIT_EVERYTHING) == -1 ) { 
		return 1; 
	}

    //Set up the screen 
	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);

	//If there was an error in setting up the screen 
	if(screen == NULL) 
	{
		return 1;
	} 

	//Libs
	mt.Initialize();
	std::string stemp = getenv("windir"); 
	stemp += "/Fonts/Achafsex.ttf";
	mt.LoadFont("mario", stemp, 12);

	//Pic
	surf_mario = SDL_LoadBMP("mario.bmp");

	//Set the window caption 
	SDL_WM_SetCaption("SDL_TTF", NULL); 
	//Fill the screen white 
	SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 100, 255, 255)); 

	//MAIN GAME LOOP
	while (bgameRunning) {	
		// check for any events from the user or the system
		SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 100, 255, 255)); 

		thistime = SDL_GetTicks();
		deltatime = (float)(thistime - lasttime)/1000;
		lasttime = thistime;

		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				bgameRunning = false;
			}
			if (event.type == SDL_MOUSEBUTTONDOWN) {
				abMouseButtons[event.button.button] = true;
			}
			if (event.type == SDL_MOUSEBUTTONUP) {
				abMouseButtons[event.button.button] = false;
			}
		}

		//Draw
		SDL_BlitSurface(surf_mario, NULL, screen, NULL);
		mt.Print(10, 100, "I'm sorry Mario, but your", 255, 255, 255, 0, 0, "mario");
		mt.Print(10, 130, "princess is in another castle.", 255, 255, 255, 0, 0, "mario");

		//Update the screen 
		if (SDL_Flip(screen) == -1) {
			return 1;
		} 
	}

	mt.Close();
	SDL_Quit();
}