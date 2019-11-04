#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include "Player.h"
#include "BadGuy.h"
#include "Bullet.h"
using namespace std;

bool CollisionCheck(float, float, float, float, float, float);
//The attributes of the screen 
const int SCREEN_WIDTH = 800; 
const int SCREEN_HEIGHT = 600; 
const int SCREEN_BPP = 32; 

SDL_Surface *screen = NULL; //the pointer to the screen in memory

int main(int argc, char *argv[]) {
	SDL_Event event;
	bool bgameRunning= true;
	bool keysHeld[323];
	srand ( time(NULL) );
	Player play;
	play.Init(400,300,rand()%256,rand()%256,rand()%256,5);
	BadGuy enemy[10];
	for (int i=0; i<10; i++)
	{
		enemy[i].init(rand()%750+25, rand()%550+25);
	}
	Bullet bullets[100];
	for (int i=0; i<100; i++)
	{
		bullets[i].SetAlive(false);
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
	SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 255, 255, 255 ) ); 
	while (bgameRunning)
	{	// check for any events from the user or the system
		SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 255, 255, 255 ) ); 
		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				bgameRunning = false;
			}
			if (event.type == SDL_KEYDOWN)
			{
				keysHeld[event.key.keysym.sym] = true;
				if (keysHeld[SDLK_r])
				{
					for (int i=0; i<10; i++)
					{
						enemy[i].SetLife(true);
					}
				}
				if (true==keysHeld[SDLK_SPACE])
				{
					for (int i=0;i<100;i++)
					{
						if (false==bullets[i].GetAlive())
						{
							bullets[i].Create(play.GetIX1(), play.GetIY1(), play.GetDeg(), 5);
							break;
						}
					}
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
			if (play.GetIXo() > 10)
			{
				play.Move('l');
			}
		}
		if ( keysHeld[SDLK_RIGHT] )
		{
			if (play.GetIXo() < SCREEN_WIDTH-10)
			{
				play.Move('r');
			}
		}
		if ( keysHeld[SDLK_UP] )
		{
			if (play.GetIYo() > 10)
			{
				play.Move('u');
			}
		}
		if (keysHeld[SDLK_DOWN])
		{
			if (play.GetIYo() < SCREEN_HEIGHT-10)
			{
				play.Move('d');
			}
		}

		for (int i=0; i<10; i++)
		{
			if (true==enemy[i].GetLife())
			{
				enemy[i].Face(play.GetIXo(), play.GetIYo());
				//enemy[i].Move();
			}
		}

		for (int i = 0; i<100; i++)
		{
			if (bullets[i].GetAlive()==true)
			{
				bullets[i].Move();
			}
		}

		
		for (int i=0; i<10; i++)
		{
			if (enemy[i].GetLife()==true)
			{
				if (true==CollisionCheck(play.GetIXo(), play.GetIYo(), play.GetSize(), enemy[i].GetPosX(), enemy[i].GetPosY(), enemy[i].GetPosSize()))
				{
					enemy[i].SetLife(false);
				}
			}
		}

		for (int i=0; i<10; i++)
		{
			if (enemy[i].GetLife()==true)
			{
				for (int j=i+1; j<10; j++) 
				{
					if (enemy[j].GetLife()==true)
					{
						if (true==CollisionCheck(enemy[i].GetPosX(), enemy[i].GetPosY(), enemy[i].GetPosSize(), enemy[j].GetPosX(), enemy[j].GetPosY(), enemy[j].GetPosSize()))
						{
							enemy[i].SetLife(false);
						}
					}
				}
			}
		}

		/*for (int i=0; i<100; i++)
		{
			if (true==CollisionCheck(play.GetIXo(), play.GetIYo(), play.GetSize(), bullets[i].GetX(), bullets[i].GetY(), bullets[i].GetSize()))
			{
				play.SetAlive(false);
			}
		}*/

		for (int i=0; i<100; i++)
		{
			if (bullets[i].GetAlive()==true)
			{
				for (int j=0; j<10; j++) 
				{
					if (enemy[j].GetLife()==true)
					{
						if (true==CollisionCheck(bullets[i].GetX(), bullets[i].GetY(), bullets[i].GetSize(), enemy[j].GetPosX(), enemy[j].GetPosY(), enemy[j].GetPosSize()))
						{
							enemy[j].SetLife(false);
							bullets[i].SetAlive(false);
						}
					}
				}
			}
		}


		if (play.GetAlive()==true)
		{
			play.Draw();
		}
		for (int i=0;i<10;i++)
		{
			if (true==enemy[i].GetLife())
			{
				enemy[i].Draw();
			}
		}
		for (int i = 0; i<100; i++)
		{
			if (bullets[i].GetAlive()==true)
			{
				bullets[i].Draw();
			}
		}
		
		SDL_Delay(10);

    	//Update the screen 
		if( SDL_Flip( screen ) == -1 ) { return 1; } 
	}

    SDL_Quit();

    return 0;  
}

bool CollisionCheck(float p1X, float p1Y, float p1S, float p2X, float p2Y, float p2S)
{
	if (sqrt(pow((p2X-p1X),2)+pow((p2Y-p1Y),2)) <= p1S + p2S)
	{
		return true;
	}
	else
		return false;
}