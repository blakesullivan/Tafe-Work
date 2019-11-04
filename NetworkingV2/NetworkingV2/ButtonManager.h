//Blake Sullivan - ButtonManager.h
#ifndef BUTTONMANAGER_H
#define BUTTONMANAGER_H

#include "SDL_gfxPrimitives.h"
#include "Button.h"
#include "DrawText.h"
#include <vector>
using namespace std;

class ButtonManager
{
private:
	vector<Button> m_vButtons;
	vector<Button>::iterator m_vButtonsIT;
	//SDL_Surface* thefont;
	DrawText dt;

public:
	ButtonManager();
	~ButtonManager();

	void AddButton(int x, int y, std::string t, unsigned int w, unsigned int h, Colours cN, Colours cH, Colours cD);
	void AddColours(unsigned int id, int colState, int red, int green, int blue, int alpha);
	void UpdateButton(int mouseX, int mouseY);
	void ButtonPressed(int mouseX, int mouseY);
	int CheckButtonPressed();
	void ButtonUnPressed(int id);
	void DrawButton(SDL_Surface* screen);

};
#endif