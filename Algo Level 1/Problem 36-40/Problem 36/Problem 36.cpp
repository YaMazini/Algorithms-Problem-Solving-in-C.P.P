
#include <iostream>
using namespace std;

enum enOperationType { Add = '+', Subtract = '-', Multiply = '*', Divide = '/' };


float ReadNumber(string Message)
{
	float Number = 0;
	cout << Message , cin >> Number;

	return Number;
}

enOperationType ReadOperationType()
{
	char OperationType = '+';
	cout << "Please Enter the operation type ( +, -, *, / ): ", cin >> OperationType;
	
	return (enOperationType) OperationType;
}

float Calculation(float Number1, float Number2, enOperationType OperationType)
{

	switch (OperationType)
	{

	case enOperationType::Add:
		return Number1 + Number2;
	
	case enOperationType::Subtract:
		return Number1 - Number2;

	case enOperationType::Multiply:
		return Number1 * Number2;

	case enOperationType::Divide:
		return Number1 / Number2;
	
	default:
		return Number1 + Number2;

	}

}




int main()
{
	float Number1 = ReadNumber("Please Enter the first Number: ");
	float Number2 = ReadNumber("Please Enter the second Number: ");
	enOperationType OperationType = ReadOperationType();

	cout << "\n Result = " << Calculation(Number1, Number2, OperationType);
	cout << "\n";

	return 0;
}