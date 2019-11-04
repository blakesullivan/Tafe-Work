//Blake Sullivan - NetworkServer.h
#ifndef NETWORKSERVER_H
#define NETWORKSERVER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#include "SDL_net.h"

class NetworkServer
{
private:
	UDPsocket sd;       /* Socket descriptor */
	UDPpacket *p;       /* Pointer to packet memory */
	int m_iQuit;

public:
	NetworkServer();

	void Init();
	int CheckServer();
	void QuitServer();

	void SetQuit(int);
	int GetQuit();
};
#endif