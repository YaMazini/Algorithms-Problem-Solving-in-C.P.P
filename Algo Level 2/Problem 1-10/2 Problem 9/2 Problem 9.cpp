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


void PrintAllDigitFrequency(int Number)
{
    for (int i = 0; i < 10; i++)                                         // Digits range from 0 to 9
    {
         short int DigitFrequency = FrequencyOfDigitInNumber(Number, i); // Check frequency of each digit in the number

        if (DigitFrequency > 0)                                          // Only print digits that appear at least once 
        {
            cout << "\n Digit [" << i << "] Frequency is "
                 << DigitFrequency << " Time(s)"
                 << "\n";
        }
    }
}



int main()
{
    int Number = ReadPositiveNumber("Please enter a positive number: ");

    PrintAllDigitFrequency(Number);


    return 0;
}