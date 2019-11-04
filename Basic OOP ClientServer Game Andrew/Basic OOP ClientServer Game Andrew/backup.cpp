//#include <iostream>
//#include <string>
//#include "sdl_net.h"
//#include "sdl_gfxPrimitives.h"
//#include "sdl.h"
//#include "network.h"
//
//using namespace std;
//
//const int SCREEN_WIDTH = 800;
//const int SCREEN_HEIGHT = 600;
//const int SCREEN_BPP = 32;
//	
//
//
//SDL_Surface * screen = NULL;
//
//SDL_Rect sclip, dclip;
//
//int main(int aargc, char** argv)
//{
//	// Network stuff
//	UDPsocket socket;
//	UDPpacket* packet;
//
//	NetManager net;
//
//	basePacket* pData = 0;
//	serverResponsePacket* srData = 0;
//	connectPacket* cData = 0;
//	newUserPacket* nuData = 0;
//	messagePacket* mData = 0;
//
//	SDL_Event event;
//
//	IPaddress serverAddress;
//	char serverNames[50][STRING_SIZE],servers[50][STRING_SIZE];
//
//	char stringBuffer[STRING_SIZE];
//
//	char userNames[100][STRING_SIZE];
//	char serverName[STRING_SIZE];
//	IPaddress userAddress[50];
//
//	int numUsers = 0;
//
//	char ipString[STRING_SIZE];
//	char temp[STRING_SIZE];
//
//	int numServers = 0;
//
//	char userName[STRING_SIZE]; // users name
//	int userNum = -1;   // users ID on the server
//
//	int netState = -1; // 0 = client, 1 = server
//
//	char messageBuffer[20][STRING_SIZE];
//
//	for(int i = 0; i < 20; i++)
//	{
//		strcpy(messageBuffer[i]," ");
//	}
//
//	printf("Do you wish to act as (c)lient or (s)erver?\n");
//	cin.getline(temp,100);
//
//	if(temp[0] == 'c' || temp[0] =='C')
//	{
//		netState = 0;
//	}
//	else
//	{
//		netState = 1;
//	}
//
//	int clientState = 0;
//	// 0 looking for server
//	// 1 input name
//	// 2 wait for response from server
//	// 3 connected to server
//
//	char testString[STRING_SIZE] = "";
//	char tempString[STRING_SIZE];
//	int chNum = 0;
//	bool bReturn = false;
//	int choice = -1;
//	bool keyUp = false, keyDown = false, keyLeft = false, keyRight = false;
//
//	int cx = 0, cy = 0;
//
//
//	if(netState == 0)
//	{
//
//		if(SDL_Init( SDL_INIT_EVERYTHING ) == -1)
//			return 1;
//
//		screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_HWSURFACE|SDL_DOUBLEBUF);
//
//		if(screen == NULL)
//			return 1;
//
//		while(clientState != -1)
//		{
//
//			SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB(screen->format,0,0,75));
//			//stringRGBA( screen,10,10,testString,255,255,255,255);
//
//			bool serverChosen = false;
//			
//	
//			while(SDL_PollEvent(&event))
//			{
//				switch(event.type)
//				{
//				case SDL_KEYDOWN:
//					switch(event.key.keysym.sym)
//					{
//						case SDLK_BACKSPACE:
//							{
//								
//								if(chNum > 0)
//								{
//									testString[chNum-1] = 0;
//									chNum--;
//								}
//							}
//							break;
//						case SDLK_RETURN:
//						{
//							chNum = 0;
//							bReturn = true;
//						}
//						break;
//						case SDLK_UP:
//							{
//								keyUp = true;
//
//							}
//							break;
//						case SDLK_DOWN:
//							{
//								keyDown = true;
//
//							}
//							break;
//						case SDLK_LEFT:
//							{
//								keyLeft = true;
//
//							}
//							break;
//						case SDLK_RIGHT:
//							{
//								keyRight = true;
//
//							}
//							break;
//						default:
//						{
//							testString[chNum] = event.key.keysym.sym;
//							chNum++;
//						}
//						break;
//					}
//					break;
//				case SDL_KEYUP:
//					switch(event.key.keysym.sym)
//					{
//						case SDLK_UP:
//							{
//								keyUp = false;
//
//							}
//							break;
//						case SDLK_DOWN:
//							{
//								keyDown = false;
//
//							}
//							break;
//						case SDLK_LEFT:
//							{
//								keyLeft = false;
//
//							}
//							break;
//						case SDLK_RIGHT:
//							{
//								keyRight = false;
//
//							}
//							break;
//					}
//					break;
//				}
//			}
//
//			//while(!serverChosen)
//			if(clientState == 0)
//			{
//				//choice = -1;
//				stringRGBA( screen,10,10,"Type -1 to refresh or type in a number to join the server:",255,255,255,255);
//				stringRGBA( screen,10,30,testString,255,255,255,255);
//
//				for(int i = 0; i < numServers; i++)
//				{
//					sprintf(tempString,"%d - %s - %s",i,serverNames[i],servers[i]);
//
//					stringRGBA(screen,10,60 + (i * 20),tempString,255,255,255,255);
//				}
//
//				if(bReturn)
//				{
//					bReturn = false;
//					choice = atoi(testString);
//
//					printf("Choice %d selected\n",choice);
//
//					if(choice == -1)
//					{
//						stringRGBA( screen,10,50,"Refreshing Server List, please wait ..",255,255,255,255);
//
//						if(SDL_Flip(screen) == -1)
//							return 1;
//
//						numServers = 0;
//	
//						serverAddress = net.ResolveHost("255.255.255.255",2000);
//
//						//sprintf((char *)packet->data,"@");	
//						pData = new basePacket();
//
//						pData->id = CLIENT_BROADCAST;
//
//						//packet->data = (Uint8*)pData;
//
//						net.SendStruct(pData,sizeof(*pData),serverAddress);
//
//						delete [] pData;
//
//						SDL_Delay(5000);
//
//						socket = net.getSocket();
//						packet = net.getPacket();
//
//						while(SDLNet_UDP_Recv(socket, packet))
//						{
//							//if(((char *)packet->data)[0] == '!')
//							srData = (serverResponsePacket*)packet->data;
//
//							printf("Packet Received, ID = %d\n",srData->id);
//
//							if(srData->id == SERVER_RESPONSE)
//							{
//
//								sprintf(serverNames[numServers],srData->serverName);//,strlen(srData->serverName));
//
//								sprintf(servers[numServers],"%d.%d.%d.%d",packet->address.host&0xff,(packet->address.host>>8)&0xff,(packet->address.host>>16)&0xff, (packet->address.host>>24)&0xff);
//					
//								numServers++;
//							}
//						}
//					}
//					else if(choice >= 0 && choice < numServers)
//					{
//						//serverChosen = true;
//						clientState = 1;
//					}
//
//					//testString[0] = '\n';
//
//					for(int i = 0; i < STRING_SIZE-1; i++)
//					{
//						testString[i] = '\0';
//					}
//				}
//			}
//			else if(clientState == 1)
//			{
//				printf("Resolving Host %d,%s\n",choice,servers[0]);
//				serverAddress = net.ResolveHost(servers[choice],2000);
//
//				//cout << "Input your name: " << endl;
//				stringRGBA(screen,10,10,"Input your name:",255,255,255,255);
//				stringRGBA(screen,10,30,testString,255,255,255,255);
//
//				//cin.getline(userName,255);
//				if(bReturn)
//				{
//					bReturn = false;
//
//					cData = new connectPacket();
//
//					cData->id = CLIENT_NEW_USER;
//					sprintf(cData->userName,testString);
//
//					net.SendStruct((basePacket*)cData,sizeof(*cData),serverAddress);
//	
//					delete [] cData;
//
//					bool connected = false;
//					clientState = 2;
//					//testString[0] = '\n';
//					for(int i = 0; i < STRING_SIZE-1; i++)
//					{
//						testString[i] = '\0';
//					}
//				}
//			}
//			else if(clientState == 2) //while(!connected)
//			{
//				socket = net.getSocket();
//				packet = net.getPacket();
//				while(SDLNet_UDP_Recv(socket, packet))
//				{
//					nuData = (newUserPacket*)packet->data;
//					
//					if(nuData->id == SERVER_NEW_USER)
//					{
//						//userNum = atoi((char*)packet->data);
//						userNum = nuData->userID;
//						printf("User ID Received: %d\n",nuData->userID);
//
//						stringRGBA(screen,10,10,"You have connected to the server",255,255,255,255);
//
//						//connected = true;
//						clientState = 3;
//					}
//				}
//			}
//			else if(clientState == 3) //bool quit = false;while(!quit)
//			{
//
//				stringRGBA(screen,10,10,"Input message:",255,255,255,255);
//				stringRGBA(screen,10,30,testString,255,255,255,255);
//
//				if(bReturn)
//				{
//					bReturn = false;
//
//					messagePacket* m1Data = new messagePacket();
//
//					m1Data->id = CLIENT_MESSAGE;
//					m1Data->userID = userNum;
//					sprintf(m1Data->message,testString);
//
//					printf("ID: %d, userNum: %d, \n",m1Data->id,m1Data->userID);
//					net.SendStruct((basePacket*)m1Data,sizeof(*m1Data),serverAddress);
//
//					delete [] mData;
//	
//					for(int i = 0; i < STRING_SIZE-1; i++)
//					{
//						testString[i] = '\0';
//					}
//				}
//
//				socket = net.getSocket();
//				packet = net.getPacket();
//				while(SDLNet_UDP_Recv(socket, packet))
//				{
//					
//					messagePacket* m2Data = (messagePacket*)packet->data;
//					//mData = 
//
//					printf("Message Received: %s\n",m2Data->message);
//
//					for(int i = 19; i > 0; i--)
//					{
//						sprintf(messageBuffer[i],messageBuffer[i-1]);
//					}
//					//printf("testing id:%d, message: %s\n",mData->message);
//					sprintf(messageBuffer[0],m2Data->message);
//				}
//
//				for(int i = 0; i < 20; i++)
//				{
//					stringRGBA(screen,10,SCREEN_HEIGHT - (20 + (20 * i)),messageBuffer[i],255,255,255,255);
//				}
//
//				if(keyUp)
//					cy--;
//				if(keyDown)
//					cy++;
//				if(keyLeft)
//					cx--;
//				if(keyRight)
//					cx++;
//
//				circleRGBA(screen,cx,cy,10,255,255,0,255);
//
//			}
//
//			if(SDL_Flip(screen) == -1)
//				return 1;
//		}
//	}
//	else // netstate == 1
//	{
//
//		net.OpenPort(2000);
//
//		//server code here
//		printf("Enter a server name: \n");
//		cin.getline(serverName,STRING_SIZE);
//
//		bool quit = false;
//
//		while (!quit)
//		{
//			socket = net.getSocket();
//			packet = net.getPacket();
//			while(SDLNet_UDP_Recv(socket, packet))
//			{
//				
//				pData = (basePacket*)packet->data;
//
//				printf("Packet received: ID = %d\n", pData->id);
//
//				if(pData->id == CLIENT_BROADCAST) //stringBuffer[0] == '@')
//				{
//					printf("A client broadcast for a server, responding...\n");	
//
//					srData = new serverResponsePacket();
//
//					srData->id = SERVER_RESPONSE;
//
//					sprintf(srData->serverName,serverName);
//					net.SendStruct((basePacket*)srData,sizeof(*srData),packet->address);
//
//					delete [] srData;
//				}
//				else if(pData->id == CLIENT_NEW_USER)//stringBuffer[0] == '$')
//				{
//					cData = (connectPacket*)packet->data;
//
//					printf("New User Received - Packet ID: %d - User Name: %s\n",cData->id,cData->userName);
//
//					sprintf(userNames[numUsers],cData->userName);
//					userAddress[numUsers].host = packet->address.host;
//					userAddress[numUsers].port = packet->address.port;
//
//					nuData = new newUserPacket();
//					nuData->id = SERVER_NEW_USER;
//					nuData->userID = numUsers;
//
//					net.SendStruct((basePacket*)nuData,sizeof(*nuData),userAddress[numUsers]);
//
//					delete [] nuData;
//
//					numUsers++;
//
//				}
//				else if(pData->id == CLIENT_MESSAGE)
//				{
//
//					mData = (messagePacket*)packet->data;
//
//					int num = mData->userID;
//
//					char tString[STRING_SIZE];
//
//					printf("Player: %d-%s, message:%s\n",num,userNames[num],mData->message);
//
//					sprintf(tString,"%s > %s",userNames[num],mData->message);
//
//					printf("%s\n",tString);
//
//					messagePacket* m1Data = new messagePacket();
//
//					m1Data->id = SERVER_MESSAGE;
//
//					for(int i = 0; i < numUsers; i++)
//					{
//						sprintf(m1Data->message,tString);
//
//						net.SendStruct((basePacket*)m1Data,sizeof(*m1Data),userAddress[i]);
//					}
//				
//					delete [] m1Data;
//				}
//
//			}
//
//		}
//	}
//
//	
//
//
//	return 0;
//}
//
