//Blake Sullivan - Splash.h
#ifndef PLAY_H
#define PLAY_H

#include "Scene.h"
#include "SDL_rotozoom.h"
#include "Player.h"
#include "NetworkClient.h"

class Play : public Scene
{
private:
	//int m_iIsRunning;
	static const unsigned int MSC_UIMAXPLAYERS = 8;
	bool m_bKeyPressed;
	SDL_Surface* player;
	SDL_Surface* temp;
	Player m_player[MSC_UIMAXPLAYERS];
	NetworkClient m_nc;

public:
	Play();

	void Init();
	void Event(SDL_Surface* screen, SDL_Event *event, float fDeltaTime);
	void Update(SDL_Surface* screen, float fDeltaTime);
	void Draw(SDL_Surface* screen, float fDeltaTime);
	int Status();
	void Dispose();

	void ResponseAction(UDPpacket*);
	void JoinPlayer(std::string);
	void MovePlayer(std::string);
};
#endif