//Blake Sullivan - Player header
#ifndef PLAYER_H
#define PLAYER_H
#include "SDL.h"   /* All SDL App's need this */
#include "SDL_gfxPrimitives.h"
#include <math.h>
extern SDL_Surface *screen;

class Player
{
private:
	float fXo, fYo, fX1, fY1, fX2, fY2, fX3, fY3, fDeg, dx, dy, fXNew, fYNew; //o = origin
	float Deg;
	int iMov;
	int myColour;
	int mR, mG, mB;

public:
	//Player();
	void Init(float, float, int, int, int, int);
	void Move(char);
	void Draw();
	void Rotate(float);
	void Face(float, float);

	float GetXo();
	float GetYo();
};

#endif