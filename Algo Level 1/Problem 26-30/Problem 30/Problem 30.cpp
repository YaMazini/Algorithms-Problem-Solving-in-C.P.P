
#include <iostream>
using namespace std;


int ReadPositiveNumber()
{
	int Number ;
	do
	{
		cout << "Please Enter a Positive Number: ", cin >> Number;

	} while (Number < 0);
	cout << "\n";

	return Number;
}

int CalculateFactorialOfNumber(int Number)
{
	int factorial = 1;
	for (int i = 1; i <= Number; i++)
	{
		factorial *= i;
	}

	return factorial;
}


void PrintResult(int Number)
{
	cout << " The Factorial of " << Number << " is: ";
	cout << CalculateFactorialOfNumber(Number) << endl;
}



int main()
{
	
	PrintResult(ReadPositiveNumber());
	

	return 0;
}