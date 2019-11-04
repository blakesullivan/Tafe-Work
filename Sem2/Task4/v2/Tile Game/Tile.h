//Blake Sullivan - Tile.h
#ifndef TILE_H
#define TILE_H

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Tile
{
private:
	const static unsigned int MCS_UISIZE = 32;
	unsigned int m_uiX, m_uiY;
	unsigned int m_uiPicPos;
	int m_iPassable;
	unsigned int m_uiGridX, m_uiGridY;
	static vector<int> m_viPass;

public:
	Tile();

	void Init(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);

	void SetX(unsigned int);
	void SetY(unsigned int);
	void SetGridX(unsigned int);
	void SetGridY(unsigned int);
	void SetPicPos(unsigned int);
	void SetPassable(int);

	unsigned int GetX();
	unsigned int GetY();
	unsigned int GetGridX();
	unsigned int GetGridY();
	unsigned int GetPicPos();
	int GetPassable();

	static unsigned int GetSize();
	static void SetTilePass();
	int GetPass(int);
};
#endif