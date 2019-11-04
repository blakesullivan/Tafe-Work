//Blake Sullivan - Bullet.cpp
#include "Bullet.h"
#include <math.h>
#define M_PI	3.141592654

Bullet::Bullet()
{
	SetX(0);
	SetY(0);
	SetDirection(0);
	SetDamage(0);
	SetMoveSpeed(0);
	SetSize(0);
}
void Bullet::Init(float x, float y, float dir, int ml, float dam, float ms, float size)
{
	SetX(x);
	SetY(y);
	SetDirection(dir);
	SetMaxLife(ml);
	SetDamage(dam);
	SetMoveSpeed(ms);
	SetSize(size);
}
void Bullet::MoveBullet(float fdt)
{
	float tempX = 0, tempY = 0;
	tempX = GetX() - ((GetMoveSpeed() * fdt) * sin(GetDirection() * M_PI / 180));
	tempY = GetY() - ((GetMoveSpeed() * fdt) * cos(GetDirection() * M_PI / 180));
	SetX(tempX);
	SetY(tempY);
}

void Bullet::SetX(float x)
{
	m_fX = x;
}
void Bullet::SetY(float y)
{
	m_fY = y;
}
void Bullet::SetDirection(float d)
{
	m_fDirection = d;
}
void Bullet::SetDamage(float d)
{
	m_fDamage = d;
}
void Bullet::SetMoveSpeed(float ms)
{
	m_fMoveSpeed = ms;
}
void Bullet::SetSize(float s)
{
	m_fSize = s;
}
void Bullet::SetLife(float l)
{
	m_fLife = l;
}
void Bullet::SetMaxLife(int ml)
{
	m_iMaxLife = ml;
}
float Bullet::GetX()
{
	return m_fX;
}
float Bullet::GetY()
{
	return m_fY;
}
float Bullet::GetDirection()
{
	return m_fDirection;
}
float Bullet::GetDamage()
{
	return m_fDamage;
}
float Bullet::GetMoveSpeed()
{
	return m_fMoveSpeed;
}
float Bullet::GetSize()
{
	return m_fSize;
}
int Bullet::GetMaxLife()
{
	return m_iMaxLife;
}
