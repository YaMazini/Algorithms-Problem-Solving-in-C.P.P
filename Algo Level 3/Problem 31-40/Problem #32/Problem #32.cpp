#include <iostream>
using namespace std;

char ReadChar(const string Message)
{
    char C1;
    cout << Message << endl;
    cin >> C1;

    while (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Please enter a character: " << endl;
        cin >> C1;
    }
    cout << "\n";

    return C1;
}

bool IsVowel(char C1)
{
    C1 = tolower(C1);
    return (C1 == 'a' || C1 == 'e' || C1 == 'i' || C1 == 'o' || C1 == 'u');
}

int main()
{
    char Letter = ReadChar("Please enter a char: ");
    
    if (IsVowel(Letter))
        cout << "Yes, Letter \'" << Letter << "\' is a vowel \n";

    else 
        cout << "No, Letter \'" << Letter << "\' is NOT a vowel \n";

    return 0;
}