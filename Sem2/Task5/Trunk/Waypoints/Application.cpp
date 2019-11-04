//Blake Sullivan - Application.cpp
#include "Application.h"

Application::Application()
{
	Init();
	Run();
}

Application::~Application()
{
	SDL_Quit();
}

void Application::Init()
{
	screen = NULL;
	m_bIsRunning = true;
	//Initialize all SDL subsystems 
	if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 ) 
		{m_bIsRunning = false;} 
    //Set up the screen 
	screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE ); 
	//If there was an error in setting up the screen 
	if( screen == NULL ) {m_bIsRunning = false;} 
	//Set the window caption 
	SDL_WM_SetCaption( "SDL Menu Test", NULL ); 

	myScene = new Splash();
}

void Application::Run()
{
	SDL_Event event;

	float fDeltaTime = 0;
	int iThisTime = 0, iLastTime = 0;
     
	while (m_bIsRunning)
	{	// check for any events from the user or the system
		//SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) ); 

		iThisTime = SDL_GetTicks();
		fDeltaTime = (float)(iThisTime - iLastTime) / 1000;
		iLastTime = iThisTime;

		myScene->Event(screen, &event, fDeltaTime);
		myScene->Update(screen, fDeltaTime);
		myScene->Draw(screen, fDeltaTime);

		if (myScene->Status() != sceneRunning)
		{
			int iTemp = myScene->Status();
			myScene->Dispose();
			delete myScene;
			switch (iTemp)
			{
			case sceneSplash:
				myScene = new Splash();
			break;
			/*case sceneMenu:
				myScene = new Menu();
			break;
			case sceneOptions:
				myScene = new Options();
			break;*/
			case scenePlay:
				myScene = new Play();
			break;
			default:
				m_bIsRunning = false;
				break;
			}
		}
    	//Update the screen 
		if( SDL_Flip( screen ) == -1 ) {m_bIsRunning = false;} 
	}
}