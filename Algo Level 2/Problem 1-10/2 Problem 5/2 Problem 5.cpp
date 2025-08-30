#include <iostream>
#include <string>
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

void PrintDigits(int Number)  //Number = 1234
{
	int Remainder = 0;

	while (Number > 0)
	{
		Remainder = Number % 10;   //This will EXTRACT the last digit: Number %  10 = 4 
		Number = Number / 10;      //This will remove the last digit: removeing remainder 4 bc it is Integer!


		cout << Remainder << "\n"; //This prints the last digit remainder = 4
	}
}


int main()
{
	PrintDigits(ReadPositiveNumber("Please Enter a positive number: "));


	return 0;
}