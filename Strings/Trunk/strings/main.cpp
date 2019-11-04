//Strings
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	string sName;
//	cout<<"Enter your name: ";
//	getline(cin,sName);
//	cout<<"Hello "<<sName<<endl;
//	system("PAUSE");
//	return 0;
//}

//String constructor
/*#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s0 ("Initial string");

	//constructors used in the same order as described above:
	string s1;
	string s2 (s0);
	string s3 (s0, 8, 3);
	string s4 ("A character sequence", 6);
	string s5 ("Another character sequence");
	string s6 (10, 'x');
	string s7a (10, 42);
	string s7b (s0.begin(), s0.begin()+7);

	cout << "s1: " << s1 << "\ns2: " << s2 << "\ns3: " << s3;
	cout << "\ns4: " << s4 << "\ns5: " << s5 << "\ns6: " << s6;
	cout << "\ns7a: " << s7a << "\ns7b: " << s7b << endl;
	system("PAUSE");
	return 0;
}*/

//Concating strings
/*#include <iostream>
#include <string>
using namespace std;

int main()
{
	string sFName, sLName, sFullName;
	cout<<"Enter your first name: ";
	cin>>sFName;
	cout<<"Enter your last name: ";
	cin>>sLName;
	sFullName=sFName + " " + sLName;
	cout<<"Hello "<<sFullName<<endl;
	system("PAUSE");
	return 0;
}*/

//string::substr
/*#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str="We think in generalities, but we live in details.";
								// quoting Alfred N. Whitehead
	string str2, str3;
	size_t pos;

	str2 = str.substr(12,12); // "generalities"
	pos = str.find("live"); //position of "live" in str
	str3 = str.substr(pos); //get from "live" to the end

	cout << str2 << ' ' << pos << ' ' << str3 << endl;

	system("PAUSE");
	return 0;
}*/

// comparing apples with apples
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str1 ("green apple");
	string str2 ("red apple");

	if (str1.compare(str2) != 0)
		cout << str1 << " is not " << str2 << endl;

	if (str1.compare(6,5,"apple") == 0)
		cout << "still, " << str1 << " is an apple\n";

	if (str2.compare(str2.size()-5,5,"apple") == 0)
		cout << "and " << str2 << " is also an apple\n";

	if (str1.compare(6,5,str2,4,5) == 0)
		cout << "therefore, both are apples\n";




	system("PAUSE");
	return 0;
}