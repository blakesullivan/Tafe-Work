//Blake Sullivan - BinaryFile.cpp
#include "BinaryFile.h"

BinaryFile::BinaryFile()
{
}

void BinaryFile::LoadFile(SudokuGrid* sgrid, string sFileName)
{
	string sPuzName = "";
	if (sFileName.length() > 1)
	{
		sPuzName = sFileName;	
	}
	else
	{
		int iPN = atoi(sFileName.c_str());
		char buffer[1] = {' '};
		sPuzName = "Puzzle#.bin";
		sPuzName.replace(sPuzName.find("#"), 1, itoa(iPN, buffer, 10));
	}
	std::fstream fromFile(sPuzName.c_str(), std::ios::in | std::ios::binary);

	if (fromFile.good() == true)
		{fromFile.read((char*)sgrid, sizeof(SudokuGrid));}
	fromFile.close();
}

void BinaryFile::WriteFile(SudokuGrid* sgrid, string sFileName)
{
	int iPN = atoi(sFileName.c_str());
	string sResultName = "Result#.bin";
	char buffer[1] = {' '};
	sResultName.replace(sResultName.find("#"), 1, itoa(iPN, buffer, 10));
	
	std::fstream resultFile(sResultName.c_str(), std::ios::out | std::ios::binary);

	if (resultFile.good())
	{
		resultFile.write((char*)sgrid, sizeof(SudokuGrid));
	}
	resultFile.close();

}