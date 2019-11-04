//Blake Sullivan - ButtonHeader.h
#ifndef BUTTONHEADER_H
#define BUTTONHEADER_H
enum buttonState
{
	bsNorm = 0, 
	bsHigh = 1, 
	bsDown = 2
};
struct Colours
{
	int iRed;
	int iGreen;
	int iBlue;
	int iAlpha;
};
enum buttonDest
{
	buttonSplash,
	buttonMenu,
	buttonOptions,
	buttonPlay,
	buttonHost,
	buttonJoin,
	buttonExit
};
#endif