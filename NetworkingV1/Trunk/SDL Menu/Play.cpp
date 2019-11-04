//Blake Sullivan - Play.cpp
#include "Play.h"

Play::Play()
{
	Init();
}

void Play::Init()
{
	player = NULL;
	temp = NULL;
	m_iIsRunning = sceneRunning;
	m_bKeyPressed = false;
	for (int i = 0; i < 323; i++)
		{m_bKeyHeld[i] = false;}
	player = SDL_LoadBMP("RaynosFull.bmp");
	SDL_SetColorKey(player, SDL_SRCCOLORKEY, SDL_MapRGB(player->format, 255, 0, 255));
	for (int i = 0; i < MSC_UIMAXPLAYERS; i++)
	{
		m_player[i].SetStart(300, 400);
		m_player[i].SetAlive(false);
		m_player[i].SetInGame(false);
	}
	Player::SetID(0);
}

void Play::Event(SDL_Surface* screen, SDL_Event *event, float fDeltaTime)
{
	if (SDL_PollEvent(event))
	{
		if (event->type == SDL_QUIT)
		{
			m_iIsRunning = sceneQuit;
		}
		if (event->type == SDL_KEYDOWN)
		{
			if (event->key.keysym.sym == SDLK_ESCAPE)
				{m_iIsRunning = sceneQuit;}
			else if (event->key.keysym.sym == SDLK_BACKSPACE)
				{m_iIsRunning = sceneMenu;}

			m_bKeyHeld[event->key.keysym.sym] = true;
		}
		if (event->type == SDL_KEYUP)
		{
			m_bKeyHeld[event->key.keysym.sym] = false;
			m_bKeyPressed = false;
		}
	}
}

void Play::Update(SDL_Surface* screen, float fDeltaTime)
{
	if ( m_bKeyHeld[SDLK_LEFT] || m_bKeyHeld[SDLK_a] )
	{
		m_player[Player::GetID()].moveLeft(fDeltaTime);
		m_bKeyHeld[SDLK_LEFT] = false;
		m_bKeyHeld[SDLK_a] = false;
	}
	if ( m_bKeyHeld[SDLK_RIGHT] || m_bKeyHeld[SDLK_d] )
	{
		m_player[Player::GetID()].moveRight(fDeltaTime);
		m_bKeyHeld[SDLK_RIGHT] = false;
		m_bKeyHeld[SDLK_d] = false;
	}
	if ( m_bKeyHeld[SDLK_UP] || m_bKeyHeld[SDLK_w] )
	{
		m_player[Player::GetID()].moveUp(fDeltaTime);
		//m_bKeyHeld[SDLK_UP] = false;
		//m_bKeyHeld[SDLK_w] = false;
	}
	if (m_bKeyHeld[SDLK_DOWN] || m_bKeyHeld[SDLK_s])
	{
		m_player[Player::GetID()].moveDown(fDeltaTime);
		//m_bKeyHeld[SDLK_DOWN] = false;
		//m_bKeyHeld[SDLK_s] = false;
	}
	if (m_bKeyHeld[SDLK_m])// && m_bKeyPressed == false)
	{
		//cout << "X= " << m_player.getX() << " Y= " <<  m_player.getY() << endl;
		m_nc.Send(m_player[Player::GetID()].GetID(), m_player[Player::GetID()].GetX(), m_player[Player::GetID()].GetY(), m_player[Player::GetID()].GetDir());
		m_bKeyPressed = true;
	}
	if (m_bKeyHeld[SDLK_j] && m_bKeyPressed == false)
	{
		//cout << "X= " << m_player.getX() << " Y= " <<  m_player.getY() << endl;
		m_nc.Send(-1, m_player[Player::GetID()].GetCharID());
		m_bKeyPressed = true;
	}
	if (true == m_nc.Receive())
	{
		ResponseAction(m_nc.GetResponse());
	}
}

void Play::Draw(SDL_Surface* screen, float fDeltaTime)
{	
	SDL_Rect sclip, dclip;

	SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 200, 100, 50)); 

	static float fFrame = 0, fFrame2 = 0;

	fFrame += (7 * fDeltaTime);
	//fFrame2 += (1 * fDeltaTime);
	if (fFrame > 4) {fFrame = 0;}
	fFrame2 = (m_player[Player::GetID()].GetDir()) / 45;
	//std::cout << "fFrame2 = " << fFrame2 << std::endl;
	if (fFrame2 > 7) {fFrame2 = 0;}
	if (fFrame2 < 0) {fFrame2 = 7;}
	//fFrame2 = 1;

	for (int i = 0; i < MSC_UIMAXPLAYERS; i++)
	{
		if (m_player[i].GetInGame() == true)
		{
			//temp = rotozoomSurface(player, (double)m_player[i].GetDir(), 1.0, 0);
			temp = rotozoomSurface(player, 0, 1.0, 0);
			SDL_SetColorKey(temp, SDL_SRCCOLORKEY, SDL_MapRGB(temp->format, 255, 0, 255)); 

			//Initialise the clipping rectangles for the source image and the destination location on screen
			sclip.x = 100 * (int)fFrame; sclip.y = 100 * (int)fFrame2; sclip.w = 100; sclip.h = 100;//sclip.w = temp->w; sclip.h = temp->h; 	//where the image is  in memory 
			dclip.x = m_player[i].GetX()-(temp->w/2); dclip.y = m_player[i].GetY()-(temp->h/2); dclip.w = temp->w; dclip.h = temp->h; 	//where to put the image on screen 
			SDL_BlitSurface(temp, &sclip, screen, &dclip);
			SDL_FreeSurface(temp);
		}
	}
}

int Play::Status()
{
	return m_iIsRunning;
}

void Play::Dispose()
{
	SDL_FreeSurface(player);
}

void Play::ResponseAction(UDPpacket *r)
{
	switch ((char)((char *)r->data[0]))
	{
	case 'J':
		std::cout << "Do J in ResponseAction!\n";
		JoinPlayer((std::string)((char *)r->data));
	break;
	case 'M':
		std::cout << "Do M in ResponseAction!\n";
		MovePlayer((std::string)((char *)r->data));
	break;
	default:
		std::cout << "Do default in ResponseAction!\n";
	break;
	}
}

void Play::JoinPlayer(std::string j)
{
	std::string sData = j;
	sData = sData.substr(sData.find(",") + 1, sData.length());
	Player::SetID(atoi(sData.substr(0, sData.find(",")).c_str()));
	m_player[Player::GetID()].SetAlive(true);
	m_player[Player::GetID()].SetInGame(true);
	sData = sData.substr(sData.find(",") + 1, sData.length());
	m_player[Player::GetID()].SetX(atof(sData.substr(0, sData.find(",")).c_str()));
	sData = sData.substr(sData.find(",") + 1, sData.length());
	m_player[Player::GetID()].SetY(atof(sData.substr(0, sData.find(",")).c_str()));
	sData = sData.substr(sData.find(",") + 1, sData.length());
	m_player[Player::GetID()].SetDirection(atoi(sData.substr(0, sData.find(",")).c_str()));
}

void Play::MovePlayer(std::string m)
{
	int moveID = 0;
	std::string sData = m;

	sData = sData.substr(sData.find(",") + 1, sData.length());
	moveID = atoi(sData.substr(0, sData.find(",")).c_str());
	sData = sData.substr(sData.find(",") + 1, sData.length());
	m_player[moveID].SetX(atof(sData.substr(0, sData.find(",")).c_str()));
	sData = sData.substr(sData.find(",") + 1, sData.length());
	m_player[moveID].SetY(atof(sData.substr(0, sData.find(",")).c_str()));
	sData = sData.substr(sData.find(",") + 1, sData.length());
	m_player[moveID].SetDirection(atoi(sData.substr(0, sData.find(",")).c_str()));
	sData = sData.substr(sData.find(",") + 1, sData.length());
	m_player[moveID].SetAlive(atoi(sData.substr(0, sData.find(",")).c_str()));
	sData = sData.substr(sData.find(",") + 1, sData.length());
	m_player[moveID].SetInGame(atoi(sData.substr(0, sData.find(",")).c_str()));
}