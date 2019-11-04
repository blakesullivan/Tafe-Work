//Blake Sullivan - Manager.cpp
#include "Manager.h"

Manager::Manager()
{
	mp_ll = new LinkedList;
	ManageProgram();
}

Manager::~Manager()
{
	delete mp_ll;
}

void Manager::ManageProgram()
{
	bool bExit = false;
	unsigned int uiOption = 0, uiNum = 0;
	do
	{
		cout << "What do you want to do?\n 1. Add Node\n 2. Delete Node\n 3. View Node\n 4. Add Multiple Nodes\n 5. Delete Full List\n 6. View Full List\n 7. Copy Node\n 8. Exit\nPlease enter numerical value of option you want: ";
		cin >> uiOption;
		switch (uiOption)
		{
		case 1:
			mp_ll->AddNode();
			bExit = false;
		break;
		case 2:
			cout << "What node position do you want to delete? ";
			cin >> uiNum;
			mp_ll->DeleteNode(uiNum);
			bExit = false;
		break;
		case 3:
			cout << "What node position do you want to view? ";
			cin >> uiNum;
			mp_ll->ViewNode(uiNum);
			bExit = false;
		break;
		case 4:
			cout << "How many nodes do you want to add? ";
			cin >> uiNum;
			mp_ll->AddMultNode(uiNum);
			bExit = false;
		break;
		case 5:
			mp_ll->DeleteAll();
			bExit = false;
		break;
		case 6:
			mp_ll->ViewAll();
			bExit = false;
		break;
		case 7:
			cout << "What nodes do you want to copy? ";
			cin >> uiNum;
			mp_ll->CopyNode(uiNum);
			bExit = false;
		break;
		default:
			bExit = true;
		}
	} while (bExit == false);
}