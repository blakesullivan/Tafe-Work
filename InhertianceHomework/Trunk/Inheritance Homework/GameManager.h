//Blake Sullivan - GameManager.h
#ifndef GAMEMANAGER
#define GAMEMANAGER

#include "ChessBoard.h"
#include "RosesCard.h"

class GameManager
{
private:
	ChessBoard m_CB;
	RosesCard m_RC;
	bool bExit;
public:
	GameManager();

	void Display();
};
#endif