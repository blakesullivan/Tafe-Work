#include "Linked_List.h"

Linked_List::Linked_List()
{
	ptrHead = NULL;
	ptrTail = ptrHead;
	ptrCurrent = ptrHead;
}
Linked_List::~Linked_List()
{

}
Node* Linked_List::createNode(int iNodeValue)
{
	return ptrNode = new Node(iNodeValue);
}
void Linked_List::addNode(Node* ptrNode)
{
	if (ptrHead == NULL)
	{
		ptrHead = ptrNode;
		ptrTail = ptrHead;
		ptrCurrent = ptrHead;
	}
	else
	{
		ptrTail->setNodePtr(ptrNode);
		ptrTail = ptrNode;
		ptrTail->setNodePtr(NULL);
	}
}
void Linked_List::createDeck(int deckSize)
{
	int iValue = 0;
	int num = 15;
	int value = 0;
	int iNodeValue = 0;

	for (int i = 0;i < deckSize;i++)
	{
		if (num > 14)
		{
			num = 2;
			value = value + 100;
		}
		iNodeValue = value + num;
		createNode(iNodeValue);
		addNode(ptrNode);
		num++;
	}
}

void Linked_List::displayNodes(int randNum)
{
	Node *ptrTempCurrent;
	
	ptrTempCurrent = ptrHead;
	cout << "Node  ";
	for (int i = 0; i < randNum;i++)
	{
		cout << setw(3) << i << ", ";
	}
	cout << endl;

	cout<< "Value " ;
	for (int i = 0;i< randNum;i++)
	{
		cout<< ptrTempCurrent->getNodeValue() << ", "; 
		ptrTempCurrent = ptrTempCurrent->getNodePointer();
	}
	cout << endl;
	system("pause");
}
void Linked_List::displayHand()
{
	Node *ptrTempCurrent;
	
	ptrTempCurrent = ptrHead;
	cout << "Node  ";
	for (int i = 0; i < 13;i++)
	{
		cout << setw(3) << i << ", ";
	}
	cout << endl;

	cout<< "Value " ;
	for (int i = 0;i< 13;i++)
	{
		cout<< ptrTempCurrent->getNodeValue() << ", "; 
		ptrTempCurrent = ptrTempCurrent->getNodePointer();
	}
	cout << endl;
	system("pause");
}
Node* Linked_List::searchList(int pickedNode,int randomCounter)
{
	Node *ptrPrevious;
	Node *ptrRemovedNode;

	ptrCurrent = ptrHead;
	if (pickedNode == 0)
	{
		ptrRemovedNode = ptrCurrent;
		ptrHead = ptrHead->getNodePointer();
	}
	else
	{
		for (int i = 1;i< randomCounter;i++)
		{
			ptrPrevious = ptrCurrent;
			ptrCurrent = ptrCurrent->getNodePointer();
			if (i == pickedNode)
			{
				ptrRemovedNode = ptrCurrent;
				ptrPrevious->setNodePtr(ptrCurrent->getNodePointer());
				break;
			}
		}
	}
	return ptrRemovedNode;
}
Node* Linked_List::getNode()
{
	return ptrHead->getNodePointer();
}
void Linked_List::sortHands()
{
	int temp;
	Node *ptrSortCurrent;

	for(int i=0;i < 13;i++)
	{
		ptrSortCurrent = ptrHead;
		for(int j=0;j < 13-1;j++)
		{
			if(ptrSortCurrent->getNodeValue() > ptrSortCurrent->getNodePointer()->getNodeValue())
			{
				temp = ptrSortCurrent->getNodePointer()->getNodeValue();
				ptrSortCurrent->getNodePointer()->setNodeValue(ptrSortCurrent->getNodeValue());
				ptrSortCurrent->setNodeValue(temp);
			}
			ptrSortCurrent = ptrSortCurrent->getNodePointer();
		}
	}
}