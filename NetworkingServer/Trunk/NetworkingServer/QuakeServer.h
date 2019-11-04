//Blake Sullivan - QuakeServer.h
#ifndef QUAKESERVER_H
#define QUAKESERVER_H

#include "NetworkServer.h"
#include "QuakePlayer.h"

class QuakeServer: public NetworkServer
{
private:
	static const int MSC_IMAXQUAKEPLAYERS = 8;
	QuakePlayer m_aQuakePlayer[MSC_IMAXQUAKEPLAYERS];

public:
	QuakeServer();

	virtual void RunServer();
	virtual void UseReceivedPacket(UDPpacket*);

	void JoinQuakePlayer(UDPpacket*);
	int FindFreeQuakePlayer();
	void MoveQuakePlayer(UDPpacket*);
	void UpdateMovement(UDPpacket*);
};
#endif