//Blake Sullivan - PlayerStats.cpp
#include "PlayerStats.h"

PlayerStats::PlayerStats()
{
	SetMaxHealth(0);
	SetMaxEnergy(0);
	SetHealth(0);
	SetEnergy(0);
	SetMoveSpeed(0);
	SetRateOfFire(0);
	SetChangeAngle(0);
	SetDirection(0);
	SetRotateAngle(0);
	SetBulletType(0);
	SetBulletMax(0);
	SetBulletsLeft(0);
}

void PlayerStats::SetMaxHealth(float mh)
{
	m_fMaxHealth = mh;
}
void PlayerStats::SetMaxEnergy(float me)
{
	m_fMaxEnergy = me;
}
void PlayerStats::SetHealth(float h)
{
	m_fHealth = h;
}
void PlayerStats::SetEnergy(float e)
{
	m_fEnergy = e;
}
void PlayerStats::SetMoveSpeed(float ms)
{
	m_fMoveSpeed = ms;
}
void PlayerStats::SetRateOfFire(float rof)
{
	m_fRateOfFire = rof;
}
void PlayerStats::SetChangeAngle(float ca)
{
	m_fChangeAngle = ca;
}
void PlayerStats::SetDirection(float d)
{
	m_fDirection = d;
}
void PlayerStats::SetRotateAngle(float ra)
{
	m_fRotateAngle = ra;
}
void PlayerStats::SetBulletType(int bt)
{
	m_iBulletType = bt;
}
void PlayerStats::SetBulletMax(int bm)
{
	m_iBulletMax = bm;
}
void PlayerStats::SetBulletsLeft(int bl)
{
	m_iBulletsLeft = bl;
}

float PlayerStats::GetHealth()
{
	return m_fHealth;
}
float PlayerStats::GetEnergy()
{
	return m_fEnergy;
}
float PlayerStats::GetMoveSpeed()
{
	return m_fMoveSpeed;
}
float PlayerStats::GetRateOfFire()
{
	return m_fRateOfFire;
}
float PlayerStats::GetChangeAngle()
{
	return m_fChangeAngle;
}
float PlayerStats::GetDirection()
{
	return m_fDirection;
}
float PlayerStats::GetRotateAngle()
{
	return m_fRotateAngle;
}

int PlayerStats::GetBulletType()
{
	return m_iBulletType;
}
int PlayerStats::GetBulletMax()
{
	return m_iBulletMax;
}
int PlayerStats::GetBulletsLeft()
{
	return m_iBulletsLeft;
}

float PlayerStats::GetBulletDamage(int cID)
{
	float bd = 0;
	switch (cID)
	{
	case cidRaynos:
		bd = 20;
	break;
	case cidPteras:
		bd = 30;
	break;
	case cidBusterEagle:
		bd = 80;
	break;
	case cidZabat:
		bd = 50;
	break;
	case cidGenoSaurer:
		bd = 30;
	break;
	case cidLigerPanzer:
		bd = 50;
	break;
	case cidShadowFox:
		bd = 1;
	break;
	case cidZaberFang:
		bd = 20;
	break;
	}
	return bd;
}
float PlayerStats::GetBulletSpeed(int cID)
{
	float bs = 0;
	switch (cID)
	{
	case cidRaynos:
		bs = 400;
	break;
	case cidPteras:
		bs = 500;
	break;
	case cidBusterEagle:
		bs = 200;
	break;
	case cidZabat:
		bs = 250;
	break;
	case cidGenoSaurer:
		bs = 250;
	break;
	case cidLigerPanzer:
		bs = 280;
	break;
	case cidShadowFox:
		bs = 450;
	break;
	case cidZaberFang:
		bs = 250;
	break;
	}
	return bs;
}
float PlayerStats::GetBulletSize(int cID)
{
	float bs = 0;
	switch (cID)
	{
	case cidRaynos:
		bs = 5;
	break;
	case cidPteras:
		bs = 5;
	break;
	case cidBusterEagle:
		bs = 7.5;
	break;
	case cidZabat:
		bs = 8;
	break;
	case cidGenoSaurer:
		bs = 5;
	break;
	case cidLigerPanzer:
		bs = 8;
	break;
	case cidShadowFox:
		bs = 2;
	break;
	case cidZaberFang:
		bs = 5;
	break;
	}
	return bs;
}

int PlayerStats::GetMaxLife(int cID)
{
	int ml = 0;
	switch (cID)
	{
	case cidRaynos:
		ml = 5;
	break;
	case cidPteras:
		ml = 5;
	break;
	case cidBusterEagle:
		ml = 10;
	break;
	case cidZabat:
		ml = 8;
	break;
	case cidGenoSaurer:
		ml = 5;
	break;
	case cidLigerPanzer:
		ml = 8;
	break;
	case cidShadowFox:
		ml = 2;
	break;
	case cidZaberFang:
		ml = 5;
	break;
	}
	return ml;
}