#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string ReadString(string Message)
{
    string Str;
    cout << Message;
    getline(cin, Str);

    cout << "\n";

    return Str;
}

bool IsSpace(char Letter)
{
    return (Letter == ' ');
}

bool IsSymbol(char Letter)
{
    return (isdigit(Letter) || isalpha(Letter) || ispunct(Letter));
}

bool IsFirstLetter(const char& Char1, const char& Char2)
{
    return !IsSpace(Char1) && IsSymbol(Char1) && IsSpace(Char2);
}

void PrintFirstLetterInString(string& StrMessage)
{
    if (!IsSpace(StrMessage[0]) && IsSymbol(StrMessage[0]))
        cout << StrMessage[0] << "\n";
      
    for (int i = 0; i < StrMessage.length(); i++)
    {
        if (IsFirstLetter(StrMessage[i], StrMessage[i - 1]))
        {
            cout << StrMessage[i] << endl;
        }
    }

}

int main()
{
    string StrMessage = ReadString("Please ente your string: ");

    cout << "First letters of this string: \n";
    PrintFirstLetterInString(StrMessage);

    return 0;
}