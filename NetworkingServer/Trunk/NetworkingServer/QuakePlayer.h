//Blake Sullivan - QuakePlayer.cpp
#ifndef QUAKEPLAYER_H
#define QUAKEPLAYER_H

#include "Player.h"
#include <string>
#include <iostream>
using std::cout;
using std::endl;

class QuakePlayer : public Player
{
private:
	int m_iCharID;
	float m_fX, m_fY;
	unsigned int m_uiDeg;
	int m_iAlive;

public:
	QuakePlayer();

	void Init(std::string, int);
	void Display();
	
	void SetCharID(int);
	void SetX(float);
	void SetY(float);
	void SetDeg(unsigned int);
	void SetAlive(int);
	
	int GetCharID();
	float GetX();
	float GetY();
	unsigned int GetDeg();
	int GetAlive();
};
#endif