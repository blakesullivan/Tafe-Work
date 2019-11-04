//2D arrays
#include <iostream>
using namespace std;

int main()
{
	int TwoD[2][2]={1,2,3,4};
	for (int i=0; i<2; i++)
	{
		for( int j=1; j>-1; j--)
		{
			cout<<TwoD[i][j]<<endl;
		}
	}
	cout << "This is a Trunk.\n";
	cout << "This is new.\n";
	system("PAUSE");
	return 0;
}
