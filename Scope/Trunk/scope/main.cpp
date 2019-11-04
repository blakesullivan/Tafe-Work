// function example
#include <iostream>
using namespace std;
int iNum1=1;//global variable
void scope();
int main ()
{
	int iNum2=2;
	cout<<"Main Function iNum1: "<<iNum1<<endl;
	cout<<"Main function iNum2:" <<iNum2<<endl;//local varaible to main
	scope();
	for(int iNum2=0;iNum2<10;iNum2++)//iNum2 local to for
	{
		cout<<"For loop iNum2:" <<iNum2<<endl;
		cout<<"For loop iNum1:" <<iNum1<<endl;
	}
	if(iNum2==2)
	{
		int iNum1=0;//iNum1 local to if
		cout<<"if block iNum1: "<<iNum1<<endl;
	}
	cout<<"Main Function iNum1: "<<iNum1<<endl;
	return 0;
}
void scope()
{
	int iNum2=10;
	if(iNum1==1)
		cout<<"Scope Function iNum1: "<<iNum1<<endl;
	cout<<"Scope function iNum2:" <<iNum2<<endl;//iNum2 local to scope function
}