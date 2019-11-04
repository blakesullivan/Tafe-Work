//Blake Sullivan - Node.cpp
#include "Node.h"

unsigned int Node::ms_uiNodeCount = 0;

Node::Node()
{
	SetDisplayPos(ms_uiNodeCount);
	ms_uiNodeCount++;
	SetNextNode(NULL);
	cout << "Node " << ms_uiNodeCount << " Constructed" << endl;
}

Node::Node(const Node& n)
{
	ms_uiNodeCount++;

	m_uiDisplayPos = n.GetDisplayPos();
	mp_nNextNode = NULL;
	cout << "Node[" << n.GetDisplayPos() << "] Copied!" << endl;
}

Node::~Node()
{
	ms_uiNodeCount--;
	cout << "Node " << m_uiDisplayPos << " destructed!" << endl;
}

void Node::SetNextNode(Node* n)
{
	mp_nNextNode = n;
}

void Node::SetDisplayPos(const unsigned int dp)
{
	m_uiDisplayPos = dp;
}

Node* Node::GetNextNode() const
{
	return mp_nNextNode;
}

unsigned int Node::GetDisplayPos() const
{
	return m_uiDisplayPos;
}

unsigned int Node::GetNodeCount()
{
	return ms_uiNodeCount;
}