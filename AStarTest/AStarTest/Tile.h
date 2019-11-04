#ifndef TILE
#define TILE
#include "SDL.h"

extern SDL_Surface *screen,*square;
extern SDL_Rect sclip,dclip;

const short cm_sTileSize=32;
class Tile
{
private:
	short m_sOpacity, m_sTileNumber;
	bool m_bPassable;
public:
	Tile();
	void setOpacity(short);
	short getOpacity();
	void setTileNumber(short);
	short getTileNumber();
	void setPassable(bool);
	bool getPassable();
	void Display(short,short);
	void Init();
};
#endif