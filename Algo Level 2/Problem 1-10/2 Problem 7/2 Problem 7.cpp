#include <iostream>
#include <string>
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

int ReverseNumber(int Number)
{
    int Reverse = 0;
    int Remainder = 0;

    while (Number > 0)
    {
        Remainder = Number % 10;
        Number = Number / 10;

        Reverse = Reverse * 10 + Remainder;
    }

    return Reverse;
}

void PrintReverseNumber(int Number)
{
    cout << "\n The Reverse of " << Number << " is: " << ReverseNumber(Number) << "\n";

}



int main()
{
    PrintReverseNumber(ReadPositiveNumber("Please enter positive number: "));



    return 0;
}