#include <iostream>
#include <string>

class customerDetail
{
public:
    long long int Phone_No();
    std::string Name();
    std::string Address();
    int NoOfMembers();
    std::string emailID();
};

long long int customerDetail ::Phone_No()
{
    long long int Phone_No;
    std::cout << "Enter Phone No: \n";
    std::cin >> Phone_No;
    std::cin.ignore();
    return Phone_No;
}

std::string customerDetail ::Name()
{
    std::string Name;
    std::cout << "Enter Name: \n";
    std::getline(std::cin, Name);
    return Name;
}

std::string customerDetail ::Address()
{
    std::string Address;
    std::cout << "Enter Address: \n";
    std::getline(std::cin, Address);
    return Address;
}

std::string customerDetail ::emailID()
{
    std::string emailID;
    std::cout << "Enter Email ID: \n";
    std::getline(std::cin, emailID);
    return emailID;
}

int customerDetail ::NoOfMembers()
{
    int NoOfMembers;
    std::cout << "Enter No of Members: \n";
    std::cin >> NoOfMembers;
    std::cin.ignore();
    return NoOfMembers;
}