//Blake Sullivan - Exercise 1
# include <iostream>
using namespace std;
int main()
{
	int iNum = 0;
	int i;
	for (i=2; i<100; i++)
	{
		iNum += i;
	}
	cout<< "The sum of all numbers below 100, starting at 2 = " <<iNum<<endl;
	return 0;
}