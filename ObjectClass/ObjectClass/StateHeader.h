//Blake Sullivan - StateHeader.h
#ifndef STATEHEADER_H
#define STATEHEADER_H

enum States
{
	stateDead = -1,
	stateInactive = 0,
	stateAlive = 1,
};
enum ObjectTypes
{
	typeCharacter = 0,
	typePickup = 1,
	typeBullet = 2
};
#endif