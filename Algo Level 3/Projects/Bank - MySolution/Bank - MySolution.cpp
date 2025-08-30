#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

const string FileName = "Clients.txt";

enum enMainMenuOption
{
	ClientList_Option = 1,
	AddNewClient_Option = 2,
	DeleteClient_Option = 3,
	UpdateClientInfo_Option = 4,
	FindClient_Option = 5,
	Exit_Option = 6
};

struct stClientData
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;

	bool MarkForDelete = false;
};


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

double ReadDouble(string Message)
{
	double D;
	cout << Message;
	cin >> D;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please Enter a Number: ";
		cin >> D;
	}

	return D;
}

stClientData ReadNewClientRecord(string AccountNumber)
{
	stClientData Client;

	Client.AccountNumber = AccountNumber;
	Client.PinCode = ReadString("\nEnter PinCode: ");
	Client.Name = ReadString("Enter Name: ");
	Client.Phone = ReadString("Enter Phone: ");
	Client.AccountBalance = ReadDouble("Enter Account Balance: ");

	return Client;
}


vector<string> SplitString(string S1, string Delim = " #//# ")
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

void PrintClientCard(stClientData& Client)
{
	cout << "\nThe following are the client details: \n";
	cout << "--------------------------------------- \n";

	cout << "Account Number : " << Client.AccountNumber << endl;
	cout << "Pin Code       : " << Client.PinCode << endl;
	cout << "Name           : " << Client.Name << endl;
	cout << "Phone          : " << Client.Phone << endl;
	cout << "Account Balance: " << Client.AccountBalance << endl;

	cout << "--------------------------------------- \n\n";
}


void PrintClientListTableHeader()
{
	cout << "___________________________________________________________________________________________\n\n";

	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(9) << "Pin Code";
	cout << "| " << left << setw(34) << "Client Name";
	cout << "| " << left << setw(14) << "Phone";
	cout << "| " << left << setw(10) << "Balance" << endl;

	cout << "___________________________________________________________________________________________\n\n";
}

void PrintClientRecordInTable(stClientData& Client)
{
	cout << "| " << left << setw(15) << Client.AccountNumber;
	cout << "| " << left << setw(9) << Client.PinCode;
	cout << "| " << left << setw(34) << Client.Name;
	cout << "| " << left << setw(14) << Client.Phone;
	cout << "| " << left << setw(8) << Client.AccountBalance << endl;
}

void ShowClientListOption(vector<stClientData>& vClients)
{
	system("cls");

	cout << "\n\t\t\t\t Client List (" << vClients.size() << ") Client(s).\n";
	PrintClientListTableHeader();

	for (stClientData& Client : vClients)
	{
		PrintClientRecordInTable(Client);
	}

	cout << "___________________________________________________________________________________________\n\n";
}


void AddNewClientScreen()
{
	cout << "-------------------------------" << endl;
	cout << "    Add New Clients Screen" << endl;
	cout << "-------------------------------" << endl;

	cout << "Adding New Client: \n\n";
}

bool FindClientByAccountNumber(string AccountNumber, vector<stClientData>& vClients, stClientData& Client, bool SaveClientData = false)
{
	for (stClientData& C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			if (SaveClientData)
			{
				Client = C;
			}

			return true;
		}
	}

	return false;
}

void AddDataLineToFile(string FileName, string DataLine)
{
	fstream ClientsFile;
	ClientsFile.open(FileName, ios::out | ios::app);

	if (ClientsFile.is_open())
	{
		ClientsFile << DataLine << endl;

		ClientsFile.close();
	}
}

void AddNewClient(string FileName, vector<stClientData>& vClients)
{
	stClientData Client;

	string AccountNumber = ReadString(" Enter Account Number: ", true);

	while (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		AccountNumber = ReadString("\nClient with [" + AccountNumber + "] already exists, enter another Account Number: ", true);
	}

	Client = ReadNewClientRecord(AccountNumber);

	AddDataLineToFile(FileName, ConvertRecordToDataLine(Client));

	vClients.push_back(Client);
}

void ShowAddNewClientsOption(string FileName, vector<stClientData>& vClients)
{
	char AddMore = 'N';
	do
	{
		system("cls");

		AddNewClientScreen();
		AddNewClient(FileName, vClients);

		AddMore = ReadChar("\nClient Added Successfully, do you want to add more clients? [Y]/[N]? ");

	} while (toupper(AddMore) == 'Y');
}


void DeleteClientScreen()
{
	cout << "------------------------------" << endl;
	cout << "     Delete Client Screen" << endl;
	cout << "------------------------------" << endl;

	cout << "Deleting Client: \n\n";
}

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<stClientData>& vClients)
{
	for (stClientData& Client : vClients)
	{
		if (Client.AccountNumber == AccountNumber)
		{
			Client.MarkForDelete = true;
			return true;
		}
	}

	return false;
}

bool DeleteClient(string FileName, vector<stClientData>& vClients)
{
	stClientData Client;
	string AccountNumber = ReadString("Please enter Account Number: ", true);

	if (FindClientByAccountNumber(AccountNumber, vClients, Client, true))
	{
		PrintClientCard(Client);
		char WantToDelete = ReadChar("\nAre you sure you want to delete this client? [Y]/[N]? ");

		if (toupper(WantToDelete) == 'Y')
		{
			MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
			SaveClientDataInFile(FileName, vClients);
			vClients = LoadDataFromFileToVector(FileName);

			cout << "\n Client Deleted Successfully.";
			return true;
		}
	}

	else
	{
		cout << "\n Client with Account Number [" << AccountNumber << "] Not Found! \n";
	}

	return false;
}

void ShowDeleteClientOption(string FileName, vector<stClientData>& vClients)
{
	system("cls");

	DeleteClientScreen();
	DeleteClient(FileName, vClients);
}


void UpdateClientInfoScreen()
{
	cout << "-------------------------------" << endl;
	cout << "   Update Client Info Screen" << endl;
	cout << "-------------------------------" << endl;

	cout << "Updating Client Info: \n\n";
}

bool UpdateClientInfo(string FileName, vector<stClientData>& vClients)
{
	stClientData NewClient;
	string AccountNumber = ReadString("Please enter Account Number: ", true);

	if (FindClientByAccountNumber(AccountNumber, vClients, NewClient, true))
	{
		PrintClientCard(NewClient);
		char WantToUpdate = ReadChar("\nAre you sure you want to update this client? [Y]/[N]? ");

		if (toupper(WantToUpdate) == 'Y')
		{
			NewClient = ReadNewClientRecord(AccountNumber);

			for (stClientData& OldClient : vClients)
			{
				if (OldClient.AccountNumber == AccountNumber)
				{
					OldClient = NewClient;
					break;
				}
			}

			SaveClientDataInFile(FileName, vClients);

			cout << "\n Client Updated Successfully.";
			return true;
		}
	}

	else
	{
		cout << "\n Client with Account Number [" << AccountNumber << "] Not Found! \n";
	}

	return false;
}

void ShowUpdateClientInfoOption(string FileName, vector<stClientData>& vClients)
{
	system("cls");

	UpdateClientInfoScreen();
	UpdateClientInfo(FileName, vClients);
}


void FindClientScreen()
{
	cout << "----------------------------" << endl;
	cout << "     Find Client Screen" << endl;
	cout << "----------------------------" << endl;

	cout << "Finding Client Info: \n\n";
}

void ShowFindClientOption(vector<stClientData>& vClients)
{
	system("cls");

	FindClientScreen();

	stClientData Client;
	string AccountNumber = ReadString("Please enter Account Number: ", true);

	if (FindClientByAccountNumber(AccountNumber, vClients, Client, true))
	{
		PrintClientCard(Client);
	}

	else
	{
		cout << "\n Client with Account Number [" << AccountNumber << "] Not Found! \n";
	}

}


void ShowExitScreenOption()
{
	system("cls");

	cout << "-------------------------\n";
	cout << "     Program Ends :)\n";
	cout << "-------------------------\n";

	system("pause > 0");
}


void PauseTheProgram()
{
	cout << "\n\n Press any key to go back to Main Menu...";
	system("pause > 0");
}

void OptionHandling(enMainMenuOption Option, string FileName, vector<stClientData>& vClients)
{
	switch (Option)
	{

	case enMainMenuOption::ClientList_Option:
	{
		ShowClientListOption(vClients);
		PauseTheProgram();
		break;
	}

	case enMainMenuOption::AddNewClient_Option:
	{
		ShowAddNewClientsOption(FileName, vClients);
		PauseTheProgram();
		break;
	}

	case enMainMenuOption::DeleteClient_Option:
	{
		ShowDeleteClientOption(FileName, vClients);
		PauseTheProgram();
		break;
	}

	case enMainMenuOption::UpdateClientInfo_Option:
	{
		ShowUpdateClientInfoOption(FileName, vClients);
		PauseTheProgram();
		break;
	}

	case enMainMenuOption::FindClient_Option:
	{
		ShowFindClientOption(vClients);
		PauseTheProgram();
		break;
	}

	case enMainMenuOption::Exit_Option:
	{
		ShowExitScreenOption();
		break;
	}

	default:
	{
		cout << "\nInvalid Input!\n";
		PauseTheProgram();
		break;
	}

	}

}

void ShowMainMenuScreen()
{
	system("cls");

	cout << "\n=========================================\n";
	cout << "            Main Menu Screen\n";
	cout << "=========================================\n";

	cout << "\t [1] Show Client List." << endl;
	cout << "\t [2] Add New Client." << endl;
	cout << "\t [3] Delete Client." << endl;
	cout << "\t [4] Update Client Info." << endl;
	cout << "\t [5] Find Client." << endl;
	cout << "\t [6] Exit." << endl;

	cout << "=========================================\n";
}


void Bank(string FileName)
{
	vector<stClientData> vClients = LoadDataFromFileToVector(FileName);

	short Option = 0;

	do
	{
		ShowMainMenuScreen();

		Option = ReadNumberInRange("\nChoose what do you want to do: [1 to 6]: ", 1, 6);

		OptionHandling((enMainMenuOption)Option, FileName, vClients);

	} while (Option != 6);

}



int main()
{
	Bank(FileName);



	return 0;
}