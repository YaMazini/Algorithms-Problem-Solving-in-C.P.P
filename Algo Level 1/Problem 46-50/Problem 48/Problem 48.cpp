#include <iostream>
#include <cmath>
using namespace std;


float ReadPositiveNumber(string Message)
{
	float Number;
	do
	{
		cout << Message, cin >> Number;

	} while (Number <= 0);

	return Number;
}

float MonthlyIstallement(float LoanAmount, float MonthsNeeded)
{
	return LoanAmount / MonthsNeeded;
}



int main()
{
	float LoanAmount = ReadPositiveNumber("Please Enter the loan amount: ");
	float MonthsNeeded = ReadPositiveNumber("Please Enter how many months you need to pay it: ");

	cout << "\n You need to pay " << MonthlyIstallement(LoanAmount, MonthsNeeded)
		<< " monthly\n";

	return 0;
}