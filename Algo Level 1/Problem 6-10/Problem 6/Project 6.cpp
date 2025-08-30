
#include <iostream>

using namespace std;


struct stInfo 
{
	string FirstName;
	string LastName;
};

stInfo ReadInfo()
{
	stInfo Info;

	cout << "Please Enter Your First Name: ", cin >> Info.FirstName;
	cout << "Please Enter Your Last Name: ", cin >> Info.LastName;
	cout << "\n";

	return Info;
}

string GetFullName(stInfo Info, bool Reversed)
{
	string FullName;

	if (Reversed == true)
	{
		FullName = Info.LastName + " " + Info.FirstName;
	}
	else 
	{
		FullName = Info.FirstName + " " + Info.LastName;
	}

	return FullName;
}

void PrintFullName(string FullName)
{
	cout << "Your Full Name is: " << FullName << "\n";
}

int main()
{
	PrintFullName(GetFullName(ReadInfo(), false));

	return 0;
}