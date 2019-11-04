//Blake Sullivan - Play.h
#ifndef PLAY_H
#define PLAY_H

#include "Scene.h"
#include "NodeManager.h"
#include <iostream>

class Play : public Scene
{
private:
	SDL_Surface* m_Background;
	Node playerNode; 
	Node badNode;
	bool m_bButtonUsed;
	NodeManager NM;

public:
	Play();

	void Init();
	//void Event(SDL_Surface* screen, SDL_Event *event, float fDeltaTime);
	void Update(SDL_Surface* screen, float fDeltaTime);
	void Draw(SDL_Surface* screen, float fDeltaTime);
	int Status();
	void Dispose();

	virtual void MouseUpEvent(SDL_Event* event);
	virtual void MouseDownEvent (SDL_Event* event);
	virtual void KeyUpEvent(SDL_Event* event);
	virtual void KeyDownEvent(SDL_Event* event);

	int FindNearestNode(Node*);
	void UpdateTargetNodes(Node*);
	void MoveBad(float);
	void DrawNodes(SDL_Surface* screen);
	bool CollisionCheck(float p1X, float p1Y, float p1S, float p2X, float p2Y, float p2S);
};
#endif