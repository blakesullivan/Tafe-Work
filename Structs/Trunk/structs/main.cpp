//structs
/*#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct movies{
	string title;
	int year;
};

void PrintMovie (movies movie);

int main()
{
	string mystr;
	movies mine, yours;
	mine.title = "2001 A Space Odyssey";
	mine.year = 1968;

	cout << "Enter title: ";
	getline (cin, yours.title);
	cout << "Enter year: ";
	getline (cin, mystr);
	stringstream(mystr) >> yours.year;

	cout << "My favourite movie is:\n ";
	PrintMovie (mine);
	cout << "And yours is:\n ";
	PrintMovie (yours);
	system("PAUSE");
	return 0;
}

void PrintMovie (movies movie)
{
	cout << movie.title;
	cout << " (" << movie.year << ")\n";
}*/

// array of structures
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#define N_MOVIES 3

struct movies {
	string title;
	int year;
};

void printmovie (movies movie);

int main ()
{
	movies films[N_MOVIES];
	string mystr;
	int n;
	for (n=0; n<N_MOVIES; n++)
	{
		cout << "Enter title: ";
		getline (cin,films[n].title);
		cout << "Enter year: ";
		getline (cin,mystr);
		stringstream(mystr) >> films[n].year;
	}
	cout << "\nYou have entered these movies:\n";
	for (n=0; n<N_MOVIES; n++)
		printmovie (films[n]);
	return 0;
}

void printmovie (movies movie)
{
	cout << movie.title;
	cout << " (" << movie.year << ")\n";
}

