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
    int roomNo();
    int roomCharges();
    int dateInput();
    int monthInput();
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

int customerDetail ::roomNo()
{
    int roomNo;
    std::cout << "Enter Room No: \n";
    std::cin >> roomNo;
    std::cin.ignore();
    return roomNo;
}

int customerDetail ::roomCharges()
{
    int roomCharges;
    std::cout << "Enter Room Charges: \n";
    std::cin >> roomCharges;
    std::cin.ignore();
    return roomCharges;
}

int customerDetail ::dateInput(){
    int date;
    std::cout << "Enter date of room registration";
    std::cin >> date;
    return date;
}

int customerDetail ::monthInput(){
    int month;
    std::cout << "Enter the month of registration";
    std::cin >> month;
    return month;
}
