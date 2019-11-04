//Blake Sullivan - Teacher.h
#ifndef TEACHER_H
#define TEACHER_H
#include <iostream>
#include <string>
#include "Subject.h"
using namespace std;

class Teacher
{
private:
	string sFirstName;
	string sLastName;
	Subject subject;

public:
	Teacher();

	void Display();
};
#endif