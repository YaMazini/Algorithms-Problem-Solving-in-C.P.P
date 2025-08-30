#include <iostream>
#include <iomanip>
using namespace std;

int ReadPositiveNumber(string Message)
{
    int Number = 0;
    cout << Message;
    cin >> Number;

    while (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Wrong Inputs! Please enter a number: ";
        cin >> Number;
    }
    cout << "\n";

    return Number;
}

void PrintFibonacciSeries(const short& FibonacciLength)
{
    int FibonacciNumber = 0;

    cout << "1   ";
    int Prev2 = 0, Prev1 = 1;

    for (int i = 2; i <= FibonacciLength; i++)
    {
        FibonacciNumber = Prev2 + Prev1;
        cout << FibonacciNumber << "   ";

        Prev2 = Prev1;
        Prev1 = FibonacciNumber;
    }

    cout << "\n";
}


int main()
{
    short FibonacciLength = ReadPositiveNumber("Please enter Fibonacci Length: ");

    PrintFibonacciSeries(FibonacciLength);

    return 0;
}
