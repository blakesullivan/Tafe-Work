//Blake Sullivan - Bullet.cpp
#include "Bullet.h"
Bullet::Bullet()
{
	m_fX = 0;
	m_fY = 0;
	m_fAngle = 0;
}
void Bullet::set(const float x, const float y, const float a, const char o)
{
	m_fX = x;
	m_fY = y;
	m_fAngle = a;
	m_cOwner = o;
}
void Bullet::move(const float fDT)
{
	float dx = 0, dy = 0;
	dx=(10*(fDT/1000))*sin((180-m_fAngle)*M_PI/180);
	dy=(10*(fDT/1000))*cos((180-m_fAngle)*M_PI/180);
	m_fX+=dx;
	m_fY+=dy;
}

void Bullet::draw(SDL_Surface* s, SDL_Surface* b)
{
	//Initialise the clipping rectangles for the source image and the destination location on screen
	sclip.x = 0; sclip.y = 0; sclip.w = 10; sclip.h = 10; 	//where the image is  in memory 
	dclip.x = m_fX; dclip.y = m_fY; dclip.w = 10; dclip.h = 10; 	//where to put the image on screen 
	SDL_BlitSurface(b, &sclip, s, &dclip);

	//circleRGBA(s, x, y, 16, 255, 255, 0, 255);
}

float Bullet::getX()
{
	return m_fX;
}
float Bullet::getY()
{
	return m_fY;
}
float Bullet::getOwner()
{
	return m_cOwner;
}