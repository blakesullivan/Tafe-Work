
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Player.h"
#include "Baddy.h"
#include "SDL_mixer.h"
#include <time.h>
using namespace std;


//The attributes of the screen 
const int SCREEN_WIDTH = 800; 
const int SCREEN_HEIGHT = 600; 
const int SCREEN_BPP = 32;

SDL_Surface *screen = NULL; //the pointer to the screen in memory
/* Mix_Chunk is like Mix_Music, only it's for ordinary sounds. */
Mix_Chunk *phaser = NULL;
Mix_Music *game = NULL;

/*	Every sound that gets played is assigned to a channel.
	Note that this is different from the number of channels you request when you open the audio device;
	a channel in SDL_mixer holds information about a sound sample that is playing, 
	while the number of channels you request when opening the device is dependant on what sort of sound you want 
	(1 channel = mono, 2 = stereo, etc) */
int phaserChannel = -1;

int main(int argc, char *argv[]) {
	SDL_Event event;
	srand ((unsigned)time(0));
	bool bgameRunning= true;
	bool keysHeld[323];
	//Audio setup
	int audio_rate = 22050;
	Uint16 audio_format = AUDIO_S16; 
	int audio_channels = 2;
	int audio_buffers = 4096;

	Player play;
	Baddy bad;
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
	
	//Set up sound
	if(Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers)) 
	{
		printf("Unable to open audio!\n");
		exit(1);
	}
	phaser = Mix_LoadWAV("bomb.wav");
	game = Mix_LoadMUS("spanishf.wav");

	//Set the window caption 
	SDL_WM_SetCaption( "SDL Test", NULL ); 
	bad.setStartPos(rand() %750+20,rand() %550+20);
	//Fill the screen white 
	SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) ); 
	Mix_PlayMusic( game,-1);
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
				if (true==keysHeld[SDLK_SPACE])
				{
					phaserChannel = Mix_PlayChannel(-1, phaser, 0);
					//play.Move('u');
				}

			}
			if (event.type == SDL_KEYUP)
			{
				keysHeld[event.key.keysym.sym] = false;
			}
		}
		if ( keysHeld[SDLK_ESCAPE] )
		{
			bgameRunning = false;
		}
		if ( keysHeld[SDLK_LEFT] )
		{
			play.Move('l');
		}
		if ( keysHeld[SDLK_RIGHT] )
		{
			play.Move('r');
		}
		if ( keysHeld[SDLK_UP] )
		{
			play.Move('u');
		}
		if (keysHeld[SDLK_DOWN])
		{
			play.Move('d');
			
		}
		if (play.CollisionCheck(bad.getSquareX(),bad.getSquareY(),bad.getSize())==true&&bad.getLife()==true)
		{
			bad.setLife(false);
			phaserChannel = Mix_PlayChannel(-1, phaser, 0);
		}
		play.Draw();
		bad.Draw();
		SDL_Delay(10);

    	//Update the screen 
		if( SDL_Flip( screen ) == -1 ) { return 1; } 
	}
	Mix_HaltMusic();
	Mix_FreeMusic(game);

	Mix_FreeChunk(phaser);
	Mix_CloseAudio();
    SDL_Quit();

    return 0;  
}

