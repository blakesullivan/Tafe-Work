//Blake Sullivan - Player.h
#ifndef PLAYER_H
#define PLAYER_H

class Player
{
private:
	static const unsigned int CS_UISIZE = 32;
	float m_fX, m_fY;
	int m_iPicRow, m_iPicCol;
	int m_iGridX, m_iGridY;

public:
	Player();
	void Init(float, float, int, int, int, int);

	void SetX(float);
	void SetY(float);
	void SetGridX(int);
	void SetGridY(int);
	void SetPicRow(int);
	void SetPicCol(int);

	float GetX();
	float GetY();
	int GetGridX();
	int GetGridY();
	int GetPicRow();
	int GetPicCol();

	static unsigned int GetSize();
};
#endif