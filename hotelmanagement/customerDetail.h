#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<iomanip>
using namespace std;

class customerDetail{
    public:

        long long int Phone_No();
        string Name();
        string Address();
        int NoOfMembers();
        string emailID();
};

long long int customerDetail ::Phone_No()
{
    long long int Phone_No;
    cout << "Enter Phone No: \n";
    cin >> Phone_No;
    cin.ignore();
    return Phone_No;
}

string customerDetail ::Name()
{
    string Name;
    cout << "Enter Name: \n";
    getline(cin, Name);
    return Name;
}

string customerDetail ::Address()
{
    string Address;
    cout << "Enter Address: \n";
    getline(cin, Address);
    return Address;
}

string customerDetail ::emailID()
{
    string emailID;
    cout << "Enter Email ID: \n";
    getline(cin, emailID);
    return emailID;
}

int customerDetail ::NoOfMembers()
{
    int NoOfMembers;
    cout << "Enter No of Members: \n";
    cin >> NoOfMembers;
    cin.ignore();
    return NoOfMembers;
}