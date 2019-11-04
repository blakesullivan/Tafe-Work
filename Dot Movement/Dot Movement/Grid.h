//Blake Sullivan - Grid.h
#ifndef GRID_H
#define GRID_H

#include "SDL_gfxPrimitives.h" 
#include "Square.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Grid
{
private:
	vector<Square> m_vSquares;
	vector<Square>::iterator m_vSquaresIT;
	SDL_Surface* m_pMap;

public:
	Grid();
	~Grid();

	void SetupGrid(int iWidth, int iHeight, string sMapName);

	void DrawGrid(SDL_Surface* screen);

	void AddSquare(int r, int c, int x, int y, int tpp);
	Square* GetSquare(int x, int y);
	Square* Grid::GetSquareFromRC(int x, int y);

	void SetMap(string);
	SDL_Surface* GetMap();
};
#endif