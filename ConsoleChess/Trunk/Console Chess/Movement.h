//Blake Sullivan - Movement.h
#ifndef MOVEMENT_H
#define MOVEMENT_H

class Movement
{
private:
	int iR1, iR2, iL1, iL2;
public:
	Movement();

	bool CheckMove(char, int, int, int, int, bool, bool, bool, bool&);
	bool CheckMoveRules(char, int, int, bool, bool, bool&);

	bool CheckRook(int, int);
	bool CheckBishop(int, int);
	bool CheckNight(int, int);
	bool CheckQueen(int, int);
	bool CheckKing(int, int, bool, bool&);
	bool CheckPawn(int, int, bool, bool);

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