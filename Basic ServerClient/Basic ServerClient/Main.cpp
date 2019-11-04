//Blake Sullivan - Main.cpp

#include "SDL.h"   /* All SDL App's need this */
#include <stdio.h>
#include <stdlib.h>
#include "SDL_gfxPrimitives.h" 

#include <string>
#include <iostream>
using namespace std;
 
#include "SDL_net.h"

int port=2000; //the port the server is listening onto
char host[255]="255.255.255.255"; //"192.168.3.12"; //"127.0.0.1";

//The attributes of the screen 
const int SCREEN_WIDTH = 800; 
const int SCREEN_HEIGHT = 600; 
const int SCREEN_BPP = 32; //Bits Per Pixel

SDL_Surface *screen = NULL; //the pointer to the screen in memory

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

int main(int argc, char **argv)
{
	UDPsocket sd;       /* Socket descriptor */
	UDPpacket *packet;       /* Pointer to packet memory */
	int quit;
	char acUserNames[100][255];
	IPaddress aipAddress[100];
	int iMaxUsers = 100;
	int iNumConnected = 0;
	char cServerName[255];
	IPaddress srvadd;
	char sIP[255];
	int iCount = 0;
	char cInput[255];
	int iID = -1;
	char cUserName[255];
	int iClientState = 0;
	// 0 - Refresh Server List page
	// 1 - Input name and connect
	// 2 - Connected to server and sending messages
	SDL_Event event;
	bool bgameRunning= true;
	bool keysHeld[323];
	int chNum = 0;
	char cStringBuffer[255];
	bool bReturn = false;

	int iNumServers = 0;
	char cServerIP[255];
	char caServers[100][255];

	char acMessages[20][255]; //array of messages
	
	basePacket* pData;
	serverResponsePacket* srData;
	connectPacket* cpData;
	newUserPacket* nuData;
	messagePacket* mData;

	string sInput = "";
	cout << "Client or Server? (c or s)\n";
	getline(cin, sInput);
	if (sInput == "c")
	{
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
		if (!(packet = SDLNet_AllocPacket(512)))
		{
			fprintf(stderr, "SDLNet_AllocPacket: %s\n", SDLNet_GetError());
			exit(EXIT_FAILURE);
		}

		for (int i=0; i<323; i++)
			{keysHeld[i] = false;} // everything will be initialized to false
		
		//Initialize all SDL subsystems 
		if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 ) 
		{ return 1; } 

		//Set up the screen 
		screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE ); 
		//If there was an error in setting up the screen 
		if(screen == NULL) {return 1;}
		//Set the window caption 
		SDL_WM_SetCaption( "SDL Network Client", NULL ); 

		chNum = 0;
		for (int i = 0; i < 255; i++)
			{cStringBuffer[i] = NULL;}

		while (iClientState != -1)
		{
			// check for any events from the user or the system
			SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0, 0, 200 ) ); 
			if (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
				{
					iClientState = -1;
				}
				if (event.type == SDL_KEYDOWN)
				{
					keysHeld[event.key.keysym.sym] = true;
					switch(event.key.keysym.sym)
					{
						case SDLK_BACKSPACE:
						{
							if (chNum > 0)
							{
								chNum--;
								cStringBuffer[chNum] = 0;
							}
						}
						break;
						case SDLK_RETURN:
						{
							chNum = 0;
							bReturn = true;
						}
						break;
						case SDLK_KP_ENTER:
						{
							chNum = 0;
							bReturn = true;
						}
						break;
						default:
						{
							cStringBuffer[chNum] = event.key.keysym.sym;
							chNum++;
						}
						break;
					}
				}
				if (event.type == SDL_KEYUP)
				{
					keysHeld[event.key.keysym.sym] = false;
				}
			}

			stringRGBA(screen, 10, 30, cStringBuffer, 255, 255, 255, 255);

			if (iClientState == 0)//Refresh Server List page
			{
				//cout << "chNum: " << chNum << endl;
				//cout << "cStringBuffer: " << cStringBuffer << endl;
				int i;
				//if (bReturn == false)
				//{
				stringRGBA(screen, 10, 10, "Press 'R' to search for Servers.", 255, 255, 255, 255);
					//printf("Press [Enter] to search for Servers.\n");
					//cin.get();
					//cin.clear();
					//printf("Searching...\n");
				//}
				for (i = 0; i < iNumServers; i++)
				{
					stringRGBA(screen, 10, 50, "Sever Results:", 255, 255, 255, 255);
					sprintf(cInput, "%i: %s", i, caServers[i]);
					stringRGBA(screen, 10, (i * 20) + 60, cInput, 255, 255, 255, 255);
				}
				if (i > 0) {stringRGBA(screen, 10, (i * 20) + 60, "What server do you wish to connect to? (Server Number)", 255, 255, 255, 255);}

				if (bReturn == true)
				{
					bReturn = false;

					sprintf(cInput, cStringBuffer);

					if (cInput[0] == 'r' || cInput[0] == 'R')
					{
						iCount = 0;
						//sprintf((char *)packet->data, "@");
						//packet->len = strlen((char *)packet->data) + 1;

						pData = new basePacket();

						pData->id = CLIENT_BROADCAST;

						//packet->data = (Uint8*)pData;
						memcpy(packet->data, pData, sizeof(*pData));
						packet->len = sizeof(*pData) + 1;

						packet->address.host = srvadd.host;	/* Set the destination host */
						packet->address.port = srvadd.port;	/* And destination port */
						
						SDLNet_UDP_Send(sd, -1, packet); /* This sets the p->channel */
						
						delete[] pData;

						SDL_Delay(5000);

						iNumServers = 0;
						while (SDLNet_UDP_Recv(sd, packet))
						{
							//sprintf(cInput, (char*)packet->data);
							//if (cInput[0] == '!')
							srData = (serverResponsePacket*)packet->data;

							if (srData->id = SERVER_RESPONSE)
							{
								iCount++;
								//char* token = strtok(cInput, ",");
								//token = strtok(NULL, "");
								//printf("Server %d: %s: ", iCount, token);
								//stringRGBA(screen, 10, (20 * iCount) + 50, token, 255, 255, 255, 255);

								

								sprintf(sIP, "%d.%d.%d.%d", packet->address.host&0xff, (packet->address.host>>8)&0xff, (packet->address.host>>16)&0xff, (packet->address.host>>24)&0xff);
								//cout << sIP << endl;
								aipAddress[iNumServers] = packet->address;
								
								//sprintf(caServers[iNumServers], "%s - %s", token, sIP);

								sprintf(caServers[iNumServers], "%s - %s", srData->serverName, sIP);
								iNumServers++;

								//stringRGBA(screen, 10, (20 * iCount) + 50, sIP, 255, 255, 255, 255);
							}
							//cout << "You have successfully connected to the server.\n";
							//cout << "Your id is: " << iID << endl;
							//connected = true;

						}
					}
					else
					{
						//printf("What server do you wish to connect to? (0 to Search again.)\n");
						//cin.getline(cInput, 255);
						SDLNet_ResolveHost(&srvadd, cInput, port);
						//printf("Server Selected.\n");
						iClientState = 1;
						for (int i = 0; i < 255; i++)
							{cStringBuffer[i] = NULL;}
						//bReturn = false;
					}
				}
				/*for (int i = 0; i < 255; i++)
					{cStringBuffer[i] = NULL;}*/
			}
			else if (iClientState == 1) //Input name and connect
			{
				//printf("Please enter your name:\n");
				stringRGBA(screen, 10, 10, "Please enter your name:", 255, 255, 255, 255);

				sprintf(cInput, cStringBuffer);

				if (bReturn == true)
				{
					bReturn = false;
					cpData = new connectPacket();
					cpData->id = CLIENT_NEW_USER;
					sprintf(cpData->userName, cInput);

					//packet->data = (Uint8*)cpData;
					memcpy(packet->data, cpData, sizeof(*cpData));
					packet->len = sizeof(*cpData) + 1;
					//sprintf((char *)packet->data, "$,%s", cInput);
					//packet->len = strlen((char *)packet->data) + 1;
					packet->address.host = srvadd.host;	/* Set the destination host */
					packet->address.port = srvadd.port;	/* And destination port */

					SDLNet_UDP_Send(sd, -1, packet); /* This sets the p->channel */

					delete[] cpData;

					bool connected = false;
					while (!connected)
					{
						while (SDLNet_UDP_Recv(sd, packet))
						{
							//iID = atoi((char*)packet->data);
							//nuData = new newUserPacket;
							nuData = (newUserPacket*)packet->data;
							iID = nuData->userID;

							cout << "You have successfully connected to the server.\n";
							cout << "Your id is: " << iID << endl;
							connected = true;
							iClientState = 2;
							for (int i = 0; i < 255; i++)
								{cStringBuffer[i] = NULL;}
						}
					}
				}
				//cin.getline(cUserName, 255);
				//sprintf((char *)p->data, "$,%s", cUserName);
				//p->address.host = srvadd.host;	/* Set the destination host */
				//p->address.port = srvadd.port;	/* And destination port */

				//p->len = strlen((char *)p->data) + 1;
				//SDLNet_UDP_Send(sd, -1, p); /* This sets the p->channel */
			}
			else if (iClientState == 2)
			{
				/* Main loop */
				//quit = 0;
				//while (!quit)
				//{
				stringRGBA(screen, 10, 10, "Fill the Buffer:", 255, 255, 255, 255);

				sprintf(cInput, cStringBuffer);

				if (bReturn == true)
				{
					bReturn = false;
					
					mData = new messagePacket();

					mData->id = CLIENT_MESSAGE;
					mData->userID = iID;
					sprintf(mData->message, cInput);
					
					//packet->data = (Uint8*)mData->message;
					memcpy(packet->data, mData, sizeof(*mData));
					packet->len = sizeof(*mData) + 1;
					//sprintf((char *)packet->data, "%d,%s", iID, cInput);
					//packet->len = strlen((char *)packet->data) + 1;
					SDLNet_UDP_Send(sd, -1, packet); /* This sets the p->channel */
					
					delete[] mData;

					if (cInput[0] == 'q' && cInput[1] == 'u' && cInput[2] == 'i' &&cInput[3] == 't')
					{
						iClientState = -1;
					}
					for (int i = 0; i < 255; i++)
						{cStringBuffer[i] = NULL;}
				}
				
				if (SDLNet_UDP_Recv(sd, packet))
				{
					//printf("%s\n", (char *)packet->data);
					messagePacket* smData = (messagePacket*)packet->data;

					cout << "Data: " << smData->message << endl;
					if (smData->id == SERVER_MESSAGE)
					{
						for (int mNum = 19; mNum > 0; mNum--)
						{
							strcpy(acMessages[mNum], acMessages[mNum-1]);
						}
						sprintf(acMessages[0], smData->message);
					}
				}
				
				for (int j = 0; j < 20; j++)
				{
					stringRGBA(screen, 10, (SCREEN_HEIGHT - 20) - (j * 20), acMessages[j], 255, 255, 255, 255);
				}
					//printf("Fill the buffer\n>");
					//cin.getline(cInput, 255);
					//sprintf((char *)p->data, "%d,%s", iID, cInput);
					////p->address.host = srvadd.host;	/* Set the destination host */
					////p->address.port = srvadd.port;	/* And destination port */
			 
					//p->len = strlen((char *)p->data) + 1;
					//SDLNet_UDP_Send(sd, -1, p); /* This sets the p->channel */
			 
					///* Quit if packet contains "quit" */
					//if (!strcmp((char *)p->data, "quit"))
					//{
					//	quit = 1;
					//	iClientState = -1;
					//}
				//}
			}
			//Update the screen 
			if( SDL_Flip( screen ) == -1 ) { return 1; } 
		} //End While

		SDLNet_FreePacket(packet);
		SDLNet_Quit();
		SDL_Quit();

		return EXIT_SUCCESS;
	}
	else	//Server start
	{
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
		if (!(packet = SDLNet_AllocPacket(512)))
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
			while (SDLNet_UDP_Recv(sd, packet))
			{
				/*printf("UDP Packet incoming\n");
				printf("\tChan:    %d\n", p->channel);
				printf("\tData:    %s\n", (char *)p->data);
				printf("\tLen:     %d\n", p->len);
				printf("\tMaxlen:  %d\n", p->maxlen);
				printf("\tStatus:  %d\n", p->status);
				printf("\tAddress: %x %x\n", p->address.host, p->address.port);*/
				
				//sprintf(cBuffer, (char*)packet->data);
				//printf("%s\n", (char*)p->data);

				basePacket* tempData = (basePacket*)packet->data;

				printf("Packet reveived: ID = %d\n", tempData->id);

				char cIP[255];
				sprintf(cIP, "%d.%d.%d.%d", packet->address.host&0xff, (packet->address.host>>8)&0xff, (packet->address.host>>16)&0xff, (packet->address.host>>24)&0xff);
				if (tempData->id == CLIENT_BROADCAST)//(cBuffer[0] == '@')
				{
					//cout << cIP << endl;
					//printf("%s from: %s\n", (char*)packet->data, cIP);
					//sprintf((char*)packet->data, "!,%s", cServerName);
					//packet->len = strlen((char *)packet->data) + 1;
					//p->address.host = aipAddress[iNumConnected].host;
					//p->address.port = aipAddress[iNumConnected].port;

					srData = new serverResponsePacket();
					srData->id = SERVER_RESPONSE;
					sprintf(srData->serverName, cServerName);
					//packet->data = (Uint8*)srData;
					memcpy(packet->data, srData, sizeof(*srData));
					packet->len = sizeof(*srData) + 1;

					SDLNet_UDP_Send(sd, -1, packet); /* This sets the p->channel */
					delete[] srData;
				}
				else if (tempData->id == CLIENT_NEW_USER)
				{
				//else if (cBuffer[0] == '$')
				//{
				//	printf ("Connecting packet: %s from: %s\n", (char*)packet->data, cIP);
				//	char* token = strtok(cBuffer,",");
				//	token = strtok(NULL, "");
					cpData = (connectPacket*)packet->data;

					printf ("Connecting packet: %s from: %s\n", cpData->userName, cIP);

					sprintf(acUserNames[iNumConnected], cpData->userName);
				//	sprintf(acUserNames[iNumConnected], token);
					aipAddress[iNumConnected].host = packet->address.host;
					aipAddress[iNumConnected].port = packet->address.port;
					
					nuData = new newUserPacket();
					nuData->id = SERVER_NEW_USER;
					nuData->userID = iNumConnected;

					//packet->data = (Uint8*)nuData;
					memcpy(packet->data, nuData, sizeof(*nuData));
					packet->len = sizeof(*nuData) + 1;
				//	sprintf((char*)packet->data, "%d", iNumConnected);
				//	packet->len = strlen((char *)packet->data) + 1;

					packet->address.host = aipAddress[iNumConnected].host;
					packet->address.port = aipAddress[iNumConnected].port;

					SDLNet_UDP_Send(sd, -1, packet); /* This sets the p->channel */
					delete[] nuData;

					iNumConnected++;
				}
				else if (tempData->id == CLIENT_MESSAGE) //Normal Message
				{
				//	//printf((char *)p->data);
				//	char* token = strtok(cBuffer,",");
				
				//	token = strtok(NULL, "");
				//	sprintf(cBuffer, token);
					messagePacket* mData = (messagePacket*)packet->data;
					int iCurrNum = mData->userID;

					printf("%s > %s\n", acUserNames[iCurrNum], mData->message);

				//	sprintf(cStringBuffer, "%s > %s", acUserNames[iCurrNum], cBuffer);
					sprintf(cStringBuffer, "%s > %s", acUserNames[iCurrNum], mData->message);
					printf("Sending to User: %s\n", cStringBuffer);

					for(int i = 0; i < iNumConnected; i++)
					{
						messagePacket* smData = new messagePacket();

						smData->id = SERVER_MESSAGE;
						sprintf(smData->message, cStringBuffer);

						cout << "Data message: " << smData->message << endl;

						//packet->data = (Uint8*)mData->message;
						memcpy(packet->data, smData, sizeof(*smData));
						packet->len = sizeof(*smData) + 1;
				//		sprintf((char*)packet->data, "%s", cStringBuffer);
						packet->address.host = aipAddress[i].host;
						packet->address.port = aipAddress[i].port;

				//		packet->len = strlen((char *)packet->data) + 1;
						SDLNet_UDP_Send(sd, -1, packet); /* This sets the p->channel */
						delete[] smData;
					}
				//
				}
				
				/* Quit if packet contains "quit" */
				if (!strcmp((char *)packet->data, "quit"))
					quit = 1;
			}		
		}
	 
		/* Clean and exit */
		SDLNet_FreePacket(packet);
		SDLNet_Quit();
		SDL_Quit();
		return EXIT_SUCCESS;
	}
}