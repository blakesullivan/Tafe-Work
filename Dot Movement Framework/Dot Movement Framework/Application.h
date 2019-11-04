//Blake Sullivan - Application.h
#ifndef APPLICATION_H
#define APPLICATION_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
//#include "ScenePos.h"
#include "Splash.h"
#include "Menu.h"
#include "Options.h"
#include "Play.h"

using namespace std;

class Application
{
private:
	//enum scenePos {sceneQuit = -2, sceneRunning = -1, sceneSplash = 0, sceneMenu = 1, sceneOptions = 2, scenePlay = 3};
	//The attributes of the screen 
	const static int SCREEN_WIDTH = 800; 
	const static int SCREEN_HEIGHT = 608; 
	const static int SCREEN_BPP = 32; //Bits Per Pixel

	SDL_Surface *screen; //the pointer to the screen in memory
	bool m_bIsRunning;

	Scene *myScene;

public:
	Application();
	~Application();

	void Init();
	void Run();
};

#endif