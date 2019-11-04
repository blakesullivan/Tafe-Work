//Blake Sullivan - Player.h
#ifndef PLAYER_H
#define PLAYER_H

class Player
{
private:
	float m_fX, m_fY;
	int m_iUserID;
	bool m_bAlive;

public:
	Player();

	void SetX(float);
	void SetY(float);
	void SetUserID(int);
	void SetAlive(bool);

	float GetX();
	float GetY();
	int GetUserID();
	bool GetAlive();
};

#endif