//Blake Sullivan - Setup.cpp
#include "Setup.h"

Setup::Setup()
{
	SetBoardColours("white", "black", "silver", "grey");
	SetGridSize(5, 3);
	SetBorderChars(-55, -69, -56, -68, -51, -70);
	SetBorderColours("yellow", "maroon");
	//Manage();
}

void Setup::Manage()
{
	int iOption = 0;
	bool bExit = false;
	do
	{
		iOption = InputOptionInt("What would you like to change?\n 1. Board Size\n 2. Board Colour\n 3. Border Colour\n 4. Border Style\n 5. Back To Main Menu\nPlease enter the number of the option: ", 1, 5);
		switch (iOption)
		{
		case 1:
			SetupBoardSize();
		break;
		case 2:
			SetupBoardColour();
		break;
		case 3:
			SetupBorderColour();
		break;
		case 4:
			SetupBorderCharacters();
		break;
		default:
			bExit = true;
		}
	} while (false == bExit);
}

void Setup::SetupBoardSize()
{
	int iOption = 0;
	iOption = InputOptionInt("What size do you want the squares to be?\n 1. Small [3 wide - 1 down]\n 2. Medium [5w-3d]\n 3. Large [7w-5d]\nPlease enter the number of the option: ", 1, 3);
	if (iOption == 1)
		{SetGridSize(3,1);}
	else if (iOption == 3)
		{SetGridSize(7,5);}
	else
		{SetGridSize(5,3);}
}
void Setup::SetupBoardColour()
{
	int iOption = 0;

	cout << "What colour do you want the board to be? (White & Black in order)\n 1. ";
	objCC.DisplayColouredText("Silver", "white", "silver");
	cout << " & ";
	objCC.DisplayColouredText("Grey", "black", "grey");
	cout << "\n 2. ";
	objCC.DisplayColouredText("Dark Cyan", "white", "dark cyan");
	cout << " & ";
	objCC.DisplayColouredText("Blue", "black", "blue");
	cout << "\n 3. ";
	objCC.DisplayColouredText("Dark Green", "white", "dark green");
	cout << " & ";
	objCC.DisplayColouredText("Maroon", "black", "maroon");
	cout << "\n 4. ";
	objCC.DisplayColouredText("Pink", "white", "pink");
	cout << " & ";
	objCC.DisplayColouredText("Purple", "black", "purple");

	iOption = InputOptionInt("\nPlease enter the number of the option: ", 1, 4);
	
	if (2 == iOption)
	{SetBoardColours("white", "black", "dark cyan", "blue");}
	else if (3 == iOption)
	{SetBoardColours("white", "black", "dark green", "maroon");}
	else if (4 == iOption)
	{SetBoardColours("white", "black", "pink", "purple");}
	else
	{SetBoardColours("white", "black", "silver", "grey");}
}
void Setup::SetupBorderColour()
{
	int iOption = 0;

	cout << "What colour do you want the Border to be?\n 1. ";
	objCC.DisplayColouredText("Yellow on Maroon", "yellow", "maroon");
	cout << "\n 2. ";
	objCC.DisplayColouredText("Green on Dark Blue", "green", "dark blue");
	cout << "\n 3. ";
	objCC.DisplayColouredText("Cyan on Purple", "cyan", "purple");
	cout << "\n 4. ";
	objCC.DisplayColouredText("Black on Yellow", "black", "yellow");

	iOption = InputOptionInt("\nPlease enter the number of the option: ", 1, 4);
	
	if (2 == iOption)
	{SetBorderColours("green", "dark blue");}
	else if (3 == iOption)
	{SetBorderColours("cyan", "purple");}
	else if (4 == iOption)
	{SetBorderColours("black", "yellow");}
	else
	{SetBorderColours("yellow", "maroon");}
}

void Setup::SetupBorderCharacters()
{
	int iOption = 0;
	cout << "What style of border do you want?\n 1. Single\n";
	cout << (char) -38 << (char) -60 << (char) -65 << endl;
	cout << (char) -77 << " " << (char) -77 << endl;
	cout << (char) -64 << (char) -60 << (char) -39 << endl;

	cout << " 2. Double\n";
	cout << (char) -55 << (char) -51 << (char) -69 << endl;
	cout << (char) -70 << " " << (char) -70 << endl;
	cout << (char) -56 << (char) -51 << (char) -68 << endl;

	iOption = InputOptionInt("Please enter the number of the option: ", 1, 2);

	if (1 == iOption)
	{SetBorderChars(-38, -65, -64, -39, -60, -77);}
	else
	{SetBorderChars(-55, -69, -56, -68, -51, -70);}
}

void Setup::SetBoardColours(string fw, string fb, string bw, string bb)
{
	sForeWhiteCol = fw;
	sForeBlackCol = fb;
	sBackWhiteCol = bw;
	sBackBlackCol = bb;
}
void Setup::SetGridSize(int x, int y)
{
	iGridSizeX = x;
	iGridSizeY = y;
} 
void Setup::SetBorderChars(char tl, char tr, char bl, char br, char h, char v)
{
	cBordTopL = tl;
	cBordTopR = tr;
	cBordBotL = bl;
	cBordBotR = br;
	cBordHor = h; 
	cBordVert = v;
} 
void Setup::SetBorderColours(string f, string b)
{
	sForeBordCol = f;
	sBackBordCol = b;
} 

string Setup::GetForeWhiteCol()
{
	return sForeWhiteCol;
}
string Setup::GetForeBlackCol()
{
	return sForeBlackCol;
} 
string Setup::GetBackWhiteCol()
{
	return sBackWhiteCol;
} 
string Setup::GetBackBlackCol()
{
	return sBackBlackCol;
} 
int Setup::GetGridSizeX()
{
	return iGridSizeX;
} 
int Setup::GetGridSizeY()
{
	return iGridSizeY;
} 
char Setup::GetBordTopL()
{
	return cBordTopL;
} 
char Setup::GetBordTopR()
{
	return cBordTopR;
} 
char Setup::GetBordBotL()
{
	return cBordBotL;
} 
char Setup::GetBordBotR()
{
	return cBordBotR;
} 
char Setup::GetBordHor()
{
	return cBordHor;
} 
char Setup::GetBordVert()
{
	return cBordVert;
} 
string Setup::GetForeBorderCol()
{
	return sForeBordCol;
} 
string Setup::GetBackBorderCol()
{
	return sBackBordCol;
}