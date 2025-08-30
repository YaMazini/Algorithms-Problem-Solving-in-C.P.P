#include <iostream>
#include <string>
using namespace std;

string ReadString(const string Message)
{
    string S1;
    cout << Message << endl;
    getline(cin, S1);
    cout << "\n";

    return S1;
}

void PrintAllWordsInString(string S1)
{
    string Word;
    string Delim = " ";
    short pos;

    while ((pos = S1.find(Delim)) != string::npos)
    {
        Word = S1.substr(0, pos);
        S1.erase(0, pos + Delim.length());

        if (Word != "")
        {
            cout << Word << endl;
        }
    }

    if (S1 != "")
    {
        cout << S1 << endl;
    }
}


int main()
{
    string S1 = ReadString("Please enter your string: ");

    cout << "\n Your string Words are: " << endl;
    PrintAllWordsInString(S1);

    return 0;
}