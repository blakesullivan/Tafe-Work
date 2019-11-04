//Blake Sullivan - Pickup.cpp
#include "Pickup.h"

Pickup::Pickup()
{
	SetPickupType(-1);
}

void Pickup::Init(int pt, float x, float y)
{
	SetPickupType(pt);
	SetX(x);
	SetY(y);
	SetTypeDifferences(pt);
}

void Pickup::Draw(SDL_Surface* screen, float fDeltaTime)
{
	SDL_Rect sclip, dclip;
	sclip.x = 0; sclip.y = 0; sclip.w = 32; sclip.h = 32;

	dclip.x = GetX() - 16; dclip.y = GetY() - 16;
	dclip.w = 32; dclip.h = 32;

	SDL_BlitSurface(GetSurface(), &sclip, screen, &dclip);
}
void Pickup::Update(float fDeltaTime)
{

}
void Pickup::Collide(int type, int id, int damage)
{
	
}
void Pickup::Dispose()
{

}

void Pickup::SetTypeDifferences(int pt)
{
	switch (pt)
	{
	case -1:
	case 0:
		SetRadius(16);
		SetDamage(-100);
		SetSurface("H.bmp");
	break;
	case 1:
		SetRadius(16);
		SetDamage(0);
		SetSurface("A1.bmp");
	break;
	case 2:
		SetRadius(16);
		SetDamage(0);
		SetSurface("A2.bmp");
	break;
	}
}

void Pickup::SetPickupType(int pt)
{
	m_iPickupType = pt;
}
int Pickup::GetPickupType()
{
	return m_iPickupType;
}