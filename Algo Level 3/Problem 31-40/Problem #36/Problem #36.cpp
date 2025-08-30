#include <iostream>
#include <string>
using namespace std;

string ReadString(string Message)
{
    string S1;
    cout << Message << endl;
    getline(cin, S1);

    return S1;
}

short CountWordsInString(string S1)
{
    string Word;
    string Delim = " ";
    short pos = 0;
    short Counter = 0;

    while ((pos = S1.find(Delim)) != string::npos)
    {
        Word = S1.substr(0, pos);
        S1.erase(0, pos + Delim.length());

        if (Word != "")
        {
            Counter++;
        }
    }

    if (S1 != "")
    {
        Counter++;
    }

    return Counter;
}

int main()
{
    string S1 = ReadString("Please enter your string: ");
    
    cout << "\n The Number of words in your string is: ";
    cout << CountWordsInString(S1) << endl;


    return 0;
}