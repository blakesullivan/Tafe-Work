//Blake Sullivan - BinaryFile.h
#ifndef BINARYFILE_H
#define BINARYFILE_H

#include "FileManager.h"

class BinaryFile : public FileManager
{
private:

public:
	BinaryFile();

	void LoadFile(SudokuGrid* sgrid, string sFileName);
	void WriteFile(SudokuGrid* sgrid, string sFileName = "");
};

#endif