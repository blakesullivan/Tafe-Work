//Blake Sullivan - Manager.cpp
#include "Manager.h"
#include "aStarLibrary.h"

Manager::Manager()
{
	screen = NULL;
	tile = NULL;
	button = NULL;
	thefont = NULL;
	player = NULL;
	badguy = NULL;
	ManagePlay();
}
Manager::~Manager()
{
	m_vTiles.clear();
	m_vButtons.clear();
	aStar::EndPathfinder();

	SDL_FreeSurface(tile);
	SDL_FreeSurface(button);
	SDL_FreeSurface(thefont);
	SDL_FreeSurface(player);
	SDL_FreeSurface(badguy);
	SDL_Quit();
}

int Manager::ManagePlay()
{
	SDL_Event event;
	bool bChangedCol = false;
	int iMouseX = 0, iMouseY = 0;
	int iPlayStyle = 0;
	bgameRunning = true;
	m_bKeyUsed = false;
	//srand(time(NULL));

	aStar::InitializePathfinder();

	float fDeltaTime = 0, fMove = 50, fThisMove = 0;
	int iThisTime = 0, iLastTime = 0;

	CreateTiles();
	CreateButtons();
	Tile::SetTilePass();
	LoadMap("map.txt");
	CreatePlayer();

	for (int i = 0; i < 323; i++)
		{keysHeld[i] = false;} // everything will be initialized to false
	for (int i = 0; i < 13; i++)
		{buttonHeld[i] = false;}
    //Initialize all SDL subsystems 
	if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 ) 
	{ return 1; } 

    //Set up the screen 
	screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE ); 
	//If there was an error in setting up the screen 
	if( screen == NULL ) { return 1; } 
	//Set the window caption 
	SDL_WM_SetCaption( "SDL Tile Game with A*", NULL ); 

	thefont = SDL_LoadBMP("font1.bmp");
	SDL_SetColorKey(thefont,SDL_SRCCOLORKEY, SDL_MapRGB(thefont->format, 0, 0, 0) ); //Black is the transparent colour
	tile = SDL_LoadBMP("tileset.bmp");
	button = SDL_LoadBMP("Button.bmp");
	//player = SDL_LoadBMP("link.bmp");
	//SDL_SetColorKey(player,SDL_SRCCOLORKEY, SDL_MapRGB(player->format, 116, 228, 150) ); //White is the transparent colour
	player = SDL_LoadBMP("Raynosshort.bmp");
	SDL_SetColorKey(player,SDL_SRCCOLORKEY, SDL_MapRGB(player->format, 255, 0, 255) ); //White is the transparent colour
	badguy = SDL_LoadBMP("badlink.bmp");
	SDL_SetColorKey(badguy,SDL_SRCCOLORKEY, SDL_MapRGB(badguy->format, 184, 184, 184) );
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
				m_bKeyUsed = false;
			}
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				buttonHeld[event.button.button] = true;
			}
			if (event.type == SDL_MOUSEBUTTONUP)
			{
				buttonHeld[event.button.button] = false;
				bChangedCol = false;
			}
		}

		iThisTime = SDL_GetTicks();
		fDeltaTime = (float)(iThisTime - iLastTime) / 1000;
		iLastTime = iThisTime;
		fThisMove += fDeltaTime;

		MovePlayer();
		if (fThisMove > 0.2)
		{
			int iTemp = 0;
			iTemp = m_player.GetPicCol() + 1;
			if (iTemp > 5) {iTemp = 0;} 
			fThisMove = 0;
			m_player.SetPicCol(iTemp);
			for (int i=0; i<bgnum; i++) 
				{m_bg[i].SetPicCol(iTemp);}
		}
		
		SDL_GetMouseState(&iMouseX, &iMouseY);

		if (1 == iPlayStyle)
			{UpdateTiles(bChangedCol, iMouseX, iMouseY);}
		else if (2 == iPlayStyle)
			{LoadMap("map.txt");}
		else if (3 == iPlayStyle)
			{SaveMap("map.txt");}
		else if (4 == iPlayStyle)
			{bgameRunning = false;}

		UpdateButtons(iMouseX, iMouseY);

		DrawTiles();
		DrawButtons();
		DrawPlayer(m_player, player);
		for (int i=0; i<bgnum; i++) 
		{DrawPlayer(m_bg[i], badguy);}

		iPlayStyle = CheckButtonPressed();
    	//Update the screen 
		if( SDL_Flip( screen ) == -1 ) { return 1; } 
	}

	return 0;
}

void Manager::CreateTiles()
{
	unsigned int uiLoop = (SCREEN_PLAY_WIDTH / Tile::GetSize())*(SCREEN_HEIGHT / Tile::GetSize());
	unsigned int tempX = 0, tempy = 0, tempCol = 0;
	//cout << "uiLoop = " << uiLoop << endl;
	for (unsigned int i = 0; i < uiLoop; i++)
	{
		//tempCol = rand() %9;
		Tile temp;
		temp.Init(tempX, tempy, tempCol, tempX / Tile::GetSize(), tempy / Tile::GetSize());
		m_vTiles.push_back(temp);
		tempX += Tile::GetSize();
		if (tempX >= SCREEN_PLAY_WIDTH)
		{
			tempX = 0;
			tempy += Tile::GetSize();
		}
		aStar::SetWalkability(temp.GetGridX(), temp.GetGridY(), temp.GetPassable());
	}
}

void Manager::UpdateTiles(bool& bColChanged, int iMouseX, int iMouseY)
{
	static unsigned int s_uiColNum = 1;
	if (buttonHeld[SDL_BUTTON_LEFT] == true)
	{
		for (m_vTilesIT = m_vTiles.begin(); m_vTilesIT != m_vTiles.end(); m_vTilesIT++)
		{
			if (iMouseX > m_vTilesIT->GetX() && iMouseX < m_vTilesIT->GetX() + Tile::GetSize())
			{
				if (iMouseY > m_vTilesIT->GetY() && iMouseY < m_vTilesIT->GetY() + Tile::GetSize())
				{
					m_vTilesIT->SetPicPos(s_uiColNum);
					break;
				}
			}
		}
	}

	m_EditTile.SetPicPos(s_uiColNum);

	if (buttonHeld[SDL_BUTTON_RIGHT] == true && bColChanged == false)
	{
		s_uiColNum++;
		if (s_uiColNum > 8) {s_uiColNum = 0;}
		bColChanged = true;
	}
}

void Manager::DrawTiles()
{
	SDL_Rect sclip, dclip;
	for (m_vTilesIT = m_vTiles.begin(); m_vTilesIT != m_vTiles.end(); m_vTilesIT++)
	{
		sclip.x = m_vTilesIT->GetPicPos() * Tile::GetSize();
		sclip.y = 0; sclip.w = Tile::GetSize(); sclip.h = Tile::GetSize();
		dclip.x = m_vTilesIT->GetX(); dclip.y = m_vTilesIT->GetY();
		dclip.w = Tile::GetSize(); dclip.h = Tile::GetSize();
		SDL_BlitSurface(tile, &sclip, screen, &dclip);
	}

	sclip.x = m_EditTile.GetPicPos() * Tile::GetSize();
	sclip.y = 0; sclip.w = Tile::GetSize(); sclip.h = Tile::GetSize();
	dclip.x = m_EditTile.GetX(); dclip.y =m_EditTile.GetY();
	dclip.w = Tile::GetSize(); dclip.h = Tile::GetSize();
	SDL_BlitSurface(tile, &sclip, screen, &dclip);
}

void Manager::CreateButtons()
{
	unsigned int uiLoop = 5;
	unsigned int tempy = 0, tempCol = 0;
	//cout << "uiLoop = " << uiLoop << endl;
	for (unsigned int i = 0; i < uiLoop; i++)
	{
		//tempCol = rand() %9;
		MenuButton temp;
		temp.Init(SCREEN_PLAY_WIDTH, tempy, i);
		if (i == 0)
		{temp.SetText("PLAY");}
		else if (i == 1)
		{temp.SetText("EDIT");}
		else if (i == 2)
		{temp.SetText("LOAD");}
		else if (i == 3)
		{temp.SetText("SAVE");}
		else
		{temp.SetText("EXIT");}

		m_vButtons.push_back(temp);
		tempy += MenuButton::GetHeight();
		m_EditTile.Init(SCREEN_PLAY_WIDTH, tempy, 0, 0, 0);
	}
}

void Manager::UpdateButtons(int iMouseX, int iMouseY)
{
	//SDL_Rect sclip, dclip;
	int iypos = 0, iCount = 0;
	//char cTemp[10];
	//for (m_vTilesIT = m_vTiles.begin(); m_vTilesIT != m_vTiles.end(); m_vTilesIT++)
	for (m_vButtonsIT = m_vButtons.begin(); m_vButtonsIT != m_vButtons.end(); m_vButtonsIT++)
	{
		m_vButtonsIT->SetPicPos(0);
		if (iMouseX > SCREEN_PLAY_WIDTH && iMouseX <= SCREEN_WIDTH) 
		{
			if (iMouseY > m_vButtonsIT->GetY() && iMouseY < (m_vButtonsIT->GetY() + MenuButton::GetHeight()))
			{
				if (buttonHeld[SDL_BUTTON_LEFT] == true)
				{
					m_vButtonsIT->SetPicPos(MenuButton::GetHeight() * 2);
					m_vButtonsIT->SetPressed(true);
				}
				else
				{
					m_vButtonsIT->SetPicPos(MenuButton::GetHeight());
					m_vButtonsIT->SetPressed(false);
				}
			}
		}
	}
}

void Manager::DrawButtons()
{
	SDL_Rect sclip, dclip;
	char cTemp[10];
	for (m_vButtonsIT = m_vButtons.begin(); m_vButtonsIT != m_vButtons.end(); m_vButtonsIT++)
	{
		sclip.x = 0; 
		sclip.y = m_vButtonsIT->GetPicPos();
		sclip.w = MenuButton::GetWidth();
		sclip.h =  MenuButton::GetHeight();

		dclip.x = m_vButtonsIT->GetX(); 
		dclip.y = m_vButtonsIT->GetY();
		dclip.w = MenuButton::GetWidth(); 
		dclip.h =  MenuButton::GetHeight();

		SDL_BlitSurface(button, &sclip, screen, &dclip);

		sprintf(cTemp,m_vButtonsIT->GetText().c_str());
		myDrawText(cTemp, m_vButtonsIT->GetX() + 50, m_vButtonsIT->GetY() + 10);
	}
}

int Manager::CheckButtonPressed()
{
	static int siButtonPressedNum = 0;
	for (m_vButtonsIT = m_vButtons.begin(); m_vButtonsIT != m_vButtons.end(); m_vButtonsIT++)
	{
		if (m_vButtonsIT->GetPressed() == true)
		{
			siButtonPressedNum = m_vButtonsIT->GetID();
		}
	}
	return siButtonPressedNum;
}

void Manager::myDrawText(char s[], int x, int y)
{
	int k;
	SDL_Rect sclip, dclip;

	for (k=0;k<strlen(s);k++)
		{
			sclip.x = 16*(int(s[k])%16); sclip.y = 16*(int(s[k])/16); sclip.w = 16; sclip.h = 16;

			dclip.x = x+(k*16); dclip.y = y; dclip.w = 16; dclip.h = 16;

			SDL_BlitSurface(thefont, &sclip, screen, &dclip);
		}
}

void Manager::LoadMap(string sFile)
{
	ifstream MapFile(sFile.c_str());
	int iTemp;
	for (m_vTilesIT = m_vTiles.begin(); m_vTilesIT != m_vTiles.end(); m_vTilesIT++)
	{
		if (MapFile.eof() == false)
		{
			MapFile >> iTemp;
			m_vTilesIT->SetPicPos(iTemp);
			aStar::SetWalkability(m_vTilesIT->GetGridX(), m_vTilesIT->GetGridY(), m_vTilesIT->GetPassable());
		}
	}
}
void Manager::SaveMap(string sFile)
{
	ofstream MapFile(sFile.c_str());
	//int iTemp;
	for (m_vTilesIT = m_vTiles.begin(); m_vTilesIT != m_vTiles.end(); m_vTilesIT++)
	{
		MapFile << m_vTilesIT->GetPicPos() << endl;
	}
}

void Manager::CreatePlayer()
{
	bool bExit = false, bPlayerDone = false;
	int iTempX = 0, iTempY = 0, i = 0;
	do
	{
		for (m_vTilesIT = m_vTiles.begin(); m_vTilesIT != m_vTiles.end(); m_vTilesIT++)
		{
			if (m_vTilesIT->GetGridX() == iTempX &&  m_vTilesIT->GetGridY() == iTempY)
			{
				if(m_vTilesIT->GetPassable() == 0)
				{
					if (bPlayerDone == false)
					{
						m_player.Init(m_vTilesIT->GetX(), m_vTilesIT->GetY(), 0, 0, m_vTilesIT->GetGridX(), m_vTilesIT->GetGridY());
						bPlayerDone = true;
					}
					else
					{
						//if (m_vTilesIT->GetGridX() == ((SCREEN_PLAY_WIDTH / Tile::GetSize()) - 1) &&  m_vTilesIT->GetGridY() == ((SCREEN_HEIGHT / Tile::GetSize()) -1) )
						if (m_bg[0].GetGridX() == 0 && m_bg[0].GetGridY() == 0)
						{
							m_bg[0].Init(m_vTilesIT->GetX(), m_vTilesIT->GetY(), 0, 0, m_vTilesIT->GetGridX(), m_vTilesIT->GetGridY());
						}
						else
						{
							i++;
							m_bg[i].Init(m_vTilesIT->GetX(), m_vTilesIT->GetY(), 0, 0, m_vTilesIT->GetGridX(), m_vTilesIT->GetGridY());
							if (i == bgnum)
								{bExit = true;}
						}
					}
				}
			}
		}
		iTempX++;
		if (iTempX > (SCREEN_PLAY_WIDTH / Tile::GetSize()))
		{
			iTempX = 0;
			iTempY++;
		}
	}while (bExit == false);
}

void Manager::DrawPlayer(Player& play, SDL_Surface* playSurf)
{
	SDL_Rect sclip, dclip;
	
	sclip.x = play.GetPicCol() * Player::GetSize(); 
	sclip.y = 0 * Player::GetSize(); //play.GetPicRow() * Player::GetSize();
	sclip.w = Player::GetSize();
	sclip.h = Player::GetSize();

	dclip.x = play.GetX(); 
	dclip.y = play.GetY();
	dclip.w = Player::GetSize(); 
	dclip.h = Player::GetSize();

	SDL_BlitSurface(playSurf, &sclip, screen, &dclip);
}

void Manager::MovePlayer()
{
	float TempX = 0, TempY = 0;

	if (m_bKeyUsed == false)
	{
		if (keysHeld[SDLK_s] || keysHeld[SDLK_DOWN])
		{
			m_player.SetPicRow(0);
			TempX = m_player.GetGridX(); TempY = m_player.GetGridY() + 1;
			m_bKeyUsed = true;
		}
		else if (keysHeld[SDLK_a] || keysHeld[SDLK_LEFT])
		{
			m_player.SetPicRow(1);
			TempY = m_player.GetGridY(); TempX = m_player.GetGridX() - 1;
			m_bKeyUsed = true;
		}
		else if (keysHeld[SDLK_d] || keysHeld[SDLK_RIGHT])
		{
			m_player.SetPicRow(2);
			TempY = m_player.GetGridY(); TempX = m_player.GetGridX() + 1;
			m_bKeyUsed = true;
		}
		else if (keysHeld[SDLK_w] || keysHeld[SDLK_UP])
		{
			m_player.SetPicRow(3);
			TempX = m_player.GetGridX(); TempY = m_player.GetGridY() - 1;
			m_bKeyUsed = true;
		}

		if (CheckMove(TempX, TempY) == 0) 
		{
			m_player.SetX(TempX * Tile::GetSize());
			m_player.SetY(TempY * Tile::GetSize());
			m_player.SetGridX(TempX); m_player.SetGridY(TempY);
			if (keysHeld[SDLK_SPACE] == true || keysHeld[SDLK_n] == true || keysHeld[SDLK_b] == true)
				{MoveBadGuy();}	
		}
	}
}

bool Manager::CheckMove(float x, float y)
{
	for (m_vTilesIT = m_vTiles.begin(); m_vTilesIT != m_vTiles.end(); m_vTilesIT++)
	{
		if (x == m_vTilesIT->GetGridX() && y == m_vTilesIT->GetGridY())
		{
			//cout << m_vTilesIT->GetGridX() << " - " << m_vTilesIT->GetGridY() << " : " << m_vTilesIT->GetPassable() << endl;
			//cout << "Player: " << m_player.GetGridX() << " - " << m_player.GetGridY() << endl;
			return m_vTilesIT->GetPassable();
		}
	}
}

void Manager::MoveBadGuy()
{
	int tempGX = 0, tempGY = 0, ID = 0;
	bool xChanged = false, yChanged = false;
	for (int i = 0; i<bgnum; i++)
	{
		if (keysHeld[SDLK_b] == true) {i++;}

		tempGX = m_bg[i].GetGridX();
		tempGY = m_bg[i].GetGridY();
		ID = i + 1;
		xChanged = false; yChanged = false;
		aStar::SetWalkability(tempGX, tempGY, 0);
		
		//bool bExit = false;
		//while (bExit == false)
		//{

			//bExit = FindPath(1, m_bg.GetX(), m_bg.GetY(), m_player.GetX(), m_player.GetY());
		//}
		aStar::FindPath(ID, m_bg[i].GetX(), m_bg[i].GetY(), m_player.GetX(), m_player.GetY());

		if (aStar::GetXPath(ID) != m_bg[i].GetX())
		{
			m_bg[i].SetX(aStar::GetXPath(ID));
			xChanged = true;
			//cout << "GetX(): " <<  m_bg.GetX() << endl;
		}
		if (aStar::GetYPath(ID) != m_bg[i].GetY())
		{
			m_bg[i].SetY(aStar::GetYPath(ID));
			yChanged = true;
			//cout << "GetY(): " << m_bg.GetY() << endl;
		}
		m_bg[i].SetGridX(m_bg[i].GetX() / Tile::GetSize());
		m_bg[i].SetGridY(m_bg[i].GetY() / Tile::GetSize());

		if (xChanged == true || yChanged == true)
			{aStar::SetWalkability(m_bg[i].GetGridX(), m_bg[i].GetGridY(), 9);}

		if (tempGX < m_bg[i].GetGridX())
			{m_bg[i].SetPicRow(2);}
		else if (tempGX > m_bg[i].GetGridX())
			{m_bg[i].SetPicRow(1);}
		else if (tempGY > m_bg[i].GetGridY())
			{m_bg[i].SetPicRow(3);}
		else
			{m_bg[i].SetPicRow(0);}

		if (keysHeld[SDLK_n] == true || keysHeld[SDLK_b] == true)
		{break;}
	}
}