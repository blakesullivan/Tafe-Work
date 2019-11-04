//Sort 3 Characters Class Definiton

class SortCharacters
{
private:
	char cChar1;
	char cChar2;
	char cChar3;
	//chars to be swapped
	char cCharS1;
	char cCharS2;
	char cCharS3;

	char cArray[20];
	int iArray[1000];

public:
	SortCharacters();
	SortCharacters(char, char, char);

	void GenerateRandomNumbers();
	void GenerateRandomCharacters(int);

	void SortChars();
	void SortIntArray();
	void SortCharArray();

	void SwapChars(char&, char&); //char, char only byReference
	void SwapInts(int&, int&);
	
	char GetChar1();
	char GetChar2();
	char GetChar3();
	char GetCharS1();
	char GetCharS2();
	char GetCharS3();

	void SetChar1(char);
	void SetChar2(char);
	void SetChar3(char);
	void SetCharS1(); //dont need input, just needs cChar1
	void SetCharS2();
	void SetCharS3();

	int GetIntArray(int);
	int* GetIntArrayPoint(int);
	char GetCharArray(int);
	char* GetCharArrayPoint(int);

	void SetIntArray(int, int);
	void SetCharArray(int, char);
};