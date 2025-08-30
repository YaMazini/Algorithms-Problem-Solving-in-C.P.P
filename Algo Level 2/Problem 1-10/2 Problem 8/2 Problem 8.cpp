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

int FrequencyOfDigitInNumber(int Number, short int DigitToCheck)
{
    int Remainder = 0;
    int Frequency = 0;

    while (Number > 0)
    {
        Remainder = Number % 10;
        Number = Number / 10;

        if (DigitToCheck == Remainder)
            Frequency++;
    }

    return Frequency;
}

void PrintResult(int Number, short int DigitToCheck)
{
    cout << "\n Digit [" << DigitToCheck << "] Frequency is "
        << FrequencyOfDigitInNumber(Number, DigitToCheck) << " Time(s)"
        << "\n";
}


int main()
{
    int Number = ReadPositiveNumber("Please enter a positive number: ");
    short int DigitToCheck = ReadPositiveNumber("Please enter a digit to ckeck: ");
 
    PrintResult(Number, DigitToCheck);


    return 0;
}