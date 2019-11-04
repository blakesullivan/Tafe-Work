//Blake Sullivan - Time Class header
#include <string>
using namespace std;

class Time
{
private:
	//Variables
	int iHours;
	int iMinutes;
	int iSeconds;
	string sTimeOfDay;

	int iHoursD;
	string sLZHours;
	int iMinutesD;
	string sLZMinutes;
	int iSecondsD;
	string sLZSeconds;
	string sTimeOfDayD;

public:
	//Constructor
	Time();

	//Functions
	void Manage();

	int InputOption();
	void InputHours(int);
	void InputMinutes();
	void InputSeconds();
	void InputTimeOfDay();
	int InputDisplayOption();
	
	bool CheckHours(int, string);
	bool CheckMinutes(string);
	bool CheckSeconds(string);
	bool CheckTimeOfDay(string);
	bool CheckInputOption(string);

	void ConvertToTweleve();
	void ConvertToTwenty();

	void Display();

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
	//string GetLZHours();
	int GetMinutesD();
	//string GetLZMinutes();
	int GetSecondsD();
	bool GetTimeType();
	//string GetLZSeconds();
	//string GetTimeOfDayD();

	void SetHoursD(int);
	//void SetLZHours(string);
	void SetMinutesD(int);
	//void SetLZMinutes(string);
	void SetSecondsD(int);
	//void SetLZSeconds(string);
	//void SetTimeOfDayD(string);
};