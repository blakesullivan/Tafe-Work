//Blake Sullivan - Manager.cpp
#include "Manager.h"

Manager::Manager() : SCREEN_WIDTH(800), SCREEN_HEIGHT(608), SCREEN_BPP(32)
{
	iCellSize = 16;
	iMouseX = 0;
	iMouseY = 0;
	for (int i = 0; i < 13; i++)
	{
		buttonHeld[i] = false;
	}
	m_bCheckGrid = false;
	screen = NULL; //the pointer to the screen in memory
	grid = NULL;
	GameManage();
}

int Manager::GameManage()
{
	SDL_Event event;
	FPSUtility fps;
	bool bgameRunning= true;
	bool keysHeld[323];
	float fDeltaTime = 0.0;
	int iLastTime = 0, iThisTime = 0;
	
	for (int i=0; i<322; i++)
	{
		keysHeld[i] = false; // everything will be initialized to false
	}
	//Initialize all SDL subsystems 
	if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 ) 
	{ return 1; }

	//Set up the screen 
	screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE ); 
	//If there was an error in setting up the screen 
	if( screen == NULL ) { return 1; } 
	//Set the window caption 
	SDL_WM_SetCaption( "SDL Task 2 - Conways Game Of Life", NULL ); 
	grid = SDL_LoadBMP("golmap.bmp"); //Setting the player to point at the image
	//SDL_SetColorKey(test,SDL_SRCCOLORKEY, SDL_MapRGB(test->format, iRClear, iGClear, iBClear) ); 	//Black is the transparent colour

	SetupGrid();

	//Fill the screen white 
	SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) ); 
	while (bgameRunning)
	{	// check for any events from the user or the system
		SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) ); 
		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				bgameRunning = false;
			}
			if (event.type == SDL_KEYDOWN)
			{
				keysHeld[event.key.keysym.sym] = true;
			}
			if (event.type == SDL_KEYUP)
			{
				keysHeld[event.key.keysym.sym] = false;
			}
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				buttonHeld[event.button.button] = true;
			}
			if (event.type == SDL_MOUSEBUTTONUP)
			{
				buttonHeld[event.button.button] = false;
			}
		}
	
		for (mv_GridIT = mv_Grid.begin(); mv_GridIT != mv_Grid.end(); mv_GridIT++)
		{
			if (buttonHeld[SDL_BUTTON_LEFT] == true)
			{
				SDL_GetMouseState(&iMouseX, &iMouseY);
				if (iMouseX > mv_GridIT->GetX() && iMouseX <= (mv_GridIT->GetX() + iCellSize))
				{
					if (iMouseY > mv_GridIT->GetY() && iMouseY <= (mv_GridIT->GetY() + iCellSize))
					{
						mv_GridIT->SetAlive(true);
					}
				}
			}
			mv_GridIT->Draw(*screen, *grid);
		}

		if (keysHeld[SDLK_SPACE] == true && m_bCheckGrid == false)
		{
			m_bCheckGrid = true;
			keysHeld[SDLK_SPACE] = false;
		}
		if (keysHeld[SDLK_SPACE] == true && m_bCheckGrid == true)
		{
			m_bCheckGrid = false;
			keysHeld[SDLK_SPACE] = false;
		}

		iThisTime = SDL_GetTicks();
		fDeltaTime = iThisTime - iLastTime;

		if (m_bCheckGrid == true)
		{
			if (fDeltaTime > 50)
			{
				CheckGrid();
				ChangeGrid();
				iLastTime = iThisTime;
			}
		}

		//Update the screen 
		if( SDL_Flip( screen ) == -1 ) { return 1; } 
	}
	SDL_FreeSurface(grid);

	SDL_Quit();
	return 0;
}

void Manager::SetupGrid()
{
	int iPos = 0, iXPos = 0, iYPos = 0, iGridNum = ((SCREEN_HEIGHT / iCellSize) * (SCREEN_WIDTH / iCellSize)), iXGrid = 0, iYGrid = 0;
	for (int i = 0; i <= iGridNum; i++)
	{
		GridPiece gpTemp;
		gpTemp.Init(iXPos, iYPos, 0, false, iXGrid, iYGrid);
		mv_Grid.push_back(gpTemp);
		iXPos += iCellSize;
		iXGrid++;
		if (iXPos >= SCREEN_WIDTH)
		{
			iXGrid = 0;
			iYGrid++;
			iXPos = 0;
			iYPos += iCellSize;
		}
	}
}

void Manager::CheckGrid()
{
	int aliveCount = 0;
	//cout << "This is a test of check grid." << endl;
	for (mv_GridIT = mv_Grid.begin(); mv_GridIT != mv_Grid.end(); mv_GridIT++)
	{
		int xCount = -1, yCount = -1;
		for (int i = 0; i < 8; i++)
		{
			int x = 0, y = 0;
			x = mv_GridIT->GetXPos() + xCount;
			y = mv_GridIT->GetYPos() + yCount;
			
			if (true == FindLiveNeighbour(x, y))
				{aliveCount++;}

			xCount++;
			if (xCount == 0 && yCount == 0) {xCount++;}
			if (xCount > 1)
			{
				xCount = -1;
				yCount++;
			}
		}
		if (mv_GridIT->GetAlive() == true)
		{
			if (aliveCount < 2)
				{mv_GridIT->SetChange(true);}
			else if (aliveCount > 3)
				{mv_GridIT->SetChange(true);}
			else
				{mv_GridIT->SetChange(false);}
			//cout << "Cell [" << mv_GridIT->GetXPos() << "," <<  mv_GridIT->GetYPos() << "] is alive!!!" << endl;
		}
		else
		{
			if (aliveCount == 3)
				{mv_GridIT->SetChange(true);}
			else
				{mv_GridIT->SetChange(false);}
		}
		aliveCount = 0;
		//system("PAUSE");
	}
}

bool Manager::FindLiveNeighbour(const int iXPos, const int iYPos)
{
	vector <GridPiece>::iterator gpIT;
	for (gpIT = mv_Grid.begin(); gpIT != mv_Grid.end(); gpIT++)
	{
		if (gpIT->GetXPos() == iXPos && gpIT->GetYPos() == iYPos)
		{
			//cout << "Cell [" << gpIT->GetXPos() << "," << gpIT->GetYPos() << "] is a neighbour to Cell [" << iXPos << "," << iYPos << "]\n";
			if (gpIT->GetAlive() == true)
			{return true;}
			else
			{return false;}
		}
	}
	return false;
}

void Manager::ChangeGrid()
{
	for (mv_GridIT = mv_Grid.begin(); mv_GridIT != mv_Grid.end(); mv_GridIT++)
	{
		if (mv_GridIT->GetChange() == true)
		{
			mv_GridIT->SwapCell();
		}
	}
}