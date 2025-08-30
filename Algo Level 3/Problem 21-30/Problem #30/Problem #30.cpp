#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string ReadString(const string Message)
{
    string S1;
    cout << Message << "\n";
    getline(cin, S1);

    cout << "\n";

    return S1;
}

char ReadCharacter(const string Message)
{
    char C;
    cout << Message << "\n";
    cin >> C;

    cout << "\n";

    return C;
}

short CharacterFrequency(const string& S1, char& Letter)
{
    short Counter = 0;
    for (short i = 0; i < S1.length(); i++)
    {
        if (S1[i] == Letter)
            Counter++;
    }

    return Counter;
}


int main()
{
    string S1 = ReadString("Please enter your string: ");
    char Letter = ReadCharacter("Please enter a character: ");

    cout << "Letter \'" << Letter << "\' Count: " << CharacterFrequency(S1, Letter) << endl;


    return 0;
}