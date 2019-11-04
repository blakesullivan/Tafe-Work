//Blake Sullivan - TextFile.cpp
#include "stdafx.h"
#include "TextFile.h"

TextFile::TextFile()
{

}

void TextFile::LoadFile(SudokuGrid* sgrid, string sFileName)
{
	m_sGrid = sgrid;
	//cout << "sFileName: " << sFileName << endl;
	ReadInPuzzle(sFileName);
	m_sGrid = NULL;
}
void TextFile::WriteFile(SudokuGrid* sgrid, string sFileName)
{
	m_sGrid = sgrid;
	if (sFileName != "")
		{m_sFileName = sFileName + ".txt";}
	else
	{
		char buffer[10] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
		//cout << "Output file name before: " << m_sFileName << endl;
		m_sFileName.replace(0, 6, "Result");
		//cout << "Output file name after: " << m_sFileName << endl;
	}
	PrintFinalPuzzle(m_sFileName);

}

void TextFile::ReadInPuzzle(string sFileName)
{
	if (sFileName.length() > 1)
	{
		string sTemp = "";
		sTemp = sFileName.substr(0, sFileName.find(".txt"));
		sTemp = sTemp.substr(sTemp.length() - 1, sTemp.length());
		//cout << "Found a .txt" << endl;
		m_sFileName = sFileName;
	}
	else
	{
		string sPuzName = "Puzzle#.txt";
		char buffer[1] = {' '};
		sPuzName.replace(sPuzName.find("#"), 1, sFileName);
		m_sFileName = sPuzName;
	}
	ifstream puzzFile(m_sFileName.c_str());
	string sFullRow = "";
	if (puzzFile.good())
	{
		int k = 0;
		for (int i = 0; i < 9; i++)
		{
			puzzFile >> sFullRow;
			for (int j = 0; j < 9; j++)
			{
				SetSquareFromFile(k, GetNumFromFull(sFullRow));
				k++;
			}
		}
	}
	puzzFile.close();
}
string TextFile::GetNumFromFull(string& sFull)
{
	string sReturn = "";
	if (sFull.find(",") > 0)
	{
		sReturn = sFull.substr(0, sFull.find(","));
		sFull = sFull.substr(sFull.find(",") + 1, sFull.length());
	}
	else
	{
		sReturn = sFull;
		sFull = "";
	}
	
	//cout << sFull << endl;
	return sReturn;
}
void TextFile::SetSquareFromFile(int i, string sNum)
{
	int iNum = 0; bool bIsEmpty = true, bIsUserNum = false;
	iNum = atoi(sNum.c_str());
	m_sGrid->SetSquare(i, iNum, false);
}
void TextFile::PrintFinalPuzzle(string sFN)
{
	cout << "Printing Result.\n";
	int r = 0, c = 0;
	
	//string sResultName = "Result#.txt";
	//char buffer[1] = {' '};
	//sResultName.replace(sResultName.find("#"), 1, itoa(iPN, buffer, 10));

	ofstream resultFile(sFN.c_str());
	for (int i = 0; i < 81; i++)
	{
		resultFile << (*m_sGrid)(i);
		//cout << (*m_sGrid)(i);
		if (c < 8) 
		{
			resultFile << ",";
			c++;
		} 
		else 
		{
			resultFile << endl;
			c = 0; 
			r++;
		}
	}
}

ofstream& operator<<(ofstream& out, Square* s)
{
	out << s->GetNum();
	return out;
}