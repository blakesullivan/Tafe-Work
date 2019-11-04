//Blake Sullivan - Level.cpp
#include "Level.h"

Level::Level()
{
	Init();
}

void Level::Init()
{
	AddCharacter(cidBuster, 400, 250, "Buster Eagle", stateAlive);
	AddCharacter(cidPteras, 200, 200, "Pteras", stateAlive);
	AddCharacter(cidRaynos, 800, 100, "Raynos", stateAlive);
	AddCharacter(cidRedler, 600, 450, "Redler", stateAlive);
	AddCharacter(cidStorm, 100, 650, "Storm Sworder", stateAlive);	
	AddCharacter(cidZabat, 850, 600, "Zabat", stateAlive);

	AddPickup(0, 250, 700);
	AddPickup(1, 700, 100);
	AddPickup(2, 850, 495);
}

void Level::AddCharacter(int cID, float x, float y, string name, int state)
{
	Character *temp;
	temp = new Character();
	temp->Init(cID, x, y, name);
	temp->SetState(state);
	temp->SetType(typeCharacter);
	m_vpObj.push_back(temp);
}

void Level::Draw(SDL_Surface* screen, float fDT)
{
	for (int i = m_vpObj.size() - 1; i >= 0; i--)
	{
		if (m_vpObj[i]->GetState() == stateAlive)
			{m_vpObj[i]->Draw(screen, fDT);}
	}
}

void Level::Update(float fDeltaTime)
{
	for (int i = m_vpObj.size() - 1; i >= 0; i--)
	{
		if (m_vpObj[i]->GetState() == stateAlive)
			{m_vpObj[i]->Update(fDeltaTime);}
	}
}

Character* Level::GetCharacter(int id)
{
	for (m_vpObjIT = m_vpObj.begin(); m_vpObjIT != m_vpObj.end(); m_vpObjIT++)
	{
		if ((*m_vpObjIT)->GetType() == typeCharacter)
		{
			Character* c1 = dynamic_cast<Character*>((*m_vpObjIT));
			if (c1->GetCharID() == id)
			{
				return c1;
			}
		}
	}
	return dynamic_cast<Character*>(*m_vpObj.begin());
}
Object* Level::GetObject(int id)
{
	for (m_vpObjIT = m_vpObj.begin(); m_vpObjIT != m_vpObj.end(); m_vpObjIT++)
	{
		if ((*m_vpObjIT)->GetID() == id)
		{
			return (*m_vpObjIT);
		}
	}
	return *m_vpObj.begin();
}

void Level::AddBullet(int cID)
{
	Character* c = GetCharacter(cID);
	Bullet* temp;
	temp = new Bullet();
	temp->Init(cID, c->GetStats()->GetBulletType(), c->GetX(), c->GetY(), c->GetStats()->GetDirection());
	temp->SetState(stateAlive);
	temp->SetType(typeBullet);
	m_vpObj.push_back(temp);
}

void Level::AddPickup(int pt, float x, float y)
{
	//static int iCurrPickup = 0;
	Pickup* temp;
	temp = new Pickup();
	temp->Init(pt, x, y);
	temp->SetState(stateAlive);
	temp->SetType(typePickup);
	m_vpObj.push_back(temp);
	//iCurrPickup++;
	//if (iCurrPickup > 2)
	//{iCurrPickup = 0;}
}