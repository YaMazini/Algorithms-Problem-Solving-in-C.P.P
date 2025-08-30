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
    short int Remainder = 0;

    while (Number > 0)
    {
        Remainder = Number % 10;
        Number = Number / 10;

        Reverse = Reverse * 10 + Remainder;
    }

    return Reverse;
}

void PrintDigitsOfNumberInOrder(int Number)
{
    short int Remainder = 0;
    int ReverseNumber = ReverseOfNumber(Number);

    while (ReverseNumber > 0)
    {
        Remainder = ReverseNumber % 10;
        ReverseNumber = ReverseNumber / 10;

        cout << Remainder << "\n";
    }
}



int main()
{
    int Number = ReadPositiveNumber("Please enter a positive number: ");

    PrintDigitsOfNumberInOrder(Number);

    return 0;
}