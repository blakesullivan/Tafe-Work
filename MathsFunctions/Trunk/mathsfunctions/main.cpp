//Maths program
#include <iostream>
using namespace std;

float add(float, float);
float subtract(float, float);
float multiply(float, float);
float divide(float, float);

int main ()
{
	bool bReplay=true;
	do
	{
		float fNum1=0;
		float fNum2=0;
		int iChoice=0;
		float fAnswer=0;
		bool bExit=false;
		char cReplay;
		cout<<"Please input 2 numbers."<<endl<<"First Number: ";
		cin>>fNum1;
		cout<<"Second Number: ";
		cin>>fNum2;
		do
		{
			cout << "What would you like to do with these two numbers?\n 1. Add\n 2. Subtract\n 3. Multiply\n 4. Divide"<<endl;
			cin>>iChoice;
			switch (iChoice)
			{
			case 1:
				fAnswer = add(fNum1, fNum2);
				bExit = true;
				break;
			case 2:
				fAnswer = subtract(fNum1, fNum2);
				bExit = true;
				break;
			case 3:
				fAnswer = multiply(fNum1, fNum2);
				bExit = true;
				break;
			case 4:
				fAnswer = divide(fNum1, fNum2);
				bExit = true;
				break;
			default:
				cout<<"Invalid input, please select again."<<endl;
				bExit = false;
			}
		}while (bExit == false);
		cout << "The result is "<< fAnswer <<endl<<endl;

		bExit = false;
		while(bExit==false)
		{
			cout<<"Do you wish to try more numbers? (y/n)"<<endl;
			cin>>cReplay;
			if(cReplay=='y'||cReplay=='Y')
			{
				cout<<endl<<endl;
				bReplay=true;
				bExit=true;
			}
			else if(cReplay=='n'||cReplay=='N')
			{
				return 0;
			}
			else
			{
				cout<<"Invalid input, please try again."<<endl;
				bExit=false;
			}
		}
	}while(bReplay==true);
}
float add(float fNum1, float fNum2)
{
	float fSum;
	fSum = fNum1 + fNum2;
	return fSum;
}
float subtract(float fNum1, float fNum2)
{
	float fSub;
	fSub = fNum1 - fNum2;
	return fSub;
}
float multiply(float fNum1, float fNum2)
{
	float fMult;
	fMult = fNum1 * fNum2;
	return fMult;
}
float divide(float fNum1, float fNum2)
{
	float fDiv;
	if (0==fNum2)
	{
		cout<<"Cannot divide by 0. Result is invalid and changed to 0."<<endl;
		fDiv=0;
	}
	else
	{
		fDiv = fNum1 / fNum2;
	}
	return fDiv;
}