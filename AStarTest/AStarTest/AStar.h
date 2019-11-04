#ifndef ASTAR
#define ASTAR
#include <vector>
#include <math.h>
#include "sdl_gfxPrimitives.h"
using std::vector;

extern SDL_Surface* screen;
class AStar
{
private:

	struct TileList
	{
		char cProperty;
		short sParentTileX;
		short sParentTileY;
		int iHeuristic;
		int iCost;
	};
	struct OpenList
	{
		short x;
		short y;
	};
	struct Waypoint
	{
		short x;
		short y;
	};

	vector <Waypoint> m_vWaypoint;
	vector <OpenList> m_vOpenList;
	vector <Waypoint>::iterator m_vWaypointit;
	vector <OpenList>::iterator m_vOpenListit;

	TileList** m_aTileList;
	short m_sCurrentX, m_sCurrentY, m_sTargetX, m_sTargetY, m_sStartX, m_sStartY, m_sNextX, m_sNextY;
	int m_iXTiles, m_iYTiles;

	template <typename typeT> typeT** New2DArray(); //Template needed for the creation of 2D dynamic array of map
	template <typename typeT> void Delete2DArray(typeT**); //Template needed for the destruction of the 2D dynamic array
	void FindPath();
	void CheckSquares();
	void CalculateHeuristic(short,short);
	void CalculateCost(short,short,bool,bool);
	void DrawPath(short,short);
public:
	AStar(int iRows, int iColumns); //You tell the constructor how many rows and columns of tiles there are in the map
	~AStar();
	void LoadData(const char* c_cpData);
	void Manager(short,short,short,short);
	void ReInit();
	//void NextStep();
	void NextNode();
	void StoreNodes();
	short getNextX();
	short getNextY();
	void DrawWaypoints();
};
#endif