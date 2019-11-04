// Using the bitwise AND, bitwise inclusive OR, bitwise exclusive OR and bitwise complement operators.
#include <iostream>
using std::cout;

#include <iomanip>
using std::endl;
using std::setw;

void displayBits(unsigned);

int main()
{
	unsigned number1;
	unsigned number2;
	unsigned mask;
	unsigned setBits;

	number1 = 2179876355;			//demonstrate bitwise &
	mask = 1;
	cout << "The result of combining the following\n";
	displayBits(number1);
	displayBits(mask);
	cout << "using bitwise AND operator & is\n";
	displayBits(number1 & mask);

	number1 = 15;					//demonstrate bitwise |
	setBits = 241;
	cout << "\nThe result of combining the following\n";
	displayBits(number1);
	displayBits(setBits);
	cout << "using the bitwise inclusive OR operate | is\n";
	displayBits(number1 | setBits);

	number1 = 139;					//demonstrate bitwise exclusive OR
	number2 = 199;
	cout << "\nThe result of combining the following\n";
	displayBits(number1);
	displayBits(number2);
	cout << "using the bitwise exclusive OR operator ^ is\n";
	displayBits(number1 ^ number2);

	number1 = 21845;				//demonstrate bitwise complement
	cout << "\nThe one's complement of\n";
	displayBits(number1);
	cout << "using the bitwise complement ~ operator is" << endl;
	displayBits(~number1);

	system("PAUSE");
	return 0;
}

void displayBits(unsigned value)
{
	const int SHIFT = 8 * sizeof(unsigned);
	cout << SHIFT << endl;
	const unsigned MASK = 1 << SHIFT-1;

	cout << "Mask " << MASK << endl;

	cout << setw(10) << value << " = ";

	for (unsigned i = 1; i < SHIFT + 1; i++)	//display bits
	{
		cout << (value & MASK ? '1' : '0');
		value <<= 1;							//shift value left by 1

		if (i % 8 == 0)
			{cout << ' ';}
	}
	cout << endl;
}