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
	
}

void Splash::Draw(SDL_Surface* screen, float fDeltaTime)
{
	SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 200, 0, 200) ); 
	stringRGBA(screen, 250, 290, "WELCOME TO BLAKES WAYPOINT PROGRAM!", 0, 0, 0, 255);
	stringRGBA(screen, 270, 310, "Press any key to start.", 0, 0, 0, 255);
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
	//m_bButtonHeld[event->button.button] = false;
}
void Splash::MouseDownEvent (SDL_Event* event)
{
	Scene::MouseDownEvent(event);
	m_iIsRunning = scenePlay;
	//m_bButtonHeld[event->button.button] = true;
}
void Splash::KeyUpEvent(SDL_Event* event)
{
	Scene::KeyUpEvent(event);
	//m_bKeysHeld[event->key.keysym.sym] = false;
}
void Splash::KeyDownEvent(SDL_Event* event)
{
	Scene::KeyDownEvent(event);
	if (m_bKeysHeld[SDLK_ESCAPE] == true)
	{
		m_iIsRunning = sceneQuit;
	}
	else// if (m_bKeysHeld[SDLK_SPACE] == true || m_bKeysHeld[SDLK_RETURN] == true)
	{
		m_iIsRunning = scenePlay;
	}
	//m_bKeysHeld[event->key.keysym.sym] = true;
}