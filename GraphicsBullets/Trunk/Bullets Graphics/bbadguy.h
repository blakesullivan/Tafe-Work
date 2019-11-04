//Blake Sullivan - bbadguy.h
#ifndef BBADGUY
#define BBADGUY

#include "SDL.h"   /* All SDL App's need this */
#include "SDL_gfxPrimitives.h" 
#include "SDL_rotozoom.h"
#include <vector>
using namespace std;

class bbadguy
{
private:
	int x,y;
	SDL_Rect bsclip, bdclip;
	bool bAlive;
	int r;
public:
	bbadguy();
	void setX(int ix);
	int getX();
	int getR();
	int getY();
	void setY(int iy);
	bool getLife();
	void setLife(bool liv);

	void draw(SDL_Surface* s, SDL_Surface* bg, int);

	SDL_Rect getRect();
};

#endif