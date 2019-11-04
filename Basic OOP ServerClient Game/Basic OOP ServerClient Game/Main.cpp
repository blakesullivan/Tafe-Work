#include "SDL.h"   /* All SDL App's need this */
#include <stdio.h>
#include <stdlib.h>
#include "SDL_gfxPrimitives.h" 

#include <iostream>
#include <string>
using namespace std;

#include "Network.h"
#include "Player.h"

int port = 2000;
char host[255] = "255.255.255.255";

//The attributes of the screen 
const int SCREEN_WIDTH = 800; 
const int SCREEN_HEIGHT = 600; 
const int SCREEN_BPP = 32; //Bits Per Pixel

SDL_Surface *screen = NULL; //the pointer to the screen in memory

int main(int argc, char *argv[]) {
	SDL_Event event;
	bool bgameRunning= true;
	bool keysHeld[323];

	NetManager NM;

	IPaddress userAddress[10];
	IPaddress serverAddress;

	int iNumUsers = 1;
	int iNumServers = 0;

	char userName[STRING_SIZE];
	int iUserNum = 0;

	int iClientState = 0;
	// 0 looking for server
	// 1 input name
	// 2 wait for response from server
	// 3 connected to server

	char cMessageBuffer[20][STRING_SIZE];

	char cTestString[STRING_SIZE] = "";
	char cTempString[STRING_SIZE];
	int iNetState = -1;

	int iPlayerNum = 0;
	bool bReturn = false;
	int iChoice = -1;

	Player aPlayer[10];

	cout << "Do you want to be the (c)lient or (s)erver?" << endl;
	cin.getline(cTempString, 100);

	if (cTempString[0] == 'c' || cTempString[0] == 'C')
	{
		iNetState = 0;
		iClientState = 0;

		NM.OpenPort(0);

		serverAddress = NM.ResolveHost("127.0.0.1", 2000);

		connectPacket* cData = new connectPacket();

		cData->id = CLIENT_NEW_USER;

		NM.SendStruct((basePacket*)cData, serverAddress, sizeof(*cData));

		delete[] cData;
	}
	else
	{
		iNetState = 1;
		iClientState = 1;
		NM.OpenPort(2000);
		aPlayer[0].SetAlive(true);
	}

	for (int i=0; i<322; i++)
	{
		keysHeld[i] = false; // everything will be initialized to false
	}
    //Initialize all SDL subsystems 
	if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 ) 
	{ return 1; } 

    //Set up the screen 
	screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE ); 
	//If there was an error in setting up the screen 
	if( screen == NULL ) { return 1; } 
	//Set the window caption 
	SDL_WM_SetCaption( "Basic OOP ServerClient Game", NULL ); 


	bool bUpdate = false, bPlayerMoved = false;
	//Fill the screen white 
	//SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) ); 
	while (iClientState != -1)
	{	// check for any events from the user or the system
		SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0, 150, 0 ) ); 

		bool bServerChosen = false;

		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				bgameRunning = false;
			}
			if (event.type == SDL_KEYDOWN)
			{
				keysHeld[event.key.keysym.sym] = true;
			}
			if (event.type == SDL_KEYUP)
			{
				keysHeld[event.key.keysym.sym] = false;
			}
		}

		if (iClientState == 0) //Waiting for response from server
		{
			while (SDLNet_UDP_Recv(NM.GetSocket(), NM.GetPacket()))
			{
				newUserPacket* nuData = (newUserPacket*)NM.GetPacket()->data;

				if (nuData->id == SERVER_NEW_USER)
				{
					iUserNum = nuData->userID;

					cout << "Connected successfully, iUserNum: " << iUserNum << endl;

					aPlayer[iUserNum].SetAlive(true);

					iClientState = 1;

					bUpdate = true;
				}
			}
		}
		else if (iClientState == 1) //Connected and Game Running
		{
			if (bUpdate == true)
			{
				basePacket* rPacket = new basePacket();

				rPacket->id = PLAYER_REFRESH;

				NM.SendStruct((basePacket*)rPacket, serverAddress, sizeof(*rPacket));

				delete[] rPacket;

				bUpdate = false;
			}
			
			
			if (keysHeld[SDLK_w] || keysHeld[SDLK_UP])
			{
				aPlayer[iUserNum].SetY(aPlayer[iUserNum].GetY() - 1);
				bPlayerMoved = true;
			}
			if (keysHeld[SDLK_s] || keysHeld[SDLK_DOWN])
			{
				aPlayer[iUserNum].SetY(aPlayer[iUserNum].GetY() + 1);
				bPlayerMoved = true;
			}
			if (keysHeld[SDLK_a] || keysHeld[SDLK_LEFT])
			{
				aPlayer[iUserNum].SetX(aPlayer[iUserNum].GetX() - 1);
				bPlayerMoved = true;
			}
			if (keysHeld[SDLK_d] || keysHeld[SDLK_RIGHT])
			{
				aPlayer[iUserNum].SetX(aPlayer[iUserNum].GetX() + 1);
				bPlayerMoved = true;
			}

			if (bPlayerMoved == true)
			{
				bPlayerMoved = false;
				if (iNetState == 0) //Client
				{
					movePacket* moPacket = new movePacket();

					moPacket->id = PLAYER_UPDATE;
					moPacket->x = aPlayer[iUserNum].GetX();
					moPacket->y = aPlayer[iUserNum].GetY();
					moPacket->userID = iUserNum;

					NM.SendStruct((basePacket*)moPacket, serverAddress, sizeof(*moPacket));

					delete[] moPacket;

				}
				else if (iNetState == 1) //Server
				{
					movePacket* moPacket = new movePacket();

					moPacket->id = PLAYER_UPDATE;
					moPacket->x = aPlayer[iUserNum].GetX();
					moPacket->y = aPlayer[iUserNum].GetY();
					moPacket->userID = iUserNum;

					for (int i = 1; i < iNumUsers; i++)
					{
						NM.SendStruct((basePacket*)moPacket, userAddress[i], sizeof(*moPacket));
					}

					delete[] moPacket;
				}
			}

			char buffer[1] = {' '};
			for (int i = 0; i < 10; i++)
			{
				if (aPlayer[i].GetAlive() == true)
				{
					filledCircleRGBA(screen, aPlayer[i].GetX(), aPlayer[i].GetY(), 10, 0, 0, 0, 255);
					stringRGBA(screen, aPlayer[i].GetX(), aPlayer[i].GetY(), itoa(i, buffer, 10), 255, 255, 255, 255);
				}
			}

			if (iNetState == 0) //Client
			{
				while (SDLNet_UDP_Recv(NM.GetSocket(), NM.GetPacket()))
				{
					basePacket* pData = (basePacket*)NM.GetPacket()->data;

					if (pData->id == PLAYER_UPDATE)
					{
						movePacket* moData = (movePacket*)pData;

						aPlayer[moData->userID].SetX(moData->x);
						aPlayer[moData->userID].SetY(moData->y);
						aPlayer[moData->userID].SetAlive(true);
					}
				}
			}
			else if (iNetState == 1) //Server
			{
				while (SDLNet_UDP_Recv(NM.GetSocket(), NM.GetPacket()))
				{
					basePacket* pData = (basePacket*)NM.GetPacket()->data;

					if (pData->id == CLIENT_NEW_USER)
					{
						cout << "New User Connecting" << endl;

						newUserPacket* nuData = new newUserPacket();

						nuData->id = SERVER_NEW_USER;
						nuData->userID = iNumUsers;

						userAddress[iNumUsers] = NM.GetPacket()->address;
						aPlayer[iNumUsers].SetAlive(true);

						NM.SendStruct((basePacket*)nuData, NM.GetPacket()->address, sizeof(*nuData));

						iNumUsers++;

						delete[] nuData;
					}
					else if (pData->id == PLAYER_UPDATE)
					{
						movePacket* moData = (movePacket*)pData;

						aPlayer[moData->userID].SetX(moData->x);
						aPlayer[moData->userID].SetY(moData->y);

						for (int i = 0; i < iNumUsers; i++)
						{
							if (i != moData->userID)
							{
								NM.SendStruct((basePacket*)moData, userAddress[i], sizeof(*moData));
							}
						}
					}
					else if (pData->id == PLAYER_REFRESH)
					{
						movePacket* moData = new movePacket();

						for (int i = 0; i < iNumUsers; i++)
						{
							moData->userID = i;
							moData->x = aPlayer[i].GetX();
							moData->y = aPlayer[i].GetY();
							moData->id = PLAYER_UPDATE;

							NM.SendStruct((basePacket*)moData, NM.GetPacket()->address, sizeof(*moData));
						}
						delete[] moData;
					}
				}
			}


			SDL_Delay(5);
			//Update the screen 
			if( SDL_Flip( screen ) == -1 ) { return 1; } 
		}
    	
	}

    SDL_Quit();

    return 0;  
}