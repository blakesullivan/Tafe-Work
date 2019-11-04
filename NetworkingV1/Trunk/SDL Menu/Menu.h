//Blake Sullivan - Splash.h
#ifndef MENU_H
#define MENU_H

#include "Scene.h"
#include "MenuButton.h"
#include <vector>
using namespace std;

class Menu : public Scene
{
private:
	enum {buttonSplash = 0, buttonMenu = 1, buttonOptions = 2, buttonPlay = 3, buttonHost = 4, buttonJoin = 5, buttonExit = 6};

	vector<MenuButton> m_vButtons;
	vector<MenuButton>::iterator m_vButtonsIT;

	SDL_Surface *thefont;
	SDL_Surface *button;
public:
	Menu();

	void Init();
	void Event(SDL_Surface* screen, SDL_Event *event, float fDeltaTime);
	void Update(SDL_Surface* screen, float fDeltaTime);
	void Draw(SDL_Surface* screen, float fDeltaTime);
	int Status();
	void Dispose();

	void CreateButtons(int, int, int);
	void UpdateButtons(int, int);
	void DrawButtons(SDL_Surface* screen);
	int CheckButtonPressed(int);
	void myDrawText(SDL_Surface* screen, char[], int, int);

};
#endif