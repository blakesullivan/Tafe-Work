//Blake Sullivan - FPSUtility.h
#ifndef FPSUTILITY
#define FPSUTILITY

#include "SDL.h"   /* All SDL App's need this */
#include "SDL_gfxPrimitives.h" 

class FPSUtility
{
private: 
	static int lastTick;
	static int lastFrameRate;
	static int frameRate;

public:
	static int CalculateFrameRate();
};
#endif