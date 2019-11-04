//Blake Sullivan - Splash.h
#ifndef SPLASH_H
#define SPLASH_H

#include "Scene.h"

class Splash : public Scene
{
private:
	//int m_iIsRunning;
public:
	Splash();

	void Init();
	void Event(SDL_Surface* screen, SDL_Event *event, float fDeltaTime);
	void Update(SDL_Surface* screen, float fDeltaTime);
	void Draw(SDL_Surface* screen, float fDeltaTime);
	int Status();
	void Dispose();
};
#endif