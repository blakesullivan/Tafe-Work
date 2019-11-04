//Blake Sullivan - Tile.h
#ifndef TILE_H
#define TILE_H

#include <iostream>
#include <fstream>
using namespace std;

class Tile
{
private:
	const static unsigned int MCS_UISIZE = 32;
	unsigned int m_uiX, m_uiY;
	unsigned int m_uiPicPos;
	bool m_bPassable;
	unsigned int m_uiGridX, m_uiGridY;

public:
	Tile();

	void Init(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);

	void SetX(unsigned int);
	void SetY(unsigned int);
	void SetGridX(unsigned int);
	void SetGridY(unsigned int);
	void SetPicPos(unsigned int);
	void SetPassable(bool);

	unsigned int GetX();
	unsigned int GetY();
	unsigned int GetGridX();
	unsigned int GetGridY();
	unsigned int GetPicPos();
	bool GetPassable();

	static unsigned int GetSize();
};
#endif