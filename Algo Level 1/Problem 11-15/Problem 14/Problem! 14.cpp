

#include <iostream>
using namespace std;


void ReadNumbers(int& Num1, int& Num2)
{
    cout << "Please Enter Number 1: ", cin >> Num1;
    cout << "Please Enter Number 2: ", cin >> Num2;
    cout << "\n";
}

void SwapNumbers(int& Num1, int& Num2)
{
    int Temp;

    Temp = Num2;
    Num2 = Num1;
    Num1 = Temp;
}

void PrintNumbers(int Num1, int Num2)
{
    cout << "Number 1 = " << Num1 << "\n";
    cout << "Number 2 = " << Num2 << "\n\n";
}


int main()
{
    int Num1, Num2;


    ReadNumbers(Num1, Num2);
    PrintNumbers(Num1, Num2);

    SwapNumbers(Num1, Num2);
    PrintNumbers(Num1, Num2);

    return 0;
}

