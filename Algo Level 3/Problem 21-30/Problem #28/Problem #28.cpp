#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string ReadString(string Message)
{
    string S1;
    cout << Message << endl;
    getline(cin, S1);

    return S1;
}

char InvertingChar(char &C)
{
    return (isupper(C)) ? tolower(C) : toupper(C);
}

string InvertingAllStringLetters(string S1)
{
    for (int i = 0; i < S1.length(); i++)
    {
        S1[i] = InvertingChar(S1[i]);
    }

    return S1;
}


int main()
{
    string S1 = ReadString("Please enter your string: ");

    cout << "\nString after Inverting All Letters Case: \n";
    cout << InvertingAllStringLetters(S1) << endl;


    return 0;
}