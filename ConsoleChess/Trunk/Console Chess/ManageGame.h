//Blake Sullivan - Manage.h
#ifndef MANAGEGAME_H
#define MANAGEGAME_H

#include "InputChecker.h"
#include "Board.h"
#include "Setup.h"
class ManageGame : public InputChecker
{
private:
	Board board;
	Setup setup;
	bool bIsCheckMate;
	string sMoveFile, sSquareFile, sPieceFile, sSetupFile;

public:
	ManageGame();

	void ManageSetup();
	void ManagePlay(bool);
	void ManageResume();
	void DrawBoard(bool);
	void SetupPieces();
	void SetupSquares();
	void SetupBoard();
	void LoadMenu();

	bool Move(string, bool);
	int ConvertX(char);
	int ConvertY(char);

	string Input(bool);
	bool InputCheckMate(bool);
	bool CheckInput(string);
	bool CheckValidCheckMateInput(string);
	bool ReturnCheckMateInput(string);

	bool CheckForCheckMate(bool, bool);
	bool CheckLetter(char);
	bool CheckNumber(char);
	bool CheckSymbol(char);

	void CheckMate(bool);

	void WriteStartupFiles();
	void WriteMoveFile(string);
	void ResetFiles();
};
#endif