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
	//float fXoc, fYoc, fRad;
	float fXo, fYo, fX1, fY1, fX2, fY2, fX3, fY3, fDeg, dx, dy, fXNew, fYNew; //o = origin
	float Deg;
	int iMov;

	//float f2Xo, f2Yo, f2X1, f2Y1, f2X2, f2Y2, f2X3, f2Y3, f2Deg, d2x, d2y, f2XNew, f2YNew; //o = origin
	//float D2eg;
	//int i2Mov;

public:
	Player();
	void Init();
	void Move(char);
	void Draw();
	void Rotate(float);
	//void R2otate();
};

#endif