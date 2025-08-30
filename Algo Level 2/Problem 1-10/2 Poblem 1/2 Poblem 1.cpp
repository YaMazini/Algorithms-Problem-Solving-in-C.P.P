#include <iostream>
using namespace std;


void PrintTableHeader()
{
	cout << "\n\t\t\tMultiplication Table From 1 to 10\n\n\t";
	for (int i = 1; i <= 10; i++)
	{
		cout << i << "\t";
	}

	cout << "\n____________________________________________________________________________________\n";
}

string ColumnSeparetor(int i)
{
	if (i < 10)
		return "   |";

	else
		return "  |";
}

void PrintMultiplicationTable()
{
	PrintTableHeader();

	for (int i = 1; i <= 10; i++)
	{
		cout << i << ColumnSeparetor(i) << "\t";

		for (int j = 1; j <= 10; j++)
		{
			cout << i * j << "\t";
		}

		cout << "\n";
	}
}



int main()
{
	PrintMultiplicationTable();

	return 0;
}                               //Code cannt run here test in another file