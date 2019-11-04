//Blake Sullivan - MenuButton.h
#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include <string>
using namespace std;

class MenuButton
{
private:
	const static unsigned int CS_BUTTONWIDTH = 200, CS_BUTTONHEIGHT = 50;
	int m_iX, m_iY;
	unsigned int m_uiID, m_uiPicPos;
	string m_sText;
	bool m_bPressed;
public:
	MenuButton();

	void Init(int, int, int);
	void Init(int, int, int, string);

	void SetX(int);
	void SetY(int);
	void SetID(unsigned int);
	void SetPicPos(unsigned int);
	void SetText(string);
	void SetPressed(bool);

	int GetX();
	int GetY();
	unsigned int GetID();
	unsigned int GetPicPos();
	string GetText();
	bool GetPressed();

	static unsigned int GetWidth();
	static unsigned int GetHeight();
};

#endif