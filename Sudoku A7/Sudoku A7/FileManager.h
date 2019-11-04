//Blake Sullivan - MyFile.h
#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <fstream>
#include <string>
#include <iostream>
using std::ofstream;
using std::ifstream;
using std::string;
using std::cout;
using std::endl;
#include "SudokuGrid.h"

class FileManager
{
protected:
	SudokuGrid* m_sGrid;

public:
	virtual void LoadFile(SudokuGrid* sgrid, string sFileName) = 0;
	virtual void WriteFile(SudokuGrid* sgrid, string sFileName = "") = 0;

};
#endif