#ifndef MYASTAR_H
#define MYASTAR_H

#include "SDL.h"   /* All SDL App's need this */
#include <stdio.h>
#include "SDL_gfxPrimitives.h" 

#include <stdlib.h>
#include <time.h>
#include "astar/stlastar.h"
#include <iostream>
#include <math.h>
using namespace std;

extern int map[  ];
extern const int MAP_WIDTH;
extern const int MAP_HEIGHT;
extern const int TILE_WIDTH;
extern SDL_Surface *screen;

class MapSearchNode
{
public:
	unsigned long x;	 // the (x,y) positions of the node
	unsigned long y;	
	
	MapSearchNode() { x = y = 0; }
	MapSearchNode( unsigned int px, unsigned int py ) { x=px; y=py; }

	double GoalDistanceEstimate( MapSearchNode &nodeGoal );
	bool IsGoal( MapSearchNode &nodeGoal );
	bool GetSuccessors( AStarSearch<MapSearchNode> *astarsearch, MapSearchNode *parent_node );
	double GetCost( MapSearchNode &successor );
	bool IsSameState( MapSearchNode &rhs );

	void PrintNodeInfo(); 


};

namespace pathfinder
{
	int findPath( int Ax, int Ay, int Bx, int By, int &Cx, int &Cy, bool display );
	int GetMap( int x, int y );
	int SetMap( int x, int y, int z );
}
#endif