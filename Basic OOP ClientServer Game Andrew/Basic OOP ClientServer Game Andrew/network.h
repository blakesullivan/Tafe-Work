#include "sdl_net.h"

#ifndef AG_NETWORK
#define AG_NETWORK

const int STRING_SIZE = 100;

enum NetworkPackets
{
	CLIENT_BROADCAST = 0,
	SERVER_RESPONSE = 1,
	CLIENT_NEW_USER = 2,
	SERVER_NEW_USER = 3,
	CLIENT_MESSAGE = 4,
	SERVER_MESSAGE = 5,
	PLAYER_UPDATE = 6,
	PLAYER_REFRESH = 7
};

#pragma pack(1)

struct basePacket
{
	int id;
};

#pragma pack(pop)

#pragma pack(1)

struct serverResponsePacket
{
	int id;
	char serverName[STRING_SIZE];
};

#pragma pack(pop)

#pragma pack(1)

struct connectPacket
{
	int id;
	char userName[STRING_SIZE];
};

#pragma pack(pop)

#pragma pack(1)

struct newUserPacket
{
	int id;
	int userID;
};

#pragma pack(pop)

#pragma pack(1)

struct messagePacket
{
	int id;
	int userID;
	char message[STRING_SIZE];
};

#pragma pack(pop)

#pragma pack(1)

struct movePacket
{
	int id;
	int x;
	int y;
	int userID;
};

#pragma pack(pop)

class NetManager
{
private:

	UDPsocket socket;
	UDPpacket* packet;

public:

	NetManager();
	~NetManager();
	void OpenPort(int);
	void AllocPacket(int);
	void SendString(char*,IPaddress);
	void SendStruct(basePacket*,int,IPaddress);
	IPaddress ResolveHost(char*,int);

	UDPsocket getSocket();
	UDPpacket* getPacket();
};

#endif