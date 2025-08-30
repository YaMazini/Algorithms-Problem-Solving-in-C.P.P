
#include <iostream>
using namespace std;

float ReadNumber()
{
	float Number;
	cout << "Please Enter a Number: ", cin >> Number;
	return Number;
}

float GetHalfNumber(float Number)
{
	float Half;
	return Half = Number / 2;
}

void PrintNumber(float Half, float Number)
{
	cout << "Half of " << Number << " is: " << Half << "\n";
}


int main()
{
	float Number = ReadNumber();
	PrintNumber(GetHalfNumber(Number), Number);

	return 0;
}
