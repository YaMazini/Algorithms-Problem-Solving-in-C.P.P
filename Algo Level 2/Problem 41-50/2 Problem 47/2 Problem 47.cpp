#include <iostream>
#include <cmath>
using namespace std;

float ReadNumber()
{
    float Number = 0;
    cout << "Please enter a number: ";
    cin >> Number;

    return Number;
}

float FractionPart(float Number)
{
    return Number - (int)Number;
}

int MyRound(float Number)
{
    float FracPart = FractionPart(Number);
    int IntPart = (int)Number;

    if (abs(FracPart) >= 0.5)
    {
        if (Number > 0)
            return IntPart + 1;

        else
            return IntPart - 1;
    }

    else
        return IntPart;
}

int main()
{
    float Number = ReadNumber();

    cout << "\n My Round is: " << MyRound(Number);
    cout << "\n C++ Round is: " << round(Number) << "\n";


    return 0;
}