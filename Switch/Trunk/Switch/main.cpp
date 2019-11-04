//This is the program to use Switchs
#include <iostream>
using namespace std;
int main()
{
	int x=0;
	do
	{
	cout<<"What do you want x to be? \n";
	cin>>x;
	switch (x)
	{
	case 1:
		cout<<"x=1";
		break;
	case 2:
		cout<<"x=2";
		break;
	default:
		if (x < 5)
		{
			cout<<"x is unkown.";
		}
		else if (x == 5)
		{
			cout<<"x is 5. Exiting!";
		}
		else
		{
			cout<<"x is over 5 and unkown. Exiting!";
		}
	}
	/*int iNum = 0;
	cout<<"How many fingers do you have on your right hand? \n";
	cin>>iNum;
	switch (iNum)
	{
	case 1:
		cout<<"You only have 1 finger, that's weird.";
		break;
	case 2:
		cout<<"You have 2 fingers, what happened?";
		break;
	case 3:
		cout<<"You have 3 fingers, that had to hurt!";
		break;
	case 4:
		cout<<"You have 4 fingers, that's correct!";
		break;
	case 5:
		cout<<"You have 5 fingers? Where did the extra one grow from?";
		break;
	default:
		cout<<"You have " << iNum << " fingers, I wasn't expecting that.";
	}
	*/
	cout<<endl;
	} while (x < 5);
	return 0;
}