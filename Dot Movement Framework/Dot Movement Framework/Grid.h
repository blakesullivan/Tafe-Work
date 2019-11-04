//Blake Sullivan - Grid.h
#ifndef GRID_H
#define GRID_H

#include "SDL_gfxPrimitives.h" 
#include "Square.h"
#include "myastar.h"
using namespace Pathfinder;
#include <vector>
#include <iostream>
using namespace std;

class Grid
{
private:
	vector<Square> m_vSquares;
	vector<Square>::iterator m_vSquaresIT;
	const int MC_IMAP_WIDTH;
	const int MC_IMAP_HEIGHT;
	const int MC_ITILE_WIDTH;
	int map[];
public:
	Grid();
	Grid(int w, int h);
	~Grid();

	void SetupGrid(int iWidth, int iHeight);

	void DrawGrid(SDL_Surface* screen);

	void AddSquare(int r, int c, int x, int y);
	Square GetSquare(int x, int y);
};
#endif