#pragma warning(disable : 4996)

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

enum enDateCompare { Before = -1, Equal = 0, After = 1 };

enum enFormatType {DayFirst = 1, MonthFirst = 2, YearFirst = 3, Typing = 4};

struct stDate
{
	short Year = 0;
	short Month = 0;
	short Days = 0;
};

string ReadString(string Message)
{
	string S1;
	cout << Message;
	getline(cin >> ws, S1);

	return S1;
}


short ReadNumber(string Message)
{
	short Number = 0;
	cout << Message;
	cin >> Number;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Please enter a number: ";
		cin >> Number;
	}

	return Number;
}

stDate ReadDate()
{
	stDate Date;

	Date.Year = ReadNumber("Please enter a Year: ");
	Date.Month = ReadNumber("Please enter a Month: ");
	Date.Days = ReadNumber("Please enter a Day: ");

	return Date;
}

vector<string> SplitString(string S1, string Delim = " ")
{
	vector<string> vWords;
	string Word;
	short Pos = 0;

	while ((Pos = S1.find(Delim)) != string::npos)
	{
		Word = S1.substr(0, Pos);

		if (Word != "")
		{
			vWords.push_back(Word);
		}

		S1.erase(0, Pos + Delim.length());
	}

	if (S1 != "")
	{
		vWords.push_back(S1);
	}

	return vWords;
}

stDate StringToDate(string DateString)
{
	stDate Date;
	vector<string> vDate = SplitString(DateString, "/");

	Date.Days = stoi(vDate[0]);
	Date.Month = stoi(vDate[1]);
	Date.Year = stoi(vDate[2]);

	return Date;
}

string DateToString(stDate Date, string Delim = "/")
{
	return to_string(Date.Days) + Delim + to_string(Date.Month) + Delim + to_string(Date.Year);
}

string ReplaceWordInString(string S1, string StringToReplace, string sRepalceTo)
{
	short pos = S1.find(StringToReplace);

	while (pos != std::string::npos)
	{
		S1 = S1.replace(pos, StringToReplace.length(), sRepalceTo);
		pos = S1.find(StringToReplace);
	}

	return S1;
}

string FormatDate(stDate Date, string DateFormat = "dd/mm/yyyy")
{
	string FormattedDateString = "";
	
	FormattedDateString = ReplaceWordInString(DateFormat, "dd", to_string(Date.Days));
	FormattedDateString = ReplaceWordInString(FormattedDateString, "mm", to_string(Date.Month));
	FormattedDateString = ReplaceWordInString(FormattedDateString, "yyyy", to_string(Date.Year));
    
	return FormattedDateString;
}



int main()
{
	string DateString = ReadString("Please Enter Date dd/mm/yyyy: ");
	stDate Date = StringToDate(DateString);
	
	cout << "\n\n" << FormatDate(Date);
	cout << "\n\n" << FormatDate(Date, "yyyy/dd/mm");
	cout << "\n\n" << FormatDate(Date, "mm/dd/yyyy");
	cout << "\n\n" << FormatDate(Date, "mm-dd-yyyy");
	cout << "\n\n" << FormatDate(Date, "dd/mm/yyyy");
	cout << "\n\n" << FormatDate(Date, "Day: dd, Month: mm, Year:yyyy") << endl;



	return 0;
}