//Blake Sullivan - NetworkClient.h
#include "NetworkClient.h"

NetworkClient::NetworkClient()
{
	 Init();
}

void NetworkClient::Init()
{
	SetPort(2000); //the port the server is listening onto
	SetHost("127.0.0.1");

	/* Initialize SDL_net */
	if (SDLNet_Init() < 0)
	{
		fprintf(stderr, "SDLNet_Init: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}
 
	/* Open a socket on random port */
	if (!(sd = SDLNet_UDP_Open(0)))
	{
		fprintf(stderr, "SDLNet_UDP_Open: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}
 
	/* Resolve server name  */
	if (SDLNet_ResolveHost(&srvadd, host, port))
	{
		fprintf(stderr, "SDLNet_ResolveHost(%s %d): %s\n", host, port, SDLNet_GetError());
		exit(EXIT_FAILURE);
	}
 
	/* Allocate memory for the packet */
	if (!(p = SDLNet_AllocPacket(512)))
	{
		fprintf(stderr, "p: SDLNet_AllocPacket: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}
	if (!(r = SDLNet_AllocPacket(512)))
	{
		fprintf(stderr, "r: SDLNet_AllocPacket: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}

}

int NetworkClient::Run()
{
	//int quit, 

	/* Main loop */
	//quit = 0;
	//while (!quit)
	//{
		
		Send();
		Receive();
		/* Quit if packet contains "quit" */
		//if (!strcmp((char *)p->data, "quit"))
			//quit = 1;
	//}
	return EXIT_SUCCESS;
}

void NetworkClient::Send()
{
	printf("Fill the buffer\n>");
	scanf("%s", (char *)p->data);

	p->address.host = srvadd.host;	/* Set the destination host */
	p->address.port = srvadd.port;	/* And destination port */

	p->len = strlen((char *)p->data) + 1;
	SDLNet_UDP_Send(sd, -1, p); /* This sets the p->channel */
}

void NetworkClient::Send(int id, float x, float y, int dir)
{
	//printf("Fill the buffer\n>");
	//scanf("%s", (char *)p->data);
	sprintf((char *)p->data, "m,%i,%f,%f,%i", id, x, y, dir);
	
	std::cout << "Data: " << p->data << std::endl;
	//cout << "X= " << x << " Y= " <<  y << endl;

	p->address.host = srvadd.host;	/* Set the destination host */
	p->address.port = srvadd.port;	/* And destination port */

	p->len = strlen((char *)p->data) + 1;
	SDLNet_UDP_Send(sd, -1, p); /* This sets the p->channel */
}

void NetworkClient::Send(int id, int cID)
{
	//printf("Fill the buffer\n>");
	//scanf("%s", (char *)p->data);
	sprintf((char *)p->data, "j,%i,%i", id, cID);
	
	std::cout << "Data: " << p->data << std::endl;
	//cout << "X= " << x << " Y= " <<  y << endl;

	p->address.host = srvadd.host;	/* Set the destination host */
	p->address.port = srvadd.port;	/* And destination port */

	p->len = strlen((char *)p->data) + 1;
	SDLNet_UDP_Send(sd, -1, p); /* This sets the p->channel */
}

bool NetworkClient::Receive()
{
	bool iReceive = false;
	//int iExit = 0;
	//do
	//{
	if (SDLNet_UDP_Recv(sd, r))
	{
		iReceive = true;
		printf("UDP Packet incoming\n");
		printf("\tChan:    %d\n", r->channel);
		printf("\tData:    %s\n", (char *)r->data);
		printf("\tLen:     %d\n", r->len);
		printf("\tMaxlen:  %d\n", r->maxlen);
		printf("\tStatus:  %d\n", r->status);
		printf("\tAddress: %x %x\n", r->address.host, r->address.port);
		//iExit = 1;

		if ((char)((char *)r->data[0])=='j')
		{
			std::cout << "Got join back" << std::endl;
			//JoinPlayer(r);
		}
	}

	return iReceive;
	//}while (!iExit);
}

void NetworkClient::SetPort(int p)
{
	port = p;
}

void NetworkClient::SetHost(char h[])
{
	//cout << h << endl;
	for (int i = 0; i < 255; i++)
	{
		host[i] = h[i];
	}
}

void NetworkClient::Dispose()
{
	SDLNet_FreePacket(p);
	SDLNet_FreePacket(r);
	SDLNet_Quit();
}

UDPpacket* NetworkClient::GetResponse()
{
	return r;
}