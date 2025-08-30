

#include <iostream>
#include <cmath>
using namespace std;

void ReadTriangleData(float& a, float& b, float& c)
{
    cout << "Please Enter The value of a: ", cin >> a;
    cout << "Please Enter The value of b: ", cin >> b;
    cout << "Please Enter The value of c: ", cin >> c;

    cout << "\n";
}

float CalculateCircleAreaByTriangle(float a, float b, float c)
{
    const float PI = 3.141592653589793238;
    float p = (a + b + c) / 2;
    float t = (a * b * c) / (4 * sqrt(p * (p - a) * (p - b) * (p - c)));

    float area = PI * pow(t, 2);

    return area;
}

void PrintResult(float Area)
{
    cout << " The Circle Area is: " << Area << "\n";
}


int main()
{
    float a, b, c;

    ReadTriangleData(a, b, c);

    PrintResult(CalculateCircleAreaByTriangle(a, b, c));

    return 0;
}

