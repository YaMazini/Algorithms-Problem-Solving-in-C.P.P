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

int MyCeil(float Number)
{
    int IntPart = int(Number);

    if (Number > 0 && Number != IntPart)
        return IntPart + 1;

    else
        return IntPart;
}



int main()
{
    float Number = ReadNumber();

    cout << "\n My Ceil is: " << MyCeil(Number);
    cout << "\n C++ Ceil is: " << ceil(Number) << "\n";


    return 0;
}