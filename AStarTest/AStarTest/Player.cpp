#include "Player.h"

Player::Player(bool bType)
{
	if (!bType)
	{
		m_sG=0;
		m_fX=96+16;
		m_fY=544+16;
	}
	else
	{
		m_fX=704+16;
		m_fY=96+16;
		m_sG=123;
	}
}
void Player::setX(short sX)
{
	m_fX=sX;
}
void Player::setY(short sY)
{
	m_fY=sY;
}
float Player::getX()
{
	return m_fX;
}
float Player::getY()
{
	return m_fY;
}
void Player::Display()
{
	filledCircleRGBA(screen,m_fX,m_fY,csm_sRad,255,m_sG,0,255);
}