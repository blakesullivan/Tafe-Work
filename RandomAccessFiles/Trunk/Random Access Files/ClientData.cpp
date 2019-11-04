//Class ClientData stores customer's credit information.
#include <string>
using namespace std; 

#include "ClientData.h"

C_ClientData::C_ClientData(	int iAccountNumberValue, 
					string acLastNameValue, 
					string acFirstNameValue, 
					double dBalanceValue)
{
	setAccountNumber(iAccountNumberValue); 
	setLastName(acLastNameValue); 
	setFirstName(acFirstNameValue); 
	setBalance(dBalanceValue);
}

int C_ClientData::getAccountNumber() const
{
	return iAccountNumber; 
} 

void C_ClientData::setAccountNumber(int iAccountNumberValue)
{
	iAccountNumber = iAccountNumberValue; 
}

string C_ClientData::getLastName() const
{
     return acLastName;
}

void C_ClientData::setLastName(string ssLastNameString)
{
	const char *acLastNameValue = ssLastNameString.data();
	int iLength = ssLastNameString.size();
	iLength = (iLength < 15 ? iLength : 14);
	strncpy(acLastName, acLastNameValue, iLength);
	acLastName[ iLength ] = '\0'; 
}

string C_ClientData::getFirstName() const
{
	return acFirstName; 
} 

void C_ClientData::setFirstName(string ssFirstNameString)
{
	const char *acFirstNameValue = ssFirstNameString.data();
	int iLength = ssFirstNameString.size();
	iLength = (iLength < 10 ? iLength : 9);
	strncpy(acFirstName, acFirstNameValue, iLength);
	acFirstName[ iLength ] = '\0'; 
}

double C_ClientData::getBalance() const 
{
	return dBalance;
}

void C_ClientData::setBalance(double dBalanceValue)
{
	dBalance = dBalanceValue;
}
