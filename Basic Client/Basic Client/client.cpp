#include <string>
#include <iostream>
using namespace std;
 
#include "SDL_net.h"

int port=2000; //the port the server is listening onto
char host[255]="255.255.255.255"; //"192.168.3.12"; //"127.0.0.1";

int main(int argc, char **argv)
{
	UDPsocket sd;
	IPaddress srvadd;
	UDPpacket *p;
	int quit;
	char sIP[255];
 
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
		fprintf(stderr, "SDLNet_AllocPacket: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}
	printf("Press [Enter] to search for Servers.\n");
	cin.get();
	cin.clear();

	int iCount = 0;
	char cInput[255];
	int iID = -1;
	char cUserName[255];

	do
	{
		iCount = 0;
		sprintf((char *)p->data, "@");
		p->address.host = srvadd.host;	/* Set the destination host */
		p->address.port = srvadd.port;	/* And destination port */
		p->len = strlen((char *)p->data) + 1;
		SDLNet_UDP_Send(sd, -1, p); /* This sets the p->channel */

		SDL_Delay(5000);

		while (SDLNet_UDP_Recv(sd, p))
		{
			sprintf(cInput, (char*)p->data);
			if (cInput[0] == '!')
			{
				iCount++;
				char* token = strtok(cInput, ",");
				token = strtok(NULL, "");
				printf("Server %d: %s: ", iCount, token);

				sprintf(sIP, "%d.%d.%d.%d", p->address.host&0xff, (p->address.host>>8)&0xff, (p->address.host>>16)&0xff, (p->address.host>>24)&0xff);
				cout << sIP << endl;
			}
			//cout << "You have successfully connected to the server.\n";
			//cout << "Your id is: " << iID << endl;
			//connected = true;
		}
		
		printf("What server do you wish to connect to? (0 to Search again.)\n");
		cin.getline(cInput, 255);
	}while (cInput[0] == '0');
	SDLNet_ResolveHost(&srvadd, cInput, port);
	printf("Server Selected.\n");

	printf("Please enter your name:\n");
	cin.getline(cUserName, 255);
	sprintf((char *)p->data, "$,%s", cUserName);
	p->address.host = srvadd.host;	/* Set the destination host */
	p->address.port = srvadd.port;	/* And destination port */

	p->len = strlen((char *)p->data) + 1;
	SDLNet_UDP_Send(sd, -1, p); /* This sets the p->channel */

	bool connected = false;
	while (!connected)
	{
		while (SDLNet_UDP_Recv(sd, p))
		{
			iID = atoi((char*)p->data);

			cout << "You have successfully connected to the server.\n";
			cout << "Your id is: " << iID << endl;
			connected = true;
		}
	}

	/* Main loop */
	quit = 0;
	while (!quit)
	{
		printf("Fill the buffer\n>");
		cin.getline(cInput, 255);
		sprintf((char *)p->data, "%d,%s", iID, cInput);
		//p->address.host = srvadd.host;	/* Set the destination host */
		//p->address.port = srvadd.port;	/* And destination port */
 
		p->len = strlen((char *)p->data) + 1;
		SDLNet_UDP_Send(sd, -1, p); /* This sets the p->channel */
 
		/* Quit if packet contains "quit" */
		if (!strcmp((char *)p->data, "quit"))
			quit = 1;
	}
 
	SDLNet_FreePacket(p);
	SDLNet_Quit();
 
	return EXIT_SUCCESS;
}