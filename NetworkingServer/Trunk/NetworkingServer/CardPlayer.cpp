//Blake Sullivan - CardPlayer.cpp
#include "CardPlayer.h"

CardPlayer::CardPlayer()
{
	for (int i = 0; i < 6; i++)
	{
		SetHand(i, 0);
		if (i < 5) {SetGarden(i, 0);}
	}
	SetName("");
	SetScore(0);
}

void CardPlayer::Init(std::string dataString, int id, bool isHost)
{
	std::string sTemp = "";
	sTemp = dataString.substr(6, dataString.length());
	std::cout << "sTemp: " << sTemp << std::endl;
	SetName(sTemp.substr(0, sTemp.find(",")).c_str());

	SetID(id);
	SetIsHost(isHost);
}

void CardPlayer::SetHand(int aPos, int cPos)
{
	m_aiHand[aPos] = cPos;
}
void CardPlayer::SetGarden(int aPos, int cPos)
{
	m_aiGarden[aPos] = cPos;
}
void CardPlayer::SetName(std::string n)
{
	m_sName = n;
}
void CardPlayer::SetScore(int s)
{
	m_iScore = s;
}

int CardPlayer::GetHand(int aPos)
{
	return m_aiHand[aPos];
}
int CardPlayer::GetGarden(int aPos)
{
	return m_aiGarden[aPos];
}
std::string CardPlayer::GetName()
{
	return m_sName;
}
int CardPlayer::GetScore()
{
	return m_iScore;
}