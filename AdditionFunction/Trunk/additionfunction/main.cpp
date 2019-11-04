//function example
#include <iostream>
using namespace std;
void hello(int);
int addition(int,int);

int main ()
{
	/*int iSum1 = 0;
	int iSum2 = 0;
	int iSum3 = 0;
	iSum1 = addition (5,3);
	iSum2 = addition (10,1);
	iSum3 = addition (11,-7);
	if (addition(5,3)==8)
		iSum=8;*/
	int iSum = 0;
	iSum = addition (5,3);
	hello(2);
	cout << "The result is " << iSum << endl;
	return 0;
}
int addition (int iNum1, int iNum2)
{
	int iSum;
	iSum = iNum1 + iNum2;
	hello(2);
	return iSum;
}
void hello(int iNum)
{
	if(iNum==1)
		addition(5,3);
	cout<<"Hello!"<<endl;
}