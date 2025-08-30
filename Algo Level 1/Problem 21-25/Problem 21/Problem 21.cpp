
#include <iostream>
#include <cmath>
using namespace std;


float ReadNumber()
{
    float L;
    cout << "Please Enter the value of L: ", cin >> L;
    return L;
}

float CalculateCircleArea(float L)
{
    const float PI = 3.14;
    float Area = (PI * pow(L, 2)) / 4;
    return Area;
}

void PrintResult(float Area)
{
    cout << "The circle Area is: " << Area << "\n";
}


int main()
{
    PrintResult(CalculateCircleArea(ReadNumber()));
    
    return 0;
}