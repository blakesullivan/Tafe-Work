//Bullet.cpp
#include "Bullet.h"

Bullet::Bullet()
{
}

void Bullet::Create(float x, float y, float dir, int move)
{
	fXo=x;
	fYo=y;
	fRad=1;
	fDir=dir;
	iMov=move;
	bAlive=true;
}
void Bullet::Draw()
{
	filledCircleRGBA(screen, fXo, fYo, fRad, 0, 0, 0, 255);
}
void Bullet::Move()
{
	float dx=iMov*sin(fDir);
	float dy=iMov*cos(fDir);
	fXo+=dx;
	fYo-=dy;
}
void Bullet::Kill()
{
	bAlive=false;
}

float Bullet::GetX()
{
	return fXo;
}
float Bullet::GetY()
{
	return fYo;
}
float Bullet::GetSize()
{
	return fRad;
}
bool Bullet::GetAlive()
{
	return bAlive;
}

void Bullet::SetAlive(bool live)
{
	bAlive=live;
}