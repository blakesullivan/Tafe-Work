//Blake Sullivan - Player.cpp
#include "Player.h"

Player::Player()
{
	SetID(-1);
	SetInGame(0);
	SetHost(0);
	SetPort(0);
}

void Player::SetID(int id)
{
	m_iID = id;
}
void Player::SetInGame(int ig)
{
	m_iInGame = ig;
}
void Player::SetHost(unsigned int h)
{
	m_uiHost = h;
}
void Player::SetPort(unsigned int p)
{
	m_uiPort = p;
}
void Player::SetIsHost(bool ih)
{
	m_bIsHost = ih;
}
int Player::GetID()
{
	return m_iID;
}
int Player::GetInGame()
{
	return m_iInGame;
}
unsigned int Player::GetHost()
{
	return m_uiHost;
}
unsigned int Player::GetPort()
{
	return m_uiPort;
}
bool Player::GetIsHost()
{
	return m_bIsHost;
}