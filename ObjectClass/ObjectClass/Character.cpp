//Blake Sullivan - Character.cpp
#include "Character.h"

Character::Character()
{
	SetX(0);
	SetY(0);
	m_cStats.SetChangeAngle(0);
	m_cStats.SetDirection(0);
	m_cStats.SetRotateAngle(0);
	m_cStats.SetMoveSpeed(0);
	SetCharID(-1);
	SetInGame(false);
	SetIsBot(false);
	SetName(" ");
}

void Character::Init(int cID, float x, float y, std::string name)
{
	SetX(x);
	SetY(y);
	SetName(name);
	SetCharID(cID);
	m_cStats.SetChangeAngle(0);
	m_cStats.SetDirection(0);

	LoadCharDiff(GetCharID());
}

void Character::LoadCharDiff(int cID)
{
	m_cStats.SetBulletsLeft(20);
	switch (cID)
	{
	case cidBuster:	//Buster Eagle
		m_cStats.SetRotateAngle(120);
		m_cStats.SetMoveSpeed(120);
		m_cStats.SetMaxHealth(150);
		m_cStats.SetBulletsLeft(20);
		SetSurface("BE.bmp");
	break;
	case cidPteras: //Pteras
		m_cStats.SetRotateAngle(175);
		m_cStats.SetMoveSpeed(150);
		m_cStats.SetMaxHealth(100);
		SetSurface("PT.bmp");
	break;
	case cidZabat: //Zabat
		m_cStats.SetRotateAngle(100);
		m_cStats.SetMoveSpeed(150);
		m_cStats.SetMaxHealth(100);
		SetSurface("Z.bmp");
	break;
	case cidRedler: //Redler
		m_cStats.SetRotateAngle(150);
		m_cStats.SetMoveSpeed(175);
		m_cStats.SetMaxHealth(100);
		SetSurface("RL.bmp");
	break;
	case cidStorm: //Stormsworder
		m_cStats.SetRotateAngle(120);
		m_cStats.SetMoveSpeed(220);
		m_cStats.SetMaxHealth(100);
		SetSurface("SS.bmp");
	break;
	default: //Raynos
		m_cStats.SetRotateAngle(150);
		m_cStats.SetMoveSpeed(200);
		m_cStats.SetMaxHealth(50);
		m_cStats.SetBulletsLeft(20);
		SetSurface("R.bmp");
	}
}

void Character::Draw(SDL_Surface* screen, float fDeltaTime)
{
	SDL_Rect dclip;
	SDL_Surface* temp = NULL;
	temp = rotozoomSurface(GetSurface(), GetStats()->GetDirection(), 1.0, 0);
	SDL_SetColorKey(temp, SDL_SRCCOLORKEY, SDL_MapRGB(temp->format, 255, 0, 255));

	dclip.x = GetX() - (temp->w/2);
	dclip.y = GetY() - (temp->h/2);
	dclip.w = temp->w; dclip.h = temp->h;

	SDL_BlitSurface(temp, &temp->clip_rect, screen, &dclip);
	SDL_FreeSurface(temp);

	int iCentreX = dclip.x + (dclip.w / 2), iCentreY = dclip.y + (dclip.h / 2);
	//circleRGBA(screen, dclip.x + (96/2), dclip.y + (96/2), 30, 255, 0, 0, 255);
	/*rectangleRGBA(screen, iCentreX - 16, iCentreY - 16, iCentreX + 16, iCentreY + 16, 255, 0, 0, 255);
	rectangleRGBA(screen, iCentreX - (16 + 32), iCentreY - 16, iCentreX - 16, iCentreY + 16, 255, 0, 0, 255);
	rectangleRGBA(screen, iCentreX + 16, iCentreY - 16, iCentreX + (16 + 32), iCentreY + 16, 255, 0, 0, 255);
	rectangleRGBA(screen, iCentreX - 16, iCentreY - (16 + 32), iCentreX + 16, iCentreY - 16, 255, 0, 0, 255);
	rectangleRGBA(screen, iCentreX - 16, iCentreY + 16, iCentreX + 16, iCentreY + (16 + 32), 255, 0, 0, 255);*/
}
void Character::Update(float fDeltaTime)
{
}
void Character::Collide(int type, int id, int damage)
{
}
void Character::Dispose()
{
	SDL_FreeSurface(GetSurface());
}

void Character::MoveCharacter(char cDir, float fdt)
{
	switch (cDir)
	{
	case 'u':
		MoveUp(fdt, 1);
	break;
	case 'd':
		MoveDown(fdt, 1);
	break;
	case 'l':
		MoveLeft(fdt, 1);
	break;
	case 'r':
		MoveRight(fdt, 1);
	break;
	case 'q':
		RotateLeft(fdt, 1);
	break;
	case 'e':
		RotateRight(fdt, 1);
	break;
	}
}
void Character::MoveLeft(float fdt, int speedMult)
{
	float tempX = 0, tempY = 0;
	float tempSpeedMult = 0.5;
	tempX = GetX() - ((m_cStats.GetMoveSpeed() * tempSpeedMult) * fdt);
	tempY = GetY();
	SetX(tempX);
	SetY(tempY);
}
void Character::MoveRight(float fdt, int speedMult)
{
	float tempX = 0, tempY = 0;
	float tempSpeedMult = 0.5;
	tempX = GetX() + ((m_cStats.GetMoveSpeed() * tempSpeedMult) * fdt);
	tempY = GetY();
	SetX(tempX);
	SetY(tempY);
}
void Character::MoveUp(float fdt, int speedMult)
{
	float tempX = 0, tempY = 0;
	tempX = GetX() - (((m_cStats.GetMoveSpeed() * speedMult) * fdt) * sin((m_cStats.GetDirection()) * M_PI / 180));
	tempY = GetY() - (((m_cStats.GetMoveSpeed() * speedMult) * fdt) * cos((m_cStats.GetDirection()) * M_PI / 180));
	SetX(tempX);
	SetY(tempY);
}
void Character::MoveDown(float fdt, int speedMult)
{
	float tempX = 0, tempY = 0;
	tempX = GetX() + ((m_cStats.GetMoveSpeed() * speedMult) * fdt) * sin((m_cStats.GetDirection() * M_PI) / 180);
	tempY = GetY() + ((m_cStats.GetMoveSpeed() * speedMult) * fdt) * cos((m_cStats.GetDirection() * M_PI) / 180);
	SetX(tempX);
	SetY(tempY);
}
void Character::RotateLeft(float fdt, int speedMult)
{
	float caTemp = m_cStats.GetDirection();
	caTemp += (m_cStats.GetRotateAngle() * speedMult) * fdt;
	if (caTemp > 360) {caTemp -= 360;}
	if (caTemp < 0) {caTemp += 360;}
	m_cStats.SetDirection(caTemp);
}
void Character::RotateRight(float fdt, int speedMult)
{
	float caTemp = m_cStats.GetDirection();
	caTemp -= (m_cStats.GetRotateAngle() * speedMult) * fdt;
	if (caTemp > 360) {caTemp -= 360;}
	if (caTemp < 0) {caTemp += 360;}
	//m_cStats.SetChangeAngle(caTemp;);
	m_cStats.SetDirection(caTemp);
}

void Character::SetCharID(int id)
{
	m_iCharID = id;
}
void Character::SetName(string n)
{
	m_sName = n;
}
void Character::SetInGame(bool ig)
{
	m_bInGame = ig;
}
void Character::SetIsBot(bool b)
{
	m_bIsBot = b;
}

int Character::GetCharID()
{
	return m_iCharID;
}
string Character::GetName()
{
	return m_sName;
}
CharStats* Character::GetStats()
{
	return &m_cStats;
}
bool Character::GetInGame()
{
	return m_bInGame;
}
bool Character::GetIsBot()
{
	return m_bIsBot;
}