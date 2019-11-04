//Blake Sullivan - Client.h
#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <iostream>
using namespace std;
 
#include "SDL_net.h"

class Client
{
private:
	int m_iPort;
	string m_sHost;
	string m_sUserName;
	int m_iID;

	UDPsocket m_Socket;
	IPaddress m_SrvAdd;
	UDPpacket *m_Packet;

public:
	Client();
	~Client();

	void Init();
	void RunClient();
	void SearchForServer();
	void ResolveServer(char cInput[255]);
	void ConnectToServer();
	string EnterUserName();
	void Chat();
};

#endif