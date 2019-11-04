//Blake Sullivan - main.cpp
#include <iostream>
#include <string>
using namespace std;

template <typename T>
T SwapVars(T& v1, T& v2)
{
	T tempV = v1;
	v1 = v2;
	v2 = tempV;
	return v1;
}

template <typename T>
T SortVars(T& v1, T& v2, T& v3)
{
	//bool bSwap = false;
	if (v1 > v2)
		SwapVars(v1, v2);

	if (v2 > v3)
		SwapVars(v2, v3);

	if (v1 > v2)
		SwapVars(v1, v2);

	return v1;
}

//template <typename T>
void SortInt()
{
	int input1, input2, input3;
	std::cout << "\nPlease input a number: ";
	std::cin >> input1;
	std::cout << "\nPlease input a number: ";
	std::cin >> input2;
	std::cout << "\nPlease input a number: ";
	std::cin >> input3;

	std::cout << "\nOrder Before Sort: " << input1 << ", " << input2 << ", " << input3 << std::endl; 

	int tempI = SortVars(input1, input2, input3);
	std::cout << "Sort Complete!\n";
	std::cout << "New Order: " << input1 << ", " << input2 << ", " << input3 << std::endl; 
}
//template <typename T>
void SortDbl()
{
	double input1, input2, input3;
	std::cout << "\nPlease input a decimal: ";
	std::cin >> input1;
	std::cout << "\nPlease input a decimal: ";
	std::cin >> input2;
	std::cout << "\nPlease input a decimal: ";
	std::cin >> input3;

	std::cout << "\nOrder Before Sort: " << input1 << ", " << input2 << ", " << input3 << std::endl; 

	double tempD = SortVars(input1, input2, input3);
	std::cout << "Sort Complete!\n";
	std::cout << "New Order: " << input1 << ", " << input2 << ", " << input3 << std::endl; 
}
//template <typename T>
void SortChar()
{
	char input1, input2, input3;
	std::cout << "\nPlease input a letter: ";
	std::cin >> input1;
	std::cout << "\nPlease input a letter: ";
	std::cin >> input2;
	std::cout << "\nPlease input a letter: ";
	std::cin >> input3;

	std::cout << "\nOrder Before Sort: " << input1 << ", " << input2 << ", " << input3 << std::endl; 

	char tempC = SortVars(input1, input2, input3);
	std::cout << "Sort Complete!\n";
	std::cout << "New Order: " << input1 << ", " << input2 << ", " << input3 << std::endl; 
}
//template <typename T>
int main()
{
	char cInput;
	std::cout << "Welcome to Blakes Sort Using Function Templates Program!\n";

	std::cout << "What would you like to sort:\n 1. Integers\n 2. Decimals\n 3. Characters\nPlease enter the number of the option you want";
	std::cin >> cInput;

	if (cInput == '1')
	{SortInt();}
	//template <typename T>
	if (cInput == '2')
	{SortDbl();}
	//template <typename T>
	if (cInput == '3')
	{SortChar();}

	system("PAUSE");
	return 0;
}