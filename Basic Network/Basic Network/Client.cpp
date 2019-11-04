//Blake Sullivan - Client.cpp
#include "Client.h"

Client::Client()
{
	m_iPort = 0;
	m_sHost = "";
	m_sUserName = "";
	m_iID = 0;
	Init();
	RunClient();
}
Client::~Client()
{
	SDLNet_FreePacket(m_Packet);
	SDLNet_Quit();
}

void Client::Init()
{
	m_iPort = 2000;
	m_sHost = "255.255.255.255";

	/* Initialize SDL_net */
	if (SDLNet_Init() < 0)
	{
		fprintf(stderr, "SDLNet_Init: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}
 
	/* Open a socket on random port */
	if (!(m_Socket = SDLNet_UDP_Open(0)))
	{
		fprintf(stderr, "SDLNet_UDP_Open: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}
 
	/* Resolve server name  */
	if (SDLNet_ResolveHost(&m_SrvAdd, m_sHost.c_str(), m_iPort))
	{
		fprintf(stderr, "SDLNet_ResolveHost(%s %d): %s\n", m_sHost, m_iPort, SDLNet_GetError());
		exit(EXIT_FAILURE);
	}
 
	/* Allocate memory for the packet */
	if (!(m_Packet = SDLNet_AllocPacket(512)))
	{
		fprintf(stderr, "SDLNet_AllocPacket: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}
}
void Client::RunClient()
{
	char cInput[255];
	bool bExit = false;
	do
	{
		SearchForServer();
		printf("What server do you wish to connect to? (0 to Search again.)\n");
		cin.getline(cInput, 255);
		if (cInput[0] != '0')
		{
			ResolveServer(cInput);
			ConnectToServer();
			Chat();
		}
	} while (bExit == false);
}
void Client::SearchForServer()
{
	int iCount = 0;
	char cInput[255];
	char sIP[255];

	printf("Press [Enter] to search for Servers.\n");
	cin.get();
	cin.clear();

	sprintf((char *)m_Packet->data, "@");
	m_Packet->address.host = m_SrvAdd.host;	/* Set the destination host */
	m_Packet->address.port = m_SrvAdd.port;	/* And destination port */
	m_Packet->len = strlen((char *)m_Packet->data) + 1;
	SDLNet_UDP_Send(m_Socket, -1, m_Packet); /* This sets the p->channel */

	SDL_Delay(5000);

	while (SDLNet_UDP_Recv(m_Socket, m_Packet))
	{
		sprintf(cInput, (char*)m_Packet->data);
		if (cInput[0] == '!')
		{
			iCount++;
			char* token = strtok(cInput, ",");
			token = strtok(NULL, "");
			printf("Server %d: %s: ", iCount, token);

			sprintf(sIP, "%d.%d.%d.%d", m_Packet->address.host&0xff, 
										(m_Packet->address.host>>8)&0xff, 
										(m_Packet->address.host>>16)&0xff, 
										(m_Packet->address.host>>24)&0xff);
			cout << sIP << endl;
		}
	}
}
void Client::ResolveServer(char cInput[255])
{
	SDLNet_ResolveHost(&m_SrvAdd, cInput, m_iPort);
	printf("Server Selected.\n");
}
void Client::ConnectToServer()
{
	sprintf((char *)m_Packet->data, "$,%s", EnterUserName().c_str());
	m_Packet->address.host = m_SrvAdd.host;	/* Set the destination host */
	m_Packet->address.port = m_SrvAdd.port;	/* And destination port */

	m_Packet->len = strlen((char *)m_Packet->data) + 1;
	SDLNet_UDP_Send(m_Socket, -1, m_Packet); /* This sets the p->channel */

	bool connected = false;
	while (!connected)
	{
		while (SDLNet_UDP_Recv(m_Socket, m_Packet))
		{
			m_iID = atoi((char*)m_Packet->data);

			cout << "You have successfully connected to the server.\n";
			cout << "Your id is: " << m_iID << endl;
			connected = true;
		}
	}
}
string Client::EnterUserName()
{
	printf("Please enter your name: ");
	getline(cin, m_sUserName);
	return m_sUserName;
}

void Client::Chat()
{
	int quit;
	char cInput[255];
	/* Main loop */
	quit = 0;
	while (!quit)
	{
		printf("Fill the buffer\n>");
		cin.getline(cInput, 255);
		sprintf((char *)m_Packet->data, "%d,%s", m_iID, cInput);
		//p->address.host = srvadd.host;	/* Set the destination host */
		//p->address.port = srvadd.port;	/* And destination port */
 
		m_Packet->len = strlen((char *)m_Packet->data) + 1;
		SDLNet_UDP_Send(m_Socket, -1, m_Packet); /* This sets the p->channel */
 
		/* Quit if packet contains "quit" */
		if (!strcmp((char *)m_Packet->data, "quit"))
			quit = 1;
	}
}