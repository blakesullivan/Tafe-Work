//Blake Sullivan - gplayer.cpp
#include "gplayer.h"
gplayer::gplayer()
{
	x=400;
	y=300;
	theangle=0;
	dx=0.0;
	dy=0.0;
	direction=0;
	r=16;
	dclip.x=-20;
	dclip.y=-20;
}

int gplayer::getX()
{
	return x;
}
int gplayer::getY()
{
	return y;
}
int gplayer::getR()
{
	return r;
}
int gplayer::getDir()
{
	return direction;
}
void gplayer::setStart(int x, int y)
{
	x=x;
	y=y;
}

void gplayer::draw(SDL_Surface* s, SDL_Surface* p, SDL_Surface* temp)
{
	temp = rotozoomSurface(p, (double)-direction, 1.0, 0);
	SDL_SetColorKey(temp, SDL_SRCCOLORKEY, SDL_MapRGB(temp->format, 0x0, 0x0, 0x0)); 

	//Initialise the clipping rectangles for the source image and the destination location on screen
	sclip.x = 0; sclip.y = 0; sclip.w = 64; sclip.h = 64; 	//where the image is  in memory 
	dclip.x = x-(temp->w/2); dclip.y = y-(temp->h/2); dclip.w = temp->w; dclip.h = temp->h; 	//where to put the image on screen 
	SDL_BlitSurface(temp, &sclip, s, &dclip);
	SDL_FreeSurface(temp);
	circleRGBA(s, x, y, 16, 255, 255, 0, 255);
}

SDL_Rect gplayer::getRect()
{
	return dclip;
}

void gplayer::setDirection(int d)
{
	direction=d;
}
void gplayer::moveLeft()
{
	theangle+=10;
}
void gplayer::moveRight()
{
	theangle-=10;
}
void gplayer::moveUp()
{
	dx=10*sin((180-direction)*M_PI/180);
	dy=10*cos((180-direction)*M_PI/180);
	x+=dx;
	y+=dy;
}
void gplayer::moveDown()
{
	dx=10*sin((180-(direction-180))*M_PI/180);
	dy=10*cos((180-(direction-180))*M_PI/180);
	x+=dx;
	y+=dy;
}