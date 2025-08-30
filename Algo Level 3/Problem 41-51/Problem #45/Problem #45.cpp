#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct stClientData
{
    string AccountNumber;
    string PinCode;
    string FullName;
    string PhoneNumber;
    double AccountBalance;
};

string ReadString(string Message)
{
    string S1;
    cout << Message;
    getline(cin, S1);

    return S1;
}

double ReadDouble(string Message)
{
    double d = 0;
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

stClientData ReadNewClientData()
{
    stClientData ClientData;

    cout << " Please enter ClientData: \n\n";

    ClientData.AccountNumber = ReadString("Enter Account Number: ");
    ClientData.PinCode = ReadString("Enter PinCode: ");
    ClientData.FullName = ReadString("Enter FullName: ");
    ClientData.PhoneNumber = ReadString("Enter Phone Number: ");
    ClientData.AccountBalance = ReadDouble("Enter Account Balance: ");

    cout << "\n\n";

    return ClientData;
}

string ConvertRecordToLine(stClientData& ClientData, string Separator = " #//# ")
{
    string StrRecord = "";
    
    StrRecord += ClientData.AccountNumber + Separator;
    StrRecord += ClientData.PinCode + Separator;
    StrRecord += ClientData.FullName + Separator;
    StrRecord += ClientData.PhoneNumber + Separator;
    StrRecord += to_string(ClientData.AccountBalance);

    return StrRecord;
}


int main()
{
    stClientData ClientData = ReadNewClientData();
    
    cout << " Client Record for Saving is: \n";
    cout << ConvertRecordToLine(ClientData) << endl;

    return 0;
}