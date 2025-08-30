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

int MonthsNeeded(float LoanAmount, float MonthlyPayment)
{
	return ceil(LoanAmount / MonthlyPayment);
}



int main()
{
	float LoanAmount = ReadPositiveNumber("Please Enter the Loan Amount: ");
	float MonthlyPayment = ReadPositiveNumber("Please Enter the Monthly Payment: ");

	cout << "\n You will need " << MonthsNeeded(LoanAmount, MonthlyPayment) << " Months to pay all the Amount\n";


	return 0;
}