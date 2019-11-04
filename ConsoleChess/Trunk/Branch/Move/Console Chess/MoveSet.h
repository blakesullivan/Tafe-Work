//Blake Sullivan - Movement.h
#ifndef MOVESET_H
#define MOVESET_H
#include <iostream>
using namespace std;

class MoveSet
{
private:
	int iR1;
	int iR2;
	int iL1;
	int iL2;

public:
	MoveSet();

	void Display();

	void SetR1(int);
	void SetR2(int);
	void SetL1(int);
	void SetL2(int);

	int GetR1();
	int GetR2();
	int GetL1();
	int GetL2();
};
#endif