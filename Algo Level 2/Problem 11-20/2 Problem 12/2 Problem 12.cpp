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

void PrintInvertedNumberPattern(int Number)
{
    for (int i = Number; i >= 1; i--)
    {
        for (int j = i; j >= 1; j--)
        {
            cout << i;
        }

        cout << "\n";
    }
}


int main()
{
    int Number = ReadPositiveNumber("Please enter a positive number: ");

    PrintInvertedNumberPattern(Number);


    return 0;
}