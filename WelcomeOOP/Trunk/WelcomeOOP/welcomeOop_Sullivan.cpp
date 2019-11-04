#include <iostream>
using namespace std;
#include <string>
using namespace std;
#include "WelcomeOop_Sullivan.h"

WelcomeOop::WelcomeOop()
{
	cout << "Welcome to C++1!\n";
}

WelcomeOop::WelcomeOop( string otherString )
{
	cout << "Welcome to C++2!\n";
	cout << otherString;
}

void WelcomeOop::DisplayMessage( string anotherString )
{
	cout << anotherString;
}