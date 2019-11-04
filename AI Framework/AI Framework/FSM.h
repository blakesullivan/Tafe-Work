//Blake Sullivan - FSM.h
#ifndef FSM_H
#define FSM_H

#include "AI_SEARCH_TARGET.h"
#include <vector>
using namespace std;

class FSM
{
private:
  WORLD * theworld;
  PLAYER *pBot;
  OBJECT *pTarget;
  vector<STATE*> aistates;
int AIstate;

public:

  FSM(PLAYER* PBOT, WORLD *w);
  ~FSM();

  void process();
  void init();
  void dispose();
};
#endif