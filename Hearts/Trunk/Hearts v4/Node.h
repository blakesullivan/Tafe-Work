#ifndef NODE_H
#define NODE_H

#include <cstdlib>
using namespace std;

class Node
{
private:
	Node *nPtr;
	int iValue;

public:
	Node(int iInputValue);
	~Node();
	void setNodeValue(int iInputValue);
	void setNodePtr(Node * nPtrValue);
	int getNodeValue();
	Node* getNodePointer();
};
#endif