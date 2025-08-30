#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

const string FileNameClients = "Clients.txt";

enum enATMMainMenueOptions
{
	QuickWithdraw_Option = 1,
	NormalWithdraw_Option = 2,
	Deposit_Option = 3,
	CheckBalance_Option = 4,
	Logout_Option = 5,
};

struct stClientData
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance = 0;

	bool MarkForDelete = false;
};

stClientData* CurrentClient = nullptr;

void GoBackToATMMainMenuScreen(vector<stClientData>& vClients);
void ATMMainMenue(vector<stClientData>& vClients);
void Login();


string ReadString(string Message, bool SkipNewLine = false)
{
	string S;
	cout << Message;
	if (SkipNewLine == false)
	{
		getline(cin, S);
		return S;
	}

	getline(cin >> ws, S);
	return S;
}

short ReadNumberInRange(string Message, short From = 1, short To = 1000)
{
	short Number;
	cout << Message;
	cin >> Number;

	while (cin.fail() || Number > To || Number < From)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter a Number From " << From << " To " << To << ": ";
		cin >> Number;
	}

	return Number;
}

int ReadNumber(string Message)
{
	short Number;
	cout << Message;
	cin >> Number;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter a Number: ";
		cin >> Number;
	}

	return Number;
}

char ReadChar(string Message)
{
	char C;
	cout << Message;
	cin >> C;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please Enter a char: ";
		cin >> C;
	}

	cin.ignore();

	return C;
}

short ReadQuickWithdrawChoice()
{
	short Option = 0;
	Option = ReadNumberInRange("\nChoose what to withdraw from [1] to [9]: ", 1, 9);
	return Option;
}

short ReadNormalWithdrawAmount()
{
	short WithdrawAmount = 0;

	do
	{
		WithdrawAmount = ReadNumber("\nEnter an amount multiple of  5`s: ");
	} while (WithdrawAmount % 5 != 0);

	return WithdrawAmount;
}

short ReadATMMainMenueOption()
{
	short Option = 0;
	Option = ReadNumberInRange("\nChoose what do you want to do [1] to [5]: ", 1, 5);
	return Option;
}


vector<string> SplitString(string S1, string Delim = " #//# ")
{
	vector<string> vWords;
	string Word;
	size_t Pos = 0;

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

stClientData ConvertDataLineToRecord(string DataLine)
{
	stClientData Client;
	vector <string> vClient = SplitString(DataLine);

	if (vClient.size() < 5) {

		cerr << "Error: Invalid data format in line: " << DataLine << endl;

		return Client;
	}

	Client.AccountNumber = vClient[0];
	Client.PinCode = vClient[1];
	Client.Name = vClient[2];
	Client.Phone = vClient[3];
	Client.AccountBalance = stod(vClient[4]);

	return Client;
}

string ConvertRecordToDataLine(stClientData& Client, string Delim = " #//# ")
{
	string DataLine;

	DataLine += Client.AccountNumber + Delim;
	DataLine += Client.PinCode + Delim;
	DataLine += Client.Name + Delim;
	DataLine += Client.Phone + Delim;
	DataLine += to_string(Client.AccountBalance);

	return DataLine;
}

vector <stClientData> LoadDataFromFileToVector(string FileName)
{
	vector <stClientData> vClients;

	fstream ClientsFile;
	ClientsFile.open(FileName, ios::in);

	if (ClientsFile.is_open())
	{
		stClientData Client;
		string Line;
		while (getline(ClientsFile, Line))
		{
			Client = ConvertDataLineToRecord(Line);
			vClients.push_back(Client);
		}

		ClientsFile.close();
	}

	return vClients;
}

void SaveClientDataInFile(string FileName, vector<stClientData>& vClients)
{
	fstream ClientsFile;
	ClientsFile.open(FileName, ios::out);

	if (ClientsFile.is_open())
	{
		string DataLine;
		for (stClientData& Client : vClients)
		{
			if (Client.MarkForDelete == false)
			{
				ClientsFile << ConvertRecordToDataLine(Client) << endl;
			}
		}

		ClientsFile.close();
	}

}


short GetQuickWithdrawAmount(short Choice)
{
	short Arr[] = { 0, 20, 50, 100, 200, 400, 600, 800, 1000 };
	return Arr[Choice];
}

void ShowQuickWithdrawScreen()
{
	cout << "==================================\n";
	cout << "          Quick Withdraw\n";
	cout << "==================================\n";

	cout << "\t[1]20   " << "  [2]50" << endl;
	cout << "\t[3]100  " << "  [4]200" << endl;
	cout << "\t[5]400  " << "  [6]600" << endl;
	cout << "\t[7]800  " << "  [8]1000" << endl;
	cout << "\t[9]Exit" << endl;

	cout << "==================================\n";
}

void QuickWithdrawOption(vector<stClientData>& vClients)
{
	short WithdrawChoice = 0;
	int WithdrawAmount = 0;
	char PerformTransaction = 'Y';

	do
	{
		system("cls");

		ShowQuickWithdrawScreen();
		cout << "Your Balance is " << CurrentClient->AccountBalance << endl;

		WithdrawChoice = ReadQuickWithdrawChoice();

		if (WithdrawChoice == 9)
		{
			GoBackToATMMainMenuScreen(vClients);
			return;
		}

		WithdrawAmount = GetQuickWithdrawAmount(WithdrawChoice);
		PerformTransaction = ReadChar("\nAre you sure you want perform this transaction? y/n? ");

		if (CurrentClient->AccountBalance >= WithdrawAmount)
		{
			if (toupper(PerformTransaction) == 'Y')
			{
				CurrentClient->AccountBalance -= WithdrawAmount;
				cout << "\nDone Successfully. Now balance is: " << CurrentClient->AccountBalance << endl;
			}

			return;
		}

		cout << "\nThe Amount exceeds your balance, make another choice.\n";
		cout << "Press AnyKey to continue...";
		system("pause<0");

	} while (CurrentClient->AccountBalance < WithdrawAmount);

}


void ShowNormalWithdrawScreen()
{
	cout << "===================================\n";
	cout << "          Normal Withdraw\n";
	cout << "===================================\n";
}

void NormalWithdrawOption()
{
	int WithdrawAmount = 0;
	char PerformTransaction = 'Y';

	do
	{
		system("cls");

		ShowNormalWithdrawScreen();

		WithdrawAmount = ReadNormalWithdrawAmount();
		PerformTransaction = ReadChar("\nAre you sure you want perform this transaction? y/n? ");

		if (CurrentClient->AccountBalance >= WithdrawAmount)
		{
			if (toupper(PerformTransaction) == 'Y')
			{
				CurrentClient->AccountBalance -= WithdrawAmount;
				cout << "\nDone Successfully. Now balance is: " << CurrentClient->AccountBalance << endl;
			}

			return;
		}

		cout << "\nThe Amount exceeds your balance, make another choice.\n";
		cout << "Press AnyKey to continue...";
		system("pause<0");

	} while (CurrentClient->AccountBalance < WithdrawAmount);

}


void ShowDepositScreen()
{
	cout << "==================================\n";
	cout << "          Deposit Screen\n";
	cout << "==================================\n";
}

void DepositOption()
{
	system("cls");

	ShowDepositScreen();

	int DepositAmount = ReadNumber("Enter a positive Deposit Amount: ");
	char PerformTransaction = ReadChar("Are you sure you want perform this transaction? y/n? ");

	if (toupper(PerformTransaction) == 'Y')
	{
		CurrentClient->AccountBalance += DepositAmount;
		cout << "\nDone Successfully. Now balance is: " << CurrentClient->AccountBalance << endl;
	}
}


void CheckBalanceOption()
{
	system("cls");

	cout << "==================================\n";
	cout << "          Balance Screen\n";
	cout << "==================================\n";

	cout << "Your Balance is " << CurrentClient->AccountBalance << endl;
}



void GoBackToATMMainMenuScreen(vector<stClientData>& vClients)
{
	cout << "\n\n Press any key to go back to Main Menu...";
	system("pause > 0");
	ATMMainMenue(vClients);
}

void ATMMainMenueScreen()
{
	cout << "=========================================\n";
	cout << "          ATM Main Menue Screen\n";
	cout << "=========================================\n";

	cout << "\t [1]Quick Withdraw." << endl;
	cout << "\t [2]Normal Withdraw." << endl;
	cout << "\t [3]Deposit." << endl;
	cout << "\t [4]Check Balance." << endl;
	cout << "\t [5]Logout." << endl;

	cout << "=========================================\n";
}

void ATMMainMenueOptionHandler(enATMMainMenueOptions Option, vector<stClientData>& vClients)
{
	switch (Option)
	{
	case enATMMainMenueOptions::QuickWithdraw_Option:
		QuickWithdrawOption(vClients);
		SaveClientDataInFile(FileNameClients, vClients);
		GoBackToATMMainMenuScreen(vClients);
		break;

	case enATMMainMenueOptions::NormalWithdraw_Option:
		NormalWithdrawOption();
		SaveClientDataInFile(FileNameClients, vClients);
		GoBackToATMMainMenuScreen(vClients);
		break;

	case enATMMainMenueOptions::Deposit_Option:
		DepositOption();
		SaveClientDataInFile(FileNameClients, vClients);
		GoBackToATMMainMenuScreen(vClients);
		break;

	case enATMMainMenueOptions::CheckBalance_Option:
		CheckBalanceOption();
		SaveClientDataInFile(FileNameClients, vClients);
		GoBackToATMMainMenuScreen(vClients);
		break;

	case enATMMainMenueOptions::Logout_Option:
		SaveClientDataInFile(FileNameClients, vClients);
		Login();
		break;

	default:
	{
		SaveClientDataInFile(FileNameClients, vClients);
		GoBackToATMMainMenuScreen(vClients);
		break;
	}

	}

}

void ATMMainMenue(vector<stClientData>& vClients)
{
	system("cls");

	ATMMainMenueScreen();
	ATMMainMenueOptionHandler((enATMMainMenueOptions)ReadATMMainMenueOption(), vClients);
}



bool FindClientByAccNumAndPinCode(string AccountNumber, string PinCode, vector<stClientData>& vClients, stClientData*& Client)
{
	for (stClientData& C : vClients)
	{
		if (C.AccountNumber == AccountNumber && C.PinCode == PinCode)
		{
			Client = &C;
			return true;
		}
	}
	return false;
}

void ShowLoginScreen()
{
	cout << "----------------------------" << endl;
	cout << "        Login Screen" << endl;
	cout << "----------------------------" << endl;
}

void Login()
{
	vector <stClientData> vClients = LoadDataFromFileToVector(FileNameClients);
	string AccountNumber, PinCode;
	bool FailedToLogin = false;

	do
	{
		system("cls");
		ShowLoginScreen();

		if (FailedToLogin)
		{
			cout << "Invalid Account Number/PinCode! \n";
		}

		AccountNumber = ReadString("Enter Account Number: ", true);
		PinCode = ReadString("Enter PinCode: ");

		FailedToLogin = true;

	} while (!FindClientByAccNumAndPinCode(AccountNumber, PinCode, vClients, CurrentClient));

	ATMMainMenue(vClients);
}



int main()
{
	Login();


	return 0;
}