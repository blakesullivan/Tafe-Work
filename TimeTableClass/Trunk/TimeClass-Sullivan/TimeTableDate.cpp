//Blake Sullivan - Date class
#include "TimeTableDate.h"

TimeTableDate::TimeTableDate()
{
	SetYear(0);
	SetMonth(0);
	SetIDay(0);
	SetSDay(" ");
	mMonth[0].name=""; mMonth[1].name="JANUARY";mMonth[2].name="FEBRUARY";mMonth[3].name="MARCH";mMonth[4].name="APRIL";mMonth[5].name="MAY";mMonth[6].name="JUNE";mMonth[7].name="JULY";mMonth[8].name="AUGUST";mMonth[9].name="SEPTEMBER";mMonth[10].name="OCTOBER";mMonth[11].name="NOVEMBER";mMonth[12].name="DECEMBER";
	mMonth[0].days=0; mMonth[1].days=31; mMonth[2].days=29; mMonth[3].days=31; mMonth[4].days=30; mMonth[5].days=31; mMonth[6].days=30; mMonth[7].days=31; mMonth[8].days=31; mMonth[9].days=30; mMonth[10].days=31; mMonth[11].days=30; mMonth[12].days=31;
	dDay[0].longName="SUNDAY";dDay[1].longName="MONDAY";dDay[2].longName="TUESDAY";dDay[3].longName="WEDNESDAY";dDay[4].longName="THURSDAY";dDay[5].longName="FRIDAY";dDay[6].longName="SATURDAY";
	dDay[0].shortName="SUN";dDay[1].shortName="MON";dDay[2].shortName="TUE";dDay[3].shortName="WED";dDay[4].shortName="THUR";dDay[5].shortName="FRI";dDay[6].shortName="SAT";
	iStartDay[11][1]=6;
}

bool TimeTableDate::CheckLeapYear(int year)
{
	if (year%400 == 0)
		{return true;}
	else if (year%100 == 0)
		{return false;}
	else if (year%4 == 0)
		{return true;}
	else
		{return false;}
}

bool TimeTableDate::CheckYear(string sTemp)
{
	const char* cTemp = sTemp.c_str();
	if (*cTemp < '0' || *cTemp > '9')
	{
		cout<<"Invalid Input. Year must be a number."<<endl;
		return false;
	}
	else
	{
		int iTemp = atoi(sTemp.c_str());
		if (iTemp >= 2011 && iTemp <= 2099)
		{return true;}
		else
		{
			cout << "Invalid Input. Year must be between 2000 and 2099."<<endl;
			return false;
		}
	}
}

bool TimeTableDate::CheckMonth(string sTemp)
{
	const char* cTemp = sTemp.c_str();
	if (*cTemp < '0' || *cTemp > '9')
	{
		cout<<"Invalid Input. Year must be a number."<<endl;
		return false;
	}
	else
	{
		int iTemp = atoi(sTemp.c_str());
		if (iTemp >= 1 && iTemp <= 12)
		{return true;}
		else
		{
			cout << "Invalid Input. Month must be between 1 and 12."<<endl;
			return false;
		}
	}
}

bool TimeTableDate::CheckDay(string sTemp)
{
	return true;
}

void TimeTableDate::SetIDay(int iTemp)
{
	iDay = iTemp;
}

void TimeTableDate::SetMonth(int iTemp)
{
	iMonth = iTemp;
}

void TimeTableDate::SetYear(int iTemp)
{
	iYear = iTemp;
}

void TimeTableDate::SetSDay(string sTemp)
{
	sDay = sTemp;
}

int TimeTableDate::GetIDay()
{
	return iDay;
}

string TimeTableDate::GetSDay()
{
	return sDay;
}

string TimeTableDate::GetDayShort(int iTemp)
{
	return dDay[iTemp].shortName;
}
string TimeTableDate::GetDayLong(int iTemp)
{
	return dDay[iTemp].longName;
}

int TimeTableDate::GetIMonth()
{
	return iMonth;
}

int TimeTableDate::GetMonthDays(int year, int month)
{
	if (2==month)
	{
		if (CheckLeapYear(year)==true)
		{return mMonth[month].days;}
		else
		{return (mMonth[month].days - 1);}
	}
	else
	{return mMonth[month].days;}
}

string TimeTableDate::GetMonthName(int iTemp)
{
	return mMonth[iTemp].name;
}

int TimeTableDate::GetYear()
{
	return iYear;
}

string TimeTableDate::DisplayHeader()
{
	string sOutput = GetDayShort(0) + "	" + GetDayShort(1) + "	" + GetDayShort(2) + "	" + GetDayShort(3) + "	" + GetDayShort(4) + "	" + GetDayShort(5) + "	" + GetDayShort(6)  + "\n";
		
	return sOutput;
}

string TimeTableDate::DisplayDate(int year, int month)
{
	string sOutput = "";
	stringstream ssString;
	int iCurDate=1, i=0;
	int iStartYear = year - 2000;
	iStartDay[iStartYear][month] = CalcStartDay(iStartYear, month);
	int iMaxDays = CalcMaxDays(iStartYear, month);
	while (i<iMaxDays)
	{
		if (i < iStartDay[iStartYear][month])
		{
			sOutput += " ";
		}
		else
		{
			ssString << iCurDate;
			sOutput += ssString.str();
			iCurDate++;
			ssString.str("");
		}

		if ((i+1) % 7 == 0)
		{sOutput += "\n";}
		else
		{sOutput += "	";}
		i++;
	}
	sOutput += "\n";
	return sOutput;
}

int TimeTableDate::CalcMaxDays(int year, int month)
{
	return GetMonthDays((year + 2000), month) + iStartDay[year][month];
}

int TimeTableDate::CalcStartDay(int year, int month)
{
	int iNum = 0, iMoveNum;
	bool bExit=false;
	if (year < 11)
	{
		//Needs more work, not quite 100%
		iMoveNum=1;//iStartDay[11][1]-1;
		for (int j=10-year; j>=0 ; j--)
		{
			int i;
			if (j > 0)
			{i=month;}
			else
			{i=1;}
			bExit=false;
			while (false==bExit)
			{
				if (j > 0)
				{
					iNum += GetMonthDays((2010 - j), i);
					if (i+1==13)
					{bExit=true;}
				}
				else if (i < 13)
				{
					iNum += GetMonthDays((2010 - j), i);
				}
				i++;
				if (i==13)
				{bExit=true;}
			}
		}
	}
	else
	{
		iMoveNum=iStartDay[11][1];
		for (int j=0; j<=year-11; j++)
		{
			int i=1;
			bExit=false;
			while (false==bExit)
			{
				if(j < year-11)
				{
					iNum += GetMonthDays((j + 2011), i);
					if (i+1==13)
					{bExit=true;}
				}
				else if (i < month)
				{
					iNum += GetMonthDays((j + 2011), i);
				}
				else if (i==month)
				{bExit=true;}
				i++;
			}
		}
	}
	//cout<<iNum<<endl;
	iNum += iMoveNum;
	//cout<<iNum<<endl;
	iNum %= 7;
	//cout<<iNum<<endl;
	//system("PAUSE");
	return iNum;
}