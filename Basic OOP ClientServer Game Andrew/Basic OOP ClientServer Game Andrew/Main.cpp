#include <iostream>
#include <string>
#include "sdl_net.h"
#include "sdl_gfxPrimitives.h"
#include "sdl.h"
#include "Character.h"
#include "network.h"

using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;

SDL_Surface * screen = NULL;

SDL_Rect sclip, dclip;

int main(int argc, char** argv)
{
	// Network stuff

	SDL_Event event;

	NetManager net;
	UDPsocket socket;
	UDPpacket* packet;

	IPaddress userAddress[10];
	IPaddress serverAddress;

	int numUsers = 1;
	int numServers = 0;

	char userName[STRING_SIZE]; // users name
	int userNum = 0;   // users ID on the server

	int clientState = 0;
	// 0 looking for server
	// 1 input name
	// 2 wait for response from server
	// 3 connected to server

	char messageBuffer[20][STRING_SIZE];

	for(int i = 0; i < 20; i++)
	{
		sprintf(messageBuffer[i]," ");
	}

	char testString[STRING_SIZE] = "";
	char tempString[STRING_SIZE];
	int netState = -1;
	
	int chNum = 0;
	bool bReturn = false;
	int choice = -1;
	bool keyUp = false, keyDown = false, keyLeft = false, keyRight = false;

	printf("Do you wish to act as (c)lient or (s)erver?\n");
	cin.getline(tempString,100);

	if(tempString[0] == 'c' || tempString[0] =='C')
	{
		netState = 0;
		clientState = 0;

		net.OpenPort(0);

		serverAddress = net.ResolveHost("127.0.0.1",2000);

		connectPacket* cData = new connectPacket();

		cData->id = CLIENT_NEW_USER;

		net.SendStruct((basePacket*)cData,sizeof(*cData),serverAddress);

		//SDL_Delay(5000);

		delete [] cData;
	}
	else
	{
		netState = 1;
		clientState = 1;

		net.OpenPort(2000);

	}
	

	Character player[10];
	player[0].setAlive(true);

	if(SDL_Init( SDL_INIT_EVERYTHING ) == -1)
		return 1;

	screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_HWSURFACE|SDL_DOUBLEBUF);

	if(screen == NULL)
		return 1;

	bool update = false;

	while(clientState != -1)
	{

		SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB(screen->format,0,0,75));
		//stringRGBA( screen,10,10,testString,255,255,255,255);

		bool serverChosen = false;
			
	
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym)
				{
					case SDLK_BACKSPACE:
						{
								
							if(chNum > 0)
							{
								testString[chNum-1] = 0;
								chNum--;
							}
						}
						break;
					case SDLK_RETURN:
					{
						chNum = 0;
						bReturn = true;
					}
					break;
					case SDLK_UP:
						{
							keyUp = true;

						}
						break;
					case SDLK_DOWN:
						{
							keyDown = true;

						}
						break;
					case SDLK_LEFT:
						{
							keyLeft = true;

						}
						break;
					case SDLK_RIGHT:
						{
							keyRight = true;

						}
						break;
					default:
					{
						testString[chNum] = event.key.keysym.sym;
						chNum++;
					}
					break;
				}
				break;
			case SDL_KEYUP:
				switch(event.key.keysym.sym)
				{
					case SDLK_UP:
						{
							keyUp = false;

						}
						break;
					case SDLK_DOWN:
						{
							keyDown = false;

						}
						break;
					case SDLK_LEFT:
						{
							keyLeft = false;

						}
						break;
					case SDLK_RIGHT:
						{
							keyRight = false;

						}
						break;
				}
				break;
			}
		}

		if(clientState == 0) // Waiting for response from server)
		{
			socket = net.getSocket();
			packet = net.getPacket();
			while(SDLNet_UDP_Recv(socket,packet))
			{
				newUserPacket* nuData = (newUserPacket*)packet->data;

				if(nuData->id == SERVER_NEW_USER)
				{
					userNum = nuData->userID;

					printf("Successfully connected, user number: %d \n",userNum);
					
					player[userNum].setAlive(true);

					clientState = 1; // connected, run game

					//SDL_Delay(5000);
					update = true;
				}


			}

		}
		else if(clientState == 1) // Connected Game Running
		{
			if(update)
			{
				basePacket* rPacket = new basePacket();

				rPacket->id = PLAYER_REFRESH;

				net.SendStruct((basePacket*)rPacket,sizeof(*rPacket),serverAddress);

				delete [] rPacket;

				update = false;

			}

			for(int i = 0; i < 20; i++)
			{
				stringRGBA(screen,10,SCREEN_HEIGHT - (20 + (20 * i)),messageBuffer[i],255,255,255,255);
			}

			if(keyUp)
				player[userNum].setY(player[userNum].getY()-1);
			if(keyDown)
				player[userNum].setY(player[userNum].getY()+1);
			if(keyLeft)
				player[userNum].setX(player[userNum].getX()-1);
			if(keyRight)
				player[userNum].setX(player[userNum].getX()+1);

			if(keyLeft || keyRight || keyUp || keyDown)
			{
				if(netState == 0) // client
				{
					movePacket* moPacket = new movePacket();

					moPacket->id = PLAYER_UPDATE;
					moPacket->x = player[userNum].getX();
					moPacket->y = player[userNum].getY();
					moPacket->userID = userNum;

					net.SendStruct((basePacket*)moPacket,sizeof(*moPacket),serverAddress);

					delete [] moPacket;


				}
				else if(netState == 1) // server
				{
					movePacket* moPacket = new movePacket();

					moPacket->id = PLAYER_UPDATE;
					moPacket->x = player[userNum].getX();
					moPacket->y = player[userNum].getY();
					moPacket->userID = userNum;


					for(int i = 1; i < numUsers; i++)
					{
						net.SendStruct((basePacket*)moPacket,sizeof(*moPacket),userAddress[i]);
					}

					delete [] moPacket;


				}


			}

			for(int i = 0; i < 10; i++)
			{
				if(player[i].getAlive())
					circleRGBA(screen,player[i].getX(),player[i].getY(),10,255,255,0,255);
			}

			if(netState == 0) // Client
			{
				socket = net.getSocket();
				packet = net.getPacket();
				while(SDLNet_UDP_Recv(socket,packet))
				{
					basePacket* pData = (basePacket*)packet->data;

					if(pData->id == PLAYER_UPDATE)
					{
						movePacket* moData = (movePacket*)pData;

						player[moData->userID].setX(moData->x);
						player[moData->userID].setY(moData->y);
						player[moData->userID].setAlive(true);
					}
				}

			}
			else if(netState == 1) // Server
			{

				socket = net.getSocket();
				packet = net.getPacket();
				while(SDLNet_UDP_Recv(socket,packet))
				{
					basePacket* pData = (basePacket*)packet->data;

					if(pData->id == CLIENT_NEW_USER)
					{
						//connectPacket* cData = (connectPacket*)pData;

						printf("New User Connecting\n");

						newUserPacket* nuData = new newUserPacket();

						nuData->id = SERVER_NEW_USER;
						nuData->userID = numUsers;

						userAddress[numUsers] = packet->address;
						player[numUsers].setAlive(true);

						net.SendStruct((basePacket*)nuData,sizeof(*nuData),packet->address);

						numUsers++;

						delete [] nuData;
						
						

					}
					else if(pData->id == PLAYER_UPDATE)
					{
						movePacket* moData = (movePacket*)pData;

						player[moData->userID].setX(moData->x);
						player[moData->userID].setY(moData->y);

						for(int i = 0; i < numUsers; i++)
						{
							if(i != moData->userID)
							{
								net.SendStruct((basePacket*)moData,sizeof(*moData),userAddress[i]);
							}
						}

					}
					else if(pData->id == PLAYER_REFRESH)
					{
						movePacket* moData = new movePacket();

						for(int i = 0; i < numUsers; i++)
						{
							

							moData->userID = i;
							moData->x = player[i].getX();
							moData->y = player[i].getY();
							moData->id = PLAYER_UPDATE;

							net.SendStruct((basePacket*)moData,sizeof(*moData),packet->address);

						}

						delete [] moData;
					}

				}

			}
		}

		SDL_Delay(5);

		if(SDL_Flip(screen) == -1)
			return 1;
	}
	

	


	return 0;
}

