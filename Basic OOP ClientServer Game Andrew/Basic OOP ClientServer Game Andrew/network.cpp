#include "network.h"

NetManager::NetManager()
{
	/* Initialize SDL_net */
	if (SDLNet_Init() < 0)
	{
		fprintf(stderr, "SDLNet_Init: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}

	OpenPort(0);
	AllocPacket(512);

}

NetManager::~NetManager()
{
	/* Clean and exit */
	SDLNet_FreePacket(packet);
	SDLNet_Quit();
}

void NetManager::OpenPort(int port)
{
	if (!(socket = SDLNet_UDP_Open(port)))	// Random Port
	{
			fprintf(stderr, "SDLNet_UDP_Open: %s\n", SDLNet_GetError());
			exit(EXIT_FAILURE);
	}

}

void NetManager::AllocPacket(int size)
{
	if (!(packet = SDLNet_AllocPacket(size)))
	{
		fprintf(stderr, "SDLNet_AllocPacket: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}
}

IPaddress NetManager::ResolveHost(char* address, int port)
{
	IPaddress serverAddress;

	if (SDLNet_ResolveHost(&serverAddress, address, port) )
	{
			//fprintf(stderr, "SDLNet_ResolveHost(%s %d): %s\n", argv[1], atoi(argv[2]), SDLNet_GetError());
			exit(EXIT_FAILURE);
	}

	return serverAddress;
}

void NetManager::SendString(char* message, IPaddress destination)
{
	sprintf((char*)packet->data,message);

	packet->address.host = destination.host;	
	packet->address.port = destination.port;				
	packet->len = strlen((char *)packet->data) + 1;
	SDLNet_UDP_Send(socket, -1, packet);	// Sends packet
}

void NetManager::SendStruct(basePacket* pData, int size,IPaddress destination)
{
	memcpy(packet->data,pData,size);

	packet->address.host = destination.host;	
	packet->address.port = destination.port;				
	packet->len = size + 1;
	SDLNet_UDP_Send(socket, -1, packet);	// Sends packet

}

UDPsocket NetManager::getSocket()
{
	return socket;
}

UDPpacket* NetManager::getPacket()
{
	return packet;
}