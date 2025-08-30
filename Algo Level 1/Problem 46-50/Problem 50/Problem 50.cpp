#include <iostream> 
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

int ReadPINCode()
{
	return ReadPositiveNumber("Please Enter the PIN Code: ");
}

bool IsCorrectPIN(int UserPIN, int PINCode)
{
		return UserPIN == PINCode;
}

void ProcessPIN(int UserPIN, int PINCode)
{
	int tries = 3;

	if (IsCorrectPIN(UserPIN, PINCode) == false)
		do
		{
			tries--;
			cout << "\n Wrong PIN! You have " << tries << " more tries\n";
			UserPIN = ReadPINCode();
			
			if (UserPIN != PINCode && tries == 1)
			{
				cout << "\n\t Card is locked!\n";
				return;
			}

		} while (UserPIN != PINCode && tries > 1);

	cout << "\n Your balance is: $7500\n";
}



int main()
{
	int PINCode = 1234;
	int UserPIN = ReadPINCode();

	ProcessPIN(UserPIN, PINCode);

	return 0;
}