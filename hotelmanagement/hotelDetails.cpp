#include "choice.h"
#include "customerDetail.h"

#include<thread>

#include<map>
#include<fstream>
#include<iostream>
using namespace std;

struct customerVariables {
    long long int Phone_No;
    string Name;
    string Address;
    int NoOfMembers;
    string emailID;

    int roomNo;
    int totalRooms;
    int bookedRooms;
    int availableRooms;
    int roomCharges;
};

class hotelmanage{
    public:

        map<string , customerVariables> customerData;
        //map<int, string> roomToCustomer;

        choice c;                       //object of choice header class of header file choice.h
        customerDetail customHeader;    //object of customerDetail class of header file customerDetail.h
        customerVariables customer;     //object of customerVariables structure

        void choice();
        void checkList();
        void customerDetails();
        void registerRoom();

        bool isAlreadyExist(string);
};

void hotelmanage ::choice(){
    int choice = c.choose();
    if(choice == 1){
        registerRoom();
    }
    else if(choice == 2){
        customerDetails();
    }
    else if(choice == 3){
        checkList();
    }
    else{
        cout << "Invalid Choice\n";
    }
}

void hotelmanage::customerDetails(){

    fstream file;
    file.open("customer.txt", ios::app);

    if (file.is_open()) {
        file << "\nAdding New Customer Details\n";

        customer.Phone_No = customHeader.Phone_No();
        file << "Phone No: " << customer.Phone_No << "\n";

        customer.Name = customHeader.Name();
        file << "Name: " << customer.Name << "\n";

        customer.Address = customHeader.Address();
        file << "Address: " << customer.Address << "\n";

        customer.NoOfMembers = customHeader.NoOfMembers();
        file << "No of Members: " << customer.NoOfMembers << "\n\n";

        customer.emailID = customHeader.emailID();
        bool alreadyExist =  isAlreadyExist(customer.emailID);
        file << "Email ID: " << customer.emailID << "\n\n";

        customerData[customer.emailID] = customer;

        file.close();
    } 
    else {
        cout << "File is not open";
    }
}

void hotelmanage ::checkList()
{
    fstream file;
    file.open("customer.txt", ios::in);

    if(file.is_open()){
        string line;
        while(getline(file, line)){
            cout << line << endl;
        }
    }
    else{
        cout << "File is not open";
    }
}

void hotelmanage ::registerRoom()
{
    fstream file;
    file.open("customer.txt", ios::app);

    customer.roomNo = 0;
    customer.totalRooms = 100;
    customer.bookedRooms = 0;
    customer.availableRooms = 100;
    customer.roomCharges = 10000;

    int NoOfDays;
    int Total_Charges;

    if(file.is_open()){
        file << "Registering New Room\n";

        cout << "Enter Room No: \n";
        cin >> customer.roomNo;
        file << "Room No: " << customer.roomNo << "\n";

        cout << "Enter No of Days: \n";
        cin >> NoOfDays;
        file << "No of Days: " << NoOfDays << "\n";

        Total_Charges = customer.roomCharges * NoOfDays;
        file << "Total Charges: " << Total_Charges;
        cout << "Total Charges: " << Total_Charges << endl;

        customerDetails();

        file.close();
    }
    else{
        cout << "File is not open";
    }
}

bool hotelmanage::isAlreadyExist(string emailID){
    fstream file;
    file.open("customer.txt", ios::in);

    if(file.is_open()){
        string line;
        while(getline(file, line)){
            if(line == emailID){
                return true;
            }
        }
    }
    else{
        cout << "File is not open";
    }
    return false;
}


int main(){
    hotelmanage h;

    return 0;
}