//Blake Sullivan - FPSUtility.cpp
#include "FPSUtility.h"

int FPSUtility::CalculateFrameRate()
{
	if (SDL_GetTicks() - lastTick >= 1000)
	{
		lastFrameRate = frameRate;
		frameRate = 0;
		lastTick = SDL_GetTicks();
	}
	frameRate++;
	return lastFrameRate;
}

int FPSUtility::frameRate=0;		
int FPSUtility::lastFrameRate=0;
int FPSUtility::lastTick=0;