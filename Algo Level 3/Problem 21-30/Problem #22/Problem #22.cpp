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

void PrintFibonacciSeries(int Prev1, int Prev2, const short FibonacciLength)
{
    int FibNumber = 0;
    if (FibonacciLength > 1)
    {
        FibNumber = Prev1 + Prev2;
        cout << FibNumber << "   ";

        Prev2 = Prev1;
        Prev1 = FibNumber;
        PrintFibonacciSeries(Prev1, Prev2, FibonacciLength - 1);
    }

    else
    {
        cout << endl;
        return;
    }
}

int main()
{
    short FibonacciLength = ReadPositiveNumber("Please enter Fibonacci Length: ");

    cout << "1   ";
    PrintFibonacciSeries(1, 0, FibonacciLength);
    
    return 0;
}
