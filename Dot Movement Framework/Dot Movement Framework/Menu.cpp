//Blake Sullivan - Splash.cpp
#include "Menu.h"

Menu::Menu()
{
	Init();
}

void Menu::Init()
{
	m_iIsRunning = sceneRunning;
	Colours cN, cH, cD;
	cN.iRed = 150; cN.iGreen = 050; cN.iBlue = 150; cN.iAlpha = 255;
	cH.iRed = 150; cH.iGreen = 150; cH.iBlue = 0; cH.iAlpha = 255;
	cD.iRed = 255; cD.iGreen = 0; cD.iBlue = 0; cD.iAlpha = 255;
	bm.AddButton(300, 150, "Splash", 200, 50, cN, cH, cD);
	bm.AddButton(300, 200, "Main Menu", 200, 50, cN, cH, cD);
	bm.AddButton(300, 250, "Options", 200, 50, cN, cH, cD);
	bm.AddButton(300, 300, "Play", 200, 50, cN, cH, cD);
	bm.AddButton(300, 350, "Exit", 200, 50, cN, cH, cD);
}

void Menu::Update(SDL_Surface* screen, float fDeltaTime)
{
	int mouseX = 0, mouseY = 0;
	SDL_GetMouseState(&mouseX, &mouseY);
	bm.UpdateButton(mouseX, mouseY);
	ManageMenu();
}

void Menu::Draw(SDL_Surface* screen, float fDeltaTime)
{
	SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0, 200, 0) ); 

	bm.DrawButton(screen);
	/*stringRGBA(screen, 300, 290, "MENU!", 0, 0, 0, 255);
	stringRGBA(screen, 300, 310, "Press 0: Splash", 0, 0, 0, 255);
	stringRGBA(screen, 300, 330, "Press 1: Menu", 0, 0, 0, 255);
	stringRGBA(screen, 300, 350, "Press 2: Options", 0, 0, 0, 255);
	stringRGBA(screen, 300, 370, "Press 3: Play", 0, 0, 0, 255);*/
}

//void Menu::Event(SDL_Surface* screen, SDL_Event *event, float fDeltaTime)
//{
//	if (SDL_PollEvent(event))
//	{
//		if (event->type == SDL_QUIT)
//		{
//			m_iIsRunning = sceneQuit;
//		}
//		if (event->type == SDL_KEYDOWN)
//		{
//			if (event->key.keysym.sym == SDLK_ESCAPE)
//				{m_iIsRunning = sceneQuit;}
//			else if (event->key.keysym.sym == SDLK_0 || event->key.keysym.sym == SDLK_KP0)
//				{m_iIsRunning = sceneSplash;}
//			else if (event->key.keysym.sym == SDLK_1 || event->key.keysym.sym == SDLK_KP1)
//				{m_iIsRunning = sceneMenu;}
//			else if (event->key.keysym.sym == SDLK_2 || event->key.keysym.sym == SDLK_KP2)
//				{m_iIsRunning = sceneOptions;}
//			else if (event->key.keysym.sym == SDLK_3 || event->key.keysym.sym == SDLK_KP3)
//				{m_iIsRunning = scenePlay;}
//			//keysHeld[event.key.keysym.sym] = true;
//		}
//		if (event->type == SDL_KEYUP)
//		{
//			//keysHeld[event.key.keysym.sym] = false;
//		}
//	}
//}

int Menu::Status()
{
	return m_iIsRunning;
}

void Menu::Dispose()
{
}

void Menu::MouseUpEvent(SDL_Event* event)
{
	Scene::MouseUpEvent(event);
}
void Menu::MouseDownEvent (SDL_Event* event)
{
	Scene::MouseDownEvent(event);
	int mouseX = 0, mouseY = 0;
	SDL_GetMouseState(&mouseX, &mouseY);
	bm.ButtonPressed(mouseX, mouseY);
}
void Menu::KeyUpEvent(SDL_Event* event)
{
	Scene::KeyUpEvent(event);
}
void Menu::KeyDownEvent(SDL_Event* event)
{
	Scene::KeyDownEvent(event);
}

void Menu::ManageMenu()
{
	int iButtonPressed = bm.CheckButtonPressed();

	if (m_bKeysHeld[SDLK_ESCAPE]  || iButtonPressed == buttonExit)
		{m_iIsRunning = sceneQuit;}
	else if (m_bKeysHeld[SDLK_0] || m_bKeysHeld[SDLK_KP0] || iButtonPressed == buttonSplash)
		{m_iIsRunning = sceneSplash;}
	else if (m_bKeysHeld[SDLK_1] || m_bKeysHeld[SDLK_KP1] || iButtonPressed == buttonMenu)
		{m_iIsRunning = sceneMenu;}
	else if (m_bKeysHeld[SDLK_2] || m_bKeysHeld[SDLK_KP2] || iButtonPressed == buttonOptions)
		{m_iIsRunning = sceneOptions;}
	else if (m_bKeysHeld[SDLK_3] || m_bKeysHeld[SDLK_KP3] || iButtonPressed == buttonPlay)
		{m_iIsRunning = scenePlay;}

	if (m_iIsRunning != sceneRunning)
		{bm.ButtonUnPressed(iButtonPressed);}
}