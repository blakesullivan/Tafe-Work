//Blake Sullivan - GameManager.cpp
#include "GameManager.h"

GameManager::GameManager()
{
	bExit = false;
	m_CB.Init(2, 8, 8, 32);
	m_RC.Init(4, 8, 51, 5);
	Display();
	system("PAUSE");
}

void GameManager::Display()
{
	cout << "GameManager DISPLAY SECTION" << endl;
	cout << "bExit: " << bExit << endl;
}