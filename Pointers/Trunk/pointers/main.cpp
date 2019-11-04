// my first pointer
/*#include <iostream>
using namespace std;

int main()
{
	int firstValue, secondValue;
	int *myPointer;
	myPointer = &firstValue;
	*myPointer = 10;
	myPointer = &secondValue;
	*myPointer = 20;
	cout << "firstValue is " << firstValue << endl;
	cout << "secondValue is " << secondValue << endl;
	system("PAUSE");
	return 0;
}*/

//more pointers
/*#include <iostream>
using namespace std;

int main ()
{
	int firstValue = 5, secondValue = 15;
	int *p1, *p2;

	p1 = &firstValue;	// p1 = address of firstValue
	p2 = &secondValue;	// p2 = address of secondValue
	*p1 = 10;			// value pointed by p1 = 10
	*p2 = *p1;			// value pointed by p2 = value pointed by p1
	p1 = p2;			// p1 = p2 (value of pointer is copied)
	*p1 = 20;			// value pointed by p1 = 20

	cout<<"firstValue is " << firstValue << endl;
	cout<<"secondValue is " << secondValue <<endl;

	system("PAUSE");
	return 0;
}*/

// more pointers, with arrays!
/*#include <iostream>
using namespace std;

int main ()
{
	int numbers[5];
	int *p;
	p = numbers; *p = 10;
	p++; *p = 20;
	p = &numbers[2]; *p = 30;
	p = numbers + 3; *p = 40;
	p = numbers; *(p+4) = 50;
	for (int n=0; n<5; n++)
		cout << numbers[n] << ", ";
	system("PAUSE");
	return 0;
}*/

// increaser
#include <iostream>
using namespace std;

void increase (void* data, int psize)
{
  if ( psize == sizeof(char) )
  { char* pchar; pchar=(char*)data; ++(*pchar); }
  else if (psize == sizeof(int) )
  { int* pint; pint=(int*)data; ++(*pint); }
}

int main ()
{
  char a = 'x';
  int b = 1602;
  increase (&a,sizeof(a));
  increase (&b,sizeof(b));
  cout << a << ", " << b << endl;
  system("PAUSE");
  return 0;
}
