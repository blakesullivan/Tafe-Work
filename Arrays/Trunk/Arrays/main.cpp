//arrays example
/*#include <iostream>
using namespace std;

int billy [] = {16, 2, 77, 40, 12071};
int n, result=0;

int main ()
{
	for ( n=0 ; n<5 ; n++ )
	{
		result += billy[n];
	}
	cout << "The result is: " << result << endl;
	system("PAUSE");
	return 0;
}*/

//arrays example 2
#include <iostream>
using namespace std;

int element[] = {1,2,3,4,5,6,7,8,9,10};

int main()
{
	for (int i=0; i<10 ; i++)
	{
		cout<<"element["<<i<<"] = "<<element[i]<<endl;
	}
	system("PAUSE");
	return 0;
}