//Blake Sullivan - Movement.cpp
#include "Movement.h"

Movement::Movement()
{
	SetR1(0);
	SetR2(0);
	SetL1(0);
	SetL2(0);
}

bool Movement::CheckMove(char cID, int iFromR, int iFromC, int iToR, int iToC, bool bIsTake, bool bIsBlack, bool bMoved, bool& bCast)
{
	int iAbsoluteRowChange = 0, iAbsoluteColChange = 0;
	//cout << "In Piece::CheckMove" << endl;
	iAbsoluteRowChange = iToR - iFromR;
	
	if (cID == 'P' && bIsBlack == false)
		{if (iAbsoluteRowChange < 0) {return false;}}
	else if (cID == 'P' && bIsBlack == true)
		{if (iAbsoluteRowChange > 0) {return false;}}

	if (iAbsoluteRowChange < 0)
		{iAbsoluteRowChange *= -1;}

	iAbsoluteColChange = iToC - iFromC;
	if (iAbsoluteColChange < 0)
		{iAbsoluteColChange *= -1;}

	if (true == CheckMoveRules(cID, iAbsoluteRowChange, iAbsoluteColChange, bIsTake, bMoved, bCast))
		{return true;}
	else
		{return false;}
}

bool Movement::CheckMoveRules(char cID, int iR, int iC, bool bIsTake, bool bMoved, bool& bCastling)
{
	bool bValid = false;
	//cout << "In Piece::CheckMoveRules" << endl;
	//cout << "cID: " << cID << " iX: " << iX << " iY: " << iY << endl;
	bCastling = false;
	if (cID == 'R')
		{bValid = CheckRook(iR, iC);}
	else if (cID == 'B')
		{bValid = CheckBishop(iR, iC);}
	else if (cID == 'N')
		{bValid = CheckNight(iR, iC);}
	else if (cID == 'Q')
		{bValid = CheckQueen(iR, iC);}
	else if (cID == 'K')
		{bValid = CheckKing(iR, iC, bMoved, bCastling);}
	else //'P'
		{bValid = CheckPawn(iR, iC, bMoved, bIsTake);}
	//cout << "piece.CheckMoveRules: bValid: " << bValid << endl;
	return bValid;
}

bool Movement::CheckRook(int iRowChange, int iColChange)
{
	if (iRowChange >= iR1 && iColChange == iR2)
		{return true;}
	else if (iColChange >= iR1 && iRowChange == iR2)
		{return true;}
	else
		{return false;}
}
bool Movement::CheckBishop(int iRowChange, int iColChange)
{
	if (iRowChange == iColChange)
		{return true;}
	else
		{return false;}
}
bool Movement::CheckNight(int iRowChange, int iColChange)
{
	if (iRowChange == iR1 && iColChange == iR2)
		{return true;}
	else if (iColChange == iR1 && iRowChange == iR2)
		{return true;}
	else
		{return false;}
}
bool Movement::CheckQueen(int iRowChange, int iColChange)
{
	if(true == CheckRook(iRowChange, iColChange))
		{return true;}
	else if (true == CheckBishop(iRowChange, iColChange))
		{return true;}
	else
		{return false;}
}
bool Movement::CheckKing(int iRowChange, int iColChange, bool bMoved, bool& bIsCast)
{
	bool bValid = false;
	if (iColChange > 0 && iRowChange == 0)
	{
		if (iColChange <= iL2 && iColChange > iL1 && bMoved == false)
		{
			bValid = true;
			bIsCast = true;
		}
		else if (iColChange <= iL1)
			{bValid = true;}
		else
			{bValid = false;}
	}
	else if (iRowChange > 0 && iColChange == 0 && iRowChange <= iL1)
		{bValid = true;}
	else if (iRowChange == iColChange && iColChange <= iL1)
		{bValid = true;}
	else
		{bValid = false;}

	return bValid;
}
bool Movement::CheckPawn(int iRowChange, int iColChange, bool bMoved, bool bIsTake)
{
	bool bValid = false;
	if (true == bIsTake)
	{
		if (iRowChange == iColChange && iRowChange <= iL1)
			{bValid = true;}
		else
			{bValid = false;}
	}
	else
	{
		if (false == bMoved)
		{
			if (iRowChange >= iR1 && iColChange == iR2 && iRowChange <= iL2)
				{bValid = true;}
			else
				{bValid = false;}
		}
		else
		{
			if (iRowChange >= iR1 && iColChange == iR2 && iRowChange == iL1)
				{bValid = true;}
			else
				{bValid = false;}
		}
	}
	return bValid;
}

void Movement::SetR1(int iTemp)
{
	iR1 = iTemp;
}
void Movement::SetR2(int iTemp)
{
	iR2 = iTemp;
}
void Movement::SetL1(int iTemp)
{
	 iL1 = iTemp;
}
void Movement::SetL2(int iTemp)
{
	iL2 = iTemp;
}
int Movement::GetR1()
{
	return iR1;
}
int Movement::GetR2()
{
	return iR2;
}
int Movement::GetL1()
{
	return iL1;
}
int Movement::GetL2()
{
	return iL2;
}