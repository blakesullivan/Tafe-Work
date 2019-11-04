//Blake Sullivan - Manager.h
#ifndef MANAGER
#define MANAGER

#include "LinkedList.h"
#include <iostream>
using namespace std;

class Manager
{
private:
	LinkedList* mp_ll;

public:
	Manager();
	~Manager();

	void ManageProgram();
};
#endif