#include <iostream>
#include <vector>
#include <string>
using namespace std;

string ReadString(string Message)
{
	string S1;
	cout << Message;
	getline(cin, S1);

	return S1;
}

string ReplaceWordInString(string S1, string WordToReplace, string ReplacedWord)
{
	short pos = S1.find(WordToReplace);

	while (pos != string::npos)
	{
		S1.replace(pos, WordToReplace.length(), ReplacedWord);
		pos = S1.find(WordToReplace);
	}
	
	return S1;
}


int main()
{
	string S1 = ReadString("Please enter a string: \n");
	string WordToReplace = ReadString("Enter a word in your string to replace: ");
	string ReplacedWord = ReadString("Enter a the replaced Word: ");

	cout << "\n Original String: \n";
	cout << S1 << endl;

	cout << "\n String After Replace: \n";
	cout << ReplaceWordInString(S1, WordToReplace, ReplacedWord) << endl;

    return 0;
}