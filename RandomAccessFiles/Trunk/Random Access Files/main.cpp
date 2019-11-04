//This program reads a random-access file sequentially,  updates
//data previously written to the file, creates data to be placed
//in the file, and deletes data previously stored in the file.

#include <iostream>
/*using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::ios;
using std::left;
using std::right;
using std::showpoint; */

#include <fstream>
/*using std::ostream;
using std::fstream;
using std::ofstream;
using std::ifstream;*/

#include <iomanip>
/*using std::setw;
using std::setprecision;*/

#include <cstdlib>
/*using std::exit; */
using namespace std;

#include "ClientData.h" 

int	enterChoice();
void createTextFile	(fstream&);
void updateRecord	(fstream&);
void newRecord		(fstream&);
void deleteRecord (fstream&);

void outputLine(ostream&, const C_ClientData&);
int	getAccount(const char * const);

enum iChoices { PRINT = 1, UPDATE, NEW, DELETE, END };

int mainOne()
{
	ofstream ofsCreditRecords("credit.dat", ios::out | ios::binary);

	if (!ofsCreditRecords)
	{
		cerr << "File \"credit.dat\" could not be opened." << endl;
		system("PAUSE");
		exit(1); 
	}

	C_ClientData clBlankClient; 
	
	for (int i =0; i < 100; i++)
	{
		ofsCreditRecords.write(reinterpret_cast<const char*>(&clBlankClient), sizeof(C_ClientData));
	}
	return 0;
}

int mainTwo()
{
	int	iAccountNumber;
	char acLastName [15];
	char acFirstName[10];
 	double dBalance;
	
	fstream ofsCredit("credit.dat", ios::in | ios::out | ios::binary);
	
	if (!ofsCredit)
	{
		cerr << "File could not be opened." << endl;
		exit(1);
	}

	cout << "Enter account number (1 to 100, 0 to end input)\n? ";

	C_ClientData clClient; 
	cin >> iAccountNumber;

	while(iAccountNumber > 0 && iAccountNumber <= 100)
	{
		cout <<  "Enter Lastname, Firstname, Balance\n? ";
		cin >> setw(15) >> acLastName;
		cin >> setw(10) >> acFirstName;
		cin >> dBalance;
		
		clClient.setAccountNumber(iAccountNumber);
		clClient.setLastName(acLastName);
		clClient.setFirstName(acFirstName); 
		clClient.setBalance(dBalance);

		ofsCredit.seekp((clClient.getAccountNumber() - 1) * sizeof(C_ClientData));
		
		ofsCredit.write(reinterpret_cast< const char * >(&clClient),  sizeof(C_ClientData));

		cout << "Enter account number\n? "; 
		cin >> iAccountNumber; 
	}
	return 0;
}

int mainThree()
{
	ifstream ifsCreditRecord("credit.dat", ios::in | ios::binary);
	
	if(!ifsCreditRecord)
	{
		cerr << "File \"credit.dat\" could not be opened." << endl; 
		exit(1);
	}

	cout << left<< setw(10) << "Account" 
				<< setw(16) << "Last Name" 
				<< setw(11) << "First Name" << left
				<< setw(10) << right << "Balance" << endl; 
	
	C_ClientData clClient;     
	
	ifsCreditRecord.read(reinterpret_cast< char * >(&clClient), sizeof(C_ClientData));
	
	while(!ifsCreditRecord.eof())
	{
		if(clClient.getAccountNumber() != 0)
		{
			outputLine(cout, clClient);
		}
		ifsCreditRecord.read(reinterpret_cast< char * >(&clClient), sizeof(C_ClientData));
	}
	return 0;
} 


int main()
{
	mainOne();
	mainTwo();
	mainThree();
	
	fstream iofsCreditRecords("credit.dat", ios::in | ios::out | ios::binary);

	if(!iofsCreditRecords)
	{
		cerr << "File \"credit.dat\" could not be opened."  << endl;
		system("PAUSE");
		exit(1);
	}
	int iChoice;
	
	while((iChoice = enterChoice()) != END)
	{
		switch(iChoice)
		{
			case PRINT:  
				createTextFile(iofsCreditRecords);
			break;
			case UPDATE:
				updateRecord(iofsCreditRecords);
			break;
			case NEW:
				newRecord(iofsCreditRecords);
			break;
			case DELETE:
				deleteRecord(iofsCreditRecords);
			break;
			default:
				cerr << "Incorrect iChoice" << endl; 
			break; 
		}
		iofsCreditRecords.clear(); 
	}
	return 0;
} 

int enterChoice()
{
	cout<< "\nEnter your iChoice" << endl
		<< "1 - store a formatted text file of accounts" << endl
		<< "    called \"print.txt\" for printing" << endl 
		<< "2 - update an account" << endl
		<< "3 - add a new account" << endl
		<< "4 - delete an account" << endl
		<< "5 - end program\n? ";

	int iMenuChoice;
	cin >> iMenuChoice;
	return iMenuChoice;
} 

void createTextFile(fstream &readFromFile)
{
	ofstream ofsPrintFile("print.txt", ios::out);

	if(!ofsPrintFile)
	{
		cerr << "File \"print.txt\" could not be created." << endl;
		exit(1);
	}

	ofsPrintFile <<left	<< setw(10) << "Account" 
						<< setw(16) << "Last Name" 
						<< setw(11) << "First Name" << right	
						<< setw(10) << "Balance" << endl;
	
	readFromFile.seekg(0);
		
	C_ClientData clClient;
	readFromFile.read(reinterpret_cast< char * >(&clClient),  sizeof(C_ClientData));
	
	while(!readFromFile.eof())
	{
		if(clClient.getAccountNumber() != 0)
		{ 
			outputLine(ofsPrintFile, clClient);
		} 
		
readFromFile.read(reinterpret_cast< char * >(&clClient),sizeof(C_ClientData));
	}
}

void updateRecord(fstream &updateFile)
{
	int iAccountNumber = getAccount("Enter account to update");
	updateFile.seekg((iAccountNumber - 1) * sizeof(C_ClientData));
	
	C_ClientData clClient;
updateFile.read(reinterpret_cast< char * >(&clClient),
sizeof(C_ClientData));

	if(clClient.getAccountNumber() != 0)
	{
		outputLine(cout, clClient);
		cout << "\nEnter charge (+) or payment (-): ";
		double dTransaction;
		cin >> dTransaction;

		double dOldBalance = clClient.getBalance();
		clClient.setBalance(dOldBalance + dTransaction);
		outputLine(cout, clClient);
		updateFile.seekp((iAccountNumber - 1) * sizeof(C_ClientData));

updateFile.write(reinterpret_cast< const char * >
(&clClient), sizeof(C_ClientData));
	} else { 
cerr << "Account #" << iAccountNumber << " has no information." << endl;
	}
}

void newRecord(fstream &insertInFile)
{
	int iAccountNumber = getAccount("Enter new account number");

	insertInFile.seekg((iAccountNumber - 1) * sizeof(C_ClientData));

	C_ClientData clClient;
insertInFile.read(reinterpret_cast< char * >(&clClient),
sizeof(C_ClientData));

	if (clClient.getAccountNumber() == 0)
	{
		char 	acLastName [ 15 ];
		char		acFirstName[ 10 ];
		double	dBalance;

		cout << "Enter lastname,  firstname,  balance\n? ";
		cin >> setw(15)  >> acLastName;
		cin >> setw(10)  >> acFirstName;
		cin >> dBalance;

		clClient.setLastName	(acLastName);
		clClient.setFirstName	(acFirstName);
		clClient.setBalance	(dBalance);
		clClient.setAccountNumber(iAccountNumber);

insertInFile.seekp((iAccountNumber -  1) * 
sizeof(C_ClientData));

insertInFile.write(reinterpret_cast< const char * >
(&clClient),sizeof(C_ClientData));
	} else  {
cerr << "Account #" << iAccountNumber <<  "already contains information." << endl; 
	} 
}

void deleteRecord(fstream &deleteFromFile)
{
	int iAccountNumber = getAccount("Enter account to delete");
	
	deleteFromFile.seekg((iAccountNumber - 1) * sizeof(C_ClientData));
	C_ClientData clClient;
deleteFromFile.read(reinterpret_cast< char * >(&clClient), 
sizeof(C_ClientData));

	if(clClient.getAccountNumber() != 0)
	{
		C_ClientData clBlankClient; 

deleteFromFile.seekp((iAccountNumber - 1) * 
sizeof(C_ClientData));

deleteFromFile.write(reinterpret_cast< const char * >
(&clBlankClient), sizeof(C_ClientData));
		cout << "Account #" << iAccountNumber << " deleted.\n";
	
} else {
		cerr << "Account # " << iAccountNumber << " is empty.\n";
}
}

void outputLine(ostream &output, const C_ClientData &clRecord)
{
	output << left << setw(10) << clRecord.getAccountNumber()
			<< setw(16) << clRecord.getLastName()
			<< setw(11) << clRecord.getFirstName()
			<< setw(10) << setprecision(2) << right << fixed
			<< showpoint << clRecord.getBalance() << endl;
}

int getAccount(const char * const prompt)
{
	int iAccountNumber;
	do
	{
		cout << prompt << " (1 - 100): ";
		cin >> iAccountNumber;
	} while(iAccountNumber <  1 || iAccountNumber > 100);
	return iAccountNumber;
}
