//Blake Sullivan - Bullet.h
#ifndef BULLET
#define BULLET

#include "SDL.h"   /* All SDL App's need this */
#include "SDL_gfxPrimitives.h" 
#include "SDL_rotozoom.h"

class Bullet
{
private:
	float m_fX, m_fY;	//current location on screen
	float m_fAngle;		//direction of shot
	char m_cOwner;		//Owner of the bullet
	SDL_Rect sclip, dclip;

public:
	Bullet();
	void set(const float, const float, const float, const char);
	float getX();
	float getY();
	float getOwner();
	// when the bullet is fired we need to put all the details in thedate
	void move(const float);	// move the bullet
	void draw(SDL_Surface*, SDL_Surface*);	// draw the bullet
};
#endif