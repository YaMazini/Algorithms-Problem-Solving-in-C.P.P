

#include <iostream>
using namespace std;

void ReadNumbers(float& a, float& h)
{
    cout << "Please Enter The value of a: ", cin >> a;
    cout << "Please Enter The value of h: ", cin >> h;
    cout << "\n";
}

float CalculateTriangleArea(float a, float h)
{
    return a / 2 * h;
}

void PrintResult(float Area)
{
    cout << "The Area of The Rectangle is: " << Area << "\n";
}


int main()
{
    float a, h;
    
    ReadNumbers(a, h);
    PrintResult(CalculateTriangleArea(a, h));

    return 0;
}

