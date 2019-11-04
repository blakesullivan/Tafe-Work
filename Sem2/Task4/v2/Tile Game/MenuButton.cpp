//Blake Sullivan - MenuButton.cpp
#include "MenuButton.h"

MenuButton::MenuButton()
{
	SetX(0);
	SetY(0);
	SetID(0);
	SetPicPos(0);
	SetText(" ");
	SetPressed(false);
}

void MenuButton::Init(int x, int y, int id)
{
	SetX(x);
	SetY(y);
	SetID(id);
}

void MenuButton::Init(int x, int y, int id, string t)
{
	SetX(x);
	SetY(y);
	SetID(id);
	SetText(t);
}

void MenuButton::SetX(int x)
{
	m_iX = x;
}

void MenuButton::SetY(int y)
{
	m_iY = y;
}
void MenuButton::SetID(unsigned int id)
{
	m_uiID = id;
}
void MenuButton::SetPicPos(unsigned int pp)
{
	m_uiPicPos = pp;
}
void MenuButton::SetText(string t)
{
	m_sText = t;
}
void MenuButton::SetPressed(bool p)
{
	m_bPressed = p;
}

int MenuButton::GetX()
{
	return m_iX;
}
int MenuButton::GetY()
{
	return m_iY;
}
unsigned int MenuButton::GetID()
{
	return m_uiID;
}
unsigned int MenuButton::GetPicPos()
{
	return m_uiPicPos;
}
string MenuButton::GetText()
{
	return m_sText;
}

bool MenuButton::GetPressed()
{
	return m_bPressed;
}

unsigned int MenuButton::GetWidth()
{
	return CS_BUTTONWIDTH;
}

unsigned int MenuButton::GetHeight()
{
	return CS_BUTTONHEIGHT;
}