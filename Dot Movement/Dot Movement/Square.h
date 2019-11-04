//Blake Sullivan - Square.h
#ifndef SQUARE_H
#define SQUARE_H

class Square
{
private:
	static int ms_iSize;
	int m_iRow, m_iCol;
	int m_iX, m_iY;
	int m_iWalkable;
	int m_iTilePicPos;

public:
	Square();

	void Init(int r, int c, int x, int y, int s, int tpp);

	void SetRow(int);
	void SetCol(int);
	void SetX(int);
	void SetY(int);
	void SetWalkable(int);
	void SetTilePicPos(int);
	static void SetSize(int);

	int GetRow();
	int GetCol();
	int GetX();
	int GetY();
	int GetWalkable();
	int GetTilePicPos();
	static int GetSize();
};
#endif