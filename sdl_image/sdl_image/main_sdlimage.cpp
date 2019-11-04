#include "sdl.h"
#include "sdl_gfxprimitives.h"
#include "sdl_image.h"

//The attributes of the screen 
const int SCREEN_WIDTH = 640; 
const int SCREEN_HEIGHT = 512; 
const int SCREEN_BPP = 32; 

SDL_Surface *screen = NULL; //the pointer to the screen in memory

int main(int argc, char *argv[]) {
	SDL_Event event;
	bool bgameRunning = true;
	bool abMouseButtons[9];

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
	if(screen == NULL) {
		return 1;
	} 

	//IMG_InitFlags();
	IMG_Init(IMG_INIT_JPG);

	SDL_Surface* Pic = IMG_Load("boxkittens.jpg");

	//Set the window caption 
	SDL_WM_SetCaption("SDL_Image", NULL); 
	//Fill the screen white 
	SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF)); 

	//MAIN GAME LOOP
	while (bgameRunning) {	
		// check for any events from the user or the system
		SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF)); 

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
		SDL_BlitSurface(Pic, NULL, screen, NULL);

		//Update the screen 
		if( SDL_Flip( screen ) == -1 ) {
			return 1;
		} 
	}
}