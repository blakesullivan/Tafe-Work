//Blake Sullivan - CardManager.cpp
#include "CardManager.h"

CardManager::CardManager()
{
	m_pDeck = NULL;
	m_pHeadHand = NULL;
	ManagePlay();
	system("PAUSE");
}

CardManager::~CardManager()
{
	delete m_pDeck;
	delete m_pHeadHand;
}

void CardManager::Init(int iNumDeckCards, int iNumHands)
{
	string sName = "";
	srand(time(NULL));
	if (m_pDeck == NULL) {SetDeck(new Deck(iNumDeckCards));}

	Hand *newHand = NULL, *currHand = NULL;
	for (int i = 0; i < iNumHands; i++)
	{
		newHand = new Hand();
		sName = "Player ";
		sName += (49 + i);
		//cout << "String Name: " << sName << endl;
		newHand->SetPlayerName(sName);
		//cout << "Hand Name: " << newHand->GetPlayerName() << endl;

		if (m_pHeadHand == NULL) 
		{
			SetHeadHand(newHand);
			currHand = GetHeadHand();
		}
		else
		{
			currHand->SetNextHand(newHand);
			currHand = currHand->GetNextHand();
		}
	}
}
void CardManager::ManagePlay()
{
	bool bExit = false;
	int iTurn = 0, iOption = 0;
	string sOption = "";
	Hand* currHand = NULL;
	Init(51, 4);
	m_pDeck->ViewAll();
	//m_pDeck->Sort();

	BeginDeal(4);
	DisplayHands();

	do
	{
		currHand = GetHand(iTurn);
		DealCard(1, GetDeck(), currHand);
		cout << currHand->GetPlayerName() << " what do you want to do?\n";
		cout << " 1. Play Card\n 2. Pass\n 3. Change Player\n 4. Exit\n";
		getline(cin, sOption);
		iOption = atoi(sOption.c_str());
		switch (iOption)
		{
		case 1:
			PlayCardOptions(currHand);
		break;
		case 2:
			//Do nothing
			cout << currHand->GetPlayerName() << " passing" << endl;
		break;
		case 3:
			cout << "Changing Player" << endl;
			iTurn++; if (iTurn >= 4) {iTurn = 0;}
		default:
			bExit = true;
		break;
		}
		
	} while (bExit == false);
	
	/*cout << "DECK LIST" << endl;
	m_pDeck->ViewAll();
	cout << m_pHeadHand->GetPlayerName() << " HAND LIST" << endl;
	m_pHeadHand->ViewAll();
	cout << m_pHeadHand->GetNextHand()->GetPlayerName() << " HAND LIST" << endl;
	m_pHeadHand->GetNextHand()->ViewAll();
	PlaceCard(rand() % 5, m_pHeadHand, m_pHeadHand->GetGarden());
	cout << m_pHeadHand->GetPlayerName() << " HAND LIST" << endl;
	m_pHeadHand->ViewAll();
	cout << m_pHeadHand->GetPlayerName() << " GARDEN LIST" << endl;
	m_pHeadHand->GetGarden()->ViewAll();
	PlaceCard(rand() % 5, m_pHeadHand->GetNextHand(), m_pHeadHand->GetNextHand()->GetGarden());
	m_pHeadHand->ViewAll();
	cout << m_pHeadHand->GetNextHand()->GetPlayerName() << " HAND LIST" << endl;
	m_pHeadHand->GetNextHand()->ViewAll();
	cout << m_pHeadHand->GetNextHand()->GetPlayerName() << " GARDEN LIST" << endl;
	m_pHeadHand->GetNextHand()->GetGarden()->ViewAll();*/
}

void CardManager::BeginDeal(unsigned int uiPlayerNum)
{
	Hand *tempHand = NULL;
	tempHand = m_pHeadHand;
	for (int i = 0; i < uiPlayerNum; i++)
	{
		//cout << "Dealing to: " << tempHand->GetPlayerName() << endl;
		DealCard(5, m_pDeck, tempHand);
		tempHand = tempHand->GetNextHand();
	}
}

void CardManager::DealCard(unsigned int uiDealAmount, LinkedList* fromLL, LinkedList* toLL)
{
	int iCardNum = 0; 
	Card* tempCard = NULL;
	for (int i = 0; i < uiDealAmount; i++)
	{
		iCardNum = rand() % fromLL->GetCardCount();
		toLL->CopyCard(fromLL->FindCard(iCardNum));
		fromLL->DeleteCard(iCardNum);
	}
}

void CardManager::PlaceCard(unsigned int uiCardNum, LinkedList* fromLL, LinkedList* toLL)
{
	Card* tempCard = NULL;
	toLL->CopyCard(fromLL->FindCard(uiCardNum));
	fromLL->DeleteCard(uiCardNum);
}

void CardManager::DisplayHands()
{
	Hand *tempHand = GetHeadHand();
	while (tempHand != NULL)
	{
		cout << "Hand: " << tempHand->GetPlayerName() << endl;
		tempHand->ViewAll();
		tempHand = tempHand->GetNextHand();
	}
}

void CardManager::SetDeck(Deck* d)
{
	m_pDeck = d;
}
void CardManager::SetHeadHand(Hand* hh)
{
	m_pHeadHand = hh;
}

Deck* CardManager::GetDeck()
{
	return m_pDeck;
}
Hand* CardManager::GetHeadHand()
{
	return m_pHeadHand;
}
Hand* CardManager::GetHand(int iNum)
{
	Hand* currHand = GetHeadHand();
	for (int i = 0; i < iNum; i++)
		{currHand = currHand->GetNextHand();}

	return currHand;
}

void CardManager::PlayCardOptions(Hand* currHand)
{
	int iOption = 0;
	string sOption = "";
	cout << "What card do you want to play?:" << endl;
	currHand->ViewAll();
	getline(cin, sOption);
	iOption = atoi(sOption.c_str());
	PlaceCard(iOption, currHand, currHand->GetGarden());
	cout << "Hand: " << currHand->GetPlayerName() << endl;
	currHand->ViewAll();
	cout << "Garden: " << currHand->GetPlayerName() << endl;
	currHand->GetGarden()->ViewAll();
}