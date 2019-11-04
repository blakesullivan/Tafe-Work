#ifndef NETWORKCLIENT_H
#define NETWORKCLIENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
//using namespace std;
#include "SDL_net.h"

class NetworkClient
{
private:
	int port; //the port the server is listening onto
	char host[255];
	UDPsocket sd;
	IPaddress srvadd;
	UDPpacket *p, *r;
	
public:
	NetworkClient();

	void Init();
	int Run();
	void Send();
	void Send(int, float, float, int);
	void Send(int, int);
	bool Receive();

	void JoinServer(UDPpacket* r);

	void Dispose();

	void SetPort(int);
	void SetHost(char[]);

	UDPpacket* GetResponse();
};

#endif