#ifndef PACKETHEADER_H
#define PACKETHEADER_H

enum NetworkPackets
{
	CLIENT_BROADCAST = 0,
	SERVER_RESPONSE = 1,
	CLIENT_NEW_USER = 2,
	SERVER_NEW_USER = 3,
	CLIENT_MESSAGE = 4,
	SERVER_MESSAGE = 5
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
	char serverName[255];
};
#pragma pack(pop)

#pragma pack(1)
struct connectPacket
{
	int id;
	char userName[255];
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
	char message[255];
};
#pragma pack(pop)

#endif