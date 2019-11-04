//Blake Sullivan - Adrian Brell's Base myastar.cpp
#include "myastar.h"

// Definitions

// map helper functions

int GetMap( int x, int y )
{

	if( x < 0 ||
	    x >= MC_IMAP_WIDTH ||
		 y < 0 ||
		 y >= MC_IMAP_HEIGHT
	  )
	{
		return 9;
	}

	return map[(y*MC_IMAP_WIDTH)+x];
}

int SetMap( int x, int y, int z )
{

	if( x < 0 ||
	    x >= MC_IMAP_WIDTH ||
		 y < 0 ||
		 y >= MC_IMAP_HEIGHT
	  )
	{
		return 0;	 
	}
	map[(y*MC_IMAP_WIDTH)+x]=z;
	return 1;
}
bool MapSearchNode::IsSameState( MapSearchNode &rhs )
{

	// same state in a maze search is simply when (x,y) are the same
	if( (x == rhs.x) &&
		(y == rhs.y) )
	{
		return true;
	}
	else
	{
		return false;
	}

}

void MapSearchNode::PrintNodeInfo()
{
	//cout << "Node position : (" << x << ", " << y << ")" << endl;
	filledCircleRGBA(screen, x * MC_IMAP_WIDTH + MC_ITILE_WIDTH/2, y * MC_IMAP_HEIGHT + MC_ITILE_WIDTH/2,5,0,255,255,255);
}

// Here's the heuristic function that estimates the distance from a Node
// to the Goal. 

float MapSearchNode::GoalDistanceEstimate( MapSearchNode &nodeGoal )
{
	float xd = fabs(float(((float)x - (float)nodeGoal.x)));
	float yd = fabs(float(((float)y - (float)nodeGoal.y)));

	return xd + yd;
}

bool MapSearchNode::IsGoal( MapSearchNode &nodeGoal )
{

	if( (x == nodeGoal.x) &&
		(y == nodeGoal.y) )
	{
		return true;
	}

	return false;
}

// This generates the successors to the given Node. It uses a helper function called
// AddSuccessor to give the successors to the AStar class. The A* specific initialisation
// is done for each node internally, so here you just set the state information that
// is specific to the application
bool MapSearchNode::GetSuccessors( AStarSearch<MapSearchNode> *astarsearch, MapSearchNode *parent_node )
{

	int parent_x = -1; 
	int parent_y = -1; 

	if( parent_node )
	{
		parent_x = parent_node->x;
		parent_y = parent_node->y;
	}
	

	MapSearchNode NewNode;

	// push each possible move except allowing the search to go backwards

	if( (GetMap( x-1, y ) < 9) 
		&& !((parent_x == x-1) && (parent_y == y))
	  ) 
	{
		NewNode = MapSearchNode( x-1, y );
		astarsearch->AddSuccessor( NewNode );
	}	

	if( (GetMap( x, y-1 ) < 9) 
		&& !((parent_x == x) && (parent_y == y-1))
	  ) 
	{
		NewNode = MapSearchNode( x, y-1 );
		astarsearch->AddSuccessor( NewNode );
	}	

	if( (GetMap( x+1, y ) < 9)
		&& !((parent_x == x+1) && (parent_y == y))
	  ) 
	{
		NewNode = MapSearchNode( x+1, y );
		astarsearch->AddSuccessor( NewNode );
	}	

		
	if( (GetMap( x, y+1 ) < 9) 
		&& !((parent_x == x) && (parent_y == y+1))
		)
	{
		NewNode = MapSearchNode( x, y+1 );
		astarsearch->AddSuccessor( NewNode );
	}	

	return true;
}

// given this node, what does it cost to move to successor. In the case
// of our map the answer is the map terrain value at this node since that is 
// conceptually where we're moving

float MapSearchNode::GetCost( MapSearchNode &successor )
{
	return (float) GetMap( x, y );

}

//					FROM		TO				NEXT SPOT
int findPath( int Ax, int Ay, int Bx, int By, int &Cx, int &Cy, bool display )
{
int result=1;
	//cout << "STL A* Search implementation\n(C)2001 Justin Heyes-Jones\n";

	// Our sample problem defines the world as a 2d array representing a terrain
	// Each element contains an integer from 0 to 5 which indicates the cost 
	// of travel across the terrain. Zero means the least possible difficulty 
	// in travelling (think ice rink if you can skate) whilst 5 represents the 
	// most difficult. 9 indicates that we cannot pass.

	// Create an instance of the search class...
	AStarSearch<MapSearchNode> astarsearch;

	unsigned int SearchCount = 0;

	const unsigned int NumSearches = 1;

	while(SearchCount < NumSearches)
	{

		// Create a start state
		MapSearchNode nodeStart;
		nodeStart.x = Ax;
		nodeStart.y = Ay; 

		// Define the goal state
		MapSearchNode nodeEnd;
		nodeEnd.x = Bx;						
		nodeEnd.y = By; 
		
		// Set Start and goal states
		
		astarsearch.SetStartAndGoalStates( nodeStart, nodeEnd );

		unsigned int SearchState;
		unsigned int SearchSteps = 0;

		do
		{
			SearchState = astarsearch.SearchStep();

			SearchSteps++;

	

		}
		while( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SEARCHING );

		if( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SUCCEEDED )
		{
			//cout << "Search found goal state\n";

				MapSearchNode *node = astarsearch.GetSolutionStart();

				int steps = 0;

				if (display) node->PrintNodeInfo();
				for( ;; )
				{
					node = astarsearch.GetSolutionNext();

					if( !node )
					{
						break;
					}
					if (steps==0)
					{
						Cx = node->x;
						Cy = node->y;
					}
					if (display) node->PrintNodeInfo();
					steps ++;
				
				};

				//cout << "Solution steps " << steps << endl;

				// Once you're done with the solution you can free the nodes up
				astarsearch.FreeSolutionNodes();

	
		}
		else if( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_FAILED ) 
		{
			cout << "Search terminated. Did not find goal state\n";
			result=0;
		
		}

		// Display the number of loops the search went through
		//cout << "SearchSteps : " << SearchSteps << "\n";

		SearchCount ++;

		astarsearch.EnsureMemoryFreed();
	}
	return result;
}

