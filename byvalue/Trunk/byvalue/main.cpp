// passing parameters by value
#include <iostream>
using namespace std;

void duplicate (int a, int b, int c)
{
  a*=2;
  b*=2;
  c*=2;
}
int main ()
{
  int a=1, b=3, c=7;
  duplicate (a, b, c);
  cout << "a=" << a << ", b=" << b << ", c=" << c<<endl;
  return 0;
}
