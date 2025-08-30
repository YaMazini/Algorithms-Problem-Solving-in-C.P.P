#include <iostream>
using namespace std;


int ReadPositiveNumber(string Message)
{
    int Number;
    do
    {
        cout << Message, cin >> Number;

    } while (Number <= 0);

    return Number;
}

int ReverseOfNumber(int Number)
{
    int Reverse = 0;
    short Remainder = 0;

    while (Number > 0)
    {
        Remainder = Number % 10;
        Number = Number / 10;

        Reverse = Reverse * 10 + Remainder;
    }

    return Reverse;
}

bool IsPalindromeNumber(int Number)
{
    return Number == ReverseOfNumber(Number);
}



int main()
{
    int Number = ReadPositiveNumber("Please enter a positive number: ");

    if (IsPalindromeNumber(Number))
        cout << "\n " << Number << " is a Palindrome number\n";

    else
        cout << "\n " << Number << " is NOT a Palindrome number\n";

    return 0;
}