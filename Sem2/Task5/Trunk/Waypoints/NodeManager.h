//Blake Sullivan - NodeManager.h
#ifndef NODEMANAGER_H
#define NODEMANAGER_H

#include "Node.h"

class NodeManager
{
private:
	Node m_aNodes[7];
	int m_aiSolution[7][7];
	int m_iCurrentNode;
	int m_iNextNode;
	int m_iClosestNode;
public:
	NodeManager();

	void SetSolution();
	void SetCurrentNode(int);
	void SetNextNode(int);
	void SetClosestNode(int);

	int GetSolution(int, int);
	int GetCurrentNode();
	int GetNextNode();
	int GetClosestNode();
	float GetNodeX(int);
	float GetNodeY(int);
	int GetNodeID(int);
};
#endif