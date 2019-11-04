//Blake Sullivan - Order_Characters
#include <iostream>
using namespace std;
int main()
{
	char cChar1, cChar2, cChar3, cTemp, cAgain;
	char cOrder [3];
	bool bAgain=true;
	bool bPlay=false;

	while(bAgain==true)
	{
		cout<<"Please input 3 characters, they will be sorted into (Number, capital, lower)\nCharacter 1: ";
		cin>>cChar1;
		cOrder[0]=cChar1;
		cout<<"Character 2: ";
		cin>>cChar2;
		cOrder[1]=cChar2;
		cout<<"Character 3: ";
		cin>>cChar3;
		cOrder[2]=cChar3;
		
		for(int iPos = 0; iPos<2; iPos++)
		{
			if (cOrder[iPos] > cOrder[iPos+1])
			{
				//Had to swap around
				cTemp=cOrder[iPos];
				cOrder[iPos]=cOrder[iPos+1];
				cOrder[iPos+1]=cTemp;
				iPos=-1;
			}
		}
		cout<<"Characters in order: "<<cOrder[0]<<", "<<cOrder[1]<<", "<<cOrder[2]<<endl;

		do
		{
			cout<<"Play again? (y/n)"<<endl;
			cin>>cAgain;
			if(cAgain=='y'||cAgain=='Y')
			{
				cout<<endl;
				bAgain=true;
				bPlay=true;
			}
			else if (cAgain=='n'||cAgain=='N')
			{
				bAgain=false;
				bPlay=true;
			}
			else
			{
				cout<<"Invalid input, please try again."<<endl;
				bPlay=false;
			}
		}while (bPlay==false);
	}
	return 0;
}