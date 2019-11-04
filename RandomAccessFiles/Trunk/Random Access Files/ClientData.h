#ifndef CLIENTDATA_H
#define CLIENTDATA_H

#include <string>
using std::string; 

class C_ClientData
{
private:
	int		iAccountNumber;
	char	acLastName[ 15 ];
	char	acFirstName[ 10 ];
	double	dBalance;

public:

	C_ClientData(int = 0, string = "", string = "", double = 0.0);

	void setAccountNumber(int); 
	int getAccountNumber() const;

	void setLastName(string);
	string getLastName() const;

	void setFirstName(string);
	string getFirstName() const;

	void setBalance(double);
	double getBalance() const;

}; 
#endif
