#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

const string FileName = "ClientsData.txt";

struct stClientData
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

string ReadString(string Message)
{
    string S;
    cout << Message;
    getline(cin, S);

    return S;
}

vector <string> SplitString(string S1, string Delim = " #//# ")
{
    vector <string> vWords;
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

stClientData ConvertDataLineToRecord(string S1)
{
    stClientData ClientData;
    vector <string> vClientData = SplitString(S1);

    ClientData.AccountNumber = vClientData[0];
    ClientData.PinCode = vClientData[1];
    ClientData.Name = vClientData[2];
    ClientData.Phone = vClientData[3];
    ClientData.AccountBalance = stod(vClientData[4]);

    return ClientData;
}

vector <stClientData> LoadDataFromFile(string FileName)
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


bool FindClientByAccountNumber(vector <stClientData> &vClients, stClientData &Client, string AccountNumber)
{
    for (stClientData& TempClient : vClients)
    {
        if (TempClient.AccountNumber == AccountNumber)
        {
            Client = TempClient;
            return true;
        }
    }

    return false;
}

void PrintClientData(stClientData& ClientData)
{
    cout << "Account Number : " << ClientData.AccountNumber << endl;
    cout << "Pin Code       : " << ClientData.PinCode << endl;
    cout << "Name           : " << ClientData.Name << endl;
    cout << "Phone          : " << ClientData.Phone << endl;
    cout << "Account Balance: " << ClientData.AccountBalance << endl;
}


int main()
{
    string AccountNumber = ReadString("Please enter Account Number to search for: ");
    vector <stClientData> vClients = LoadDataFromFile(FileName);
    stClientData Client;

    if (FindClientByAccountNumber(vClients, Client, AccountNumber))
    {
        cout << "\n\n The following are the client details: \n";
        PrintClientData(Client);
    }

    else
    {
        cout << "\n Client With Account Number (" << AccountNumber << ") Not Found!\n";
    }


    return 0;
}