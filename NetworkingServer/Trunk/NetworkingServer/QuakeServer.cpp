//Blake Sullivan - QuakeServer.cpp
#include "QuakeServer.h"

QuakeServer::QuakeServer()
{
	Init();
	RunServer();
}

void QuakeServer::RunServer()
{
	printf("Quake Server Running\n");
	do
	{
		if (CheckServer()==1)
		{cout << "Message Recieved And Dealt With.";}
	} while (GetQuit() == 0);
}

void QuakeServer::UseReceivedPacket(UDPpacket* rp)
{
	//cout << "(char *)m_ReceivedPacket->data[0]: " << (char *)m_ReceivedPacket->data[0] << endl;
	//if (!strcmp((char *)m_ReceivedPacket->data, "j") )
	if (!strcmp((char *)rp->data, "BRS"))
	{
		/* Quit if packet contains "quit" */
		if (!strcmp((char *)rp->data, "quit"))
			{SetQuit(1);}

		if ((char)((char *)rp->data[4])=='j')
		{JoinQuakePlayer(rp);}
		if ((char)((char *)rp->data[4])=='m')
		{MoveQuakePlayer(rp);}
	}

	UpdateMovement(rp);
}
void QuakeServer::JoinQuakePlayer(UDPpacket *play)
{
	cout << "In JoinQuakePlayer" << endl;
	int iQuakePlayer = FindFreeQuakePlayer();
	cout << "iQuakePlayer = " << iQuakePlayer << endl;
	if (iQuakePlayer >= 0)
	{
		m_aQuakePlayer[iQuakePlayer].Init((char*)play->data, iQuakePlayer);
		m_aQuakePlayer[iQuakePlayer].SetHost(play->address.host);
		m_aQuakePlayer[iQuakePlayer].SetPort(play->address.port);
		sprintf((char*)play->data, "BRS,J,%i,%f,%f,%i", 
				m_aQuakePlayer[iQuakePlayer].GetID(),
				m_aQuakePlayer[iQuakePlayer].GetX(),
				m_aQuakePlayer[iQuakePlayer].GetY(),
				m_aQuakePlayer[iQuakePlayer].GetDeg());
		play->len = strlen((char *)play->data) + 1;
		SendReply(play);
	}
}

int QuakeServer::FindFreeQuakePlayer()
{
	int iResult = -1;
	for (int i = 0; i < MSC_IMAXQUAKEPLAYERS; i++)
	{
		if (m_aQuakePlayer[i].GetID() == -1)
		{
			iResult = i;
			break;
		}
	}
	return iResult;
}

void QuakeServer::MoveQuakePlayer(UDPpacket *m)
{
	int QuakePlayerID = 0;
	std::string sData = (std::string)((char *)m->data);

	sData = sData.substr(sData.find(",") + 1, sData.length()); //clears out the letter identifer
	QuakePlayerID = atoi(sData.substr(0, sData.find(",")).c_str());
	sData = sData.substr(sData.find(",") + 1, sData.length());
	m_aQuakePlayer[QuakePlayerID].SetX(atof(sData.substr(0, sData.find(",")).c_str()));
	sData = sData.substr(sData.find(",") + 1, sData.length());
	m_aQuakePlayer[QuakePlayerID].SetY(atof(sData.substr(0, sData.find(",")).c_str()));
	sData = sData.substr(sData.find(",") + 1, sData.length());
	m_aQuakePlayer[QuakePlayerID].SetDeg(atoi(sData.substr(0, sData.find(",")).c_str()));
}

void QuakeServer::UpdateMovement(UDPpacket *play)
{
//	id = get id out pof pdata
//	for (i=0,i<10 i++)
//	{
//		if {m_ReceivedPacket[i] is in game && i !=id
//	m_ReceivedPacket->address.host = m_ReceivedPacket[i].hosdt;	/* Set the destination host */
//	m_ReceivedPacket->address.port = m_ReceivedPacket[i].port;	/* And destination port */
//
//	m_ReceivedPacket->len = strlen((char *)m_ReceivedPacket->data) + 1;
//	SDLNet_UDP_Send(m_Socket, -1, m_ReceivedPacket); /* This sets the m_ReceivedPacket->chan*/
//	}
	
	
	for (int i = 0; i < MSC_IMAXQUAKEPLAYERS; i++)
	{
		if (m_aQuakePlayer[i].GetInGame() == 1)
		{
			play->address.host = m_aQuakePlayer[i].GetHost();	/* Set the destination host */
			play->address.port = m_aQuakePlayer[i].GetPort();	/* And destination port */

			for (int j = 0; j < MSC_IMAXQUAKEPLAYERS; j++)
			{
				if (i != m_aQuakePlayer[j].GetID() && m_aQuakePlayer[j].GetInGame() == 1)
				{
					sprintf((char*)play->data, "M,%i,%f,%f,%i,%i,%i", 
							m_aQuakePlayer[j].GetID(),
							m_aQuakePlayer[j].GetX(),
							m_aQuakePlayer[j].GetY(),
							m_aQuakePlayer[j].GetDeg(),
							m_aQuakePlayer[j].GetAlive(),
							m_aQuakePlayer[j].GetInGame()
							);
					play->len = strlen((char *)play->data) + 1;
				
					//DisplayData(play);
					SendReply(play);
				}
			}
		}
	}

}