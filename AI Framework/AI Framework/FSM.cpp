//Blake Sullivan - FSM.cpp
#include "FSM.h"

void FSM::init()
  {
	AI_SEARCH_TARGET *b =new AI_SEARCH_TARGET(pBot, theworld, pTarget);
	aistates.push_back( b );
	AI_FIGHT *b1 =new AI_FIGHT(pBot, theworld, pTarget);
	aistates.push_back( b1 );
	AI_FLEE *b2 =new AI_FLEE(pBot, theworld, pTarget);
	aistates.push_back( b2 );
	
	AIstate=GameFlowType::AI_SEARCH_E;
	
  }


void  FSM::process()
  {
//…
//… some code here to do the targeting





	if ( pBot->getAmmo() >=20 && pBot->getHealth() >=20 && LOS==true )
		AIstate=GameFlowType::AI_FIGHT;
	else if  ( pBot->getHealth() < 50 && LOS==false)
		AIstate=GameFlowType::AI_SEARCH_H;
	else if  ( pBot->getAmmo() < 50 && LOS==false)
		AIstate=GameFlowType::AI_SEARCH_A;
	else if  ( pBot->getAmmo() >=50 && pBot->getHealth() >=50 && LOS==false)
		AIstate=GameFlowType::AI_SEARCH_E;
	else if  ( (pBot->getAmmo() <20 || pBot->getHealth() <20) && LOS==true)
		AIstate=GameFlowType::AI_FLEE;
	else {
		cout << "NOOOOOOOOOOOOO!!!"<< endl;
	}

	if (oldstate != AIstate)
	{
		aistates[oldstate%3]->terminate(); // if you really need to do this
		switch (AIstate)
		{
		case GameFlowType::AI_SEARCH_H:
			pTarget=theworld->findNearestObject(pBot->getX(),pBot->getY(), GameFlowType::HEALTH, pBot->getID(), d);
			aistates[AIstate%3]->setTarget(pTarget);
			aistates[AIstate%3]->activate();
			cout << "SEARCH FOR HEALTH"  << pTarget->getID() << endl;
			break;
		case GameFlowType::AI_SEARCH_A:
			pTarget=theworld->findNearestObject(pBot->getX(),pBot->getY(), GameFlowType::AMMO, pBot->getID(), d);
			aistates[AIstate%3]->setTarget(pTarget);
			aistates[AIstate%3]->activate();
			cout << "SEARCH FOR AMMO"  << pTarget->getID() << endl;
			break;
		case GameFlowType::AI_SEARCH_E:
			aistates[AIstate%3]->setTarget(pTarget2);
			aistates[AIstate%3]->activate();
			cout << "SEARCH FOR ENEMY"  << pTarget2->getID() << endl;
			break;
		case GameFlowType::AI_FIGHT:
			aistates[AIstate%3]->setTarget(pTarget2); // just set it any way just in case we change targets?? did we handle that above
			aistates[AIstate%3]->activate();
			cout << "FIGHT"  << pTarget2->getID() << endl;
			break;
		case GameFlowType::AI_FLEE:
			pTarget=theworld->findFurtherestObject(pBot->getX(),pBot->getY(), pBot->getID());
			aistates[AIstate%3]->setTarget(pTarget);
			aistates[AIstate%3]->activate(); //this sets the target x and Y
			cout << "FLEE"  << pTarget->getID() << endl;
			break;

// all this code assumes the target was found and there is a valid point er here
			// ie i dont do any error checking


		}

	}

// process whatever is the selected state
	aistates[AIstate%3]->process();
	
  }

//---------------------------------------------------------------------------------

//In the player init()
//		brain = new FSM	(this, theworld);

//in the player update function ()
//	brain->process();
