//Blake Sullivan - Splash.h
#ifndef OPTIONS_H
#define OPTIONS_H

#include "Scene.h"
//#include "NetworkClient.h"

class Options : public Scene
{
private:
	//int m_iIsRunning;
	//NetworkClient m_nc;
public:
	Options();

	void Init();
	void Event(SDL_Surface* screen, SDL_Event *event, float fDeltaTime);
	void Update(SDL_Surface* screen, float fDeltaTime);
	void Draw(SDL_Surface* screen, float fDeltaTime);
	int Status();
	void Dispose();
};
#endif