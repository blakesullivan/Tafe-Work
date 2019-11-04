//Blake Sullivan - Splash.cpp
#include "Options.h"

Options::Options()
{
	Init();
}

void Options::Init()
{
	m_iIsRunning = sceneRunning;
}

void Options::Update(SDL_Surface* screen, float fDeltaTime)
{
	if (m_bKeysHeld[SDLK_BACKSPACE])
		{m_iIsRunning = sceneMenu;}
}

void Options::Draw(SDL_Surface* screen, float fDeltaTime)
{
	SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 200, 0, 0) ); 
	stringRGBA(screen, 300, 290, "Options!", 0, 0, 0, 255);
	stringRGBA(screen, 250, 310, "Press backspace to go back to Menu", 0, 0, 0, 255);
}

//void Options::Event(SDL_Surface* screen, SDL_Event *event, float fDeltaTime)
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
//	}
//}

int Options::Status()
{
	return m_iIsRunning;
}

void Options::Dispose()
{
}

void Options::MouseUpEvent(SDL_Event* event)
{
	Scene::MouseUpEvent(event);
}
void Options::MouseDownEvent (SDL_Event* event)
{
	Scene::MouseDownEvent(event);
}
void Options::KeyUpEvent(SDL_Event* event)
{
	Scene::KeyUpEvent(event);
}
void Options::KeyDownEvent(SDL_Event* event)
{
	Scene::KeyDownEvent(event);
}