//Blake Sullivan - Player.h
#ifndef PLAYER_H
#define PLAYER_H

#include <math.h>
#include <iostream>
//using namespace std;

class Player
{
private:
	const static double ms_dPI;
	static int ms_iMyID;
	float x, y;
	float theangle;
	double dx, dy;
	int direction;
	int r;
	float m_fMoveSpeed;
	int m_iCharID;
	bool m_bAlive, m_bInGame;

public:
	Player();

	float GetX();
	float GetY();
	int GetR();
	int GetDir();
	static int GetID();
	int GetCharID();
	bool GetAlive();
	bool GetInGame();
	
	void SetStart(int tempx, int tempy);
	void SetX(float tempx);
	void SetY(float tempy);
	void SetDirection(int d);
	static void SetID(int);
	void SetCharID(int);
	void SetAlive(bool);
	void SetInGame(bool);

	void moveLeft(float fdt);
	void moveRight(float fdt);
	void moveUp(float fdt);
	void moveDown(float fdt);

};
#endif