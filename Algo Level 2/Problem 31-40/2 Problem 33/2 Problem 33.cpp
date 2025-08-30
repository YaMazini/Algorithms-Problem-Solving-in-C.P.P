#include <iostream>
using namespace std;

enum enCharType{SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4};

int RandomNumber(const int From, const int To)
{
	return rand() % (To - From + 1) + From;
}

int ReadPositiveNumber(string Message)
{
	int Number = 0;
	do
	{
		cout << Message;
		cin >> Number;
	} while (Number <= 0);

	return Number;
}


char GetRandomCharacter(enCharType CharType)
{
	switch (CharType)
	{
	case enCharType::SmallLetter:
		return char(RandomNumber(97, 122));

	case enCharType::CapitalLetter:
		return char(RandomNumber(65, 90));

	case enCharType::SpecialCharacter:
		return char(RandomNumber(33, 47));

	case enCharType::Digit:
		return char(RandomNumber(48, 57));
	
	default:
		return '?';
	}
}

string GenerateRandomWord(enCharType CharType, short Length)
{
	string Word = "";
	for (int i = 1; i <= Length; i++)
	{
		Word += GetRandomCharacter(CharType);
	}

	return Word;
}

string GenerateKey()
{
	string Key = "";
	for (int i = 1; i <= 4; i++)
	{
		Key += GenerateRandomWord(enCharType::CapitalLetter, 4);
		if (i != 4)
			Key += "-";
	}

	return Key;
}


void FillStringArrayWithKeys(string Arr[100], int ArrLength)
{
	for (int i = 0; i < ArrLength; i++)
	{
		Arr[i] = GenerateKey();
	}
}

void PrintStringArray(string Arr[100], int ArrLength)
{
	for (int i = 0; i < ArrLength; i++)
	{
		cout << "Array [" << i + 1 << "]: "
			<< Arr[i] << "\n";
	}
}




int main()
{
	srand((unsigned)time(NULL));

	string Arr[100];
    int ArrLength = 0;
	ArrLength = ReadPositiveNumber("Please enter the number of arrays: ");


	FillStringArrayWithKeys(Arr, ArrLength);
	PrintStringArray(Arr, ArrLength);


    return 0;
}