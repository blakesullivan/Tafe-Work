//Blake Sullivan - Play.cpp
#include "Play.h"

Play::Play(SDL_Surface* screen) : m_Grid(screen->clip_rect.w, screen->clip_rect.h)
{
	Init(screen);
}

void Play::Init()
{
}

void Play::Init(SDL_Surface* screen)
{
	m_iIsRunning = sceneRunning;
	m_Grid.SetupGrid(screen->clip_rect.w, screen->clip_rect.h);
	m_Key.Init('k', 400, 300, 200, 10);
	m_Key.SetColour(0, 50, 200);
	m_Mouse.Init('m', 200, 100, 0, 10);
	m_Mouse.SetColour(200, 0, 50);
}

void Play::Update(SDL_Surface* screen, float fDeltaTime)
{
	if (m_bKeysHeld[SDLK_BACKSPACE])
		{m_iIsRunning = sceneMenu;}

	if (m_bButtonHeld[SDL_BUTTON_RIGHT] == true)
	{
		int mouseX, mouseY;
		SDL_GetMouseState(&mouseX, &mouseY);
		m_Mouse.SetX(mouseX);
		m_Mouse.SetY(mouseY);
		m_bButtonHeld[SDL_BUTTON_RIGHT] = false;
	}

	if (m_bKeysHeld[SDLK_w] == true || m_bKeysHeld[SDLK_UP] == true)
		{m_Key.MovePlayer('u', fDeltaTime);}
	if (m_bKeysHeld[SDLK_s] == true || m_bKeysHeld[SDLK_DOWN] == true)
		{m_Key.MovePlayer('d', fDeltaTime);}
	if (m_bKeysHeld[SDLK_a] == true || m_bKeysHeld[SDLK_LEFT] == true)
		{m_Key.MovePlayer('l', fDeltaTime);}
	if (m_bKeysHeld[SDLK_d] == true || m_bKeysHeld[SDLK_RIGHT] == true)
		{m_Key.MovePlayer('r', fDeltaTime);}
}

void Play::Draw(SDL_Surface* screen, float fDeltaTime)
{
	SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 255, 255, 255) ); 
	//stringRGBA(screen, 300, 290, "Play!", 0, 0, 0, 255);
	//stringRGBA(screen, 250, 310, "Press backspace to go back to Menu", 0, 0, 0, 255);
	m_Grid.DrawGrid(screen);
	filledCircleRGBA(screen, m_Key.GetX(), m_Key.GetY(), m_Key.GetSize(), m_Key.GetRed(), m_Key.GetGreen(), m_Key.GetBlue(), m_Key.GetAlpha());
	filledCircleRGBA(screen, m_Mouse.GetX(), m_Mouse.GetY(), m_Mouse.GetSize(), m_Mouse.GetRed(), m_Mouse.GetGreen(), m_Mouse.GetBlue(), m_Mouse.GetAlpha());

}

//void Play::Event(SDL_Surface* screen, SDL_Event *event, float fDeltaTime)
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

int Play::Status()
{
	return m_iIsRunning;
}

void Play::Dispose()
{
}

void Play::MouseUpEvent(SDL_Event* event)
{
	Scene::MouseUpEvent(event);
}
void Play::MouseDownEvent (SDL_Event* event)
{
	Scene::MouseDownEvent(event);
}
void Play::KeyUpEvent(SDL_Event* event)
{
	Scene::KeyUpEvent(event);
}
void Play::KeyDownEvent(SDL_Event* event)
{
	Scene::KeyDownEvent(event);
}