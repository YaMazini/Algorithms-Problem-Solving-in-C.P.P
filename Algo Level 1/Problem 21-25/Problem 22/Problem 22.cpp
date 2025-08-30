

#include <iostream>
#include <cmath>
using namespace std;

void ReadTriangleData(float& a, float& b)
{
	cout << "Please Enter The value of a: ", cin >> a;
	cout << "Please Enter The value of b: ", cin >> b;
	cout << "\n";
}

float CalculateCircleAreaByTriangle(float a, float b)
{
	const float PI = 3.14;
	float Area = PI * (pow(b, 2) / 4) * ((2 * a - b) / (2 * a + b));
	return Area;
}

void PrintResult(float Area)
{
	cout << " The Circle Area is: " << Area << "\n";
}


int main()
{
	float a, b;

	ReadTriangleData(a, b);
	PrintResult(CalculateCircleAreaByTriangle(a, b));

	return 0;
}