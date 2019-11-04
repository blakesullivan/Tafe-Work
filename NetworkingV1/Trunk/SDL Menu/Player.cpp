//Blake Sullivan - gplayer.cpp
#include "Player.h"
#define initAngle 60

double m_dPI = 3.141592654;
int Player::ms_iMyID = 0;

Player::Player()
{
	x=400;
	y=300;
	theangle=90;
	dx=0.0;
	dy=0.0;
	direction=90;
	r=23;
	m_fMoveSpeed=150;
	//Player::SetID(0);
	SetCharID(1);
}

float Player::GetX()
{
	return x;
}
float Player::GetY()
{
	return y;
}
int Player::GetR()
{
	return r;
}
int Player::GetDir()
{
	return direction;
}
int Player::GetID()
{
	return ms_iMyID;
}
int Player::GetCharID()
{
	return m_iCharID;
}
bool Player::GetAlive()
{
	return m_bAlive;
}
bool Player::GetInGame()
{
	return m_bInGame;
}

void Player::SetStart(int tempx, int tempy)
{
	x=tempx;
	y=tempy;
}
void Player::SetX(float tempx)
{
	x = tempx;
}
void Player::SetY(float tempy)
{
	y = tempy;
}

void Player::SetDirection(int d)
{
	direction=d;
}
void Player::SetID(int id)
{
	ms_iMyID = id;
}
void Player::SetCharID(int cID)
{
	m_iCharID = cID;
}

void Player::SetAlive(bool a)
{
	m_bAlive = a;
}
void Player::SetInGame(bool ig)
{
	m_bInGame = ig;
}

void Player::moveLeft(float fdt)
{
	//theangle+=initAngle*fdt;
	theangle -= 45;
	if (theangle > 360) {theangle -= 360;}
	if (theangle < 0) {theangle += 360;}
	SetDirection(theangle);
}
void Player::moveRight(float fdt)
{
	//theangle-=initAngle*fdt;
	theangle += 45;
	if (theangle > 360) {theangle -= 360;}
	if (theangle < 0) {theangle += 360;}
	SetDirection(theangle);
}
void Player::moveUp(float fdt)
{
	dy=(m_fMoveSpeed*fdt)*sin((direction)*m_dPI/180);
	dx=(m_fMoveSpeed*fdt)*cos((direction)*m_dPI/180);
	x+=dx;
	y-=dy;
}
void Player::moveDown(float fdt)
{
	//cout << "fdt: " << fdt << " direction: " << direction << endl;
	dy = (m_fMoveSpeed*fdt) * sin((direction) * m_dPI/180);
	dx = (m_fMoveSpeed*fdt) * cos((direction) * m_dPI/180);
	//cout << "dx: " << dx << " dy: " << dy << " x: " << x << " y: " << y << endl;
	x -= dx;
	y += dy;
	//cout << "dx: " << dx << " dy: " << dy << " x: " << x << " y: " << y << endl;
}