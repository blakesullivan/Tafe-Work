//Blake Sullivan - gplayer.h
#ifndef GPLAYER
#define GPLAYER

#include "SDL.h"   /* All SDL App's need this */
#include "SDL_gfxPrimitives.h" 
#include "SDL_rotozoom.h"

class gplayer
{
private:
	int x, y;
	SDL_Rect sclip, dclip;
	float theangle;
	double dx, dy;
	int direction;
	int r;

public:
	gplayer();

	int getX();
	int getY();
	int getR();
	int getDir();
	void setStart(int x, int y);

	void draw(SDL_Surface* s, SDL_Surface* p, SDL_Surface* temp);

	SDL_Rect getRect();

	void setDirection(int d);
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
};
#endif