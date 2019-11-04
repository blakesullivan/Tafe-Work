//Blake Sullivan - ButtonHeader.h
#ifndef BUTTONHEADER_H
#define BUTTONHEADER_H

enum buttonState 
{
	buttonNorm = 0, 
	buttonHighlight = 1, 
	buttonDown = 2
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
	buttonSplash = 0,
	buttonMenu = 1,
	buttonOptions = 2,
	buttonPlay = 3,
	buttonExit = 4
};
#endif