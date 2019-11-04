//Blake Sullivan - Splash.h
#ifndef MENU_H
#define MENU_H

#include "Scene.h"
#include "ButtonManager.h"
#include "MyText.h"

class Menu : public Scene
{
private:
	ButtonManager* m_pBM;
	MyText* m_pMT;

public:
	Menu();
	Menu(MyText* mt);

	void Init();
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