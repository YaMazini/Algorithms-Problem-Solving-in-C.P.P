#include <iostream>
using namespace std;


int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message, cin >> Number;

    } while (Number <= 0);

    return Number;
}

void PrintInverteLetterPattern(int Number)
{
    for (int i = Number; i >= 1; i--)
    {
        for (int j = i; j >= 1; j--)
        {
            cout << char(64 + i);
        }
        cout << "\n";
    }
}


int main()
{
    int Number = ReadPositiveNumber("Please enter a positive number: ");

    PrintInverteLetterPattern(Number);


    return 0;
}