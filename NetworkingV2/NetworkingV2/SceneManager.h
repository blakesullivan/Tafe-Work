//Blake Sullivan - SceneManager.h
#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
//#include "ScenePos.h"
#include "Splash.h"
#include "Menu.h"
#include "Options.h"
#include "Play.h"

using namespace std;

class SceneManager
{
private:
	//enum scenePos {sceneQuit = -2, sceneRunning = -1, sceneSplash = 0, sceneMenu = 1, sceneOptions = 2, scenePlay = 3};
	//The attributes of the screen 
	const static int SCREEN_WIDTH = 1024; //1024; 
	const static int SCREEN_HEIGHT = 672; //768; 
	const static int SCREEN_BPP = 32; //Bits Per Pixel

	SDL_Surface *screen; //the pointer to the screen in memory
	bool m_bIsRunning;

	Scene *myScene;

public:
	SceneManager();
	~SceneManager();

	void Init();
	void Run();
};

#endif