//Blake Sullivan - NetworkServer.cpp
#include "NetworkServer.h"
NetworkServer::NetworkServer()
{
	//Init();
	//RunServer();
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
	if (!(m_Socket = SDLNet_UDP_Open(2000)))
	{
		fprintf(stderr, "SDLNet_UDP_Open: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}
 
	/* Make space for the packet */
	if (!(m_ReceivedPacket = SDLNet_AllocPacket(512)))
	{
		fprintf(stderr, "SDLNet_AllocPacket: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}
	if (!(m_SendingPacket = SDLNet_AllocPacket(512)))
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
	while (SDLNet_UDP_Recv(m_Socket, m_ReceivedPacket))
	{
		iResult = 1;
		printf("UDP Packet incoming\n");
		printf("\tChan:    %d\n", m_ReceivedPacket->channel);
		printf("\tData:    %s\n", (char *)m_ReceivedPacket->data);
		printf("\tLen:     %d\n", m_ReceivedPacket->len);
		printf("\tMaxlen:  %d\n", m_ReceivedPacket->maxlen);
		printf("\tStatus:  %d\n", m_ReceivedPacket->status);
		printf("\tAddress: %x %x\n", m_ReceivedPacket->address.host, m_ReceivedPacket->address.port);

		UseReceivedPacket(m_ReceivedPacket);
	}
	//}
	return iResult;
}

void NetworkServer::QuitServer()
{
	/* Clean and exit */
	SDLNet_FreePacket(m_ReceivedPacket);
	SDLNet_FreePacket(m_SendingPacket);
	SDLNet_Quit();
}

void NetworkServer::SendReply(UDPpacket* m)
{
	//printf("Fill the buffer\n>");
	//scanf("%s", (char *)m_ReceivedPacket->data);

	//m_ReceivedPacket->address.host = srvadd.host;	/* Set the destination host */
	//m_ReceivedPacket->address.port = srvadd.port;	/* And destination port */

	//m_ReceivedPacket->len = strlen((char *)m_ReceivedPacket->data) + 1;
	SDLNet_UDP_Send(m_Socket, -1, m); /* This sets the m_ReceivedPacket->channel */
}

void NetworkServer::SetQuit(int q)
{
	m_iQuit = q;
}
int NetworkServer::GetQuit()
{
	return m_iQuit;
}