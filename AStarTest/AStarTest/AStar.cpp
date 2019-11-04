#include "AStar.h"
#include <string>
using std::string;

AStar::AStar(int iRows, int iColumns)
{
	m_iXTiles=iRows;
	m_iYTiles=iColumns;
	m_aTileList=New2DArray<TileList>();
}
AStar::~AStar()
{
	Delete2DArray(m_aTileList);
}
void AStar::LoadData(const char* c_cpData)
{
	string ssData=c_cpData;
	for (int i=0;i<m_iXTiles*m_iYTiles;i++)
	{
		short sPass;
		sscanf(ssData.c_str(),"%d;",&sPass);
		if (sPass==0)
			m_aTileList[i/m_iYTiles][i%m_iYTiles].cProperty='X'; //X for Not Passable
		else if (sPass==1)
			m_aTileList[i/m_iYTiles][i%m_iYTiles].cProperty='W'; //W for Waiting
		m_aTileList[i/m_iYTiles][i%m_iYTiles].sParentTileX=i/m_iYTiles;
		m_aTileList[i/m_iYTiles][i%m_iYTiles].sParentTileY=i%m_iYTiles;
		m_aTileList[i/m_iYTiles][i%m_iYTiles].iHeuristic=99999;
		m_aTileList[i/m_iYTiles][i%m_iYTiles].iCost=99999;
		ssData.erase(0,ssData.find(';')+1);
	}
}
template <typename typeT> typeT** AStar::New2DArray()
{     
	typeT **apArray;

	apArray = new typeT*[m_iXTiles];
	for( int i = 0 ; i < m_iXTiles ; i++ )
	apArray[i] = new typeT [m_iYTiles];

	return apArray;
}
template <typename typeT> void AStar::Delete2DArray(typeT** apArray)
{      
	delete [] *apArray;
	delete [] apArray;
}
void AStar::Manager(short sStartX, short sStartY, short sTargetX, short sTargetY)
{
	m_sStartX=sStartX;
	m_sStartY=sStartY;
	m_sTargetX=sTargetX;
	m_sTargetY=sTargetY;
	ReInit(); //Always Reinitialise
	
	while (m_sTargetX!=m_sCurrentX||m_sTargetY!=m_sCurrentY)
		FindPath();
	StoreNodes();
}
void AStar::FindPath()
{
	CheckSquares();
	int iSmallestCombo=99999999;
	for (m_vOpenListit=m_vOpenList.begin();m_vOpenListit!=m_vOpenList.end();m_vOpenListit++)
	{
		short i=m_vOpenListit->x;
		short n=m_vOpenListit->y;
		if (m_aTileList[i][n].iCost+m_aTileList[i][n].iHeuristic<iSmallestCombo) 
		//Then check if the square's combined cost and heuristic value is the smallest
		{
			m_sCurrentX=i; //If so, reset the current X and Y
			m_sCurrentY=n;
			iSmallestCombo=m_aTileList[i][n].iCost+m_aTileList[i][n].iHeuristic;
		}
	}
	/*for (short i=0;i<cm_sXTiles;i++) //check out all the squares for the open list squares
	{
		for (short n=0;n<m_iYTiles;n++)
		{
			if (m_aTileList[i][n].cProperty=='O')
			{
				if (m_aTileList[i][n].iCost+m_aTileList[i][n].iHeuristic<iSmallestCombo) 
				//Then check if the square's combined cost and heuristic value is the smallest
				{
					m_sCurrentX=i; //If so, reset the current X and Y
					m_sCurrentY=n;
					iSmallestCombo=m_aTileList[i][n].iCost+m_aTileList[i][n].iHeuristic;
				}
			}
		}
	}*/
}
void AStar::ReInit()
{
	m_sCurrentX=m_sStartX; //Reset the current X and Y to the start
	m_sCurrentY=m_sStartY;

	for (short i=0;i<m_iXTiles;i++) //Reinitialise Squares
	{
		for (short n=0;n<m_iYTiles;n++)
		{
			if (m_aTileList[i][n].cProperty!='X')
				m_aTileList[i][n].cProperty='W';

			m_aTileList[i][n].sParentTileX=i;
			m_aTileList[i][n].sParentTileY=n;
			m_aTileList[i][n].iHeuristic=99999;
			m_aTileList[i][n].iCost=0;
		}
	}
	if (!m_vWaypoint.empty())
		m_vWaypoint.erase(m_vWaypoint.begin(),m_vWaypoint.end());
	if (!m_vOpenList.empty())
		m_vOpenList.erase(m_vOpenList.begin(),m_vOpenList.end());
}
void AStar::CheckSquares() /*Checks the surrounding tiles of the input tile see if: A. the adjacent tile is on the map; B. the 
						   adjacent tile is passable; C. the adjacent tile is not on the closed or open lists.  It then calls 
						   calculating functions*/
{
	m_aTileList[m_sCurrentX][m_sCurrentY].cProperty='C'; //C to show this this tile is now part of the Closed List

	for (m_vOpenListit=m_vOpenList.begin();m_vOpenListit!=m_vOpenList.end();m_vOpenListit++) /*Remove the location element from the 
																							 OpenList vector*/
	{
		if (m_vOpenListit->x==m_sCurrentX&&m_vOpenListit->y==m_sCurrentY)
		{
			m_vOpenList.erase(m_vOpenListit);
			break;
		}
	}

	//Before Calculation, the tiles are assigned their parent tile
	if (m_sCurrentX+1<m_iXTiles) //Checks that it's not the edge of the map
	{
		if (m_aTileList[m_sCurrentX+1][m_sCurrentY].cProperty=='W')
		{
			m_aTileList[m_sCurrentX+1][m_sCurrentY].sParentTileX=m_sCurrentX;
			m_aTileList[m_sCurrentX+1][m_sCurrentY].sParentTileY=m_sCurrentY;
			CalculateHeuristic(m_sCurrentX+1,m_sCurrentY);
			CalculateCost(m_sCurrentX+1,m_sCurrentY,1,0);
		}
		if (m_aTileList[m_sCurrentX+1][m_sCurrentY].cProperty!='X') //Stops 'corner cutting'
		{
			if (m_sCurrentY+1<m_iYTiles&&m_aTileList[m_sCurrentX+1][m_sCurrentY+1].cProperty=='W'&&m_aTileList[m_sCurrentX][m_sCurrentY+1].cProperty!='X')
			{
				m_aTileList[m_sCurrentX+1][m_sCurrentY+1].sParentTileX=m_sCurrentX;
				m_aTileList[m_sCurrentX+1][m_sCurrentY+1].sParentTileY=m_sCurrentY;
				CalculateHeuristic(m_sCurrentX+1,m_sCurrentY+1);
				CalculateCost(m_sCurrentX+1,m_sCurrentY+1,1,1);
			}
			if (m_sCurrentY-1>=0&&m_aTileList[m_sCurrentX+1][m_sCurrentY-1].cProperty=='W'&&m_aTileList[m_sCurrentX][m_sCurrentY-1].cProperty!='X')
			{
				m_aTileList[m_sCurrentX+1][m_sCurrentY-1].sParentTileX=m_sCurrentX;
				m_aTileList[m_sCurrentX+1][m_sCurrentY-1].sParentTileY=m_sCurrentY;
				CalculateHeuristic(m_sCurrentX+1,m_sCurrentY-1);
				CalculateCost(m_sCurrentX+1,m_sCurrentY-1,1,1);
			}
		}
	}
	if (m_sCurrentX-1>=0) //Checks that it's not the edge of the map
	{
		if (m_aTileList[m_sCurrentX-1][m_sCurrentY].cProperty=='W')
		{
			m_aTileList[m_sCurrentX-1][m_sCurrentY].sParentTileX=m_sCurrentX;
			m_aTileList[m_sCurrentX-1][m_sCurrentY].sParentTileY=m_sCurrentY;
			CalculateHeuristic(m_sCurrentX-1,m_sCurrentY);
			CalculateCost(m_sCurrentX-1,m_sCurrentY,1,0);
		}
		if (m_aTileList[m_sCurrentX-1][m_sCurrentY].cProperty!='X') //Stops 'corner cutting'
		{
			if (m_sCurrentY+1<m_iYTiles&&m_aTileList[m_sCurrentX-1][m_sCurrentY+1].cProperty=='W'&&m_aTileList[m_sCurrentX][m_sCurrentY+1].cProperty!='X')
			{
				m_aTileList[m_sCurrentX-1][m_sCurrentY+1].sParentTileX=m_sCurrentX;
				m_aTileList[m_sCurrentX-1][m_sCurrentY+1].sParentTileY=m_sCurrentY;
				CalculateHeuristic(m_sCurrentX-1,m_sCurrentY+1);
				CalculateCost(m_sCurrentX-1,m_sCurrentY+1,1,1);
			}
			if (m_sCurrentY-1>=0&&m_aTileList[m_sCurrentX-1][m_sCurrentY-1].cProperty=='W'&&m_aTileList[m_sCurrentX][m_sCurrentY-1].cProperty!='X')
			{
				m_aTileList[m_sCurrentX-1][m_sCurrentY-1].sParentTileX=m_sCurrentX;
				m_aTileList[m_sCurrentX-1][m_sCurrentY-1].sParentTileY=m_sCurrentY;
				CalculateHeuristic(m_sCurrentX-1,m_sCurrentY-1);
				CalculateCost(m_sCurrentX-1,m_sCurrentY-1,1,1);
			}
		}
	}
	if (m_sCurrentY+1<m_iYTiles&&m_aTileList[m_sCurrentX][m_sCurrentY+1].cProperty=='W')
	{
		m_aTileList[m_sCurrentX][m_sCurrentY+1].sParentTileX=m_sCurrentX;
		m_aTileList[m_sCurrentX][m_sCurrentY+1].sParentTileY=m_sCurrentY;
		CalculateHeuristic(m_sCurrentX,m_sCurrentY+1);
		CalculateCost(m_sCurrentX,m_sCurrentY+1,0,1);
	}
	if (m_sCurrentY-1>=0&&m_aTileList[m_sCurrentX][m_sCurrentY-1].cProperty=='W')
	{
		m_aTileList[m_sCurrentX][m_sCurrentY-1].sParentTileX=m_sCurrentX;
		m_aTileList[m_sCurrentX][m_sCurrentY-1].sParentTileY=m_sCurrentY;
		CalculateHeuristic(m_sCurrentX,m_sCurrentY-1);
		CalculateCost(m_sCurrentX,m_sCurrentY-1,0,1);
	}
}
void AStar::CalculateHeuristic(short sX, short sY) /*Guesses the distance from the current location to the target.  The closer it is, 
												   the lower iHeuristic will be*/
{	/*This function contains a commented algorithm.  While I prefer the Manhattem Method, others may see better results using the 
	Chebyshev Distance.  Just uncomment one and comment the other.*/


	//The Manhatten Method (4 Square Heuristic Algorithm)
	/*m_aTileList[sX][sY].iHeuristic = 10*(abs(sX-m_sTargetX)+abs(sY-m_sTargetY)); */


	//The Chebyshev Distance(8 Square Heuristic Algorithm)
	short sXDistance = abs(sX-m_sTargetX);
	short sYDistance = abs(sY-m_sTargetY);
	if (sXDistance > sYDistance)
		m_aTileList[sX][sY].iHeuristic = 14*sYDistance + 10*(sXDistance-sYDistance);
	else
		m_aTileList[sX][sY].iHeuristic = 14*sXDistance + 10*(sYDistance-sXDistance);


	m_aTileList[sX][sY].cProperty='O'; //Add this square to the Open List

	OpenList TempList; //Create a temporary OpenList struct
	TempList.x=sX; //Populate struct
	TempList.y=sY;
	m_vOpenList.push_back(TempList);//Populate vector with temporary struct
}
void AStar::CalculateCost(short sX, short sY, bool bX, bool bY) //calculates movement cost based on movement in the X and/or Y direction
{
	short sPreviousX=m_aTileList[sX][sY].sParentTileX;
	short sPreviousY=m_aTileList[sX][sY].sParentTileY;
	if (bX!=bY) //Exclusive Or statement
		m_aTileList[sX][sY].iCost = 10+m_aTileList[sPreviousX][sPreviousY].iCost;
	else
		m_aTileList[sX][sY].iCost = 14+m_aTileList[sPreviousX][sPreviousY].iCost;
}
/*void AStar::NextStep()
{
	if (m_sStartX!=m_sTargetX||m_sStartY!=m_sTargetY)
	{
		short i=m_sTargetX;
		short n=m_sTargetY;
		while (m_aTileList[i][n].sParentTileX!=m_sStartX||m_aTileList[i][n].sParentTileY!=m_sStartY)
		{
			short Temp=i;
			i=m_aTileList[i][n].sParentTileX;
			n=m_aTileList[Temp][n].sParentTileY;
		}
		m_sNextX=i;
		m_sNextY=n;
	}
	while (m_sCurrentX!=m_sStartX||m_sCurrentY!=m_sStartY)
	{
		DrawPath(m_sCurrentX,m_sCurrentY);
		m_sCurrentX=m_aTileList[m_sCurrentX][m_sCurrentY].sParentTileX;
		m_sCurrentY=m_aTileList[m_sCurrentX][m_sCurrentY].sParentTileY;
	}
}*/
void AStar::StoreNodes()
{
	if (m_sStartX!=m_sTargetX||m_sStartY!=m_sTargetY)
	{
		short i=m_sTargetX;
		short n=m_sTargetY;
		float fPrevAngle=0;

		while (m_aTileList[i][n].sParentTileX!=m_sStartX||m_aTileList[i][n].sParentTileY!=m_sStartY) //Work back through the path
		{
			short sTempX=i;
			short sTempY=n;
			i=m_aTileList[i][n].sParentTileX;
			n=m_aTileList[sTempX][n].sParentTileY;

			float fCurrentAngle=atan2f(sTempY-n,sTempX-i);
			if (fPrevAngle!=fCurrentAngle) /*If there is a change in direction of the path, record the X and Y coordinates of where 
										   that change occurred in the waypoint struct and populate the waypoint vector with it*/
			{
				Waypoint tempWay;
				tempWay.x=sTempX;
				tempWay.y=sTempY;
				m_vWaypoint.push_back(tempWay);
			}
			fPrevAngle=fCurrentAngle;
		}
	}
	if (!m_vWaypoint.empty())
	{
		m_sNextX=(m_vWaypoint.rbegin())->x;
		m_sNextY=(m_vWaypoint.rbegin())->y;
	}
}
void AStar::NextNode()
{
	m_vWaypoint.pop_back();
	if (!m_vWaypoint.empty())
	{
		m_sNextX=(m_vWaypoint.rbegin())->x;
		m_sNextY=(m_vWaypoint.rbegin())->y;
	}
}
short AStar::getNextX()
{
	return m_sNextX;
}
short AStar::getNextY()
{
	return m_sNextY;
}
void AStar::DrawPath(short x, short y)
{
	filledCircleRGBA(screen,x*32+16,y*32+16,10,255,0,255,255);
}
void AStar::DrawWaypoints()
{
	for (m_vWaypointit=m_vWaypoint.begin();m_vWaypointit!=m_vWaypoint.end();m_vWaypointit++)
		filledCircleRGBA(screen,m_vWaypointit->x*32+16,m_vWaypointit->y*32+16,10,255,255,255,255);
}