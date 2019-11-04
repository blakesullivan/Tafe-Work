#include "WelcomeOop_Sullivan.h"

int main()
{
	WelcomeOop welcomeObj_1;
	WelcomeOop welcomeObj_2( "This is another line!\n" );

	welcomeObj_2.DisplayMessage( "Hope this compiles!\n" );
	welcomeObj_2.greeting = "Lets hope this shit works.";
	welcomeObj_1.DisplayMessage(welcomeObj_2.greeting);
	system("PAUSE");
	return 0;
}