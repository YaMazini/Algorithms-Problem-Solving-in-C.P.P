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
    cin.ignore();
    getline(cin, S);

    return S;
}

double ReadDouble(string Message)
{
    double d;
    cout << Message;
    cin >> d;

    while (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Please enter a double: ";
        cin >> d;
    }

    return d;
}

char ReadChar(string Message)
{
    char C;
    cout << Message;
    cin.ignore();
    cin >> C;

    while (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Please enter a char: ";
        cin >> C;
    }

    return C;
}


stClientData ReadNewClientData()
{
    stClientData ClientData;

    cout << " Adding New Client: \n\n";

    ClientData.AccountNumber = ReadString("Enter Account Number: ");
    ClientData.PinCode = ReadString("Enter Pin Code: ");
    ClientData.Name = ReadString("Enter Name: ");
    ClientData.Phone = ReadString("Enter Phone: ");
    ClientData.AccountBalance = ReadDouble("Enter Account Balance: ");

    cout << "\n";

    return ClientData;
}

string ConvertDataToLine(stClientData& ClientData, string Delim = " #//# ")
{
    string S = "";

    S += ClientData.AccountNumber + Delim;
    S += ClientData.PinCode + Delim;
    S += ClientData.Name + Delim;
    S += ClientData.Phone + Delim;
    S += to_string(ClientData.AccountBalance);

    return S;
}

void AddDataLineToFile(string DataLine, const string FileName)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out | ios::app);

    if (MyFile.is_open())
    {
        MyFile << DataLine << endl;

        MyFile.close();
    }
}

void AddNewClient()
{
    stClientData ClientData = ReadNewClientData();

    AddDataLineToFile(ConvertDataToLine(ClientData), FileName);
}

void AddClients()
{
    char AddMore = 'Y';

    do
    {
        system("cls");

        AddNewClient();

        AddMore = ReadChar("Client Added Successfully, do you want to add more clients? [Y]/[N]? ");

    } while (toupper(AddMore) == 'Y');
}


int main()
{

    AddClients();



    return 0;
}