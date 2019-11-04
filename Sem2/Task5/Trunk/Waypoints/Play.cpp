//Blake Sullivan - Play.cpp
#include "Play.h"
#include <Math.h>

Play::Play()
{
	Init();
}

void Play::Init()
{
	m_Background = NULL;
	m_iIsRunning = sceneRunning;
	m_Background = SDL_LoadBMP("Rome.bmp");
	playerNode.Init(0, 50, 350); //sets the player near node 2 at the start
	badNode.Init(0, NM.GetNodeX(0), NM.GetNodeY(0)); //sets the badguy on node 1
	NM.SetClosestNode(2);
	UpdateTargetNodes(&badNode);
	m_bButtonUsed = false;
	//SDL_SetColorKey(background, SDL_SRCCOLORKEY, SDL_MapRGB(background->format, 255, 0, 255));
}

void Play::Update(SDL_Surface* screen, float fDeltaTime)
{
	static bool bKeyUsed = false;
	int mouseX = 0, mouseY = 0;
	if (m_bButtonHeld[SDL_BUTTON_LEFT] || m_bButtonHeld[SDL_BUTTON_RIGHT]) {SDL_GetMouseState(&mouseX, &mouseY);}
	if (m_bButtonHeld[SDL_BUTTON_LEFT] == true && m_bButtonUsed == false)
	{
		playerNode.Init(mouseX, mouseY);
		m_bButtonUsed = true;
	}
	NM.SetClosestNode(NM.GetNodeID(FindNearestNode(&playerNode)));

	if (m_bKeysHeld[SDLK_SPACE] && bKeyUsed == false)
	{
		UpdateTargetNodes(&badNode);
		bKeyUsed = true;
	}
	if (m_bKeysHeld[SDLK_SPACE])
	{
		MoveBad(fDeltaTime);
	}
}

void Play::Draw(SDL_Surface* screen, float fDeltaTime)
{
	SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0, 200, 50) ); 
	
	SDL_BlitSurface(m_Background, NULL, screen, NULL); //This draws the background image

	//Draws the player and bad guy
	filledCircleRGBA(screen, playerNode.GetX(), playerNode.GetY(), 10, 200, 100, 50, 255);
	filledCircleRGBA(screen, badNode.GetX(), badNode.GetY(), 10, 20, 100, 250, 255);

	DrawNodes(screen);

	char cTemp[255];
	sprintf_s(cTemp, "Current Node: %i", NM.GetCurrentNode());
	stringRGBA(screen, 25, 220, cTemp, 0, 0, 0, 255);
	sprintf_s(cTemp, "Next Node: %i", NM.GetNextNode());
	stringRGBA(screen, 25, 240, cTemp, 0, 0, 0, 255);
	sprintf_s(cTemp, "Closest Node: %i", NM.GetClosestNode());
	stringRGBA(screen, 25, 260, cTemp, 0, 0, 0, 255);
}

int Play::Status()
{
	return m_iIsRunning;
}

void Play::Dispose()
{
	SDL_FreeSurface(m_Background);
}

void Play::MouseUpEvent(SDL_Event* event)
{
	Scene::MouseUpEvent(event);
	m_bButtonUsed = false;
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

int Play::FindNearestNode(Node* pn)
{
	int iNode = -1;
	float fNodeDistance = 0;
	float temp = 0;
	float tempX1 = 0, tempX2 = 0, tempY1 = 0, tempY2 = 0;
	for (int i = 0; i < 7; i++)
	{
		//If it's on the node then that is the nearest node
		if (pn->GetX() == NM.GetNodeX(i) && pn->GetY() == NM.GetNodeY(i))
		{
			iNode = i;
			break;
		}

		//swaps the x depending on who is on the left most
		if (NM.GetNodeX(i) > pn->GetX())
		{
			tempX1 = pn->GetX();
			tempX2 = NM.GetNodeX(i);
		}
		else
		{
			tempX1 = NM.GetNodeX(i);
			tempX2 = pn->GetX();
		}
		//swaps the y depending on who is on the higher
		if (NM.GetNodeY(i) > pn->GetY())
		{
			tempY1 = NM.GetNodeY(i);
			tempY2 = pn->GetY();
		}
		else
		{
			tempY1 = pn->GetY();
			tempY2 = NM.GetNodeY(i);
		}

		//Distance formula
		temp = sqrtf(powf((tempX2 - tempX1), 2)+ powf((tempY2 - tempY1),2));
		if (temp < fNodeDistance || fNodeDistance == 0) 
		{
			iNode = i;
			fNodeDistance = temp;
		}
	}
	return iNode;
}

void Play::UpdateTargetNodes(Node* n)
{
	//Get Node ID used because all nodes are starting 1, array is starting 0
	NM.SetCurrentNode(NM.GetNodeID(FindNearestNode(n)));
	//CurrentNode - 1 because Current Node is the ID, and the ID is +1 compared to the array.
	//ClosestNode same as above.
	NM.SetNextNode(NM.GetSolution(NM.GetCurrentNode()-1, NM.GetClosestNode()-1));
}

void Play::MoveBad(float fdt)
{
	float tempDeg = 0, fDeg = 0, nodeX = 0, nodeY = 0, badX = 0, badY = 0, fMov = 60;

	//Sets the angle the bad guy is going to be moving on.
	nodeX = NM.GetNodeX(NM.GetNextNode()-1);
	nodeY = NM.GetNodeY(NM.GetNextNode()-1);
	badX = badNode.GetX();
	badY = badNode.GetY();
	tempDeg = atan((nodeX-badX)/(badY-nodeY))*180/M_PI;
	
	//Sets the final angle depending on the higher most node used
	if (nodeY > badY)
	{
		tempDeg+=180;
	}
	fDeg = tempDeg;
	//sets the angle to radians
	fDeg = (fDeg*M_PI/180);
	
	//calcualtes and sets the the new coordinates for the badguy.
	float moveX = 0, moveY = 0;
	moveX = (fMov * fdt) * sin(fDeg);
	moveY = (fMov * fdt) * cos(fDeg);
	badX += moveX;
	badY -= moveY;
	badNode.SetX(badX);
	badNode.SetY(badY);

	//checks how close the badguy is to the node and if close enough makes it jump to it.
	if (true == CollisionCheck(NM.GetNodeX(NM.GetNextNode()-1), NM.GetNodeY(NM.GetNextNode()-1), 5, badNode.GetX(), badNode.GetY(), 5))
	{
		badNode.SetX(NM.GetNodeX(NM.GetNextNode()-1) -1);
		badNode.SetY(NM.GetNodeY(NM.GetNextNode()-1) -1);
		//Once it's jumped it checks to see where it needs to go next.
		UpdateTargetNodes(&badNode);
	}
}

void Play::DrawNodes(SDL_Surface* screen)
{
	for (int i = 0; i < 7; i++)
	{
		filledCircleRGBA(screen, NM.GetNodeX(i), NM.GetNodeY(i), 1, 200, 200, 0, 255);
	}
}

bool Play::CollisionCheck(float p1X, float p1Y, float p1S, float p2X, float p2Y, float p2S)
{
	//Uses Circle Collision
	if (sqrt(pow((p2X-p1X),2)+pow((p2Y-p1Y),2)) <= p1S + p2S)
		{return true;}
	else
		{return false;}
}