#include "FPS Modulator.h"

FPS_Modulator::FPS_Modulator()
{
	deltatime=0;
	lasttime=0;
	modulator=0;
	thistime=0;
	FPS=25;
}
void FPS_Modulator::CalcMod() //This calculates the modulating number
{
	thistime=SDL_GetTicks(); //Gets the number of milliseconds since some time and date in 1980 (or 1979?)
	deltatime=(float)(thistime-lasttime)/1000; /*This equation converts the time to complete the game loop from milliseconds to 
											   seconds*/
	lasttime=thistime; //Store the most recently recorded time for the next time around the loop
	modulator=FPS*deltatime;
	/*As the variable 'modulator' will be quite small, I'll use it to divide initial times for countdown timers and to multiply to
	movement increments.*/
}
void FPS_Modulator::setFPS(int FramesPerSecond) //User can define FPS.  Default is 25
{
	FPS=FramesPerSecond; 
}
float FPS_Modulator::getMod() //This returns the modulating number
{
	return modulator;
}
bool FPS_Modulator::getFrameChange()
{
	fPreCounter=fPostCounter;
	fPostCounter+=getMod(); //Add to the counter the FPS modulator
	if ((int)fPostCounter-(int)fPreCounter>=1) //If there is a difference in the counters as integers then...
	{
		fPostCounter-=1.00; //Makes sure the counter doesn't reach its limit
		return true;
	}
	else
		return false;
}
void FPS_Modulator::forceSetMod(float mod)
{
	modulator=mod;
}