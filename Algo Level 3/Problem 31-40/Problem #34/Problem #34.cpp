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

void PrintAllVowelsInString(string S1)
{
    for (short i = 0; i < S1.length(); i++)
    {
        if (IsVowel(S1[i]))
            cout << S1[i] << "    ";
    }

    cout << "\n";
}


int main()
{
    string S1 = ReadString("Please enter your string: ");

    cout << "Vowels in your string are: ";
    PrintAllVowelsInString(S1);


    return 0;
}