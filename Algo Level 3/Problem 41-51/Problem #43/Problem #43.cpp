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


vector <string> SplitString(string S1, string Delim)
{
    vector <string> vWords;
    string Word;
    short pos;
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

string StringToLower(string S1)
{
    string LowerS1 = "";
    for (short i = 0; i < S1.length(); i++)
    {
        LowerS1 += tolower((S1[i]));
    }

    return LowerS1;
}

string JoinString(vector<string> vWords, string Delim)
{
    string S1 = "";
    for (string& Word : vWords)
    {
        S1 += Word + Delim;
    }

    return S1.substr(0, S1.length() - Delim.length());
}

string ReplaceWordInString(vector<string> vWords, string WordToReplace, string ReplacedWord, string Delim, bool MatchCase = true)
{
    for (string& Word : vWords)
    {
        if (MatchCase)
        {
            if (Word == WordToReplace)
            {
                Word = ReplacedWord;
            }
        }

        else
        {
            if (StringToLower(Word) == StringToLower(WordToReplace))
            {
                Word = ReplacedWord;
            }
        }
    }

    return JoinString(vWords, Delim);
}


int main()
{
    string S1 = ReadString("Please enter your string: ");
    vector <string> vS1Words = SplitString(S1, " ");

    string WordToReplace = ReadString("Please enter a word from your string to Replace: ");
    string ReplacedWord = ReadString("Please enter the replaced Word: ");

    cout << "\n Original String: \n" << S1 << endl;

    cout << "\n Replace with Match Case: " << endl;
    cout << ReplaceWordInString(vS1Words, WordToReplace, ReplacedWord, " ") << endl;

    cout << "\n Replace Without Match Case: " << endl;
    cout << ReplaceWordInString(vS1Words, WordToReplace, ReplacedWord, " ", false) << endl;


    return 0;
}