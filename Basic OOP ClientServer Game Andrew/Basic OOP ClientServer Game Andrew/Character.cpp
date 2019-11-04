
#include "Character.h"

Character::Character()
{
	x = 20;
	y = 20;

	alive = false;

	userID = 0;
}


void Character::setX(int nx)
{
	x = nx;
} 

void Character::setY(int ny)
{
	y = ny;
}

int Character::getX()
{
	return x;
}

int Character::getY()
{
	return y;
}

bool Character::getAlive()
{
	return alive;
}

void Character::setAlive(bool nalive)
{
	alive = nalive;
}

void Character::setUserID(int userNum)
{
	userID = userNum;
}

int Character::getUserID()
{
	return userID;
}
