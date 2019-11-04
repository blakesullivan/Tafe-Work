//Blake Sullivan - Square.h
#ifndef SQUARE_H
#define SQUARE_H

class Square
{
private:
	static const int MSC_ISIZE = 32;
	int m_iRow, m_iCol;
	int m_iX, m_iY;

public:
	Square();

	void Init(int r, int c, int x, int y);

	void SetRow(int);
	void SetCol(int);
	void SetX(int);
	void SetY(int);

	int GetRow();
	int GetCol();
	int GetX();
	int GetY();
	static int GetSize();
};
#endif