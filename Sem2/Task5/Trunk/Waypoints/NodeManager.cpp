//Blake Sullivan - NodeManager.cpp
#include "NodeManager.h"

NodeManager::NodeManager()
{
	m_aNodes[0].Init(1, 346, 232);
	m_aNodes[1].Init(2, 256, 377);
	m_aNodes[2].Init(3, 481, 377);
	m_aNodes[3].Init(4, 605, 260);
	m_aNodes[4].Init(5, 699, 503);
	m_aNodes[5].Init(6, 433, 512);
	m_aNodes[6].Init(7, 537, 416);
	SetSolution();
	SetCurrentNode(0);
	SetNextNode(0);
	SetClosestNode(0);
}

void NodeManager::SetSolution()
{
	m_aiSolution[0][0] = 1;
	m_aiSolution[0][1] = 2;
	m_aiSolution[0][2] = 3;
	m_aiSolution[0][3] = 4;
	m_aiSolution[0][4] = 4;
	m_aiSolution[0][5] = 3;
	m_aiSolution[0][6] = 3;

	m_aiSolution[1][0] = 1;
	m_aiSolution[1][1] = 2;
	m_aiSolution[1][2] = 3;
	m_aiSolution[1][3] = 3;
	m_aiSolution[1][4] = 3;
	m_aiSolution[1][5] = 3;
	m_aiSolution[1][6] = 3;

	m_aiSolution[2][0] = 1;
	m_aiSolution[2][1] = 2;
	m_aiSolution[2][2] = 3;
	m_aiSolution[2][3] = 4;
	m_aiSolution[2][4] = 4;
	m_aiSolution[2][5] = 6;
	m_aiSolution[2][6] = 6;

	m_aiSolution[3][0] = 1;
	m_aiSolution[3][1] = 3;
	m_aiSolution[3][2] = 3;
	m_aiSolution[3][3] = 4;
	m_aiSolution[3][4] = 5;
	m_aiSolution[3][5] = 3;
	m_aiSolution[3][6] = 5;

	m_aiSolution[4][0] = 4;
	m_aiSolution[4][1] = 6;
	m_aiSolution[4][2] = 4;
	m_aiSolution[4][3] = 4;
	m_aiSolution[4][4] = 5;
	m_aiSolution[4][5] = 6;
	m_aiSolution[4][6] = 7;

	m_aiSolution[5][0] = 3;
	m_aiSolution[5][1] = 3;
	m_aiSolution[5][2] = 3;
	m_aiSolution[5][3] = 3;
	m_aiSolution[5][4] = 5;
	m_aiSolution[5][5] = 6;
	m_aiSolution[5][6] = 7;

	m_aiSolution[6][0] = 6;
	m_aiSolution[6][1] = 6;
	m_aiSolution[6][2] = 6;
	m_aiSolution[6][3] = 5;
	m_aiSolution[6][4] = 5;
	m_aiSolution[6][5] = 6;
	m_aiSolution[6][6] = 7;
}
void NodeManager::SetCurrentNode(int cur)
{
	m_iCurrentNode = cur;
}
void NodeManager::SetNextNode(int nn)
{
	m_iNextNode = nn;
}
void NodeManager::SetClosestNode(int cn)
{
	m_iClosestNode = cn;
}

int NodeManager::GetSolution(int fromNode, int toNode)
{
	return m_aiSolution[fromNode][toNode];
}
int NodeManager::GetCurrentNode()
{
	return m_iCurrentNode;
}
int NodeManager::GetNextNode()
{
	return m_iNextNode;
}
int NodeManager::GetClosestNode()
{
	return m_iClosestNode;
}
float NodeManager::GetNodeX(int n)
{
	return m_aNodes[n].GetX();
}
float NodeManager::GetNodeY(int n)
{
	return m_aNodes[n].GetY();
}
int NodeManager::GetNodeID(int n)
{
	return m_aNodes[n].GetID();
}