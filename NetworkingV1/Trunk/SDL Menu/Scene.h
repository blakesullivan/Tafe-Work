//Blake Sullivan - Scene.h
#ifndef SCENE_H
#define SCENE_H

#include "SDL.h"   /* All SDL App's need this */
#include "SDL_gfxPrimitives.h"
#include "ScenePos.h"

class Scene
{
protected:
	int m_iIsRunning;
	bool m_bKeyHeld[323];
	bool m_bButtonHeld[13];

public:
	virtual void Init() = 0;
	virtual void Event(SDL_Surface* screen, SDL_Event *event, float fDeltaTime) = 0;
	virtual void Update(SDL_Surface* screen, float fDeltaTime) = 0;
	virtual void Draw(SDL_Surface* screen, float fDeltaTime) = 0;
	virtual int Status() = 0;
	virtual void Dispose() = 0;
};
#endif