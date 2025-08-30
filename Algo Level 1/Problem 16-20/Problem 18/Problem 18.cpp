

#include <iostream>
using namespace std;

void ReadNumbers(float& r)
{
    cout << "Please Enter The value of r: ", cin >> r;
    cout << "\n";
}

float CalculateCircleArea(float r)
{
    const float PI = 3.14;
    return PI * pow(r, 2);
}

void PrintResult(float Area)
{
    cout << "The Circle Area is: " << Area << "\n";
}


int main()
{
    float r;

    ReadNumbers(r);
    PrintResult(CalculateCircleArea(r));

    return 0;
}