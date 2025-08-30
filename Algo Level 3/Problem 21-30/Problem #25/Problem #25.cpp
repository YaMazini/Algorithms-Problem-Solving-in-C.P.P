#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string ReadString(string Message)
{
    string Str;
    cout << Message << "\n";
    getline(cin, Str);

    cout << "\n";

    return Str;
}

bool IsSpace(const char& Letter)
{
    return Letter == ' ';
}

string GetlowerLettersforEachWord(string S1)
{
    bool IsFirstLetter = true;
    for (short i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ' && IsFirstLetter)
        {
            S1[i] = tolower(S1[i]);
        }
    
        IsFirstLetter = (IsSpace(S1[i])) ? true : false;
    }

    return S1;
}

int main()
{
    string S1 = ReadString("Please ente your string: ");

    cout << "String After conversion: \n";
    cout << GetlowerLettersforEachWord(S1) << endl;

    return 0;
}