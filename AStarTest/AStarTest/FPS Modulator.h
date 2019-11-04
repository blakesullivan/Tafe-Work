//This is a ready-made Modulator for adjusting variables in an SDL game loop to maintain a user-defined framerate
#ifndef FPS_MODULATOR
#define FPS_MODULATOR
#include "SDL.h"

class FPS_Modulator
{
private:
	float deltatime, modulator, fPreCounter, fPostCounter;
	int lasttime, thistime, FPS;
public:
	FPS_Modulator();
	void CalcMod();
	void setFPS(int=25);
	float getMod();
	bool getFrameChange();
	void forceSetMod(float);
};
#endif