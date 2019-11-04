//Blake Sullivan - Manager.cpp
#include "Manager.h"
Manager::Manager()
{
	screen = NULL; //the pointer to the screen in memory
	player = NULL;   //the pointer to the image of the player
	tmp = NULL;
	thefont = NULL; //we will use this for text
	badguy = NULL;
	pi = 3.14159265f;
	Play();
}

int Manager::Play()
{
	SDL_Event event;
	srand((unsigned)time(0));
	bool bgameRunning= true;
	bool keysHeld[323];
	int iFrame=0;
	FPSUtility fps;
	char sFps[255];
	int direction=0;
	int deltaTime = 0;
	int thisTime = 0;
	int lastTime = 0;
	int mouse_x=0, mouse_y=0;
	int deltaTime2 = 0;
	int thisTime2 = 0;
	int lastTime2 = 0;
	gplayer play;
	bbadguy bad[5];
	for (int i=0;i<5;i++)
	{
		
		 bad[i].setX(rand()%700+1);
		 bad[i].setY(rand()%500+1);
	}

	for (int i=0; i<322; i++)
	{
		keysHeld[i] = false; // everything will be initialized to false
	}
    //Initialize all SDL subsystems 
	if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 ) 
	{ return 1; } 

    //Set up the screen 
	screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE ); 
	//screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_DOUBLEBUF|SDL_SWSURFACE);

	//If there was an error in setting up the screen 
	if( screen == NULL ) { return 1; } 
	//Set the window caption 
	SDL_WM_SetCaption( "SDL Work", NULL ); 

	
	//The initialisation
	thefont = SDL_LoadBMP( "font1.bmp" );
	
	player = SDL_LoadBMP( "Red2.bmp" ); //Setting the player to point at the image
	SDL_SetColorKey(player,SDL_SRCCOLORKEY, SDL_MapRGB(player->format, 69, 78, 91) ); 	//Black is the transparent colour 
	badguy = SDL_LoadBMP( "Guard.bmp" ); //Setting the player to point at the image
	SDL_SetColorKey(badguy,SDL_SRCCOLORKEY, SDL_MapRGB(badguy->format, 69, 78, 91) ); 	//Black is the transparent colour 
	bull = SDL_LoadBMP("bullet.bmp");
	SDL_SetColorKey(bull, SDL_SRCCOLORKEY, SDL_MapRGB(bull->format, 255, 255, 255));
	
	//Fill the screen white 
	SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) ); 
	while (bgameRunning)
	{	// check for any events from the user or the system
		SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 50, 200, 100 ) ); 
		
		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				bgameRunning = false;
			}
			if (event.type == SDL_KEYDOWN)
			{
				keysHeld[event.key.keysym.sym] = true;
			}
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				if (event.button.button == SDL_BUTTON_LEFT) 
				{
					Bullet tempBullet;
					tempBullet.set(play.getX(), play.getY(), play.getDir(), 'p');
					bullets.push_back(tempBullet);
				}
			}
			if (event.type == SDL_KEYUP)
			{
				keysHeld[event.key.keysym.sym] = false;
			}
		}
		thisTime2 = SDL_GetTicks();
		deltaTime2 = thisTime2 - lastTime2;
		if(deltaTime2 > 50)
		{
			if ( keysHeld[SDLK_LEFT] || keysHeld[SDLK_a] )
			{
				play.moveLeft();
			}
			if ( keysHeld[SDLK_RIGHT] || keysHeld[SDLK_d] )
			{
				play.moveRight();
			}
			if ( keysHeld[SDLK_UP] || keysHeld[SDLK_w] )
			{
				play.moveUp();
			}
			if (keysHeld[SDLK_DOWN] || keysHeld[SDLK_s])
			{
				play.moveDown();
			}
			lastTime2 = thisTime2;
		}
		play.setDirection(getDegreeToTarget(play.getX(),play.getY(),mouse_x,mouse_y));
		//rectangleRGBA(screen,x1, y1,x2,y2,255, 1, 1, 100);
		play.draw(screen, player, tmp);

		for (bulletsIt = bullets.begin(); bulletsIt < bullets.end();)
		{
			bulletsIt->move(deltaTime2);
			bulletsIt->draw(screen, bull);
			if (bulletsIt->getX() > SCREEN_WIDTH || bulletsIt->getX() < 0)
			{
				bullets.erase(bulletsIt);
			}
			else if (bulletsIt->getY() > SCREEN_HEIGHT || bulletsIt->getY() < 0)
			{
				bullets.erase(bulletsIt);
			}
			else
			{bulletsIt++;}
		}

		for (int i=0;i<5;i++)
		{
			if(bad[i].getLife()==true)
			{	
				if(CollisionCheck(play.getX(),play.getY(), play.getR(), bad[i].getX(), bad[i].getY(), bad[i].getR())==true)
				{
					bad[i].setLife(false);
				}
				for (bulletsIt = bullets.begin(); bulletsIt < bullets.end();)
				{
					if (CollisionCheck(bulletsIt->getX(),bulletsIt->getY(), 10, bad[i].getX(), bad[i].getY(), bad[i].getR())==true)
					{
						bullets.erase(bulletsIt);
						bad[i].setLife(false);
					}
					else
						{bulletsIt++;}
				}
			}
		}
		
		for (int i=0;i<5;i++)
		{

			if (bad[i].getLife()==true)
			{
				bad[i].draw(screen, badguy, iFrame);
			}

		}
		//SDL_BlitSurface(player, &sclip, screen, &dclip);

		thisTime = SDL_GetTicks();
		deltaTime = thisTime - lastTime;
		
		if(deltaTime>1000)
		{
			iFrame++;
			if (iFrame>4) {iFrame=0;}
			lastTime = thisTime;
		}
		if(iFrame>=4)
			iFrame=0;
		
		//Using the function to draw text on the screen at 100,100
		//myDrawText("Hello World", 100, 100);

		//sprintf(sFps,"Frames Per Second: %d",fps.CalculateFrameRate());
		//myDrawText(sFps, 20, 500);

		//SDL_Delay( 100 );

		SDL_GetMouseState(&mouse_x, &mouse_y);
		//Update the screen 
		if( SDL_Flip( screen ) == -1 ) { return 1; } 
	}

	// Clean up after your self before leaving
	SDL_FreeSurface(player);
	SDL_FreeSurface(thefont);
	SDL_FreeSurface(tmp);
	SDL_FreeSurface(badguy);
	SDL_FreeSurface(bull);
    SDL_Quit();

    return 0;  
}

void Manager::myDrawText(char s[], int x, int y)
{
	int k;
	SDL_Rect sclip, dclip;

	for (k=0;k<strlen(s);k++)
	{
		sclip.x = 16*(int(s[k])%16); sclip.y = 16*(int(s[k])/16); sclip.w = 16; sclip.h = 16;

		dclip.x = x+(k*16); dclip.y = y; dclip.w = 16; dclip.h = 16;

		SDL_BlitSurface(thefont, &sclip, screen, &dclip);
	}
}

bool Manager::CollisionCheck(int x1,int y1, int r1, int x2, int y2, int r2)
{

	if (sqrt(pow((float)(x2-x1),2) + pow((float)(y2 - y1),2)) <= r1+ r2) 
		{return true;}
	else
		{return false;}
}


int Manager::getDegreeToTarget(double xpos1, double ypos1, double xpos2, double ypos2) 
{
	float value;

	value = atan2(ypos2 - ypos1, xpos2 - xpos1);
	value = value * (180 / M_PI) + 90;
	return value;
}