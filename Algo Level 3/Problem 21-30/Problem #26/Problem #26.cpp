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

string ToUpperForEachLetter(string S1)
{
    bool IsFirstLetter = true;
    for (int i = 0; i < S1.length(); i++)
    {
        S1[i] = toupper(S1[i]);
    }

    return S1;
}

string ToLowerForEachLetter(string S1)
{
    bool IsFirstLetter = true;
    for (int i = 0; i < S1.length(); i++)
    {
        S1[i] = tolower(S1[i]);
    }

    return S1;
}

int main()
{
    string S1 = ReadString("Please ente your string: ");

    cout << "String After Upper: \n";
    cout << ToUpperForEachLetter(S1) << endl;

    cout << "\nString After Lower: \n";
    cout << ToLowerForEachLetter(S1) << endl;

    return 0;
}