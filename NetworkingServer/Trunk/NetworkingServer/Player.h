//Blake Sullivan - Player.h
#ifndef PLAYER_H
#define PLAYER_H

class Player
{
protected:
	int m_iID;
	int m_iInGame;
	//IPaddress m_IP;
	unsigned int m_uiHost;
	unsigned int m_uiPort;
	bool m_bIsHost;

public:
	Player();

	void SetID(int);
	void SetInGame(int);
	void SetHost(unsigned int);
	void SetPort(unsigned int);
	void SetIsHost(bool);

	int GetID();
	int GetInGame();
	unsigned int GetHost();
	unsigned int GetPort();
	bool GetIsHost();
};
#endif