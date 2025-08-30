#include <iostream>
#include <string>
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

void PrintLetterPattern(int Number)
{
    for (int i = 1; i <= Number; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << char(64 + i);
        }

        cout << "\n";
    }
}


int main()
{
    int Number = ReadPositiveNumber("Please enter a positive number: ");

    PrintLetterPattern(Number);


    return 0;
}