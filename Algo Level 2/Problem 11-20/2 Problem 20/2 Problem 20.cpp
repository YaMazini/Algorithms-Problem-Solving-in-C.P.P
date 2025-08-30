#include <iostream>
#include <cstdlib>
using namespace std; 

enum enCharType{SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4};

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

char GetRandomChar(enCharType CharType)
{
    char RandomChar;
    switch (CharType)
    {
    case enCharType::SmallLetter:
        return RandomChar = char(RandomNumber(97, 122));

    case enCharType::CapitalLetter:
        return RandomChar = char(RandomNumber(65, 90));

    case enCharType::SpecialCharacter:
        return RandomChar = char(RandomNumber(33, 47));

    case enCharType::Digit:
        return RandomChar = char(RandomNumber(48, 57));

    default:
        return '?';
    }
}

int main()
{
    srand((unsigned)time(NULL));

    cout << GetRandomChar(enCharType::SmallLetter) << "\n";
    cout << GetRandomChar(enCharType::CapitalLetter) << "\n";
    cout << GetRandomChar(enCharType::SpecialCharacter) << "\n";
    cout << GetRandomChar(enCharType::Digit) << "\n";


    return 0;
}