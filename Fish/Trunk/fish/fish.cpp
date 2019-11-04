#include "fish.h"

fish::fish()
{
    age = 0;
}

int fish::getAge() 
{
	return age;
}

void fish::setAge(int newage) 
{
	age = newage;
}