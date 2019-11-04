//Blake Sullivan - FPSUtility.h
#ifndef FPSUTILITY
#define FPSUTILITY
#include "SDL.h"   /* All SDL App's need this */

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