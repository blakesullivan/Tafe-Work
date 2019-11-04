//Blake Sullivan - Manager.h
#ifndef MANAGER_H
#define MANAGER_H

#include "SDL.h"   /* All SDL App's need this */
//#include "SDL_gfxPrimitives.h" 
//#include <stdio.h>
//#include <stdlib.h>
//#include <iostream>
//#include <vector>
//#include <time.h>
//#include <fstream>
#include "Tile.h"
#include "MenuButton.h"
#include "Player.h"
//using namespace std;

class Manager
{
private:
	//The attributes of the screen 
	const static int SCREEN_WIDTH = 1000;
	const static int SCREEN_PLAY_WIDTH = 800;
	const static int SCREEN_HEIGHT = 608; 
	const static int SCREEN_BPP = 32; //Bits Per Pixel
	const static int bgnum = 3;

	SDL_Surface *screen; //the pointer to the screen in memory
	SDL_Surface *tile;
	SDL_Surface *button;
	SDL_Surface *thefont;
	SDL_Surface *player;
	SDL_Surface *badguy;

	vector<Tile> m_vTiles;
	vector<Tile>::iterator m_vTilesIT;

	vector<MenuButton> m_vButtons;
	vector<MenuButton>::iterator m_vButtonsIT;

	bool keysHeld[323];
	bool m_bKeyUsed;
	bool buttonHeld[13];
	bool bgameRunning;

	Tile m_EditTile;
	Player m_player;
	Player m_bg[bgnum];

public:
	Manager();
	~Manager();

	int ManagePlay();
	void CreateTiles();
	void UpdateTiles(bool&, int, int);
	void DrawTiles();

	void CreateButtons();
	void UpdateButtons(int, int);
	void DrawButtons();
	int CheckButtonPressed();

	void LoadMap(string);
	void SaveMap(string);

	void CreatePlayer();
	void DrawPlayer(Player&, SDL_Surface*);
	void MovePlayer();
	void MoveBadGuy();
	bool CheckMove(float, float);

	void myDrawText(char[], int, int);
};

#endif