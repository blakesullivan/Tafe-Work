//Blake Sullivan - Time Class header
#ifndef TIMETABLE_H
#define TIMETABLE_H
#include <string>
using namespace std;

class TimeTable
{
private:
	//Variables
	int iHours;
	int iMinutes;
	int iSeconds;
	string sTimeOfDay;

	int iHoursDisplay;
	string sLZHours;
	int iMinutesDisplay;
	string sLZMinutes;
	int iSecondsDisplay;
	string sLZSeconds;
	string sTimeOfDayDisplay;

	string sLessonName;

	struct Time
	{
		string sName;
		int iHourStart;
		int iHourEnd;
		string sMinuteLZStart;
		string sMinuteLZEnd;
		int iMinuteStart;
		int iMinuteEnd;
		float fDuration;
		string sTimeOfDayStart;
		string sTimeOfDayEnd;
	};

	Time lesson[10];

public:
	//Constructor
	TimeTable();

	//Functions
	void Manage();
	void LessonInput(int);
	void LessonDelete(int);

	int InputOption();
	void InputHours(int);
	void InputMinutes();
	void InputSeconds();
	void InputTimeOfDay();
	int InputDisplayOption();
	void InputLessonName(int);
	
	bool CheckHours(int, string);
	bool CheckMinutes(string);
	bool CheckSeconds(string);
	bool CheckTimeOfDay(string);
	bool CheckInputOption(string);

	void ConvertToTweleve();
	void ConvertToTwenty();

	void Display();
	void DisplayLesson();

	//Modify Input Variables
	int GetHours();
	int GetMinutes();
	int GetSeconds();
	string GetTimeOfDay();

	void SetHours(int);
	void SetMinutes(int);
	void SetSeconds(int);
	void SetTimeOfDay(string);

	//Modifiy Display variables
	//LZ = Leading Zero
	int GetHoursD();
	string GetLZHours();
	int GetMinutesD();
	string GetLZMinutes();
	int GetSecondsD();
	string GetLZSeconds();
	string GetTimeOfDayD();

	void SetHoursD(int);
	void SetLZHours(string);
	void SetMinutesD(int);
	void SetLZMinutes(string);
	void SetSecondsD(int);
	void SetLZSeconds(string);
	void SetTimeOfDayD(string);

	void SetLessonArrayStart(int);
	void SetLessonArrayEnd(int);

	string GetLessonName(int);
	int GetLessonHS(int);
	int GetLessonHE(int);
	string GetLessonLZMS(int);
	int GetLessonMS(int);
	string GetLessonLZME(int);
	int GetLessonME(int);
	float GetLessonDur(int);
	string GetLessonToDS(int);
	string GetLessonToDE(int);

	void SetLessonName(int, string);
	void SetLessonHS(int, int);
	void SetLessonHE(int, int);
	void SetLessonLZMS(int, string);
	void SetLessonMS(int, int);
	void SetLessonLZME(int, string);
	void SetLessonME(int, int);
	void SetLessonDur(int, float);
	void SetLessonToDS(int, string);
	void SetLessonToDE(int, string);
};
#endif