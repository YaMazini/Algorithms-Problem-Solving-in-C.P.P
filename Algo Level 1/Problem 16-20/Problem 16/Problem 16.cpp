

#include <iostream>
#include <cmath>
using namespace std;


void ReadNumbers(float& a, float& d)
{
	cout << "Please Enter The value of a: ", cin >> a;
	cout << "Please Enter The value of d: ", cin >> d;
	cout << "\n\n";
}

float CalculateRectangleAreaBySideAndDiagonal(float a, float d)
{
	return a * sqrt(pow(d, 2) - pow(a, 2));
}

void PrintResult(float Area)
{
	cout << "The Rectangle Area is: " << Area << "\n\n";
}



int main()
{
	float a, d;

	ReadNumbers(a, d);
	PrintResult(CalculateRectangleAreaBySideAndDiagonal(a, d));

	return 0;
}

