//String Splitting program.
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string sInput, sPrefix, sOutput;
	int x=0;
	cout<<"Please input a sentence: "<<endl;
	getline(cin, sInput);
	/*sInput = "Accept that some days you are the pigeon and some days you are the statue";
	cout<<sInput<<endl;*/
	for (int i = 0; i <= sInput.length(); i++)
	{
		if (sInput[i] == ' ' || i == sInput.length())
		{
			x++;
			if (x==1)
			{sPrefix="st";}
			else if (x==2)
			{sPrefix="nd";}
			else if (x==3)
			{sPrefix="rd";}
			else
			{sPrefix="th";}

			cout<<x<<sPrefix<<" word: "<<sOutput<<endl;
			sOutput = "";
		}
		else
		{
			sOutput += sInput[i];
		}
	}
	system("PAUSE");
	return 0;
}