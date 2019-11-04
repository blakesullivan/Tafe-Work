//Blake Sullivan - Splash.h
#ifndef PLAY_H
#define PLAY_H

#include "Scene.h"
#include "Player.h"
#include "Grid.h"

class Play : public Scene
{
private:
	Grid m_Grid;
	Player m_Key;
	Player m_Mouse;	
	
public:
	Play(SDL_Surface* screen);

	void Init();
	void Init(SDL_Surface* screen);
	//void Event(SDL_Surface* screen, SDL_Event *event, float fDeltaTime);
	void Update(SDL_Surface* screen, float fDeltaTime);
	void Draw(SDL_Surface* screen, float fDeltaTime);
	int Status();
	void Dispose();

	virtual void MouseUpEvent(SDL_Event* event);
	virtual void MouseDownEvent (SDL_Event* event);
	virtual void KeyUpEvent(SDL_Event* event);
	virtual void KeyDownEvent(SDL_Event* event);
};
#endif