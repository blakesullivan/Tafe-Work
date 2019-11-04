//Blake Sullivan - Main.cpp
#include "CardServer.h"
#include "QuakeServer.h"
#include <iostream>
int main (int argc, char *argv[])
{
	int iInput;
	std::cout << "Which Server are you running?\n 1. Card Server\n 2. Quake Server\n";
	std::cin >> iInput;
	if (iInput == 1)
		{CardServer cs;}
	else if (iInput == 2)
		{QuakeServer qs;}
	return 0;
}