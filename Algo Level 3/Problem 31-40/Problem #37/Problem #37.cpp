#include <iostream>
#include <vector>
#include <string>
using namespace std;

string ReadString(string Message)
{
    string S1;
    cout << Message << endl;
    getline(cin, S1);

    return S1;
}

vector <string> SplitString(string S1, const string& Delim)
{
    vector<string> vWords;
    string Word;
    short pos = 0;

    while ((pos = S1.find(Delim)) != string::npos)
    {
        Word = S1.substr(0, pos);
        S1.erase(0, pos + Delim.length());

        if (Word != "")
        {
            vWords.push_back(Word);
        }
    }

    if (S1 != "")
    {
        vWords.push_back(S1);
    }

    return vWords;
}

int main()
{
    string S1 = ReadString("Please enter your string: ");
    vector<string> vWords = SplitString(S1, " ");

    cout << "\n Tokens = " << vWords.size() << endl;

    for (string& S : vWords)
    {
        cout << S << endl;
    }


    return 0;
}