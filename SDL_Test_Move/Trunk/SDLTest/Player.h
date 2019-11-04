//Player.h
#ifndef Player_H
#define Player_H
#include "SDL.h"
#include "SDL_gfXPrimitives.h" 
#include <math.h>
extern SDL_Surface *screen;
class Player
{
private:
	float iXo,iYo,fRad;
	int iMov;
	float fXo, fYo, fX1, fY1, fX2, fY2, fX3, fY3, fDeg, dx, dy, fXNew, fYNew; //o = origin
	float Deg;
	int myColour;
	int mR, mG, mB;
	bool bAlive;

	struct boxXY
	{
		float x;
		float y;
		float size;
	};
	boxXY pos;

public:
	Player();
	void Init(float, float, int, int, int, int);
	void Move(char);
	void Rotate(float);
	void Draw();
	//bool CollisionCheck(struct boxXy bp);
	bool CollisionCheck(float, float, float);
	float GetIXo();
	float GetIYo();
	float GetIX1();
	float GetIY1();
	float GetDeg();
	bool GetAlive();
	int GetSize();
	
};

#endif