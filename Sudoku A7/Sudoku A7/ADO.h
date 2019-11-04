//Blake Sullivan - ADO.h
#ifndef ADO_H
#define ADO_H

#import <C:\\Program Files\\Common Files\\System\\ado\\msado15.dll> rename("EOF", "AdoNSEOF")

#include <iostream>
#include <tchar.h>
using namespace std;

#include <direct.h>

#include "SudokuGrid.h"

class ADO
{
private:
	std::string m_sPuzName;
	std::string m_sDataBaseName;
	SudokuGrid* m_pSG;
	ADODB::_ConnectionPtr m_pConnection;
	HRESULT hr;

	const char* DAM;

public:
	ADO();
	~ADO();

	void Init(std::string puzName, std::string dbName);

	bool ConnectToDB();
	bool OpenConnection();
	bool CloseConnection();

	void SetupPuzzle(SudokuGrid* sg, std::string fromTable, std::string sPuzNum);
	void OutputCurrent(SudokuGrid* sg, std::string sPuzNum, std::string id);

	std::string GetWorkingPath();
};

#endif