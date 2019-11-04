//Blake Sullivan - String Date Program
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

enum Months
{
	mJan = 1,
	mFeb = 2,
	mMar = 3,
	mApr = 4,
	mMay = 5,
	mJun = 6,
	mJul = 7,
	mAug = 8,
	mSep = 9,
	mOct = 10,
	mNov = 11,
	mDec = 12
};

bool CheckValidDate(int, int, int);
bool CheckValidDay(int, int, int);
bool CheckValidMonth(int);
bool CheckValidYear(int);
bool CheckValidLeapYear(int);
bool ExitProgram();
void Run();

int main()
{
	Run();
	system("PAUSE");
	return 0;
}

void Run()
{
	string sInput, sOutput;
	int iDay = 0, iMonth = 0, iYear = 0;
	bool bExit = false;
	do
	{
		iDay = 0; iMonth = 0; iYear = 0;
		cout << "Please input the date. [dd/mm/yyyy]" << endl;
		getline(cin, sInput);
		for (int i = 0; i <= sInput.length(); i++)
		{
			if (sInput[i] == '/' || i == sInput.length())
			{
				if (iDay == 0)
				{
					iDay = atoi(sOutput.c_str());
					sOutput = "";
				}
				else if (iMonth == 0)
				{
					iMonth = atoi(sOutput.c_str());
					sOutput = "";
				}
				else if (iYear == 0)
				{
					iYear = atoi(sOutput.c_str());
					sOutput = "";
				}
			}
			else
			{
				sOutput += sInput[i];
			}
		}
		if (CheckValidDate(iDay, iMonth, iYear))
		{
			cout << "Valid Date:" << endl;
			cout << "Day: " << iDay << "\nMonth: " << iMonth << "\nYear: " << iYear << endl;
		}
		else
			{cout << "Invalid Date." << endl;}

		bExit = ExitProgram();

	}while (bExit == false);
}

bool ExitProgram()
{
	string sInput = "";
	cout << "Do you want to replay? (y/n)" << endl;
	getline(cin, sInput);
	if (sInput[0] == 'y' || sInput[1] == 'Y')
		{return false;}
	else
		{return true;}
}

bool CheckValidDate(int iDay, int iMonth, int iYear)
{
	bool bValid = false;
	if (CheckValidMonth(iMonth) == true)
	{
		if (CheckValidYear(iYear) == true)
		{
			if (CheckValidDay(iDay, iMonth, iYear) == true)
			{
				bValid = true;
			}
		}
	}
	return bValid;
}

bool CheckValidMonth(int iMonth)
{
	if (iMonth > 0 && iMonth <= 12)
		{return true;}
	else
		{return false;}
}

bool CheckValidYear(int iYear)
{
	if (iYear > 1900 && iYear <= 2100)
		{return true;}
	else
		{return false;}
}

bool CheckLeapYear(int iYear)
{
	if (iYear % 4 == 0)
		{return true;}
	else
		{return false;}
}

bool CheckValidDay(int iDay, int iMonth, int iYear)
{
	if (iMonth == mFeb)
	{
		if (iDay > 0 && iDay < 28)
			{return true;}
		else if (CheckLeapYear(iYear) == true && iDay == 29)
			{return true;}
		return false;
	}
	else
	{
		if (iMonth == mApr || iMonth == mJun || iMonth == mSep || iMonth == mNov)
		{
			if (iDay > 0 && iDay <= 30)
				{return true;}
			else
				{return false;}
		}
		else
		{
			if (iDay > 0 && iDay <= 31)
				{return true;}
			else
				{return false;}
		}
	}
}
