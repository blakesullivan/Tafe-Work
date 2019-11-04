#include "FPSUtility.h"

int FPSUtility::frameRate=0;		
int FPSUtility::lastFrameRate=0;
int FPSUtility::lastTick=0;

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