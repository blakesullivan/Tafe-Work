//Blake Sullivan - Play.cpp
#include "Play.h"

Play::Play()
{
	Init();
}

void Play::Init()
{
	m_iIsRunning = sceneRunning;
	m_aPlayer[0].Init(0, 200, 200, "Player 1 - Raynos");
	m_aPlayer[1].Init(1, 500, 500, "Player 2 - Buster Eagle");
	m_aPlayer[2].Init(2, 400, 300, "Player 3 - Pteras");
	m_aPlayer[3].Init(3, 700, 400, "Player 4 - Zabat");
	Player::SetMyID(3);
	m_fTimer = 90;
}

void Play::Update(SDL_Surface* screen, float fDeltaTime)
{
	int buttonmult = 0;
	m_fTimer -= fDeltaTime;
	if (m_bKeysHeld[SDLK_BACKSPACE])
		{m_iIsRunning = sceneMenu;}

	if (m_bButtonHeld[SDL_BUTTON_RIGHT])
		{buttonmult = 1;}
	else
		{buttonmult = 1;}

	if (m_bKeysHeld[SDLK_LEFT] || m_bKeysHeld[SDLK_a])
		{m_aPlayer[Player::GetMyID()].MoveLeft(fDeltaTime, buttonmult);}

	if (m_bKeysHeld[SDLK_RIGHT] || m_bKeysHeld[SDLK_d])
		{m_aPlayer[Player::GetMyID()].MoveRight(fDeltaTime, buttonmult);}
	
	if (m_bKeysHeld[SDLK_UP] || m_bKeysHeld[SDLK_w])
		{m_aPlayer[Player::GetMyID()].MoveUp(fDeltaTime, buttonmult);}

	if (m_bKeysHeld[SDLK_DOWN] || m_bKeysHeld[SDLK_s])
		{m_aPlayer[Player::GetMyID()].MoveDown(fDeltaTime, buttonmult);}

	if (m_bButtonHeld[SDL_BUTTON_LEFT])
	{
		m_aPlayer[Player::GetMyID()].AddBullet();
		m_bButtonHeld[SDL_BUTTON_LEFT] = false;
	}

	if (m_bKeysHeld[SDLK_c])
	{
		int tempID = 0;
		tempID = Player::GetMyID();
		tempID++;
		if (tempID > 3) {tempID = 0;}
		Player::SetMyID(tempID);
		m_bKeysHeld[SDLK_c] = false;
	}
	
	MoveBullets(fDeltaTime);

}

void Play::Draw(SDL_Surface* screen, float fDeltaTime)
{
	SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 00, 200, 0) ); 
	//stringRGBA(screen, 300, 290, "Play!", 0, 0, 0, 255);
	//stringRGBA(screen, 250, 310, "Press backspace to go back to Menu", 0, 0, 0, 255);
	DrawTimer(screen);
	DrawBullets(screen);
	DrawPlayers(screen);
}

void Play::DrawPlayers(SDL_Surface* screen)
{
	SDL_Rect dclip;
	for (int i = 0; i < MCS_IMAXPLAYERS; i++)
	{
		if (m_aPlayer[i].GetCharacterID() >= 0)
		{
			temp = rotozoomSurface(m_aPlayer[i].GetCharacterSurface(), m_aPlayer[i].GetDirection(), 1.0, 0);
			SDL_SetColorKey(temp, SDL_SRCCOLORKEY, SDL_MapRGB(temp->format, 255, 0, 255));

			dclip.x = m_aPlayer[i].GetX() - (temp->w/2);
			dclip.y = m_aPlayer[i].GetY() - (temp->h/2);
			dclip.w = temp->w; dclip.h = temp->h;

			SDL_BlitSurface(temp, &temp->clip_rect, screen, &dclip);
			SDL_FreeSurface(temp);

			int iCentreX = dclip.x + (dclip.w / 2), iCentreY = dclip.y + (dclip.h / 2);
			//circleRGBA(screen, dclip.x + (96/2), dclip.y + (96/2), 30, 255, 0, 0, 255);
			rectangleRGBA(screen, iCentreX - 16, iCentreY - 16, iCentreX + 16, iCentreY + 16, 255, 0, 0, 255);
			rectangleRGBA(screen, iCentreX - (16 + 32), iCentreY - 16, iCentreX - 16, iCentreY + 16, 255, 0, 0, 255);
			rectangleRGBA(screen, iCentreX + 16, iCentreY - 16, iCentreX + (16 + 32), iCentreY + 16, 255, 0, 0, 255);
			rectangleRGBA(screen, iCentreX - 16, iCentreY - (16 + 32), iCentreX + 16, iCentreY - 16, 255, 0, 0, 255);
			rectangleRGBA(screen, iCentreX - 16, iCentreY + 16, iCentreX + 16, iCentreY + (16 + 32), 255, 0, 0, 255);

			//rectangleRGBA(screen, dclip.x, dclip.y + 32, dclip.x + 32, dclip.y + (32*2), 255, 0, 0, 255);
			//rectangleRGBA(screen, dclip.x + 32, dclip.y+32, dclip.x + (32*2), dclip.y + (32*2), 255, 0, 0, 255);
			//rectangleRGBA(screen, dclip.x + (32*2), dclip.y+32, dclip.x + (32*3), dclip.y + (32*2), 255, 0, 0, 255);
			//rectangleRGBA(screen, dclip.x + 32, dclip.y+(32*2), dclip.x + (32*2), dclip.y + (32*3), 255, 0, 0, 255);
		}
	}
}
void Play::DrawBullets(SDL_Surface* screen)
{
	for (int i = 0; i < MCS_IMAXPLAYERS; i++)
	{
		m_aPlayer[i].DrawBullets(screen);
	}
}
void Play::MoveBullets(float fdt)
{
	for (int i = 0; i < MCS_IMAXPLAYERS; i++)
	{
		m_aPlayer[i].MoveBullets(fdt);
	}
}
void Play::DrawTimer(SDL_Surface* screen)
{
	char buffer[10];
	int iTimeBuff = 2;
	//if (m_fTimer < 10) {iTimeBuff = 3;}

	boxRGBA(screen, 390, 45, 420, 70, 0, 0, 0, 255);
	dt.DrawTextToSurface(screen, gcvt(m_fTimer, iTimeBuff, buffer), 390, 50);
}

//void Play::Event(SDL_Surface* screen, SDL_Event *event, float fDeltaTime)
//{
//	if (SDL_PollEvent(event))
//	{
//		if (event->type == SDL_QUIT)
//		{
//			m_iIsRunning = sceneQuit;
//		}
//		if (event->type == SDL_KEYDOWN)
//		{
//			if (event->key.keysym.sym == SDLK_ESCAPE)
//				{m_iIsRunning = sceneQuit;}
//			else
//				{m_iIsRunning = sceneMenu;}
//			//keysHeld[event.key.keysym.sym] = true;
//		}
//		if (event->type == SDL_KEYUP)
//		{
//			//keysHeld[event.key.keysym.sym] = false;
//		}
//	}
//}

int Play::Status()
{
	return m_iIsRunning;
}

void Play::Dispose()
{
}

void Play::MouseUpEvent(SDL_Event* event)
{
	Scene::MouseUpEvent(event);
}
void Play::MouseDownEvent (SDL_Event* event)
{
	Scene::MouseDownEvent(event);
}
void Play::KeyUpEvent(SDL_Event* event)
{
	Scene::KeyUpEvent(event);
}
void Play::KeyDownEvent(SDL_Event* event)
{
	Scene::KeyDownEvent(event);
}