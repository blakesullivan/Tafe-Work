//constructing vectors
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> myNum(4,100); //four ints with value 100
	vector<int>::iterator myNumIt;
	int count = 0;

	//myNum.push_back(20);
	//myNum.insert(myNum.begin()+2, 20);

	//myNum.pop_back();
	//myNum.erase(myNum.begin()+2);
	//myNum.erase(myNum.end()-2);
	//myNum.erase(myNum.begin(), myNum.begin()+2);


	/*for(int i=0; i<myNum.size(); i++)
	{
		myNum[i]=i;
	}*/

	for(myNumIt=myNum.begin(); myNumIt!=myNum.end(); myNumIt++)
	{
		(*myNumIt) = count;
		count++;
	}

	for(int i=0; i<myNum.size(); i++)
	{
		cout << myNum[i]<<endl;
	}
	//vector<int> myNum(10); //four ints with value 100

	//for(int i=0; i<myNum.size(); i++)
	//{
	//	myNum[i] = i+1;
	//	cout << myNum[i]<<endl;
	//}
	system("PAUSE");
	return 0;
}