//Sort 3 Characters Function file
#include "SortCharacters.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

SortCharacters::SortCharacters()
{
	//initialize random seed:
	srand ( time(NULL) );
}

SortCharacters::SortCharacters(char c1, char c2, char c3)
{
	SetChar1(c1); //has validation
	SetChar2(c2);
	SetChar3(c3);
	SetCharS1();
	SetCharS2();
	SetCharS3();

	SortChars();
}

void SortCharacters::SortChars()
{
	if (cCharS1 > cCharS2)
		SwapChars(cCharS1, cCharS2);

	if (cCharS2 > cCharS3)
		SwapChars(cCharS2, cCharS3);

	if (cCharS1 > cCharS2)
		SwapChars(cCharS1, cCharS2);
}

void SortCharacters::GenerateRandomNumbers()
{
	int iTemp;
	for (int i=0; i<1000; i++)
	{
		//Initialize random number to be guessed
		iTemp = rand() %100 + 1;
		SetIntArray(i, iTemp);
	}
}

void SortCharacters::GenerateRandomCharacters(int iOption)
{
	char cTemp;
	int iNum;
	for (int i=0; i<20; i++)
	{
		//Initialize random number to be guessed
		if (1==iOption)
		{iNum=65;}
		else
		{iNum=97;}
		cTemp = rand() %26 + iNum;
		SetCharArray(i, cTemp);
	}
}

void SortCharacters::SortCharArray()
{
	bool bExit=false;
	while(bExit==false)
	{
		bExit=true;
		for (int i = 0; i < 19; i++)
		{
			if (cArray[i]>cArray[i+1])
			{
				SwapChars(cArray[i], cArray[i+1]);
				bExit=false;
			}
		}
	}
}

void SortCharacters::SortIntArray()
{
	bool bExit=false;
	while(bExit==false)
	{
		bExit=true;
		for (int i = 0; i < 999; i++)
		{
			if (iArray[i]>iArray[i+1])
			{
				SwapInts(iArray[i], iArray[i+1]);
				bExit=false;
			}
		}
	}
}

void SortCharacters::SwapInts(int& iNum1, int& iNum2)
{
	int iTemp;
	iTemp = iNum1;
	iNum1 = iNum2;
	iNum2 = iTemp;
}

void SortCharacters::SwapChars(char& cTemp1, char& cTemp2)
{
	char cTemp;
	cTemp = cTemp1;
	cTemp1 = cTemp2;
	cTemp2 = cTemp;
}

char SortCharacters::GetChar1()
{
	return cChar1;
}

char SortCharacters::GetChar2()
{
	return cChar2;
}

char SortCharacters::GetChar3()
{
	return cChar3;
}

char SortCharacters::GetCharS1()
{
	return cCharS1;
}

char SortCharacters::GetCharS2()
{
	return cCharS2;
}

char SortCharacters::GetCharS3()
{
	return cCharS3;
}

void SortCharacters::SetChar1(char cTemp)
{
	cChar1 = cTemp;
}

void SortCharacters::SetChar2(char cTemp)
{
	cChar2 = cTemp;
}

void SortCharacters::SetChar3(char cTemp)
{
	cChar3 = cTemp;
}

void SortCharacters::SetCharS1()
{
	cCharS1 = cChar1;
}

void SortCharacters::SetCharS2()
{
	cCharS2 = cChar2;
}

void SortCharacters::SetCharS3()
{
	cCharS3 = cChar3;
}

int SortCharacters::GetIntArray(int iNum)
{
	return iArray[iNum];
}
int* SortCharacters::GetIntArrayPoint(int iNum)
{
	return & iArray[iNum];
}
char SortCharacters::GetCharArray(int iNum)
{
	return cArray[iNum];
}
char* SortCharacters::GetCharArrayPoint(int iNum)
{
	return & cArray[iNum];
}

void SortCharacters::SetIntArray(int iNum, int iSetNum)
{
	iArray[iNum] = iSetNum;
}
void SortCharacters::SetCharArray(int iNum, char cSetChar)
{
	cArray[iNum] = cSetChar;
}