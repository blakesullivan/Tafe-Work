//Blake Sullivan - DrawText.h
#ifndef DRAWTEXT_H
#define DRAWTEXT_H
#include "SDL.h"
#include <string>
using std::string;

class DrawText
{
private:
	SDL_Surface* thefont;

public:
	DrawText();
	~DrawText();

	void DrawTextToSurface(SDL_Surface* screen, string s, int, int);
};
#endif