//Blake Sullivan - Manager.h
#ifndef MANAGER
#define MANAGER

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <vector>

#include "gplayer.h"
#include "bbadguy.h"
#include "Bullet.h"
#include "FPSUtility.h"

using namespace std;

class Manager
{
private:
	//The attributes of the screen 
	const static int SCREEN_WIDTH = 800; 
	const static int SCREEN_HEIGHT = 600; 
	const static int SCREEN_BPP = 32; 
	float pi;
	vector <Bullet> bullets;
	vector <Bullet>::iterator bulletsIt;

	SDL_Surface *screen;
	SDL_Surface *player;
	SDL_Surface *tmp;
	SDL_Rect sclip,dclip;
	SDL_Surface *thefont;
	SDL_Surface *badguy;
	SDL_Surface *bull;

public:
	Manager();
	int Play();
	void myDrawText(char s[], int x, int y);
	bool CollisionCheck(int x1,int y1, int r1, int x2, int y2, int r2);
	int getDegreeToTarget(double xpos1, double ypos1, double xpos2, double ypos2);
};

#endif