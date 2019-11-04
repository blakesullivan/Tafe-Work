#include "Node.h"

Node::Node(int iInputValue)
{
	setNodeValue(iInputValue);
	setNodePtr(NULL);
}
Node::~Node()
{
	
}
void Node::setNodeValue(int iInputValue)
{
	iValue = iInputValue;
}
void Node::setNodePtr(Node * nPtrValue)
{
	nPtr = nPtrValue;
}
int Node::getNodeValue()
{
	return iValue;
}
Node* Node::getNodePointer()
{
	return nPtr;
}