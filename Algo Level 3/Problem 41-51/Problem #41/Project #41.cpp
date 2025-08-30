#include <iostream>
#include <vector>
#include <string>
using namespace std;

string ReadString(string Message)
{
	string S1;
	cout << Message << endl;
	getline(cin, S1);

	return S1;
}

vector <string> SplitString(string S1, string Delim)
{
	vector <string> sWords;
	string Word;
	short pos = 0;

	while ((pos = S1.find(Delim)) != string::npos)
	{
		Word = S1.substr(0, pos);
		S1.erase(0, pos + Delim.length());

		if (Word != "")
		{
			sWords.push_back(Word);
		}
	}

	if (S1 != "")
	{
		sWords.push_back(S1);
	}

	return sWords;
}

string ReverseWordsInString(string S1, string Delim)
{
	string S2 = "";

	vector <string> vWords = SplitString(S1, Delim);
	vector <string>::iterator iter = vWords.end();

	while (iter != vWords.begin())
	{
		iter--;
		S2 += *(iter) + Delim;
	}

	return S2.substr(0, S2.length() - Delim.length());
}

int main()
{
	string S1 = ReadString("Please enter your string: ");

	cout << "\n String after reversing words: \n";
	cout << ReverseWordsInString(S1, " ") << endl;

	

	return 0;
}