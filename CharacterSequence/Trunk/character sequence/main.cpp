//Character Sequence
/*#include <iostream>
using namespace std;
int main ()
{
  char cQuestion[] = "Please, enter your name: ";
  char cGreeting[] = "Hello, ";
  char cYourname [80];
  cout << cQuestion;
  cin >> cYourname;
  cout<<endl << cGreeting << cYourname << "!"<<endl;
  system("PAUSE");
  return 0;
}*/

#include <iostream>
using namespace std;
int main ()
{
  char cQuestion[] = "Please, enter your first name: ";
  char cGreeting[] = "Hello, ";
  char cYourname [80];
  char cMovie[80];
  cout << cQuestion;
  cin.getline(cYourname, 80);// >> cYourname;
  cout<<"Enter you favourite movie ";
  cin.getline(cMovie, 80);//>>cMovie;
  cout<<endl << cGreeting << cYourname << "!";
  cout<<endl<<"Your fav movie is "<<cMovie<<endl;
  system("PAUSE");
  return 0;
}