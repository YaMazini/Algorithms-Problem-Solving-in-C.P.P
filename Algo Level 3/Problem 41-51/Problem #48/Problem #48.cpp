#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct stClientData
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
};

const string FileName = "ClientsData.txt";


vector <string> SplitString(string S1, string Delim)
{
	vector <string> vWords;

	string Word;
	short pos = 0;

	while ((pos = S1.find(Delim)) != string::npos)
	{
		Word = S1.substr(0, pos);
		
		if (Word != "")
		{
			vWords.push_back(Word);
		}

		S1.erase(0, Word.length() + Delim.length());
	}

	if (S1 != "")
	{
		vWords.push_back(S1);
	}

	return vWords;
}

stClientData ConvertLineToRecord(string S1)
{
	stClientData ClientData;

	vector<string> vClientData = SplitString(S1, " #//# ");
	
	ClientData.AccountNumber = vClientData[0];
	ClientData.PinCode = vClientData[1];
	ClientData.Name = vClientData[2];
	ClientData.Phone = vClientData[3];
	ClientData.AccountBalance = stod(vClientData[4]);

	return ClientData;
}

vector <stClientData> LoadClientDataFromFile(string FileName)
{
	vector <stClientData> vClientData;
	fstream ClientFile;
	ClientFile.open(FileName, ios::in);


	if (ClientFile.is_open())
	{
		string Line;
		stClientData ClientData;

		while (getline(ClientFile, Line))
		{
			ClientData = ConvertLineToRecord(Line);

			vClientData.push_back(ClientData);
		}

		ClientFile.close();
	}

	return vClientData;
}


void PrintClientTableHeader()
{
	cout << "______________________________________________________________________________________________\n\n";

	cout << "| " << setw(15) << left << "Account Number"
		 << "| " << setw(10) << left << "Pin Code"
		 << "| " << setw(30) << left << "Client Name"
		 << "| " << setw(15) << left << "Phone"
		 << "| " << setw(12) << left << "Balance"
		 << "\n";

	cout << "______________________________________________________________________________________________\n\n";
}

void PrintClientRecord(stClientData &ClientData)
{

	cout << "| " << setw(15) << left << ClientData.AccountNumber
		 << "| " << setw(10) << left << ClientData.PinCode
		 << "| " << setw(30) << left << ClientData.Name
		 << "| " << setw(15) << left << ClientData.Phone
		 << "| " << setw(12) << left << to_string(ClientData.AccountBalance)
		 << "\n";
}

void PrintClientsData(vector <stClientData> &vClientData)
{
	cout << "\n\t\t\t\t Client List (" << vClientData.size() << ") Clients(s).\n";
	PrintClientTableHeader();

	for (stClientData& Client : vClientData)
	{
		PrintClientRecord(Client);
	}

	cout << "______________________________________________________________________________________________\n";
}


int main()
{
	vector <stClientData> vClientData = LoadClientDataFromFile(FileName);

	PrintClientsData(vClientData);

	return 0;
}