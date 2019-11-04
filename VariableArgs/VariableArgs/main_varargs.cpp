#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <stdarg.h>

void PrintStuff (const char* Format, ...) 
{
	va_list Args;
	va_start(Args, Format);

	double FArg;
	int IArg;
	char CArg;
	
	for (int i = 0; Format[i] != '\0'; ++i) 
	{
		if (Format[i] == 'f') 
		{
			FArg = va_arg(Args, double);
			cout << "Found a float: " << FArg << endl;
		}
		else if (Format[i] == 'i') 
		{
			IArg = va_arg(Args, int);
			cout << "Found an int: " << IArg << endl;
		}
		else if (Format[i] == 'c') 
		{
			CArg = va_arg(Args, char);
			cout << "Found a char: " << CArg << endl;
		}
		else 
		{
			cout << "Unknown type: " << Format[i] << endl;
		}
	}

	va_end(Args);
}

int main() 
{
	PrintStuff("iiffifccx", 200, 42, 3.1415, 6666.9999, 1000, 9.9, 2, '#', 'x');

	cout << endl << "End of arguments." << endl;
	cin.get();

	return 0;
}