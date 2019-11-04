//Blake Sullivan - Pickup.h
#ifndef PICKUP_H
#define PICKUP_H

#include "Object.h"

class Pickup : public Object
{
private:
	int m_iPickupType;
	
public:
	Pickup();

	void Init(int pt, float x, float y);

	void Draw(SDL_Surface* screen, float fDeltaTime);
	void Update(float fDeltaTime);
	void Collide(int type, int id, int damage);
	void Dispose();

	void SetTypeDifferences(int pt);

	void SetPickupType(int pt);
	int GetPickupType();
};

#endif