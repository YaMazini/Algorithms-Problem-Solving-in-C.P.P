#include <iostream>
#include <string>
#include <vector>
using namespace std;

string JoinString(vector<string> &vString, string Delim)
{
	string S1 = "";

	for (string& S : vString)
	{
		S1 += S + Delim;
	}

	return S1.substr(0, S1.length() - Delim.length());
}



int main()
{
	vector<string> vString = { "Omar", "Youssef", "Yahya", "Mariem" };

	cout << " Vector before join: \n";
	for (string& S : vString)
	{
		cout << S << endl;
	}

	cout << "\n Vector after join: \n" << JoinString(vString, ", ") << endl;

	return 0;
}