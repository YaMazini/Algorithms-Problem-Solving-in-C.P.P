#include <iostream>
#include <vector>
#include <string>
using namespace std;

int ReadNumber(string Message)
{
	int Number = 0;
	cout << Message;
	cin >> Number;
	cout << "\n";

	return Number;
}

string NumberToText(int Number)
{
	if (Number < 0)
	{
		return NumberToText(Number * -1);
	}

	if (Number == 0)
	{
		return "";
	}

	if (Number >= 1 && Number <= 19)
	{
		string Arr[] = { "", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine ", "Ten ",
			"Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen "};
	
		return Arr[Number];
	}

	if (Number >= 20 && Number <= 99)
	{
		string Arr[] = { "", "", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety " };
		
		return Arr[Number / 10] + NumberToText(Number % 10);
	}


	if (Number >= 100 && Number <= 199)
	{
		return "One Hundred " + NumberToText(Number % 100);
	}

	if (Number >= 200 && Number <= 999)
	{
		return NumberToText(Number / 100) + "Hundred " + NumberToText(Number % 100);
	}


	if (Number >= 1000 && Number <= 1999)
	{
		return "One Thousand " + NumberToText(Number % 1000);
	}

	if (Number >= 2000 && Number <= 9999) 
	{
		return NumberToText(Number / 1000) + "Thousand " + NumberToText(Number % 1000);
	}

	
	if (Number >= 10000 && Number <= 99999)
	{
		return NumberToText(Number / 1000) + "Thousand " + NumberToText(Number % 1000);
	}


	if (Number >= 100000 && Number <= 999999)
	{
		return NumberToText(Number / 1000) + "Thousand " + NumberToText(Number % 1000);
	}


	if (Number >= 1000000 && Number <= 999999999)
	{
		return NumberToText(Number / 1000000) + "Million " + NumberToText(Number % 1000000);
	}
	
	
	if (Number == 1000000000)
	{
		return "One Billion ";
	}

	return "\n This Function can t calculate a number above One Billion \n";
}



int main()
{
	int Number = ReadNumber("Please enter a Number From [1] to [1000000000]: ");


	if (Number > 0)
	    cout << " " << NumberToText(Number) << endl;


	else 
		cout << " Minus " << NumberToText(Number) << endl;



	return 0;
}