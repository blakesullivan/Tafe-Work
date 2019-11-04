//Blake Sullivan - Object.h
#ifndef OBJECT_H
#define OBJECT_H

#include "SDL_gfxPrimitives.h"
#include "SDL_rotozoom.h"
#include "StateHeader.h"
#include <string>
using std::string;

class Object
{
protected:
	int m_iID;
	int m_iType;
	int m_iState;	//State of the object
	float m_fX, m_fY;
	float m_fRadius;	//Circle Collision Detection, can be modified for Square
	int m_iDamage;	//Damage this object will do
	SDL_Surface* m_Surface;

public:
	Object();

	virtual void Draw(SDL_Surface* screen, float fDeltaTime) = 0;
	virtual void Update(float fDeltaTime) = 0;
	virtual void Collide(int type, int id, int damage) = 0;
	virtual void Dispose() = 0;

	void SetID(int);
	void SetType(int);
	void SetState(int);
	void SetX(float);
	void SetY(float);
	void SetRadius(float);
	void SetDamage(int);
	void SetSurface(string);

	int GetID();
	int GetType();
	int GetState();
	float GetX();
	float GetY();
	float GetRadius();
	int GetDamage();
	SDL_Surface* GetSurface();
};

#endif