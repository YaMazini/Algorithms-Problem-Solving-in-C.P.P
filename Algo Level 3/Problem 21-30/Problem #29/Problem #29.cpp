#include <iostream>
#include <string>
#include <cctype>
using namespace std;

struct stStringInfo
{
    short Length = 0;
    short CapitalLetters = 0;
    short SmallLetters = 0;
    short Digits = 0;
    short SpecialChars = 0;
    short Spaces = 0;
};

string ReadString(const string Message)
{
    string S1;
    cout << Message << "\n";
    getline(cin, S1);

    cout << "\n";

    return S1;
}

bool isspace(char& Char)
{
    return (Char == ' ');
}

stStringInfo FillStringInfo(const string& S1)
{
    stStringInfo StringInfo;
    StringInfo.Length = S1.length();

    for (short i = 0; i < S1.length(); i++)
    {
        if (isupper(S1[i]))
            StringInfo.CapitalLetters++;

        else if (islower(S1[i]))
            StringInfo.SmallLetters++;

        else if (ispunct(S1[i]))
            StringInfo.SpecialChars++;

        else if (isdigit(S1[i]))
            StringInfo.Digits++;

        else if (isspace(S1[i]))
            StringInfo.Spaces++;

    }

    return StringInfo;
}

void PrintStringInfo(const stStringInfo &StringInfo)
{
    cout << "String Length: " << StringInfo.Length << "\n";
    cout << "Capital Letters Count: " << StringInfo.CapitalLetters << "\n";
    cout << "Small Letters Count: " << StringInfo.SmallLetters << "\n";
    cout << "Special Characters Count: " << StringInfo.SpecialChars << "\n";
    cout << "Digits Count: " << StringInfo.Digits << "\n";
    cout << "Spaces Count: " << StringInfo.Spaces << "\n";
}


int main()
{
    string S1 = ReadString("Please enter your string: ");
    stStringInfo StringInfo = FillStringInfo(S1);

    PrintStringInfo(StringInfo);


    return 0;
}