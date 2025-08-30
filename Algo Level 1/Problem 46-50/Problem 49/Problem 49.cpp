#include <iostream>
#include <cmath>
using namespace std;


int ReadPositiveNumber(string Message)
{
	int Number;
	do
	{
		cout << Message, cin >> Number;
	
	} while (Number <= 0);

	return Number;
}

bool IsValidPINCode(int PINCode, int UserPIN)
{
	if (PINCode == UserPIN)
		return true;

	else
		return false;
}


void PrintResult(bool IsValidPINCode)
{
	if (IsValidPINCode == true)
		cout << "\n Your Balance is: $7500\n";

	else
		cout << "\n WrongPIN!\n";
}



int main()
{
	int PINCode = 1234;
	int UserPIN = ReadPositiveNumber("Please Enter the PIN Code: ");

	PrintResult(IsValidPINCode(PINCode, UserPIN));


	return 0;
}