//Blake Sullivan - NetworkServer.h
#ifndef NETWORKSERVER_H
#define NETWORKSERVER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SDL_net.h"

class NetworkServer
{
protected:
	UDPsocket m_Socket;				/* Socket descriptor */
	UDPpacket *m_ReceivedPacket;    /* Pointer to packet memory for receiving*/
	UDPpacket *m_SendingPacket;		/* Pointer to packet memory for sending */
	int m_iQuit;

public:
	NetworkServer();

	virtual void Init();
	virtual void RunServer() = 0;
	virtual int CheckServer();
	virtual void UseReceivedPacket(UDPpacket*) = 0;
	virtual void QuitServer();
	virtual void SendReply(UDPpacket*);

	virtual void SetQuit(int);
	virtual int GetQuit();
};
#endif