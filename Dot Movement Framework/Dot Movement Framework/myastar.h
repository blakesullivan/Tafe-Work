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

extern int map[ ];
extern const int MC_IMAP_WIDTH;
extern const int MC_IMAP_HEIGHT;
extern const int MC_ITILE_WIDTH;
extern SDL_Surface *screen;

class MapSearchNode
{
public:
	unsigned int x;	 // the (x,y) positions of the node
	unsigned int y;	
	
	MapSearchNode() { x = y = 0; }
	MapSearchNode( unsigned int px, unsigned int py ) { x=px; y=py; }

	float GoalDistanceEstimate( MapSearchNode &nodeGoal );
	bool IsGoal( MapSearchNode &nodeGoal );
	bool GetSuccessors( AStarSearch<MapSearchNode> *astarsearch, MapSearchNode *parent_node );
	float GetCost( MapSearchNode &successor );
	bool IsSameState( MapSearchNode &rhs );

	void PrintNodeInfo(); 
};

namespace Pathfinder
{
	int findPath( int Ax, int Ay, int Bx, int By, int &Cx, int &Cy, bool display );
	int GetMap( int x, int y );
	int SetMap( int x, int y, int z );
}
#endif