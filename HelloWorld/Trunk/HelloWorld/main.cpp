// my first program in C++
#include <iostream>
//#define PI 3.141592
using namespace std;
const double PI = 3.141592;
int main ()
{
	//Section 1- Output.
	double a=5.56;
	double b=PI;
	double c=0;
	c = a * b;
	//cout << c << endl << endl;
	cout << "Hello World " << c << "!" << endl << "\n";

	//Section 2- Input.
	int iAge=0;
	do{
	cout << "How old are you? \n";
	cin>>iAge;
	cout<< "You are " << iAge << " years old. \n";
	if (iAge > 20) 
	{cout<<"Congrats! You're not young! \n";}
	else
	{cout<<"Wow, you're young! \n";}
	} while (iAge < 50);
	//Ends program
	return 0;
}