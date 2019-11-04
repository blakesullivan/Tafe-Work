//Blake Sullivan - Splash.cpp
#include "Menu.h"

Menu::Menu()
{
	thefont = NULL;
	button = NULL;
	Init();
}

void Menu::Init()
{
	for (int i = 0; i < 323; i++)
	{m_bKeyHeld[i]=false;}
	for (int i = 0; i < 13; i++)
	{m_bButtonHeld[i] = false;}

	m_iIsRunning = sceneRunning;
	thefont = SDL_LoadBMP("font1.bmp");
	SDL_SetColorKey(thefont,SDL_SRCCOLORKEY, SDL_MapRGB(thefont->format, 0, 0, 0) ); //Black is the transparent colour
	button = SDL_LoadBMP("button.bmp");
	CreateButtons(7, 300, 125);
}

void Menu::Update(SDL_Surface* screen, float fDeltaTime)
{
	int iMouseX = 0, iMouseY = 0, iButtonClicked = -1;
	SDL_GetMouseState(&iMouseX, &iMouseY);
	UpdateButtons(iMouseX, iMouseY);
	iButtonClicked = CheckButtonPressed(iButtonClicked);

	if (m_bKeyHeld[SDLK_ESCAPE] || iButtonClicked == buttonExit)
		{m_iIsRunning = sceneQuit;}
	else if (m_bKeyHeld[SDLK_0] || m_bKeyHeld[SDLK_KP0] || iButtonClicked == buttonSplash)
		{m_iIsRunning = sceneSplash;}
	else if (m_bKeyHeld[SDLK_1] || m_bKeyHeld[SDLK_KP1] || iButtonClicked == buttonMenu)
		{m_iIsRunning = sceneMenu;}
	else if (m_bKeyHeld[SDLK_2] || m_bKeyHeld[SDLK_KP2] || iButtonClicked == buttonOptions)
		{m_iIsRunning = sceneOptions;}
	else if (m_bKeyHeld[SDLK_3] || m_bKeyHeld[SDLK_KP3] || iButtonClicked == buttonPlay)
		{m_iIsRunning = scenePlay;}
}

void Menu::Draw(SDL_Surface* screen, float fDeltaTime)
{
	SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0, 200, 0) ); 

	/*stringRGBA(screen, 300, 290, "MENU!", 0, 0, 0, 255);
	stringRGBA(screen, 300, 310, "Press 0: Splash", 0, 0, 0, 255);
	stringRGBA(screen, 300, 330, "Press 1: Menu", 0, 0, 0, 255);
	stringRGBA(screen, 300, 350, "Press 2: Options", 0, 0, 0, 255);
	stringRGBA(screen, 300, 370, "Press 3: Play", 0, 0, 0, 255);*/

	DrawButtons(screen);
}

void Menu::Event(SDL_Surface* screen, SDL_Event *event, float fDeltaTime)
{
	if (SDL_PollEvent(event))
	{
		//if (event->type == SDL_QUIT)
		//{
		//	m_iIsRunning = sceneQuit;
		//}
		//if (event->type == SDL_KEYDOWN)
		//{
		//	/*if (event->key.keysym.sym == SDLK_ESCAPE)
		//		{m_iIsRunning = sceneQuit;}
		//	else if (event->key.keysym.sym == SDLK_0 || event->key.keysym.sym == SDLK_KP0)
		//		{m_iIsRunning = sceneSplash;}
		//	else if (event->key.keysym.sym == SDLK_1 || event->key.keysym.sym == SDLK_KP1)
		//		{m_iIsRunning = sceneMenu;}
		//	else if (event->key.keysym.sym == SDLK_2 || event->key.keysym.sym == SDLK_KP2)
		//		{m_iIsRunning = sceneOptions;}
		//	else if (event->key.keysym.sym == SDLK_3 || event->key.keysym.sym == SDLK_KP3)
		//		{m_iIsRunning = scenePlay;}*/
		//	//keysHeld[event.key.keysym.sym] = true;
		//}
		//if (event->type == SDL_KEYUP)
		//{
		//	//keysHeld[event.key.keysym.sym] = false;
		//}

		if (event->type == SDL_QUIT)
			{m_iIsRunning = sceneQuit;}

		if (event->type == SDL_KEYDOWN)
			{m_bKeyHeld[event->key.keysym.sym] = true;}
		if (event->type == SDL_KEYUP)
			{m_bKeyHeld[event->key.keysym.sym] = false;}

		if (event->type == SDL_MOUSEBUTTONDOWN)
			{m_bButtonHeld[event->button.button] = true;}
		if (event->type == SDL_MOUSEBUTTONUP)
			{m_bButtonHeld[event->button.button] = false;}
	}
}

int Menu::Status()
{
	return m_iIsRunning;
}

void Menu::Dispose()
{
	SDL_FreeSurface(thefont);
	SDL_FreeSurface(button);
}

void Menu::CreateButtons(int iButNum, int iStartX, int iStartY)
{
	unsigned int iTempX = iStartX, iTempY = iStartY, tempCol = 0;
	//cout << "uiLoop = " << uiLoop << endl;
	for (unsigned int i = 0; i < iButNum; i++)
	{
		//tempCol = rand() %9;
		MenuButton temp;
		temp.Init(iTempX, iTempY, i);
		if (i == buttonSplash)
		{temp.SetText("SPLASH");}
		else if (i == buttonMenu)
		{temp.SetText("MENU");}
		else if (i == buttonOptions)
		{temp.SetText("OPTIONS");}
		else if (i == buttonPlay)
		{temp.SetText("PLAY");}
		else if (i == buttonHost)
		{temp.SetText("HOST");}
		else if (i == buttonJoin)
		{temp.SetText("JOIN");}
		else
		{temp.SetText("EXIT");}

		m_vButtons.push_back(temp);
		iTempY += MenuButton::GetHeight();
	}
}

void Menu::UpdateButtons(int iMouseX, int iMouseY)
{
	SDL_Rect sclip, dclip;
	int iypos = 0, iCount = 0;
	char cTemp[10];
	//for (m_vTilesIT = m_vTiles.begin(); m_vTilesIT != m_vTiles.end(); m_vTilesIT++)
	for (m_vButtonsIT = m_vButtons.begin(); m_vButtonsIT != m_vButtons.end(); m_vButtonsIT++)
	{
		m_vButtonsIT->SetPicPos(0);
		if (iMouseX > m_vButtonsIT->GetX() && iMouseX <= (m_vButtonsIT->GetX() + MenuButton::GetWidth())) 
		{
			if (iMouseY > m_vButtonsIT->GetY() && iMouseY < (m_vButtonsIT->GetY() + MenuButton::GetHeight()))
			{
				if (m_bButtonHeld[SDL_BUTTON_LEFT] == true)
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

void Menu::DrawButtons(SDL_Surface* screen)
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
		myDrawText(screen, cTemp, m_vButtonsIT->GetX() + 50, m_vButtonsIT->GetY() + 10);
	}
}

int Menu::CheckButtonPressed(int iButton)
{
	int iButtonPressedNum = iButton;
	for (m_vButtonsIT = m_vButtons.begin(); m_vButtonsIT != m_vButtons.end(); m_vButtonsIT++)
	{
		if (m_vButtonsIT->GetPressed() == true)
			{iButtonPressedNum = m_vButtonsIT->GetID();}
	}
	return iButtonPressedNum;
}

void Menu::myDrawText(SDL_Surface* screen, char s[], int x, int y)
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