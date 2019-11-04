//Blake Sullivan - 
#include "NetworkServer.h"
NetworkServer::NetworkServer()
{
}

void NetworkServer::Init()
{
	/* Initialize SDL_net */
	if (SDLNet_Init() < 0)
	{
		fprintf(stderr, "SDLNet_Init: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}
 
	/* Open a socket */
	if (!(sd = SDLNet_UDP_Open(2000)))
	{
		fprintf(stderr, "SDLNet_UDP_Open: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}
 
	/* Make space for the packet */
	if (!(p = SDLNet_AllocPacket(512)))
	{
		fprintf(stderr, "SDLNet_AllocPacket: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}

	SetQuit(0);
}

int NetworkServer::CheckServer()
{	
	int iResult = 0;
	/* Main loop */
	//while (!quit)
	//{
	/* Wait a packet. UDP_Recv returns != 0 if a packet is coming */
	if (SDLNet_UDP_Recv(sd, p))
	{
		iResult = 1;
		printf("UDP Packet incoming\n");
		printf("\tChan:    %d\n", p->channel);
		printf("\tData:    %s\n", (char *)p->data);
		printf("\tLen:     %d\n", p->len);
		printf("\tMaxlen:  %d\n", p->maxlen);
		printf("\tStatus:  %d\n", p->status);
		printf("\tAddress: %x %x\n", p->address.host, p->address.port);

		/* Quit if packet contains "quit" */
		if (!strcmp((char *)p->data, "quit"))
			SetQuit(1);
	}
	//}
	return iResult;
}

void NetworkServer::QuitServer()
{
	/* Clean and exit */
	SDLNet_FreePacket(p);
	SDLNet_Quit();
}

void NetworkServer::SetQuit(int q)
{
	m_iQuit = q;
}
int NetworkServer::GetQuit()
{
	return m_iQuit;
}