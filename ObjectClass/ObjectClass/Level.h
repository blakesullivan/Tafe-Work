//Blake Sullivan - Level.h
#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include "Character.h"
#include "Bullet.h"
#include "Pickup.h"
using namespace std;

class Level
{
private:
	vector<Object*> m_vpObj;
	vector<Object*>::iterator m_vpObjIT;

public:
	Level();

	void Init();
	void Update(float fDeltaTime);

	void AddCharacter(int cID, float x, float y, string name, int state);
	void Draw(SDL_Surface* screen, float fDT);
	Character* GetCharacter(int id);
	
	void AddBullet(int cID);

	void AddPickup(int pt, float x, float y);
	
	Object* GetObject(int id);
};

#endif