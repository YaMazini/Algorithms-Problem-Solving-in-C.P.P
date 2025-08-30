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

bool IsVowel(char C1)
{
    C1 = tolower(C1);
    return (C1 == 'a' || C1 == 'e' || C1 == 'i' || C1 == 'o' || C1 == 'u');
}

short CountVowels(string S1)
{
    short Counter = 0;

    for (short i = 0; i < S1.length(); i++)
    {
        if (IsVowel(S1[i]))
            Counter++;
    }

    return Counter;
}


int main()
{
    string S1 = ReadString("Please enter your string: ");

    cout << "Number of vowels is: " << CountVowels(S1) << endl;


    return 0;
}