//Blake Sullivan - Splash.h
#ifndef MENU_H
#define MENU_H

#include "Scene.h"
#include "ButtonManager.h"

class Menu : public Scene
{
private:
	ButtonManager bm;

public:
	Menu();

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

	void ManageMenu();
};
#endif