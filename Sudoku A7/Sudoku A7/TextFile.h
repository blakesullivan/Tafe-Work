//Blake Sullivan - TextFile.h
#ifndef TEXTFILE_H
#define TEXTFILE_H

#include "FileManager.h"

class TextFile : public FileManager
{
private:
	string m_sFileName;

public:
	TextFile();

	void LoadFile(SudokuGrid* sgrid, string sFileName);
	void WriteFile(SudokuGrid* sgrid, string sFileName = "");

	void ReadInPuzzle(string sFileName);
	string GetNumFromFull(string& sFull);
	void SetSquareFromFile(int i, string sNum);
	void PrintFinalPuzzle(string sFN);

	friend ofstream& operator<<(ofstream&, Square*);
};

#endif