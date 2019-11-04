//Blake Sullivan - bbadguy.cpp
#include "bbadguy.h"
bbadguy::bbadguy()
{
	bAlive=true;
	x=400;
	y=0;
	r=16;
	bdclip.x=-20;
	bdclip.y=-20;
}
void bbadguy::setX(int ix)
{
	x=ix;
}
int bbadguy::getX()
{
	return x;
}
int bbadguy::getR()
{
	return r;
}
int bbadguy::getY()
{
	return y;
}
void bbadguy::setY(int iy)
{
	y=iy;
}
bool bbadguy::getLife()
{
	return bAlive;
}
void bbadguy::setLife(bool liv)
{
	bAlive=liv;
}

void bbadguy::draw(SDL_Surface* s, SDL_Surface* bg, int iFrame)
{
	bsclip.x = iFrame*32; bsclip.y = 0; bsclip.w = 32; bsclip.h = 32; 	//where the image is  in memory 
	bdclip.x = x; bdclip.y = y; bdclip.w = 32; bdclip.h = 32; 	//where to put the image on screen 
	SDL_BlitSurface(bg, &bsclip, s, &bdclip);

	circleRGBA(s, x+(bdclip.w/2), y+(bdclip.h/2), r, 255, 255, 0, 255);
}
SDL_Rect bbadguy::getRect()
{
	return bdclip;
}