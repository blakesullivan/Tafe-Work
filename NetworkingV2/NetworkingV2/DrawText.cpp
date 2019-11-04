//Blake Sullivan - DrawText.cpp
#include "DrawText.h"

DrawText::DrawText()
{
	thefont = NULL;
	thefont = SDL_LoadBMP("font.bmp");
	SDL_SetColorKey(thefont, SDL_SRCCOLORKEY, SDL_MapRGB(thefont->format, 0, 0, 0));
}

DrawText::~DrawText()
{
	SDL_FreeSurface(thefont);
}

void DrawText::DrawTextToSurface(SDL_Surface* screen, string s, int x, int y)
{
	int k;
	SDL_Rect sclip, dclip;

	for (k=0;k<strlen(s.c_str());k++)
	{
		sclip.x = 16*(int(s[k])%16); sclip.y = 16*(int(s[k])/16); sclip.w = 16; sclip.h = 16;

		dclip.x = x+(k*16); dclip.y = y; dclip.w = 16; dclip.h = 16;

		SDL_BlitSurface(thefont, &sclip, screen, &dclip);
	}
}