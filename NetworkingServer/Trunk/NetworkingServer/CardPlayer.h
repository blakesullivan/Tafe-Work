//Blake Sullivan - CardPlayer.h
#ifndef CARDPLAYER_H
#define CARDPLAYER_H

#include "Player.h"
#include <string>
#include <iostream>

class CardPlayer : public Player
{
private:
	int m_aiHand[6];
	int m_aiGarden[5];
	std::string m_sName;
	int m_iScore;

public:
	CardPlayer();

	void Init(std::string dataString, int id, bool isHost);

	void SetHand(int aPos, int cPos);
	void SetGarden(int aPos, int cPos);
	void SetName(std::string);
	void SetScore(int);
	

	int GetHand(int aPos);
	int GetGarden(int aPos);
	std::string GetName();
	int GetScore();
};

#endif