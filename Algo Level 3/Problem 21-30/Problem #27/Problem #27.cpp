#include <iostream>
#include <string>
#include <cctype>
using namespace std;

char ReadChar(string Message)
{
    char Char;
    cout << Message << "\n";
    cin >> Char;

    cout << "\n";

    return Char;
}

char InvertingChar(char& Char)
{
    return (isupper(Char)) ? tolower(Char) : toupper(Char);
}

int main()
{
    char Char = ReadChar("Please enter a character");

    cout << "Char After inverting case: \n";
    cout << InvertingChar(Char) << endl;
 
    return 0;
}