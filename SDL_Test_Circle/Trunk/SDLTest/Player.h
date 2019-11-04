//Player.h
#ifndef Player_H
#define Player_H
#include "SDL.h"
#include "SDL_gfxPrimitives.h" 
#include <math.h>
extern SDL_Surface *screen;

class Player
{
private:
	float iXo,iYo,fRad;
	int iMov;
public:
	Player();
	void Move(char);
	void Draw();
	bool CollisionCheck(float,float,float);
	
};

#endif