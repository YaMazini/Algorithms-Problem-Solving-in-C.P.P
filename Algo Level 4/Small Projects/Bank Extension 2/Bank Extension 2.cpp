#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

const string FileNameClients = "Clients.txt";
const string FileNameUsers = "Users.txt";

void MainMenu();
void TransactionsMenu();
void GoBackToMainMenuScreen();

void ManageUserMenuOption();
void ShowAccessDeniedMessage();
void Login();


enum enMainMenuOption
{
	ClientList_Option = 1,
	AddNewClient_Option = 2,
	DeleteClient_Option = 3,
	UpdateClientInfo_Option = 4,
	FindClient_Option = 5,
	Transactions_Option = 6,
	ManageUsers_Option = 7,
	Logout_Option = 8,
};

enum enTransactionsMenuOption
{
	Deposit_Option = 1,
	Withdraw_Option = 2,
	TotalBalances_Option = 3,
	MainMenu_Optionnnn = 4
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


enum enUserMenuOption
{
	UserList_Option = 1,
	AddNewUser_Option = 2,
	DeleteUser_Option = 3,
	UpdateUserInfo_Option = 4,
	FindUser_Option = 5,
	O_MainMenu_Option = 6,
};

enum enMainMenuePermissions
{
	eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
	pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64
};

bool CheckAccessPermission(enMainMenuePermissions Permission);

struct stUserData
{
	string UserName;
	string Password;
	short Permissions = 0;
	bool MarkForDelete = 0;
};

stUserData CurrentUser;


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

short ReadMainMenuOption()
{
	short Option = 0;
	Option = ReadNumberInRange("\nChoose what do you want to do: [1 to 8]: ", 1, 8);
	return Option;
}

short ReadTransactionsMenuOption()
{
	short Option = 0;
	Option = ReadNumberInRange("\nChoose what do you want to do: [1 to 4]: ", 1, 4);
	return Option;
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

short ReadUserMenuOption()
{
	short Option = 0;
	Option = ReadNumberInRange("\nChoose what do you want to do: [1 to 6]: ", 1, 6);
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

	if (!CheckAccessPermission(enMainMenuePermissions::pListClients))
	{
		ShowAccessDeniedMessage();
		return;
	}

	if (vClients.size() > 0)
	{
		cout << "\n\t\t\t\t Client List (" << vClients.size() << ") Client(s).\n";
		PrintClientListTableHeader();

		for (stClientData& Client : vClients)
		{
			PrintClientRecordInTable(Client);
		}

		cout << "___________________________________________________________________________________________\n\n";
	}

	else
	{
		cout << "\n No Client is Available in the System! \n";
		cout << "You Can Add Clients By Entering [2] Add New Client.";
	}
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
	fstream File;
	File.open(FileName, ios::out | ios::app);

	if (File.is_open())
	{
		File << DataLine << endl;

		File.close();
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
	system("cls");

	if (!CheckAccessPermission(enMainMenuePermissions::pAddNewClient))
	{
		ShowAccessDeniedMessage();
		return;
	}

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

	if (!CheckAccessPermission(enMainMenuePermissions::pDeleteClient))
	{
		ShowAccessDeniedMessage();
		return;
	}

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

	if (!CheckAccessPermission(enMainMenuePermissions::pUpdateClients))
	{
		ShowAccessDeniedMessage();
		return;
	}

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

	if (!CheckAccessPermission(enMainMenuePermissions::pFindClient))
	{
		ShowAccessDeniedMessage();
		return;
	}

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


void DepositScreen()
{
	cout << "------------------------" << endl;
	cout << "     Deposit Screen" << endl;
	cout << "------------------------" << endl;

	cout << "Deposit: \n\n";
}

bool PerformTransactionOperation(string AccountNumber, double EnteredAmount, string FileName, vector<stClientData>& vClients)
{
	char WantTransaction = ReadChar("\n\nAre you sure you want to perform this transaction? [Y]/[N]? ");

	if (toupper(WantTransaction) == 'Y')
	{
		for (stClientData& Client : vClients)
		{
			if (Client.AccountNumber == AccountNumber)
			{
				Client.AccountBalance += EnteredAmount;
				SaveClientDataInFile(FileName, vClients);

				cout << "\n Done Successfully. New Balance: " << Client.AccountBalance << endl;

				return true;
			}
		}
	}

	return false;
}

void DepositClientBalance(string FileName, vector<stClientData>& vClients)
{
	stClientData Client;
	string AccountNumber = ReadString("Please enter Account Number: ", true);

	while (!FindClientByAccountNumber(AccountNumber, vClients, Client, true))
	{
		cout << "\nClient with [" << AccountNumber << "] does not exist. \n\n";
		AccountNumber = ReadString("Please enter Account Number: ", true);
	}

	PrintClientCard(Client);
	double DepositAmount = ReadDouble("Please enter deposit amount: ");

	PerformTransactionOperation(AccountNumber, DepositAmount, FileName, vClients);
}

void ShowDepositOption(string FileName, vector<stClientData>& vClients)
{
	system("cls");

	DepositScreen();
	DepositClientBalance(FileName, vClients);
}


void WithdrawScreen()
{
	cout << "-------------------------" << endl;
	cout << "     Withdraw Screen" << endl;
	cout << "-------------------------" << endl;

	cout << "Withdraw: \n\n";
}

double ReadWithdrawAmount(double AccountBalance)
{
	double WithdrawAmount = ReadDouble("Please enter Withdraw amount: ");

	while (WithdrawAmount > AccountBalance)
	{
		cout << "\nAmount Exceeds the balance, you can withdraw up to: " << AccountBalance << endl;
		WithdrawAmount = ReadDouble("Please enter Withdraw amount: ");
	}

	return WithdrawAmount;
}

void WithdrawClientBalance(string FileName, vector<stClientData>& vClients)
{
	stClientData Client;
	string AccountNumber = ReadString("Please enter Account Number: ", true);

	while (!FindClientByAccountNumber(AccountNumber, vClients, Client, true))
	{
		cout << "\nClient with [" << AccountNumber << "] does not exist. \n\n";
		AccountNumber = ReadString("Please enter Account Number: ", true);
	}

	PrintClientCard(Client);
	double WithdrawAmount = ReadWithdrawAmount(Client.AccountBalance);

	PerformTransactionOperation(AccountNumber, (WithdrawAmount * -1), FileName, vClients);
}

void ShowWithdrawOption(string FileName, vector<stClientData>& vClients)
{
	system("cls");

	WithdrawScreen();
	WithdrawClientBalance(FileName, vClients);
}


void PrintTotalBalancesTableHeader()
{
	cout << "___________________________________________________________________________________________\n\n";

	cout << "|  " << left << setw(16) << "Account Number";
	cout << "| " << left << setw(34) << "Client Name";
	cout << "| " << left << setw(10) << "Balance" << endl;

	cout << "___________________________________________________________________________________________\n\n";
}

void PrintClientInfoInTable(stClientData& Client)
{
	cout << "|  " << left << setw(16) << Client.AccountNumber;
	cout << "| " << left << setw(34) << Client.Name;
	cout << "| " << left << setw(10) << Client.AccountBalance << endl;
}

void ShowClientsTotalBalance(vector<stClientData>& vClients)
{
	system("cls");

	if (vClients.size() > 0)
	{
		double TotalBalances = 0;
		PrintTotalBalancesTableHeader();

		for (stClientData& Client : vClients)
		{
			PrintClientInfoInTable(Client);
			TotalBalances = TotalBalances + Client.AccountBalance;
		}

		cout << "___________________________________________________________________________________________\n\n";
		cout << "\t\t\t Total Balances: " << TotalBalances << endl;
	}

	else
	{
		cout << "\n No Client is Available in the System! \n";
		cout << "You Can Add Clients By Entering [2] Add New Client.";
	}
}


void ShowTransactionMenuScreen()
{
	cout << "=========================================\n";
	cout << "         Transaction Menu Screen \n";
	cout << "=========================================\n";

	cout << "\t [1] Deposit." << endl;
	cout << "\t [2] Withdraw." << endl;
	cout << "\t [3] Total Balances." << endl;
	cout << "\t [4] Main Menu." << endl;

	cout << "=========================================\n";
}

void GoBackToTransactionsMenuScreen()
{
	cout << "\n\n Press any key to go back to Main Menu...";
	system("pause > 0");
	TransactionsMenu();
}

void TransactionsMenuOptionHandler(enTransactionsMenuOption Option, string FileName, vector<stClientData>& vClients)
{
	switch (Option)
	{

	case enTransactionsMenuOption::Deposit_Option:
	{
		ShowDepositOption(FileName, vClients);
		GoBackToTransactionsMenuScreen();
		break;
	}

	case enTransactionsMenuOption::Withdraw_Option:
	{
		ShowWithdrawOption(FileName, vClients);
		GoBackToTransactionsMenuScreen();
		break;
	}

	case enTransactionsMenuOption::TotalBalances_Option:
	{
		ShowClientsTotalBalance(vClients);
		GoBackToTransactionsMenuScreen();
		break;
	}

	case enTransactionsMenuOption::MainMenu_Optionnnn:
	{
		GoBackToMainMenuScreen();
		break;
	}

	default:
	{
		cout << "\nInvalid Input!";
		break;
	}

	}

}

void TransactionsMenu()
{
	system("cls");

	if (!CheckAccessPermission(enMainMenuePermissions::pTranactions))
	{
		ShowAccessDeniedMessage();
		GoBackToMainMenuScreen();
		return;
	}

	vector<stClientData> vClients = LoadDataFromFileToVector(FileNameClients);

	ShowTransactionMenuScreen();
	TransactionsMenuOptionHandler((enTransactionsMenuOption)ReadTransactionsMenuOption(), FileNameClients, vClients);
}



short ReadPermissionsToSet()
{
	short Permissions = 0;
	char Answer = 'n';

	cout << "\nDo you want to give full access? y/n? ";
	cin >> Answer;

	if (Answer == 'y' || Answer == 'Y')
	{
		return -1;
	}

	cout << "\nDo you want to give access to : \n ";

	cout << "\nShow Client List? y/n? ";
	cin >> Answer;

	if (Answer == 'y' || Answer == 'Y')
	{
		Permissions += enMainMenuePermissions::pListClients;
	}

	cout << "\nAdd New Client? y/n? ";
	cin >> Answer;

	if (Answer == 'y' || Answer == 'Y')
	{
		Permissions += enMainMenuePermissions::pAddNewClient;
	}

	cout << "\nDelete Client? y/n? ";
	cin >> Answer;

	if (Answer == 'y' || Answer == 'Y')
	{
		Permissions += enMainMenuePermissions::pDeleteClient;
	}

	cout << "\nUpdate Client? y/n? ";
	cin >> Answer;

	if (Answer == 'y' || Answer == 'Y')
	{
		Permissions += enMainMenuePermissions::pUpdateClients;
	}

	cout << "\nFind Client? y/n? ";
	cin >> Answer;

	if (Answer == 'y' || Answer == 'Y')
	{
		Permissions += enMainMenuePermissions::pFindClient;
	}

	cout << "\nTransactions? y/n? ";
	cin >> Answer;

	if (Answer == 'y' || Answer == 'Y')
	{
		Permissions += enMainMenuePermissions::pTranactions;
	}

	cout << "\nManage Users? y/n? ";
	cin >> Answer;

	if (Answer == 'y' || Answer == 'Y')
	{
		Permissions += enMainMenuePermissions::pManageUsers;
	}

	return (Permissions == 127) ? -1 : Permissions;
}

stUserData ReadNewUserRecord(string UserName)
{
	stUserData User;

	User.UserName = UserName;
	User.Password = ReadString("Enter Password: ", true);
	User.Permissions = ReadPermissionsToSet();

	return User;
}


stUserData ConvertDataLineToRecord_User(string DataLine)
{
	stUserData User;
	vector <string> vUser = SplitString(DataLine);

	if (vUser.size() < 3) {

		cerr << "Error: Invalid data format in line: " << DataLine << endl;

		return User;
	}

	User.UserName = vUser[0];
	User.Password = vUser[1];
	User.Permissions = stoi(vUser[2]);


	return User;
}

string ConvertRecordToDataLine_User(stUserData& User, string Delim = " #//# ")
{
	string DataLine;

	DataLine += User.UserName + Delim;
	DataLine += User.Password + Delim;
	DataLine += to_string(User.Permissions);


	return DataLine;
}

vector <stUserData> LoadDataFromFileToVector_User(string FileName)
{
	vector <stUserData> vUsers;

	fstream UsersFile;
	UsersFile.open(FileName, ios::in);

	if (UsersFile.is_open())
	{
		stUserData User;
		string Line;
		while (getline(UsersFile, Line))
		{
			User = ConvertDataLineToRecord_User(Line);
			vUsers.push_back(User);
		}

		UsersFile.close();
	}

	return vUsers;
}

void SaveClientDataInFile_User(string FileName, vector<stUserData>& vUsers)
{
	fstream UsersFile;
	UsersFile.open(FileName, ios::out);

	if (UsersFile.is_open())
	{
		for (stUserData& User : vUsers)
		{
			if (User.MarkForDelete == false)
			{
				UsersFile << ConvertRecordToDataLine_User(User) << endl;
			}
		}

		UsersFile.close();
	}
}

void PrintUserCard(stUserData& User)
{
	cout << "\nThe following are the User details: \n";
	cout << "--------------------------------------- \n";

	cout << "UserName   : " << User.UserName << endl;
	cout << "Password   : " << User.Password << endl;
	cout << "Permession : " << User.Permissions << endl;

	cout << "--------------------------------------- \n\n";
}


void PrintUserListTableHeader()
{
	cout << "___________________________________________________________________________________________\n\n";

	cout << "| " << left << setw(15) << "User Name";
	cout << "| " << left << setw(9) << "Password";
	cout << "| " << left << setw(58) << "Permissions" << endl;

	cout << "___________________________________________________________________________________________\n\n";
}

void PrintUserRecordInTable(stUserData& User)
{
	cout << "| " << left << setw(15) << User.UserName;
	cout << "| " << left << setw(9) << User.Password;
	cout << "| " << left << setw(58) << User.Permissions << endl;
}

void ShowUserListOption(vector<stUserData>& vUsers)
{
	system("cls");

	if (vUsers.size() > 0)
	{
		cout << "\n\t\t\t\t Client List (" << vUsers.size() << ") Client(s).\n";
		PrintUserListTableHeader();

		for (stUserData& User : vUsers)
		{
			PrintUserRecordInTable(User);
		}

		cout << "\n___________________________________________________________________________________________\n\n";
	}
}


void AddNewUserScreen()
{
	cout << "-------------------------------" << endl;
	cout << "    Add New User Screen" << endl;
	cout << "-------------------------------" << endl;

	cout << "Adding New User: \n\n";
}

bool FindUserByUserName(string UserName, vector<stUserData>& vUsers, stUserData& User, bool SaveUserData = false)
{
	for (stUserData& U : vUsers)
	{
		if (U.UserName == UserName)
		{
			if (SaveUserData == true)
			{
				User = U;
			}

			return true;
		}
	}

	return false;
}

bool FindUserByUserNameAndPassword(string UserName, string Password, vector<stUserData>& vUsers, stUserData& User, bool SaveUserData = false)
{
	for (stUserData& U : vUsers)
	{
		if (U.UserName == UserName && U.Password == Password)
		{
			if (SaveUserData)
			{
				User = U;
			}

			return true;
		}
	}

	return false;
}

void AddNewUser(string FileName, vector<stUserData>& vUsers)
{
	stUserData User;

	User.UserName = ReadString("Enter UserName: ", true);

	while (FindUserByUserName(User.UserName, vUsers, User))
	{
		User.UserName = ReadString("\nUser with [" + User.UserName + "] is already exists, enter another UserName: ", true);
	}

	User.Password = ReadString("Enter Password: ", true);
	User.Permissions = ReadPermissionsToSet();

	AddDataLineToFile(FileName, ConvertRecordToDataLine_User(User));

	vUsers.push_back(User);
}

void ShowAddNewUsersOption(string FileName, vector<stUserData>& vUsers)
{
	char AddMore = 'N';
	do
	{
		system("cls");

		AddNewUserScreen();
		AddNewUser(FileName, vUsers);

		AddMore = ReadChar("\nUser Added Successfully, do you want to add more Users? [Y]/[N]? ");

	} while (toupper(AddMore) == 'Y');
}


void DeleteUserScreen()
{
	cout << "------------------------------" << endl;
	cout << "     Delete User Screen" << endl;
	cout << "------------------------------" << endl;

	cout << "Deleting User: \n\n";
}

bool MarkUserForDeleteByUserName(string UserName, vector<stUserData>& vUsers)
{
	for (stUserData& User : vUsers)
	{
		if (User.UserName == UserName)
		{
			User.MarkForDelete = true;
			return true;
		}
	}

	return false;
}

bool DeleteUser(string FileName, vector<stUserData>& vUsers)
{
	stUserData User;
	string UserName = ReadString("Please enter UserName: ", true);

	if (UserName == "Admin")
	{
		cout << "\n You Cannot delete the Admin! \n";
		return false;
	}

	if (FindUserByUserName(UserName, vUsers, User, true))
	{
		PrintUserCard(User);
		char WantToDelete = ReadChar("\nAre you sure you want to delete this User? [Y]/[N]? ");

		if (toupper(WantToDelete) == 'Y')
		{
			MarkUserForDeleteByUserName(UserName, vUsers);
			SaveClientDataInFile_User(FileName, vUsers);
			vUsers = LoadDataFromFileToVector_User(FileName);

			cout << "\n User Deleted Successfully. \n";
			return true;
		}
	}

	else
	{
		cout << "\n User with UserName [" << UserName << "] Not Found! \n";
	}

	return false;
}

void ShowDeleteUserOption(string FileName, vector<stUserData>& vUsers)
{
	system("cls");

	DeleteUserScreen();
	DeleteUser(FileName, vUsers);
}


void UpdateUserInfoScreen()
{
	cout << "-------------------------------" << endl;
	cout << "   Update User Info Screen" << endl;
	cout << "-------------------------------" << endl;

	cout << "Updating User Info: \n\n";
}

bool UpdateUserInfo(string FileName, vector<stUserData>& vUsers)
{
	stUserData NewUser;
	string UserName = ReadString("Please enter UserName: ", true);

	if (UserName == "Admin")
	{
		cout << "\n You Cannot Update the Admin! \n";
		return false;
	}

	if (FindUserByUserName(UserName, vUsers, NewUser, true))
	{
		PrintUserCard(NewUser);
		char WantToUpdate = ReadChar("\nAre you sure you want to update this User? [Y]/[N]? ");

		if (toupper(WantToUpdate) == 'Y')
		{
			NewUser = ReadNewUserRecord(UserName);

			for (stUserData& OldUser : vUsers)
			{
				if (OldUser.UserName == UserName)
				{
					OldUser = NewUser;
					break;
				}
			}

			SaveClientDataInFile_User(FileName, vUsers);

			cout << "\n User Updated Successfully. \n";
			return true;
		}
	}

	else
	{
		cout << "\n User with UserName [" << UserName << "] Not Found! \n";
	}

	return false;
}

void ShowUpdateUserInfoOption(string FileName, vector<stUserData>& vUsers)
{
	system("cls");

	UpdateUserInfoScreen();
	UpdateUserInfo(FileName, vUsers);
}


void FindUserScreen()
{
	cout << "----------------------------" << endl;
	cout << "     Find User Screen" << endl;
	cout << "----------------------------" << endl;

	cout << "Finding User Info: \n\n";
}

void ShowFindUserOption(vector<stUserData>& vUsers)
{
	system("cls");

	FindUserScreen();

	stUserData User;
	string UserName = ReadString("Please enter UserName: ", true);

	if (FindUserByUserName(UserName, vUsers, User, true))
	{
		PrintUserCard(User);
	}

	else
	{
		cout << "\n User with UserName [" << UserName << "] Not Found! \n";
	}

}


bool CheckAccessPermission(enMainMenuePermissions Permission)
{
	if (CurrentUser.Permissions == enMainMenuePermissions::eAll)
		return true;

	if ((Permission & CurrentUser.Permissions) == Permission)
		return true;

	return false;
}

void ShowAccessDeniedMessage()
{
	cout << "\n------------------------------------\n";
	cout << "Access Denied, \nYou dont Have Permission To Do this,\nPlease Conact Your Admin.";
	cout << "\n------------------------------------\n";
}

void ShowManageUsersMenueScreen()
{
	system("cls");

	cout << "====================================\n";
	cout << "      Manage Users Menu Screen\n";
	cout << "====================================\n";

	cout << "\t [1] Show List Users." << endl;
	cout << "\t [2] Add New User." << endl;
	cout << "\t [3] Delete User." << endl;
	cout << "\t [4] Update User Info." << endl;
	cout << "\t [5] Find User." << endl;
	cout << "\t [6] Main Menue." << endl;

	cout << "====================================\n";
}

void GoBackToUsersMenueScreen()
{
	cout << "\n\n Press any key to go back to User Menu...";
	system("pause > 0");
	ManageUserMenuOption();
}


void UsersMenuOptionHandler(enUserMenuOption Option, string FileName, vector<stUserData>& vUsers)
{
	switch (Option)
	{

	case enUserMenuOption::UserList_Option:
	{
		ShowUserListOption(vUsers);
		GoBackToUsersMenueScreen();
		break;
	}

	case enUserMenuOption::AddNewUser_Option:
	{
		ShowAddNewUsersOption(FileName, vUsers);
		GoBackToUsersMenueScreen();
		break;
	}

	case enUserMenuOption::DeleteUser_Option:
	{
		ShowDeleteUserOption(FileName, vUsers);
		GoBackToUsersMenueScreen();
		break;
	}

	case enUserMenuOption::UpdateUserInfo_Option:
	{
		ShowUpdateUserInfoOption(FileName, vUsers);
		GoBackToUsersMenueScreen();
		break;
	}

	case enUserMenuOption::FindUser_Option:
	{
		ShowFindUserOption(vUsers);
		GoBackToUsersMenueScreen();
		break;
	}

	case enUserMenuOption::O_MainMenu_Option:
	{
		GoBackToMainMenuScreen();
		break;
	}

	default:
	{
		cout << "\nInvalid Input!\n";
		GoBackToUsersMenueScreen();
		break;
	}

	}
}

void ManageUserMenuOption()
{
	system("cls");

	if (!CheckAccessPermission(enMainMenuePermissions::pManageUsers))
	{
		ShowAccessDeniedMessage();
		return;
	}

	vector<stUserData> vUsers = LoadDataFromFileToVector_User(FileNameUsers);

	ShowManageUsersMenueScreen();
	UsersMenuOptionHandler((enUserMenuOption)ReadUserMenuOption(), FileNameUsers, vUsers);
}


void ShowMainMenuScreen()
{
	system("cls");

	cout << "=========================================\n";
	cout << "            Main Menu Screen\n";
	cout << "=========================================\n";

	cout << "\t [1] Show Client List." << endl;
	cout << "\t [2] Add New Client." << endl;
	cout << "\t [3] Delete Client." << endl;
	cout << "\t [4] Update Client Info." << endl;
	cout << "\t [5] Find Client." << endl;
	cout << "\t [6] Transactions." << endl;
	cout << "\t [7] Manage Users." << endl;
	cout << "\t [8] Logout." << endl;

	cout << "=========================================\n";
}

void GoBackToMainMenuScreen()
{
	cout << "\n\n Press any key to go back to Main Menu...";
	system("pause > 0");
	MainMenu();
}

void MainMenuOptionHandler(enMainMenuOption Option, string FileName, vector<stClientData>& vClients)
{
	switch (Option)
	{

	case enMainMenuOption::ClientList_Option:
	{
		ShowClientListOption(vClients);
		GoBackToMainMenuScreen();
		break;
	}

	case enMainMenuOption::AddNewClient_Option:
	{
		ShowAddNewClientsOption(FileName, vClients);
		GoBackToMainMenuScreen();
		break;
	}

	case enMainMenuOption::DeleteClient_Option:
	{
		ShowDeleteClientOption(FileName, vClients);
		GoBackToMainMenuScreen();
		break;
	}

	case enMainMenuOption::UpdateClientInfo_Option:
	{
		ShowUpdateClientInfoOption(FileName, vClients);
		GoBackToMainMenuScreen();
		break;
	}

	case enMainMenuOption::FindClient_Option:
	{
		ShowFindClientOption(vClients);
		GoBackToMainMenuScreen();
		break;
	}

	case enMainMenuOption::Transactions_Option:
	{
		TransactionsMenu();
		GoBackToMainMenuScreen();
		break;
	}

	case enMainMenuOption::ManageUsers_Option:
	{
		ManageUserMenuOption();
		GoBackToMainMenuScreen();
		break;
	}

	case enMainMenuOption::Logout_Option:
	{
		Login();
		break;
	}

	default:
	{
		cout << "\nInvalid Input!\n";
		GoBackToMainMenuScreen();
		break;
	}

	}

}

void MainMenu()
{
	vector<stClientData> vClients = LoadDataFromFileToVector(FileNameClients);

	ShowMainMenuScreen();
	MainMenuOptionHandler((enMainMenuOption)ReadMainMenuOption(), FileNameClients, vClients);
}

void LoginScreen()
{
	cout << "----------------------" << endl;
	cout << "     Login Screen" << endl;
	cout << "----------------------" << endl;
}

void Login()
{
	vector<stUserData> vUsers = LoadDataFromFileToVector_User(FileNameUsers);

	bool FailedToLogin = false;
	string UserName, Password;

	do
	{

		system("cls");

		LoginScreen();

		if (FailedToLogin)
		{
			cout << "Invalid UserName/Password!\n";
		}

		UserName = ReadString("Enter UserName: ", true);
		Password = ReadString("Enter PassWord: ");

		FailedToLogin = true;

	} while (!FindUserByUserNameAndPassword(UserName, Password, vUsers, CurrentUser, true));

	MainMenu();

}



int main()
{
	Login();

	system("pause>0");

	return 0;
}