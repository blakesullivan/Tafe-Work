//Blake Sullivan - QuakePlayer.cpp
#include "QuakePlayer.h"

QuakePlayer::QuakePlayer()
{
	SetCharID(0);
	SetX(0);
	SetY(0);
	SetDeg(0);
	SetAlive(0);
}

void QuakePlayer::Init(std::string QuakePlayerp, int id)
{
	std::string sData = "";
	float fTempX = 0, fTempY = 0;
	int fTempDeg = 0;
	SetID(id);
	sData = QuakePlayerp.substr(6, QuakePlayerp.length());
	cout << "sData: " << sData << endl;
	SetCharID(atoi(sData.substr(0, sData.find(",")).c_str()));
	SetAlive(true);
	SetInGame(true);

	switch (GetID())
	{
	case 1: //Opp 0
		fTempX = 400;
		fTempY = 50;
		fTempDeg = 270;
	break;
	case 2: //Opp 3
		fTempX = 50;
		fTempY = 300;
		fTempDeg = 0;
	break;
	case 3: //Opp 2
		fTempX = 750;
		fTempY = 300;
		fTempDeg = 180;
	break;

	case 4: //Opp 5
		fTempX = 750;
		fTempY = 50;
		fTempDeg = 225;
	break;
	case 5: //Opp 4
		fTempX = 50;
		fTempY = 550;
		fTempDeg = 45;
	break;

	case 6: //Opp 7
		fTempX = 50;
		fTempY = 50;
		fTempDeg = 325;
	break;
	case 7: //Opp 6
		fTempX = 750;
		fTempY = 550;
		fTempDeg = 135;
	break;
	
	default: //Opp 1
		fTempX = 400;
		fTempY = 550;
		fTempDeg = 90;
	break;
	}
	SetX(fTempX);
	SetY(fTempY);
	SetDeg(fTempDeg);
	
	Display();
}

void QuakePlayer::Display()
{
	cout << "GetID(): " << GetID() << endl;
	cout << "GetCharID(): " << GetCharID() << endl;
	cout << "GetX(): " << GetX() << endl;
	cout << "GetY(): " << GetY() << endl;
	cout << "GetDeg(): " << GetDeg() << endl;
	cout << "GetHost(): " << GetHost() << endl;
	cout << "GetPort(): " << GetPort() << endl;
}

void QuakePlayer::SetCharID(int cid)
{
	m_iCharID = cid;
}
void QuakePlayer::SetX(float x)
{
	m_fX = x;
}
void QuakePlayer::SetY(float y)
{
	m_fY = y;
}
void QuakePlayer::SetDeg(unsigned int d)
{
	m_uiDeg = d;
}
void QuakePlayer::SetAlive(int a)
{
	m_iAlive = a;
}

int QuakePlayer::GetCharID()
{
	return m_iCharID;
}
float QuakePlayer::GetX()
{
	return m_fX;
}
float QuakePlayer::GetY()
{
	return m_fY;
}
unsigned int QuakePlayer::GetDeg()
{
	return m_uiDeg;
}
int QuakePlayer::GetAlive()
{
	return m_iAlive;
}
