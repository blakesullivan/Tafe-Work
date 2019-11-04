#include "Game.h"

Game::Game()//Constructor loads the map.  Copied from the map editor's Load() function.
{
	ifstream load("SavedMap.txt");
	string ssLine;
	string ssString;
	while (load.good()&&load.eof()==false) //If the file can be opened and not endoffile, read the line and add it to the string
	{
		getline(load,ssLine);
		ssString=ssString+ssLine;
	}
	load.close();

	for (short i=0;i<cm_sXTiles;i++)
	{
		for (short n=0;n<cm_sYTiles;n++) //For each tile, take the useful data and delete the unuseful data 
		{
			ssString.erase(0,ssString.find(" ")+1);
			ssString.erase(0,ssString.find(" ")+1);
			if (ssString.find(" ")==1)
				m_Tile[i][n].setOpacity((short)ssString[0]-48);
			else if (ssString.find(" ")==2)
				m_Tile[i][n].setOpacity(((short)ssString[0]-48)*10+(short)ssString[1]-48);
			else 
				m_Tile[i][n].setOpacity(100);
			ssString.erase(0,ssString.find(" ")+1);
			ssString.erase(0,ssString.find(" ")+1);
			m_Tile[i][n].setPassable((short)ssString[0]-48);
			ssString.erase(0,ssString.find(" ")+1);
			ssString.erase(0,ssString.find(" ")+1);
			if (ssString.find(" ")==1)
				m_Tile[i][n].setTileNumber((short)ssString[0]-48);
			else if (ssString.find(" ")==2)
				m_Tile[i][n].setTileNumber(((short)ssString[0]-48)*10+(short)ssString[1]-48);
		} 
	}
}
void Game::Draw()
{
	for (short i=0;i<cm_sXTiles;i++) //Draw the map tiles
	{
		for (short n=0;n<cm_sYTiles;n++)
			m_Tile[i][n].Display(i,n);
	}
	m_Good.Display();
	m_Bad.Display();
}
void Game::MouseInput(char cIn, short sX, short sY)
{
	short sTileX=sX/cm_sTileSize;
	short sTileY=sY/cm_sTileSize;

	switch (cIn)
	{
	case 'l':
		if (m_Tile[sTileX][sTileY].getPassable())
		{
			m_Good.setX(sX);
			m_Good.setY(sY);
			if (m_Bad.getMovement())
				m_Bad.setPrevious(false);
		}
		break;
	default:
		break;
	}
}
void Game::KeyInput(char cIn)
{
	switch (cIn)
	{
	case 'g':
		m_Bad.MovementToggle();
		break;
	default:
		break;
	}
}
void Game::Move()
{
	m_Bad.Move(m_Good.getX(),m_Good.getY());
}