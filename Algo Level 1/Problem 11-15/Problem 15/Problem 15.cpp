

#include <iostream>
using namespace std;

void ReadNumbers(float &a, float &b)
{
    cout << "Please Enter the value of a: ", cin >> a;
    cout << "Please Enter the value of b: ", cin >> b;
    cout << "\n";
}

float CalculateRectangleArea(float a, float b)
{
    return a * b;
}

void PrintResult(float Area)
{
    cout << "The Rectangle Area is: " << Area << "\n";
}

int main()
{
    float a, b;

    ReadNumbers(a, b);
    PrintResult(CalculateRectangleArea(a, b));

    return 0;
}

