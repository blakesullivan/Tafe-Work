//Blake Sullivan - Node.h
#ifndef NODE
#define NODE

#include <iostream>
using namespace std;
class Node
{
private:
	static unsigned int ms_uiNodeCount;
	Node* mp_nNextNode;
	unsigned int m_uiDisplayPos;

public:
	Node();
	Node(const Node&);
	~Node();
	
	void SetNextNode(Node*);
	void SetDisplayPos(const unsigned int);

	Node* GetNextNode() const;
	unsigned int GetDisplayPos() const;
	static unsigned int GetNodeCount();
};
#endif