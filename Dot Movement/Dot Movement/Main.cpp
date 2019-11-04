//Blake Sullivan - Main.cpp

#include "SDL.h"   /* All SDL App's need this */
#include <stdio.h>
#include <stdlib.h>
#include "SDL_gfxPrimitives.h" 
#include "Player.h"
#include "Grid.h"
#include "myastar.h"
using namespace pathfinder;

using namespace std;

//The attributes of the screen 
const int SCREEN_WIDTH = 1024; 
const int SCREEN_HEIGHT = 768; 
const int SCREEN_BPP = 32; //Bits Per Pixel
const int MAP_WIDTH = 64;
const int MAP_HEIGHT = 48;
const int TILE_WIDTH = 32;
int map[MAP_WIDTH * MAP_HEIGHT];

SDL_Surface *screen = NULL; //the pointer to the screen in memory

int main(int argc, char *argv[]) 
{
	SDL_Event event;
	bool bgameRunning= true;
	bool abKeysHeld[323];
	bool abButtonHeld[13];
	float fDeltaTime = 0, fSpaceTime = 0;
	int iThisTime = 0, iLastTime = 0;
	bool bGridChanged = true;
    
	Grid gGrid;
	gGrid.SetupGrid(MAP_WIDTH * TILE_WIDTH, MAP_HEIGHT * TILE_WIDTH, "D1");
	Player pKey;
	Player pMouse;

	pKey.Init('k', 32, 32, 200, 10);
	pKey.SetColour(0, 50, 200);
	pMouse.Init('m', 300, 400, 0, 10);
	pMouse.SetColour(200, 0, 50);

	for (int i=0; i<323; i++)
	{
		abKeysHeld[i] = false; // everything will be initialized to false
		if (i < 13) {abButtonHeld[i] = false;}
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
		iThisTime = SDL_GetTicks();
		fDeltaTime = static_cast<float>(iThisTime - iLastTime) / 1000;
		iLastTime = iThisTime;

		SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) ); 

		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
				{bgameRunning = false;}
			if (event.type == SDL_KEYDOWN)
				{abKeysHeld[event.key.keysym.sym] = true;}
			if (event.type == SDL_KEYUP)
				{abKeysHeld[event.key.keysym.sym] = false;}
			if (event.type == SDL_MOUSEBUTTONDOWN)
				{abButtonHeld[event.button.button] = true;}
			if (event.type == SDL_MOUSEBUTTONUP)
				{abButtonHeld[event.button.button] = false;}
		}
		
		if (abButtonHeld[SDL_BUTTON_LEFT] == true)
		{
			int mouseX, mouseY;
			SDL_GetMouseState(&mouseX, &mouseY);
			if (gGrid.GetSquare(mouseX, mouseY)->GetWalkable() == 0)
			{
				cout << "Change Colour to 9" << endl;
				gGrid.GetSquare(mouseX, mouseY)->SetWalkable(9);
			}
			else
			{
				cout << "Change Colour to 0" << endl;
				gGrid.GetSquare(mouseX, mouseY)->SetWalkable(0);
			}
			abButtonHeld[SDL_BUTTON_LEFT] = false;
			cout << "Change Colour: " << gGrid.GetSquare(mouseX, mouseY)->GetWalkable() << " Row: " << gGrid.GetSquare(mouseX, mouseY)->GetRow() << " Col: " << gGrid.GetSquare(mouseX, mouseY)->GetCol() << endl;
		}
		gGrid.DrawGrid(screen);

		if (abKeysHeld[SDLK_u] == true)
		{
			cout << "Updating Map.\n";
			abKeysHeld[SDLK_u] = false;
			bGridChanged = true;
		}

		if (bGridChanged == true)
		{
			bGridChanged = false;
			int tempX = 0, tempY = 0;
			for (int i = 0; i < MAP_WIDTH * MAP_HEIGHT; i++)
			{
				SetMap(tempX, tempY, gGrid.GetSquareFromRC(tempX, tempY)->GetWalkable());
				tempX++;;
				if (tempX >= MAP_WIDTH ) {tempX = 0; tempY++;}
			}
		}

		if (abButtonHeld[SDL_BUTTON_RIGHT] == true)
		{
			int mouseX, mouseY;
			SDL_GetMouseState(&mouseX, &mouseY);
			pMouse.SetX(mouseX);
			pMouse.SetY(mouseY);
			abButtonHeld[SDL_BUTTON_RIGHT] = false;
			cout << "Red Square Row: " << gGrid.GetSquare(pMouse.GetX(), pMouse.GetY())->GetRow() << " Col: " << gGrid.GetSquare(pMouse.GetX(), pMouse.GetY())->GetCol() << endl;
		}

		if (abKeysHeld[SDLK_w] == true || abKeysHeld[SDLK_UP] == true)
			{pKey.MovePlayer('u', fDeltaTime);}
		if (abKeysHeld[SDLK_s] == true || abKeysHeld[SDLK_DOWN] == true)
			{pKey.MovePlayer('d', fDeltaTime);}
		if (abKeysHeld[SDLK_a] == true || abKeysHeld[SDLK_LEFT] == true)
			{pKey.MovePlayer('l', fDeltaTime);}
		if (abKeysHeld[SDLK_d] == true || abKeysHeld[SDLK_RIGHT] == true)
			{pKey.MovePlayer('r', fDeltaTime);}

		if (abKeysHeld[SDLK_SPACE] == true && fSpaceTime > 0.2) //0)
		{
			fSpaceTime = 0;
			int MoveX = 0, MoveY = 0;
			findPath(pKey.GetX() / TILE_WIDTH, pKey.GetY() / TILE_WIDTH, pMouse.GetX() / TILE_WIDTH, pMouse.GetY() / TILE_WIDTH, MoveX, MoveY, false);
			cout << "MoveX: " << MoveX << " MoveY: " << MoveY << endl;
			cout << "KeyX: " << (int)(pKey.GetX()/TILE_WIDTH) << " KeyY: " << (int)(pKey.GetY()/TILE_WIDTH) << endl;
			cout << "MouseX: " << (int)(pMouse.GetX()/TILE_WIDTH) << " MouseY: " << (int)(pMouse.GetY()/TILE_WIDTH) << endl;
			if (MoveX > 0 || ((int)(pKey.GetX()/TILE_WIDTH) != (int)(pMouse.GetX()/TILE_WIDTH))) {pKey.SetX((MoveX * TILE_WIDTH) + (TILE_WIDTH/2));} // + (Square::GetSize() / 2));
			if (MoveY > 0 || ((int)(pKey.GetY()/TILE_WIDTH) != (int)(pMouse.GetY()/TILE_WIDTH))) {pKey.SetY((MoveY * TILE_WIDTH) + (TILE_WIDTH/2));} // + (Square::GetSize() / 2));

			/*findPath(pKey.GetX(), pKey.GetY(), pMouse.GetX(), pMouse.GetY(), MoveX, MoveY, true);
			cout << "MoveX: " << MoveX << " MoveY: " << MoveY << endl;
			if (MoveX > 0) {pKey.SetX(MoveX);} // + (Square::GetSize() / 2));
			if (MoveX > 0) {pKey.SetY(MoveY);} // + (Square::GetSize() / 2));*/
		}
		fSpaceTime += fDeltaTime;
		//cout << fDeltaTime << endl;

		filledCircleRGBA(screen, pKey.GetX(), pKey.GetY(), pKey.GetSize(), pKey.GetRed(), pKey.GetGreen(), pKey.GetBlue(), pKey.GetAlpha());
		filledCircleRGBA(screen, pMouse.GetX(), pMouse.GetY(), pMouse.GetSize(), pMouse.GetRed(), pMouse.GetGreen(), pMouse.GetBlue(), pMouse.GetAlpha());

    	//Update the screen 
		if( SDL_Flip( screen ) == -1 ) { return 1; } 
	}

    SDL_Quit();

    return 0;  
}