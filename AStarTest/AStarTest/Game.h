#ifndef GAME
#define GAME
#include "Tile.h"
#include "BadGuy.h"
#include "GoodGuy.h"

const short cm_sMaxTileImages=6;
class Game
{
private:
	Tile m_Tile[cm_sXTiles][cm_sYTiles];
	BadGuy m_Bad;
	GoodGuy m_Good;
	short m_sX, m_sY;
public:
	Game();
	void Draw();
	void MouseInput(char,short,short);
	void KeyInput(char);
	void Move();
};
#endif