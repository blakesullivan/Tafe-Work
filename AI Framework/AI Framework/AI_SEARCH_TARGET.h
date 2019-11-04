//Blake Sullivan - AI_SEARCH_TARGET.h
#ifndef AISEARCHTARGET_H
#define AISEARCHTARGET_H

#include "State.h"

class AI_SEARCH_TARGET: public STATE
{
public:
	AI_SEARCH_TARGET(PLAYER* thepBot, WORLD *w, OBJECT* pTar);
	void activate();
	void process();
	void terminate();
	int getStatus();
	void setTarget(OBJECT *Target);

};

#endif