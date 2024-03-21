#include "customerDetail.h"
#include "choice.h"

#include<thread>
#include<sqlite3.h>

#include<fstream>
#include<iostream>
#include<map>  // Include map
using namespace std;

// Define the Customer structure
struct Customer {
    long long int Phone_No;
    string Name;
    string Address;
    int NoOfMembers;
    // Add other relevant fields (e.g., booking history, preferences)
};

class hotelmanage{
    public:
        int roomNo;
        int totalRooms;
        int bookedRooms;
        int availableRooms;
        int roomCharges;
        map<long long int, Customer> customerData;  // Map to store customer data
        map<int, long long int> roomToCustomer; // Map to store room-to-customer mapping

        hotelmanage(){
            roomNo = 0;
            totalRooms = 100;
            bookedRooms = 0;
            availableRooms = 100;
            roomCharges = 10000;
            choice();
        }

        choice c;
        customerDetail customHeader;

        void choice();
        void checkList();
        void customerDetails();
        void registerRoom();
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
        cout << "Invalid Choice\\n";
    }
}

void hotelmanage::customerDetails(){
    Customer customer;  // Create a new Customer object

    cout << "\\nAdding New Customer Details\\n";

    customer.Phone_No = customHeader.Phone_No();  // Get phone number
    cout << "Phone No: " << customer.Phone_No << endl;

    customer.Name = customHeader.Name();  // Get customer name
    cout << "Name: " << customer.Name << endl;

    customer.Address = customHeader.Address();  // Get customer address
    cout << "Address: " << customer.Address << endl;

    customer.NoOfMembers = customHeader.NoOfMembers();  // Get number of members
    cout << "No of Members: " << customer.NoOfMembers << endl;

    // Add the customer to the map
    customerData[customer.Phone_No] = customer;
}

void hotelmanage::checkList(){
    cout << "\\nCustomer List:\\n";
    for (const auto& entry : customerData) {
        cout << "Phone No: " << entry.first << endl;
        cout << "Name: " << entry.second.Name << endl;
        cout << "Address: " << entry.second.Address << endl;
        cout << "No of Members: " << entry.second.NoOfMembers << endl;
        cout << endl;
    }
}

void hotelmanage ::registerRoom(){
    int Room_No;
    int NoOfDays;
    int Total_Charges;

    cout << "\\nRegistering New Room\\n";

    cout << "Enter Room No: ";
    cin >> Room_No;

    cout << "Enter No of Days: ";
    cin >> NoOfDays;

    Total_Charges = roomCharges * NoOfDays;
    cout << "Total Charges: " << Total_Charges << endl;

    customerDetails();  // Add customer details

    // Update room availability
    bookedRooms++;
    availableRooms--;

    //roomToCustomer[Room_No] = customHeader.Phone_No;
    cout << "Room " << Room_No << " registered successfully!\\n";
}

int main(){
    hotelmanage h;

    return 0;
}
