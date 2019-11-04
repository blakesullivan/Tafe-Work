//Blake Sullivan - Splash.cpp
#include "Splash.h"

Splash::Splash()
{
	Init();
}

void Splash::Init()
{
	m_iIsRunning = sceneRunning;
}

void Splash::Update(SDL_Surface* screen, float fDeltaTime)
{
	if (m_bKeysHeld[SDLK_ESCAPE] == true)
		{m_iIsRunning = sceneQuit;}
	else if (m_bKeysHeld[SDLK_SPACE] == true || m_bKeysHeld[SDLK_RETURN] == true)
		{m_iIsRunning = sceneMenu;}		
}
void Splash::Draw(SDL_Surface* screen, float fDeltaTime)
{
	SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0, 0, 200) ); 
	stringRGBA(screen, 300, 290, "SPLASH!", 0, 0, 0, 255);
	stringRGBA(screen, 250, 310, "Press any key to go to Menu", 0, 0, 0, 255);
}

//void Splash::Event(SDL_Surface* screen, SDL_Event *event, float fDeltaTime)
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
//			else
//				{m_iIsRunning = sceneMenu;}
//			//keysHeld[event.key.keysym.sym] = true;
//		}
//		if (event->type == SDL_KEYUP)
//		{
//			//keysHeld[event.key.keysym.sym] = false;
//		}
//		if (event->type == SDL_MOUSEBUTTONDOWN)
//		{
//			m_iIsRunning = sceneMenu;
//		}
//	}
//}

int Splash::Status()
{
	return m_iIsRunning;
}

void Splash::Dispose()
{
}

void Splash::MouseUpEvent(SDL_Event* event)
{
	Scene::MouseUpEvent(event);
}
void Splash::MouseDownEvent (SDL_Event* event)
{
	Scene::MouseDownEvent(event);
	m_iIsRunning = sceneMenu;
}
void Splash::KeyUpEvent(SDL_Event* event)
{
	Scene::KeyUpEvent(event);
}
void Splash::KeyDownEvent(SDL_Event* event)
{
	Scene::KeyDownEvent(event);
	m_iIsRunning = sceneMenu;
}