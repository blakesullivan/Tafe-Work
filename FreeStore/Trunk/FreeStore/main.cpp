//Blake Sullivan - main.cpp
#include <iostream>
using namespace std;

int main()
{
	/*int iCard = 12;
	int *piCard1 = &iCard;
	int *piCard2;

	cout << "&iCard = " << &iCard << endl;
	cout << "iCard = " << iCard << endl << endl;

	cout << "&piCard1 = " << &piCard1 << endl;
	cout << "piCard1 = " << piCard1 << endl;
	cout << "*piCard1 = " << *piCard1 << endl << endl;

	piCard2 = new int;
	*piCard2 = */
	int* piNumber = new int;
	*piNumber = 1234;

	cout << "int value = " << *piNumber << " : location = " << piNumber << " : location reference = " << &piNumber << endl;

	double* pdAmount = new double;
	*pdAmount = 1234.56;

	cout << "double value = " << *pdAmount << " : location = " << pdAmount << " : location reference = " << &pdAmount << endl;

	cout << "size of piNumber = " << sizeof(piNumber);
	cout << " : size of *piNumber = " << sizeof(*piNumber) << endl;
	cout << "size of pdAmount = " << sizeof(pdAmount);
	cout << " : size of *pdAmount = " << sizeof(*pdAmount) << endl;
	
	delete piNumber;
	delete pdAmount;

	system("PAUSE");
	return 0;
}