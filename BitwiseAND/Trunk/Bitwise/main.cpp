//Printing an unsigned integer in bits.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <iomanip>
using std::setw;

void displayBits(unsigned);

int main()
{
	unsigned inputValue;
	bool bExit = false;

	while (bExit == false)
	{
		cout << "Enter an unsigned integer (0 to Exit): ";
		cin >> inputValue;
		displayBits(inputValue);

		if (inputValue == 0)
			{bExit = true;}
	}
	system("PAUSE");
	return 0;
}

void displayBits(unsigned value)
{
	const int SHIFT = 8 * sizeof(unsigned);
	cout << "SHIFT: " << SHIFT << endl;
	const unsigned MASK = 1 << SHIFT-1;

	cout << "Mask: " << MASK << endl;

	cout << setw(10) << value << " = ";

	for (unsigned i = 1; i < SHIFT + 1; i++)	//display bits
	{
		cout << (value & MASK ? '1' : '0');
		value <<= 1;							//shift value left by 1

		if (i % 8 == 0)							//output a space after 8 bits
			{cout << ' ';}
	}
	cout << endl;
}