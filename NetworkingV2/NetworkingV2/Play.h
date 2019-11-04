//Blake Sullivan - Splash.h
#ifndef PLAY_H
#define PLAY_H

#include "Scene.h"
#include "Player.h"
#include "SDL_rotozoom.h"
#include "DrawText.h"

class Play : public Scene
{
private:
	const static int MCS_IMAXPLAYERS = 8;
	SDL_Surface *temp;
	Player m_aPlayer[MCS_IMAXPLAYERS];
	float m_fTimer;
	DrawText dt;

public:
	Play();

	void Init();
	//void Event(SDL_Surface* screen, SDL_Event *event, float fDeltaTime);
	void Update(SDL_Surface* screen, float fDeltaTime);
	void Draw(SDL_Surface* screen, float fDeltaTime);
	int Status();
	void Dispose();

	virtual void MouseUpEvent(SDL_Event* event);
	virtual void MouseDownEvent (SDL_Event* event);
	virtual void KeyUpEvent(SDL_Event* event);
	virtual void KeyDownEvent(SDL_Event* event);

	void DrawPlayers(SDL_Surface* screen);
	void DrawTimer(SDL_Surface* screen);
	void DrawBullets(SDL_Surface* screen);
	void MoveBullets(float fdt);
};
#endif