#include <string>
#include <iostream>
using namespace std;

#include "SDL_net.h"
 
int server(int argc, char **argv)
{
	UDPsocket sd;       /* Socket descriptor */
	UDPpacket *p;       /* Pointer to packet memory */
	int quit;
	char acUserNames[100][255];
	IPaddress aipAddress[100];
	int iMaxUsers = 100;
	int iNumConnected = 0;
	char cServerName[255];

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
 
	cout << "Please enter Server Name: ";
	cin.getline(cServerName, 255);

	printf("Server: %s is ready.\n", cServerName);

	char cBuffer[255];
	/* Main loop */
	quit = 0;
	while (!quit)
	{
		/* Wait a packet. UDP_Recv returns != 0 if a packet is coming */
		while (SDLNet_UDP_Recv(sd, p))
		{
			/*printf("UDP Packet incoming\n");
			printf("\tChan:    %d\n", p->channel);
			printf("\tData:    %s\n", (char *)p->data);
			printf("\tLen:     %d\n", p->len);
			printf("\tMaxlen:  %d\n", p->maxlen);
			printf("\tStatus:  %d\n", p->status);
			printf("\tAddress: %x %x\n", p->address.host, p->address.port);*/
			
			sprintf(cBuffer, (char*)p->data);
			//printf("%s\n", (char*)p->data);
			char cIP[255];
			sprintf(cIP, "%d.%d.%d.%d", p->address.host&0xff, (p->address.host>>8)&0xff, (p->address.host>>16)&0xff, (p->address.host>>24)&0xff);
			if (cBuffer[0] == '@')
			{
				cout << cIP << endl;
				printf("%s from: %s\n", (char*)p->data, cIP);
				sprintf((char*)p->data, "!,%s", cServerName);
				//p->address.host = aipAddress[iNumConnected].host;
				//p->address.port = aipAddress[iNumConnected].port;

				p->len = strlen((char *)p->data) + 1;
				SDLNet_UDP_Send(sd, -1, p); /* This sets the p->channel */
			}
			else if (cBuffer[0] == '$')
			{
				printf ("Connecting packet: %s from: %s\n", (char*)p->data, cIP);
				char* token = strtok(cBuffer,",");
				token = strtok(NULL, "");

				sprintf(acUserNames[iNumConnected], token);
				aipAddress[iNumConnected].host = p->address.host;
				aipAddress[iNumConnected].port = p->address.port;

				sprintf((char*)p->data, "%d", iNumConnected);
				p->address.host = aipAddress[iNumConnected].host;
				p->address.port = aipAddress[iNumConnected].port;

				p->len = strlen((char *)p->data) + 1;
				SDLNet_UDP_Send(sd, -1, p); /* This sets the p->channel */

				iNumConnected++;
			}
			else
			{
				char* token = strtok(cBuffer,",");
				int iCurrNum = atoi(token);
				token = strtok(NULL, "");
				sprintf(cBuffer, token);

				printf("%s > %s\n", acUserNames[iCurrNum], cBuffer);
				
			}
			
			/* Quit if packet contains "quit" */
			if (!strcmp((char *)p->data, "quit"))
				quit = 1;
		}		
	}
 
	/* Clean and exit */
	SDLNet_FreePacket(p);
	SDLNet_Quit();
	return EXIT_SUCCESS;
}