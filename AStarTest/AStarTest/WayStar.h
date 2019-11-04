//Hybrid AStar and Coordinates algorithm by Paul Turner
#ifndef WAYSTAR
#define WAYSTAR
#define _USE_MATH_DEFINES
#include <vector>
#include "sdl_gfxPrimitives.h"
using std::vector;

class WayStar
{
//The private section contains member variables and some internal functions used in the algorithm
private:
	struct TileList //Stores variables to be used for each tile
	{
		char cProperty; //Stores whether the tile is on the Open List (O), the Closed List (C), impassable (X), or waiting (W)
		short sParentTileX; //Stores the previous tile's X coordinates
		short sParentTileY; //Stores the previous tile's Y coordinates
		int iHeuristic; //Stores the Heuristic Value of the tile
		int iCost; //Stores the cost needed to reach the tile
	};
	struct Coordinates //Stores the coordinates of each waypoint as a vector (see below)
	{
		short x;
		short y;
	};

	vector <Coordinates> m_vWaypoint;
	vector <Coordinates> m_vOpenList;
	vector <Coordinates> m_vList;
	vector <Coordinates>::iterator m_vWaypointit;
	vector <Coordinates>::iterator m_vOpenListit;
	vector <Coordinates>::iterator m_vListit;

	TileList** m_aTileList; //To hold the 2D dynamic array
	Coordinates m_Current, m_Target, m_Start, m_Next; //Other variables
	int m_iXTiles, m_iYTiles;

	//The following functions are in the private section as they are the internal machinations of the algorithm
	template <typename typeT> typeT** New2DArray(); //Template needed for the creation of 2D dynamic array of map
	template <typename typeT> void Delete2DArray(typeT**); //Template needed for the destructio
	void ReInit(); //Step 1: Reinitializes/Resets everything (including any stored waypoints)
	void CheckSquares(); /*Step 2: Looks at all 8 adjacent squares and if they are passable and not on the open list, it does steps 3
						 and 4 for each*/
	void CalculateHeuristic(short,short); //Step 3: Calculate the distance between the square and the target (ignoring immpassable squares)
	void CalculateCost(short,short,bool,bool); //Step 4: Calculate how much it will cost to get to this square from the start
	void FindPath(); /*Step 5: Adds the heuristic and cost of the squares on the open list, decides which one has the smallest result 
					 and repeats step 2 from that square until the target is reached*/
	void StoreNodes(); /*Step 6: Once the target is reached, this function backtracks through the squares and whenever the path changes
					   course it stores the coordinates of where it took place thereby making waypoints.*/

	//The following 2 functions are from the optimisation process.
	Coordinates InLoopCheck(Coordinates,float,float,short); /*As the for loops call the functions, they move an invisible 'marker' along
															the edges of the 'corridor' that form the edges of a connection between 
															every second waypoint.  This stores the Tile coordinates for later retrieval*/
	void FinalOptimizationStep(); /*This retrieves the tiles and checks to see if any of them are impassable.  If not, it then deletes 
								  the waypoint between the two checked ones in the vector*/
public:
	WayStar(int iRows, int iColumns); //You tell the constructor how many rows and columns of tiles there are in the map
	~WayStar();
	void LoadData(const char* c_cpData); /*Loads a passability char string, with passable tiles being '1' and impassable being '0'.
										 Each number is seperated by a ';'*/
	void Manager(short sStartX, short sStartY, short sTargetX, short sTargetY); /*Runs the algorithm to find a path from where you 
																				are (sStartX,sStartY) to where you want to end up 
																				(sTargetX, sTargetY).  Takes a large chunk of CPU
																				time*/
	short getNextX(); /*gets the X coordinate of the next Coordinates, or if it's the final waypoint it goes directly for the target 
					  pixel's X coordinate*/
	short getNextY(); /*gets the Y coordinate of the next Coordinates, or if it's the final waypoint it goes directly for the target 
					  pixel's Y coordinate*/
	void NextNode(); /*When you get to the X and Y coordinates that you gathered from getNextX and getNextY, you call this function
					 to delete the current waypoint and set getNextX and getNextY to the coordinates of the next waypoint*/
	void Optimise(short TileSize); /*This will take a small chunk of CPU time compared to the Manager, but is still fairly intensive 
								   for the CPU.  It optimises the otherwise rough path found by the Manager.*/
	void DrawWaypoints(SDL_Surface* screen, short TileSize); //This shows where the waypoints are in the path.

		/*NOTE: If you wish to use the DrawWaypoints function, just uncomment it here and at the bottom of the .cpp file and 
		uncomment #include SDL_gfxPrimitives at the top of this file */
};
#endif