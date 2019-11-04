#ifndef PLAYER
#define PLAYER
#include "sdl_gfxPrimitives.h"

extern SDL_Surface *screen;
class Player
{
protected:
	float m_fX, m_fY;
	short m_sG;
	const static short csm_sRad=16;
public:
	Player(bool);
	void setX(short);
	void setY(short);
	float getX();
	float getY();
	void Display();
};
#endif