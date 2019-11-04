//Blake Sullivan - Shopping List
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	vector<string> vsList(1);
	vector<string>::iterator vsListIt;
	bool bExit = false;
	string sInput = "";
	int iInput = 0, iCount = 0;;
	do
	{
		cout << "Welcome to Blakes Shopping List.\n 1. Add List\n 2. View List\n 3. Delete Item\n 4. Exit\nPlease enter the number of the option you want: ";
		getline(cin, sInput);
		iInput = atoi(sInput.c_str());
		switch (iInput)
		{
		case 1: //Add List
			sInput = "";
			cout << "\nEnter the item for the list: ";
			getline(cin, sInput);
			vsList.push_back(sInput);
		break;
		case 2: //View List
			cout << "\nYour list contains:" << endl;
			for (vsListIt = vsList.begin(); vsListIt != vsList.end(); vsListIt++)
			{
				cout << (*vsListIt) << endl;
			}
		break;
		case 3: //Delete Item
			iCount = 0;
			cout << "\nPlease enter the item you want to remove: ";
			getline(cin, sInput);
			for (vsListIt = vsList.begin(); vsListIt != vsList.end(); vsListIt++)
			{
				//cout << iCount << ": sInput.compare((*vsListIt) = " << sInput.compare((*vsListIt)) << endl;
				if (sInput.compare((*vsListIt)) == 0)
				{
					vsList.erase(vsListIt);
					break;
				}
				iCount++;
			}
		break;
		default: //Exit
			bExit = true;
		}
		cout << endl;
	} while (bExit == false);
	return 0;
}