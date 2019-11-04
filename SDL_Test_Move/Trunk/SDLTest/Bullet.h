//Bullet.h
#ifndef BULLET_H
#define BULLET_H
#include "SDL.h"
#include "SDL_gfXPrimitives.h" 
#include <math.h>
extern SDL_Surface *screen;

class Bullet
{
private:
	float fXo, fYo, fRad;
	float fDir;
	bool bAlive;
	int iMov;

public:
	Bullet();

	void Create(float, float, float, int);
	void Draw();
	void Move();
	void Kill();

	float GetX();
	float GetY();
	bool GetAlive();
	float GetSize();

	void SetAlive(bool);
};
#endif