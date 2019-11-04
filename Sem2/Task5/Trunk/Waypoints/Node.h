//Blake Sullivan - Node.h
#ifndef NODE_H
#define NODE_H

class Node
{
private:
	float m_fX, m_fY;
	int m_iID;
public:
	Node();

	void Init(int, float, float);
	void Init(float, float);

	void SetID(int);
	void SetX(float);
	void SetY(float);

	int GetID();
	float GetX();
	float GetY();
};
#endif