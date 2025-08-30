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

    bool MarkForDelete = false;
};

string ReadString(string Message)
{
    string S;
    cout << Message;
    getline(cin, S);

    return S;
}

char ReadChar(string Message)
{
    char C;
    cout << Message;
    cin >> C;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout << "Please enter a char: ";
        cin >> C;
    }

    return C;
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

string ConvertRecordToDataLine(stClientData& ClientData, string Delim = " #//# ")
{
    string DataLine;

    DataLine += ClientData.AccountNumber + Delim;
    DataLine += ClientData.PinCode + Delim;
    DataLine += ClientData.Name + Delim;
    DataLine += ClientData.Phone + Delim;
    DataLine += to_string(ClientData.AccountBalance);

    return DataLine;
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

vector <stClientData> LoadDataFromFileToVector(string FileName)
{
    vector<stClientData> vClients;
    fstream ClientsFile;
    ClientsFile.open(FileName, ios::in);

    if (ClientsFile.is_open())
    {
        string Line;
        stClientData Client;
        while (getline(ClientsFile, Line))
        {
            Client = ConvertDataLineToRecord(Line);
            vClients.push_back(Client);
        }

        ClientsFile.close();
    }

    return vClients;
}


bool FindClientByAccountNumber(vector<stClientData>& vClients, stClientData& Client, string AccountNumber)
{
    for (stClientData& C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;
        }
    }
    return false;
}

void PrintClientCard(stClientData& Client)
{
    cout << "\n The following are the client details: \n\n";

    cout << "Account Number : " << Client.AccountNumber << endl;
    cout << "Pin Code       : " << Client.PinCode << endl;
    cout << "Name           : " << Client.Name << endl;
    cout << "Phone          : " << Client.Phone << endl;
    cout << "Account Balance: " << Client.AccountBalance << "\n\n";
}

void SaveClientsVectorToFile(string FileName, vector<stClientData>& vClients)
{
    fstream ClientsFile;
    ClientsFile.open(FileName, ios::out);
    
    if (ClientsFile.is_open())
    {
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

bool MarkClientForDeleteByAccountNumber(vector<stClientData>& vClients, string AccountNumber)
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

bool DeleteClientByAccountNumber(vector<stClientData>& vClients, string FileName, string AccountNumber)
{
    char WantToDelete = 'N';
    stClientData Client;
    
    if (FindClientByAccountNumber(vClients, Client, AccountNumber))
    {
        PrintClientCard(Client);
        WantToDelete = ReadChar("Do you want to delete this client? [Y]/[N]? ");
        
        if (toupper(WantToDelete) == 'Y')
        {
            MarkClientForDeleteByAccountNumber(vClients, AccountNumber);
            SaveClientsVectorToFile(FileName, vClients);

            vClients = LoadDataFromFileToVector(FileName);

            cout << "\nClient Deleted Succesfully. \n";

            return true;
        }
    }

    else
    {
        cout << "\n Client with Account Number (" << AccountNumber << ") Not Found! \n";
    }

    return false;
}



int main()
{
    vector <stClientData> vClients = LoadDataFromFileToVector(FileName);
    string AccountNumber = ReadString("Please enter Account Number: ");
    
    DeleteClientByAccountNumber(vClients, FileName, AccountNumber);


    return 0;
}