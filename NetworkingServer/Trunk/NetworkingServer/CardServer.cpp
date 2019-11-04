//Blake Sullivan - CardServer.cpp
#include "CardServer.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

CardServer::CardServer()
{
	Init();
	RunServer();
}

void CardServer::Init()
{
	NetworkServer::Init();
	m_iCurrentStartPos = 0;
	m_iDeckRemaining = MSC_IMAXCARDS;
	
	srand(time(NULL));
}

void CardServer::RunServer()
{
	printf("Card Server Running\n");
	do
	{
		if (CheckServer()==1)
			{std::cout << "Message Recieved And Dealt With.\n";}
	} while (GetQuit() == 0);
}

void CardServer::UseReceivedPacket(UDPpacket* rp)
{
	std::cout << "In CardServer::UseReceivedPacket\n"; 
	if ((char)((char *)rp->data[0])=='B' && (char)((char *)rp->data[1])=='R' && (char)((char *)rp->data[2])=='S')
	{
		std::cout << "Inside the IF\n"; 
		/* Quit if packet contains "quit" */
		if (!strcmp((char *)rp->data, "quit"))
			{SetQuit(1);}

		if ((char)((char *)rp->data[4])=='h')
			{JoinPlayer(rp, 0);}
		if ((char)((char *)rp->data[4])=='j')
			{JoinPlayer(rp, 1);}
	}
}

void CardServer::SetupHost(UDPpacket* hp)
{
	int iPlayer = FindFreePlayer();
	if (iPlayer >= 0)
	{
		sprintf((char*)m_SendingPacket->data, "BRS,J,%i,%i",iPlayer,1);
		printf("Sending Data: ");
		printf((char*)m_SendingPacket->data);
		m_aCardPlayers[iPlayer].Init((char*)m_SendingPacket->data, iPlayer, true);
		m_aCardPlayers[iPlayer].SetHost(hp->address.host);
		m_aCardPlayers[iPlayer].SetPort(hp->address.port);
	}
	else
	{
		sprintf((char*)m_SendingPacket->data, "BRS,M,%s", "No Free Players");
	}
	m_SendingPacket->address.host = hp->address.host;	/* Set the destination host */
	m_SendingPacket->address.port = hp->address.port;	/* And destination port */
	m_SendingPacket->len = strlen((char *)m_SendingPacket->data) + 1;
	SendReply(m_SendingPacket);
}

void CardServer::JoinPlayer(UDPpacket* jp, int isHost)
{
	int iPlayer = FindFreePlayer();
	if (iPlayer >= 0)
	{
		sprintf((char*)m_SendingPacket->data, "BRS,J,%i,%i",iPlayer,isHost);
		std::cout << "Sending Data: " << (char*)m_SendingPacket->data << std::endl;
		m_aCardPlayers[iPlayer].Init((char*)jp->data, iPlayer, isHost);
		m_aCardPlayers[iPlayer].SetHost(jp->address.host);
		m_aCardPlayers[iPlayer].SetPort(jp->address.port);
	}
	else
	{
		sprintf((char*)m_SendingPacket->data, "BRS,M,%s", "No Free Players");
	}
	m_SendingPacket->address.host = jp->address.host;	/* Set the destination host */
	m_SendingPacket->address.port = jp->address.port;	/* And destination port */
	m_SendingPacket->len = strlen((char *)m_SendingPacket->data) + 1;
	SendReply(m_SendingPacket);
}

int CardServer::FindFreePlayer()
{
	for (int i = 0; i < 4; i++)
	{
		if (m_aCardPlayers[i].GetName() == "")
			{return i;}
	}
	return -1;
}