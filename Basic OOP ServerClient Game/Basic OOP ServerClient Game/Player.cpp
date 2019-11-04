//Blake Sullivan - Player.cpp
#include "Player.h"

Player::Player()
{
	SetX(20);
	SetY(20);
	SetUserID(-1);
	SetAlive(false);
}

void Player::SetX(float x)
{
	m_fX = x;
}
void Player::SetY(float y)
{
	m_fY = y;
}
void Player::SetUserID(int uid)
{
	m_iUserID = uid;
}
void Player::SetAlive(bool a)
{
	m_bAlive = a;
}

float Player::GetX()
{
	return m_fX;
}
float Player::GetY()
{
	return m_fY;
}
int Player::GetUserID()
{
	return m_iUserID;
}
bool Player::GetAlive()
{
	return m_bAlive;
}