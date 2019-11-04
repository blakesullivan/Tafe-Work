//Blake Sullivan - Manager.h
#ifndef MANAGER
#define MANAGER
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "FPSUtility.h"
#include "GridPiece.h"
using namespace std;

class Manager
{
private:
	//The attributes of the screen 
	const int SCREEN_WIDTH; 
	const int SCREEN_HEIGHT; 
	const int SCREEN_BPP; //Bits Per Pixel
	
	int iCellSize;
	int iMouseX, iMouseY;
	bool buttonHeld[13];
	bool m_bCheckGrid;

	SDL_Surface *screen; //the pointer to the screen in memory
	SDL_Surface *grid;
	//SDL_Rect sclip, dclip;

	vector <GridPiece> mv_Grid;
	vector <GridPiece>::iterator mv_GridIT;

public:
	Manager();
	int GameManage();
	void SetupGrid();
	void CheckGrid();
	bool FindLiveNeighbour(const int, const int);
	void ChangeGrid();
};
#endif