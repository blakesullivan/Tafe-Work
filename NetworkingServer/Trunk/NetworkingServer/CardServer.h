//Blake Sullivan - CardServer.h
#ifndef CARDSERVER_H
#define CARDSERVER_H

#include "NetworkServer.h"
#include <iostream>
#include "CardPlayer.h"
class CardServer: public NetworkServer
{
private:
	enum CardLocations
	{
		clDeck = 0,
		clP1Hand = 1,
		clP1Garden = 2,
		clP2Hand = 3,
		clP2Garden = 4,
		clP3Hand = 5,
		clP3Garden = 6,
		clP4Hand = 7,
		clP4Garden = 8,
		clDiscard = 9
	};
	static const int MSC_IMAXCARDS = 51;
	int m_iDeckRemaining;
	int m_iCurrentStartPos;
	CardPlayer m_aCardPlayers[4];

public:
	CardServer();

	virtual void Init();
	virtual void RunServer();
	virtual void UseReceivedPacket(UDPpacket*);

	void SetupHost(UDPpacket*);
	void JoinPlayer(UDPpacket*, int isHost);
	void DealCard(int iHandPos);

	int FindFreePlayer();
	
};
#endif