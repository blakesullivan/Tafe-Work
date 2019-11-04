//Blake Sullivan - Square.h
#ifndef SQUARE_H
#define SQUARE_H
#include <iostream>
using namespace std;
class Square
{
private:
	bool bIsWhite;
	int iLocRow;
	int iLocCol;
	int iGridRef;
	int iPiece;

public:
	Square();

	void Display();

	void Init(bool, int, int, int, int);

	void SetIsWhite(bool);
	void SetLocRow(int);
	void SetLocCol(int);
	void SetGridRef(int);
	void SetPiece(int);

	bool GetIsWhite();
	int GetLocRow();
	int GetLocCol();
	int GetGridRef();
	int GetPiece();
};
#endif