//Blake Sullivan - Player.cpp
#include "Player.h"

int Player::ms_iMyID = 0;

Player::Player()
{
	SetX(0);
	SetY(0);
	m_pStats.SetChangeAngle(0);
	m_pStats.SetDirection(0);
	m_pStats.SetRotateAngle(0);
	m_pStats.SetMoveSpeed(0);
	SetCharacterID(-1);
	SetAlive(false);
	SetInGame(false);
	SetName(" ");
	m_Character = NULL;
	
}
Player::~Player()
{
	SDL_FreeSurface(m_Character);
}

void Player::Init(int cID, float x, float y, std::string name)
{
	SetX(x);
	SetY(y);
	SetName(name);
	SetCharacterID(cID);
	m_pStats.SetChangeAngle(0);
	m_pStats.SetDirection(0);

	LoadCharDiff(GetCharacterID());
}

void Player::LoadCharDiff(int cID)
{
	m_pStats.SetBulletsLeft(20);
	switch (cID)
	{
	case 1:	//Buster Eagle
		m_pStats.SetRotateAngle(120);
		m_pStats.SetMoveSpeed(120);
		m_pStats.SetMaxHealth(100);
		m_pStats.SetBulletsLeft(20);
		SetCharacterSurface("BE.bmp");
	break;
	case 2: //Pteras
		m_pStats.SetRotateAngle(175);
		m_pStats.SetMoveSpeed(150);
		m_pStats.SetMaxHealth(100);
		SetCharacterSurface("PT.bmp");
	break;
	case 3: //Zabat
		m_pStats.SetRotateAngle(100);
		m_pStats.SetMoveSpeed(150);
		m_pStats.SetMaxHealth(100);
		SetCharacterSurface("ZB.bmp");
	break;
	case 4: //Geno Saurer
		m_pStats.SetRotateAngle(20);
		m_pStats.SetMoveSpeed(30);
		m_pStats.SetMaxHealth(100);
		SetCharacterSurface("GS.bmp");
	break;
	case 5: //Liger Zero Panzer
		m_pStats.SetRotateAngle(20);
		m_pStats.SetMoveSpeed(30);
		m_pStats.SetMaxHealth(100);
		SetCharacterSurface("LZ.bmp");
	break;
	case 6: //Shadow Fox
		m_pStats.SetRotateAngle(20);
		m_pStats.SetMoveSpeed(30);
		m_pStats.SetMaxHealth(100);
		SetCharacterSurface("SF.bmp");
	break;
	case 7: // Zaber Fang
		m_pStats.SetRotateAngle(20);
		m_pStats.SetMoveSpeed(30);
		m_pStats.SetMaxHealth(100);
		SetCharacterSurface("ZF.bmp");
	break;
	default: //Raynos
		m_pStats.SetRotateAngle(150);
		m_pStats.SetMoveSpeed(200);
		m_pStats.SetMaxHealth(50);
		m_pStats.SetBulletsLeft(20);
		SetCharacterSurface("R.bmp");
	}
}

void Player::AddBullet()
{
	if (m_vBullets.size() < m_pStats.GetBulletsLeft())
	{
		Bullet temp;
		temp.Init(GetX(), GetY(), m_pStats.GetDirection(), m_pStats.GetMaxLife(m_iCharacterID), m_pStats.GetBulletDamage(m_iCharacterID), m_pStats.GetBulletSpeed(m_iCharacterID), m_pStats.GetBulletSize(m_iCharacterID));
		m_vBullets.push_back(temp);
	}
}

void Player::DrawBullets(SDL_Surface* screen)
{
	for (m_vBulletsIT = m_vBullets.begin(); m_vBulletsIT != m_vBullets.end(); m_vBulletsIT++)
	{
		filledCircleRGBA(screen, m_vBulletsIT->GetX(), m_vBulletsIT->GetY(), m_vBulletsIT->GetSize(), 255, 216, 0, 255);
	}
}

void Player::MoveBullets(float fdt)
{
	for (m_vBulletsIT = m_vBullets.begin(); m_vBulletsIT != m_vBullets.end(); m_vBulletsIT++)
	{
		m_vBulletsIT->MoveBullet(fdt);
	}
}

void Player::MoveLeft(float fdt, int speedMult)
{
	/*float tempX = 0, tempY = 0;
	float tempSpeedMult = 0.5;
	tempX = GetX() - ((m_pStats.GetMoveSpeed() * tempSpeedMult) * fdt);
	tempY = GetY();
	SetX(tempX);
	SetY(tempY);*/
	float caTemp = m_pStats.GetDirection();
	caTemp += (m_pStats.GetRotateAngle() * speedMult) * fdt;
	if (caTemp > 360) {caTemp -= 360;}
	if (caTemp < 0) {caTemp += 360;}
	m_pStats.SetDirection(caTemp);
}
void Player::MoveRight(float fdt, int speedMult)
{
	/*float tempX = 0, tempY = 0;
	float tempSpeedMult = 0.5;
	tempX = GetX() + ((m_pStats.GetMoveSpeed() * tempSpeedMult) * fdt);
	tempY = GetY();
	SetX(tempX);
	SetY(tempY);*/
	float caTemp = m_pStats.GetDirection();
	caTemp -= (m_pStats.GetRotateAngle() * speedMult) * fdt;
	if (caTemp > 360) {caTemp -= 360;}
	if (caTemp < 0) {caTemp += 360;}
	//m_pStats.SetChangeAngle(caTemp;);
	m_pStats.SetDirection(caTemp);
}
void Player::MoveUp(float fdt, int speedMult)
{
	float tempX = 0, tempY = 0;
	tempX = GetX() - (((m_pStats.GetMoveSpeed() * speedMult) * fdt) * sin((m_pStats.GetDirection()) * M_PI / 180));
	tempY = GetY() - (((m_pStats.GetMoveSpeed() * speedMult) * fdt) * cos((m_pStats.GetDirection()) * M_PI / 180));
	SetX(tempX);
	SetY(tempY);
}
void Player::MoveDown(float fdt, int speedMult)
{
	float tempX = 0, tempY = 0;
	tempX = GetX() + ((m_pStats.GetMoveSpeed() * speedMult) * fdt) * sin((m_pStats.GetDirection() * M_PI) / 180);
	tempY = GetY() + ((m_pStats.GetMoveSpeed() * speedMult) * fdt) * cos((m_pStats.GetDirection() * M_PI) / 180);
	SetX(tempX);
	SetY(tempY);
}

void Player::SetMyID(static int id)
{
	ms_iMyID = id;
}
void Player::SetX(float x)
{
	m_fX = x;
}
void Player::SetY(float y)
{
	m_fY = y;
}
void Player::SetCharacterID(int id)
{
	m_iCharacterID = id;
}
void Player::SetAlive(bool a)
{
	m_bAlive = a;
}
void Player::SetInGame(bool ig)
{
	m_bInGame = ig;
}
void Player::SetCharacterSurface(std::string s)
{
	m_Character = SDL_LoadBMP(s.c_str());
	SDL_SetColorKey(m_Character, SDL_SRCCOLORKEY, SDL_MapRGB(m_Character->format, 255, 0, 255));
}
void Player::SetName(std::string s)
{
	m_sName = s;
}

int Player::GetMyID()
{
	return ms_iMyID;
}
float Player::GetX()
{
	return m_fX;
}
float Player::GetY()
{
	return m_fY;
}
int Player::GetCharacterID()
{
	return m_iCharacterID;
}
float Player::GetDirection()
{
	return m_pStats.GetDirection();
}
bool Player::GetAlive()
{
	return m_bAlive;
}
bool Player::GetInGame()
{
	return m_bInGame;
}
SDL_Surface* Player::GetCharacterSurface()
{
	return m_Character;
}
std::string Player::GetName()
{
	return m_sName;
}