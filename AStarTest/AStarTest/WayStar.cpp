#include "WayStar.h"
#include <string>
#include <math.h>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

WayStar::WayStar(int iRows, int iColumns)
{
	m_iXTiles=iRows;
	m_iYTiles=iColumns;
	m_aTileList=New2DArray<TileList>();
}
WayStar::~WayStar()
{
	Delete2DArray(m_aTileList);
}
void WayStar::LoadData(const char* c_cpData)
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
template <typename typeT> typeT** WayStar::New2DArray()
{     
	typeT **apArray;

	apArray = new typeT*[m_iXTiles];
	for( int i = 0 ; i < m_iXTiles ; i++ )
	apArray[i] = new typeT [m_iYTiles];

	return apArray;
}
template <typename typeT> void WayStar::Delete2DArray(typeT** apArray)
{      
	delete [] *apArray;
	delete [] apArray;
}
void WayStar::Manager(short sStartX, short sStartY, short sTargetX, short sTargetY)
{
	m_Start.x=sStartX;
	m_Start.y=sStartY;
	m_Target.x=sTargetX;
	m_Target.y=sTargetY;
	ReInit(); //Always Reinitialise
	
	while (m_Target.x!=m_Current.x||m_Target.y!=m_Current.y)
		FindPath();
	StoreNodes();
}
void WayStar::FindPath()
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
			m_Current.x=i; //If so, reset the current X and Y
			m_Current.y=n;
			iSmallestCombo=m_aTileList[i][n].iCost+m_aTileList[i][n].iHeuristic;
		}
	}
}
void WayStar::ReInit()
{
	m_Current=m_Start; //Reset the current X and Y to the start

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
void WayStar::CheckSquares() /*Checks the surrounding tiles of the input tile see if: A. the adjacent tile is on the map; B. the 
						   adjacent tile is passable; C. the adjacent tile is not on the closed or open lists.  It then calls 
						   calculating functions*/
{
	m_aTileList[m_Current.x][m_Current.y].cProperty='C'; //C to show this this tile is now part of the Closed List

	for (m_vOpenListit=m_vOpenList.begin();m_vOpenListit!=m_vOpenList.end();m_vOpenListit++) /*Remove the location element from the 
																							 OpenList vector*/
	{
		if (m_vOpenListit->x==m_Current.x&&m_vOpenListit->y==m_Current.y)
		{
			m_vOpenList.erase(m_vOpenListit);
			break;
		}
	}

	//Before Calculation, the tiles are assigned their parent tile
	if (m_Current.x+1<m_iXTiles) //Checks that it's not the edge of the map
	{
		if (m_aTileList[m_Current.x+1][m_Current.y].cProperty=='W')
		{
			m_aTileList[m_Current.x+1][m_Current.y].sParentTileX=m_Current.x;
			m_aTileList[m_Current.x+1][m_Current.y].sParentTileY=m_Current.y;
			CalculateHeuristic(m_Current.x+1,m_Current.y);
			CalculateCost(m_Current.x+1,m_Current.y,1,0);
		}
		if (m_aTileList[m_Current.x+1][m_Current.y].cProperty!='X') //Stops 'corner cutting'
		{
			if (m_Current.y+1<m_iYTiles&&m_aTileList[m_Current.x+1][m_Current.y+1].cProperty=='W'&&m_aTileList[m_Current.x][m_Current.y+1].cProperty!='X')
			{
				m_aTileList[m_Current.x+1][m_Current.y+1].sParentTileX=m_Current.x;
				m_aTileList[m_Current.x+1][m_Current.y+1].sParentTileY=m_Current.y;
				CalculateHeuristic(m_Current.x+1,m_Current.y+1);
				CalculateCost(m_Current.x+1,m_Current.y+1,1,1);
			}
			if (m_Current.y-1>=0&&m_aTileList[m_Current.x+1][m_Current.y-1].cProperty=='W'&&m_aTileList[m_Current.x][m_Current.y-1].cProperty!='X')
			{
				m_aTileList[m_Current.x+1][m_Current.y-1].sParentTileX=m_Current.x;
				m_aTileList[m_Current.x+1][m_Current.y-1].sParentTileY=m_Current.y;
				CalculateHeuristic(m_Current.x+1,m_Current.y-1);
				CalculateCost(m_Current.x+1,m_Current.y-1,1,1);
			}
		}
	}
	if (m_Current.x-1>=0) //Checks that it's not the edge of the map
	{
		if (m_aTileList[m_Current.x-1][m_Current.y].cProperty=='W')
		{
			m_aTileList[m_Current.x-1][m_Current.y].sParentTileX=m_Current.x;
			m_aTileList[m_Current.x-1][m_Current.y].sParentTileY=m_Current.y;
			CalculateHeuristic(m_Current.x-1,m_Current.y);
			CalculateCost(m_Current.x-1,m_Current.y,1,0);
		}
		if (m_aTileList[m_Current.x-1][m_Current.y].cProperty!='X') //Stops 'corner cutting'
		{
			if (m_Current.y+1<m_iYTiles&&m_aTileList[m_Current.x-1][m_Current.y+1].cProperty=='W'&&m_aTileList[m_Current.x][m_Current.y+1].cProperty!='X')
			{
				m_aTileList[m_Current.x-1][m_Current.y+1].sParentTileX=m_Current.x;
				m_aTileList[m_Current.x-1][m_Current.y+1].sParentTileY=m_Current.y;
				CalculateHeuristic(m_Current.x-1,m_Current.y+1);
				CalculateCost(m_Current.x-1,m_Current.y+1,1,1);
			}
			if (m_Current.y-1>=0&&m_aTileList[m_Current.x-1][m_Current.y-1].cProperty=='W'&&m_aTileList[m_Current.x][m_Current.y-1].cProperty!='X')
			{
				m_aTileList[m_Current.x-1][m_Current.y-1].sParentTileX=m_Current.x;
				m_aTileList[m_Current.x-1][m_Current.y-1].sParentTileY=m_Current.y;
				CalculateHeuristic(m_Current.x-1,m_Current.y-1);
				CalculateCost(m_Current.x-1,m_Current.y-1,1,1);
			}
		}
	}
	if (m_Current.y+1<m_iYTiles&&m_aTileList[m_Current.x][m_Current.y+1].cProperty=='W')
	{
		m_aTileList[m_Current.x][m_Current.y+1].sParentTileX=m_Current.x;
		m_aTileList[m_Current.x][m_Current.y+1].sParentTileY=m_Current.y;
		CalculateHeuristic(m_Current.x,m_Current.y+1);
		CalculateCost(m_Current.x,m_Current.y+1,0,1);
	}
	if (m_Current.y-1>=0&&m_aTileList[m_Current.x][m_Current.y-1].cProperty=='W')
	{
		m_aTileList[m_Current.x][m_Current.y-1].sParentTileX=m_Current.x;
		m_aTileList[m_Current.x][m_Current.y-1].sParentTileY=m_Current.y;
		CalculateHeuristic(m_Current.x,m_Current.y-1);
		CalculateCost(m_Current.x,m_Current.y-1,0,1);
	}
}
void WayStar::CalculateHeuristic(short sX, short sY) /*Guesses the distance from the current location to the target.  The closer it is, 
												   the lower iHeuristic will be*/
{	
	/*This function contains a commented algorithm.  While I prefer the Chebyshev Distance, others may see better results using the 
	Manhatten Method.  Just have one uncommented and the other commented out.*/
	
	//The Manhatten Method (4 Square Heuristic Algorithm)
	//m_aTileList[sX][sY].iHeuristic = 10*(abs(sX-m_Target.x)+abs(sY-m_Target.y));

	//The Chebyshev Distance(8 Square Heuristic Algorithm)
	short sXDistance = abs(sX-m_Target.x);
	short sYDistance = abs(sY-m_Target.y);
	if (sXDistance > sYDistance)
		m_aTileList[sX][sY].iHeuristic = 14*sYDistance + 10*(sXDistance-sYDistance);
	else
		m_aTileList[sX][sY].iHeuristic = 14*sXDistance + 10*(sYDistance-sXDistance);

	m_aTileList[sX][sY].cProperty='O'; //Add this square to the Open List
	Coordinates TempList; //Create a temporary struct
	TempList.x=sX; //Populate struct
	TempList.y=sY;
	m_vOpenList.push_back(TempList);//Populate vector with temporary struct
}
void WayStar::CalculateCost(short sX, short sY, bool bX, bool bY) //calculates movement cost based on movement in the X and/or Y direction
{
	short sPreviousX=m_aTileList[sX][sY].sParentTileX;
	short sPreviousY=m_aTileList[sX][sY].sParentTileY;
	if (bX!=bY) //Exclusive Or statement (or an equivalent)
		m_aTileList[sX][sY].iCost = 10+m_aTileList[sPreviousX][sPreviousY].iCost;
	else
		m_aTileList[sX][sY].iCost = 14+m_aTileList[sPreviousX][sPreviousY].iCost;
}
void WayStar::StoreNodes()
{
	if (m_Start.x!=m_Target.x||m_Start.y!=m_Target.y)
	{
		short i=m_Target.x;
		short n=m_Target.y;
		float fPrevAngle=0;

		while (m_aTileList[i][n].sParentTileX!=m_Start.x||m_aTileList[i][n].sParentTileY!=m_Start.y) //Work back through the path
		{
			short sTempX=i;
			short sTempY=n;
			i=m_aTileList[i][n].sParentTileX;
			n=m_aTileList[sTempX][n].sParentTileY;

			float fCurrentAngle=atan2f(sTempY-n,sTempX-i);
			if (fPrevAngle!=fCurrentAngle) /*If there is a change in direction of the path, record the X and Y coordinates of where 
										   that change occurred in the waypoint struct and populate the waypoint vector with it*/
			{
				Coordinates tempWay;
				tempWay.x=sTempX;
				tempWay.y=sTempY;
				m_vWaypoint.push_back(tempWay);
			}
			fPrevAngle=fCurrentAngle;
		}
	}
	if (!m_vWaypoint.empty())
		m_Next=*m_vWaypoint.rbegin();
}
void WayStar::NextNode()
{
	m_vWaypoint.pop_back();
	if (!m_vWaypoint.empty())
		m_Next=*m_vWaypoint.rbegin();
}
short WayStar::getNextX()
{
	return m_Next.x;
}
short WayStar::getNextY()
{
	return m_Next.y;
}
void WayStar::Optimise(short sTileSize)
{
	if (m_vWaypoint.size()>=2)
	{
		Coordinates Previous, TrueCoords, TrueCoordsTarget;
		for (m_vWaypointit=m_vWaypoint.begin();m_vWaypointit!=m_vWaypoint.end()-2;m_vWaypointit++)
		{
			if (m_vWaypointit>m_vWaypoint.end()-2)
				break;

			Coordinates WayStore=*(m_vWaypointit+2);
			float fAngle=atan2f(m_vWaypointit->y-WayStore.y,m_vWaypointit->x-WayStore.x);

			//This block figures out the line length, angle and X&Y offsets
			float offsetX=cos(fAngle-M_PI_2)*sTileSize/2;
			float offsetY=sin(fAngle-M_PI_2)*sTileSize/2;

			TrueCoords.x=m_vWaypointit->x*sTileSize+sTileSize/2;
			TrueCoords.y=m_vWaypointit->y*sTileSize+sTileSize/2;
			TrueCoordsTarget.x=WayStore.x*sTileSize+sTileSize/2;
			TrueCoordsTarget.y=WayStore.y*sTileSize+sTileSize/2;
			Previous=TrueCoords;

			for (short a=-1;a<2;a+=2)
			{
				for (float i=TrueCoords.x+offsetX*a, n=TrueCoords.y+offsetY*a;i>TrueCoordsTarget.x+offsetX*a&&n<TrueCoordsTarget.y+offsetY*a;i-=cos(fAngle), n-=sin(fAngle))
					Previous=InLoopCheck(Previous,i,n,sTileSize);
				for (float i=TrueCoords.x+offsetX*a, n=TrueCoords.y+offsetY*a;i<TrueCoordsTarget.x+offsetX*a&&n<TrueCoordsTarget.y+offsetY*a;i-=cos(fAngle), n-=sin(fAngle))
					Previous=InLoopCheck(Previous,i,n,sTileSize);
				for (float i=TrueCoords.x+offsetX*a, n=TrueCoords.y+offsetY*a;i<TrueCoordsTarget.x+offsetX*a&&n>TrueCoordsTarget.y+offsetY*a;i-=cos(fAngle), n-=sin(fAngle))
					Previous=InLoopCheck(Previous,i,n,sTileSize);
				for (float i=TrueCoords.x+offsetX*a, n=TrueCoords.y+offsetY*a;i>TrueCoordsTarget.x+offsetX*a&&n>TrueCoordsTarget.y+offsetY*a;i-=cos(fAngle), n-=sin(fAngle))
					Previous=InLoopCheck(Previous,i,n,sTileSize);
			}
			FinalOptimizationStep();
		}

		m_vWaypointit=m_vWaypoint.end()-2;
		float fAngle=atan2f(m_vWaypointit->y-m_Start.y,m_vWaypointit->x-m_Start.x);

		//This block figures out the line length, angle and X&Y offsets
		float offsetX=cos(fAngle-M_PI_2)*sTileSize/2;
		float offsetY=sin(fAngle-M_PI_2)*sTileSize/2;

		TrueCoords.x=m_vWaypointit->x*sTileSize+sTileSize/2;
		TrueCoords.y=m_vWaypointit->y*sTileSize+sTileSize/2;
		TrueCoordsTarget.x=m_Start.x*sTileSize+sTileSize/2;
		TrueCoordsTarget.y=m_Start.y*sTileSize+sTileSize/2;

		for (short a=-1;a<2;a+=2)
		{
			for (float i=TrueCoords.x+offsetX*a, n=TrueCoords.y+offsetY*a;i>TrueCoordsTarget.x+offsetX*a&&n<TrueCoordsTarget.y+offsetY*a;i-=cos(fAngle), n-=sin(fAngle))
				Previous=InLoopCheck(Previous,i,n,sTileSize);
			for (float i=TrueCoords.x+offsetX*a, n=TrueCoords.y+offsetY*a;i<TrueCoordsTarget.x+offsetX*a&&n<TrueCoordsTarget.y+offsetY*a;i-=cos(fAngle), n-=sin(fAngle))
				Previous=InLoopCheck(Previous,i,n,sTileSize);
			for (float i=TrueCoords.x+offsetX*a, n=TrueCoords.y+offsetY*a;i<TrueCoordsTarget.x+offsetX*a&&n>TrueCoordsTarget.y+offsetY*a;i-=cos(fAngle), n-=sin(fAngle))
				Previous=InLoopCheck(Previous,i,n,sTileSize);
			for (float i=TrueCoords.x+offsetX*a, n=TrueCoords.y+offsetY*a;i>TrueCoordsTarget.x+offsetX*a&&n>TrueCoordsTarget.y+offsetY*a;i-=cos(fAngle), n-=sin(fAngle))
				Previous=InLoopCheck(Previous,i,n,sTileSize);
		}
		FinalOptimizationStep();
	}
	if (!m_vWaypoint.empty())
		m_Next=*m_vWaypoint.rbegin();
}
WayStar::Coordinates WayStar::InLoopCheck(Coordinates Previous, float i, float n, short sTileSize)
{
	if ((short)i/sTileSize!=Previous.x/sTileSize||(short)n/sTileSize!=Previous.y/sTileSize)
	{
		Coordinates TempList; //Create a temporary struct
		TempList.x=i/sTileSize; //Populate struct
		TempList.y=n/sTileSize;
		m_vList.push_back(TempList);//Populate vector with temporary struct
	}
	Previous.x=i;
	Previous.y=n;
	return Previous;
}
void WayStar::FinalOptimizationStep()
{
	bool bBreak=false;
	for (m_vListit=m_vList.begin();m_vListit!=m_vList.end();m_vListit++)
	{
		if (m_aTileList[m_vListit->x][m_vListit->y].cProperty=='X')
		{
			bBreak=true;
			break;
		}
	}

	if (bBreak==false)
		m_vWaypoint.erase(m_vWaypointit+1);
	m_vList.clear();
}
void WayStar::DrawWaypoints(SDL_Surface *screen, short sTileSize)
{
	for (m_vWaypointit=m_vWaypoint.begin();m_vWaypointit!=m_vWaypoint.end();m_vWaypointit++)
		filledCircleRGBA(screen,m_vWaypointit->x*sTileSize+sTileSize/2,m_vWaypointit->y*sTileSize+sTileSize/2,10,255,255,255,255);
}