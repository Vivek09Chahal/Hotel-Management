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
        int Phone_No();
        string Name();
        string Address();
        int NoOfMembers();
};

int customerDetail ::Phone_No()
{
    int Phone_No;
    cout << "Enter Phone No: \n";
    cin >> Phone_No;
    return Phone_No;
}

string customerDetail ::Name()
{
    string Name;
    cout << "Enter Name: \n";
    cin.ignore();
    getline(cin, Name);
    return Name;
}

string customerDetail ::Address()
{
    string Address;
    cout << "Enter Address: \n";
    cin.ignore();
    getline(cin, Address);
    return Address;
}

int customerDetail ::NoOfMembers()
{
    int NoOfMembers;
    cout << "Enter No of Members: \n";
    cin >> NoOfMembers;
    return NoOfMembers;
}