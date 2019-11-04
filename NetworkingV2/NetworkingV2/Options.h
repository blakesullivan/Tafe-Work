//Blake Sullivan - Splash.h
#ifndef OPTIONS_H
#define OPTIONS_H

#include "Scene.h"

class Options : public Scene
{
private:
	
public:
	Options();

	void Init();
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