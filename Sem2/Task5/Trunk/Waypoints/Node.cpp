//Blake Sullivan - Node.cpp
#include "Node.h"

Node::Node()
{
	SetID(0);
	SetX(0);
	SetY(0);
}

void Node::Init(int id, float x, float y)
{
	SetID(id);
	SetX(x);
	SetY(y);
}

void Node::Init(float x, float y)
{
	SetX(x);
	SetY(y);
}

void Node::SetID(int id)
{
	m_iID = id;
}
void Node::SetX(float x)
{
	m_fX = x;
}
void Node::SetY(float y)
{
	m_fY = y;
}

int Node::GetID()
{
	return m_iID;
}
float Node::GetX()
{
	return m_fX;
}
float Node::GetY()
{
	return m_fY;
}