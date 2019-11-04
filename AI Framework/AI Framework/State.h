//Blake Sullivan - State.h
#ifndef STATE_H
#define STATE_H

#include "Level.h"
#include "Character.h"

class State
{
protected: 
		int id;				//each goal has an id 
		WORLD* theworld;	// a pointer to the world
		PLAYER *mOwner;	// a pointer to the player
		OBJECT *target;  // the target object
		int status;
		int type;
public:
	//STATE();
	virtual void activate()=0;
	virtual void process()=0;
	virtual void terminate()=0;	
	virtual int getStatus()=0;
	virtual void setTarget(OBJECT *Target)=0;
};
#endif