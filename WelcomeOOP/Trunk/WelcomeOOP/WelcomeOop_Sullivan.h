#include <string>
using namespace std;

class WelcomeOop
{
private:

public:
	WelcomeOop();				//Constructors
	WelcomeOop( string );

	void DisplayMessage( string );	//Functions
	string greeting;			//Variables
};
//#endif