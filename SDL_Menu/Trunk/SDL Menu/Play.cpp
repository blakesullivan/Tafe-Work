//Blake Sullivan - Play.cpp
#include "Play.h"

Play::Play()
{
	Init();
}

Play::Play(MyText* mt)
{
	m_pMT = mt;
	Init();
}

void Play::Init()
{
	m_iIsRunning = sceneRunning;

	m_pBM = new ButtonManager(m_pMT);
	AddAndSetButtons();
}

void Play::Update(SDL_Surface* screen, float fDeltaTime)
{
	if (m_bKeysHeld[SDLK_BACKSPACE])
		{m_iIsRunning = sceneMenu;}
}

void Play::Draw(SDL_Surface* screen, float fDeltaTime)
{
	SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 200, 200, 0) ); 
	//stringRGBA(screen, 300, 290, "Play!", 0, 0, 0, 255);
	//stringRGBA(screen, 250, 310, "Press backspace to go back to Menu", 0, 0, 0, 255);
	m_pBM->DrawButton(screen);
}

int Play::Status()
{
	return m_iIsRunning;
}

void Play::Dispose()
{
	delete m_pBM;
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

void Play::AddAndSetButtons()
{
	Colours colD, colH, colP;
	colD.iRed = 128; colD.iGreen = 128; colD.iBlue = 128; colD.iAlpha = 255;
	colH.iRed = 255; colH.iGreen = 255; colH.iBlue = 30; colH.iAlpha = 100;
	colP.iRed = 255; colP.iGreen = 0; colP.iBlue = 0; colP.iAlpha = 255;

	m_pBM->AddButton(300, 500, "Win/Loss", 90, 30, true, true, colD, colH, colP, false, sceneMenu);
	/*for (int i = 0; i < MCS_IMAXDISP; i++)
	{
		if (cd[i].GetLoc() == cpPlayerHand)
		{
			m_pBM->AddButton(cd[i].GetX() - 95, cd[i].GetY() + 25,"Play", 90, 30, true, true, colD, colH, colP);
			m_pBM->AddButton(0, cd[i].GetY() + cd[i].GetCardSize() + 5 - 30,"Clear", 50, 30, true, true, colD, colH, colP);
			break;
		}
	}*/
}