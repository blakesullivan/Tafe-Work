#include "Tile.h"

Tile::Tile()
{
	Init();
}
void Tile::setOpacity(short sOpacity) /*sets opacity (opposite of transparency) from 0-100.  This tells the player whether they 
									  can see through the tile and if so how far*/
{
	m_sOpacity=sOpacity;
}
short Tile::getOpacity()
{
	return m_sOpacity;
}
void Tile::setTileNumber(short sTileNumber) //sets the TileNumber of tile
{
	m_sTileNumber=sTileNumber;
}
short Tile::getTileNumber()
{
	return m_sTileNumber;
}
void Tile::setPassable(bool bPass) //sets whether the player can pass through the tile
{
	m_bPassable=bPass;
}
bool Tile::getPassable()
{
	return m_bPassable;
}
void Tile::Display(short X,short Y) //Draws the tile once its X and Y position are passed to it
{
	sclip.x=m_sTileNumber*cm_sTileSize; sclip.y = 0; sclip.w = cm_sTileSize; sclip.h = cm_sTileSize; 	//where the image is  in memory 
	dclip.x = X*cm_sTileSize; dclip.y = Y*cm_sTileSize; dclip.w = cm_sTileSize; dclip.h = cm_sTileSize; 	//where to put the image on screen 
	SDL_BlitSurface(square, &sclip, screen, &dclip);
}
void Tile::Init() //Resets and initialises the tiles (constructor calls this function)
{
	m_sTileNumber=0;
	m_sOpacity=0;
	m_bPassable=true;
}