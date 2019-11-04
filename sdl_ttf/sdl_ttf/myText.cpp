#include "myText.h"
typedef std::map<std::string, TTF_Font*>::iterator FontIterator;

myText::myText()
{
	TTF_X = 0;
	TTF_Y = 0;
}
myText::~myText()
{
	//Close();
}

TTF_Font* myText::GetFont(std::string key) 
{		
	FontIterator pos = m_Fonts.find(key);
	if (pos == m_Fonts.end()) {return NULL;}
	return pos->second;	
}	

void myText::CloseFont(TTF_Font* font) 
{		
	if (font != NULL) 
	{			
		TTF_CloseFont(font);			
		font = NULL;		
	}	
}	

void myText::CloseFont(std::string key) 
{		
	CloseFont(GetFont(key));		
	FontIterator pos = m_Fonts.find(key);		
	if (pos != m_Fonts.end())
		{m_Fonts.erase(pos);}
}	

bool myText::Initialize() 
{		
	if(TTF_Init() == -1) 
		{return false;}
	else 
		{return true;}
}	

void myText::Close() 
{		
	for (FontIterator pos = m_Fonts.begin(); pos != m_Fonts.end(); ++pos) 
		{CloseFont(pos->second);}		
	TTF_Quit();	
}	

bool myText::LoadFont(std::string key, std::string filename, int fontSize) 
{		
	std::fstream fin; 		
	fin.open(filename.c_str(), std::ios::in);		
	if (fin.is_open()) 
	{ // Check if the file exists			
		fin.close();			
		TTF_Font* font = TTF_OpenFont(filename.c_str(), fontSize);			
		if (font == NULL) 
		{				
			printf("TTF_OpenFont: %s\n", TTF_GetError());				
			return false;			
		}			
		m_Fonts[key] = font;			
		DefaultFont = key;			
		return true;		
	}		
	fin.close();		
	return false;	
}	

SDL_Surface* myText::MakeTextSurface(std::string text, TTF_Font* font, int r, int g, int b)
{
	SDL_Surface* txtSurface;
	SDL_Color colour = {r, g, b, 0};

	if(!(txtSurface = TTF_RenderText_Solid(font,text.c_str(), colour)))
	{
		printf("TTF_Print: %s\n", TTF_GetError());
		if(txtSurface != NULL)
			SDL_FreeSurface(txtSurface);
		return NULL;
	}
	return txtSurface;
}

int myText::FontHeight(std::string key)
{
	TTF_Font *font = GetFont(key);

	if(font != NULL) {return TTF_FontHeight(font);}
	return 0;
}

bool myText::Print(int x, int y, std::string text, int r, int g, int b, int halign, int valign, std::string fontKey)
{
	/*			FIND THE FONT		*/
	TTF_Font* FontTTF;
	if (fontKey == "default")
	{
		FontTTF = GetFont(DefaultFont);
	}
	else
	{
		FontTTF = GetFont(fontKey);
	}
	if (FontTTF == NULL) { // Choose any font if there isn't a default
		for (FontIterator pos = m_Fonts.begin(); pos != m_Fonts.end(); ++pos)
		{
			FontTTF = GetFont(pos->first);
			if (FontTTF != NULL)
			{
				break;
			}
		}
	}
	if (FontTTF == NULL)
	{
		return false; // exit if there isn't font
	}

	// Create the surface and paint
	SDL_Surface* txtSurface = MakeTextSurface(text, FontTTF, r, g, b);
	if (txtSurface != NULL) 
	{
		SDL_Rect dest;
		switch (halign) 
		{
		case 1: // Center
			dest.x = x - (int)(txtSurface->w/2);
		break;
		case 2: // Right
			dest.x = x - (int)txtSurface->w;
		break;
		default: // Left
			dest.x = x;
		}
		switch (valign) 
		{
		case 1: // Center
			dest.y = y - (int)(txtSurface->h/2);
		break;
		case 2: // Bottom
			dest.y = y - (int)txtSurface->h;
		break;
		default: // Top
			dest.y = y;
		}

		SDL_BlitSurface(txtSurface, NULL, screen, &dest);
		SDL_FreeSurface(txtSurface);
		return true;
	}
	else
	{
		return false;
	}
}

