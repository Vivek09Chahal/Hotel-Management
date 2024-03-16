#include "customerDetail.h"
#include "choice.h"

#include<thread>

#include<fstream>
#include<iostream>
using namespace std;

class hotelmanage{
    public:
        int roomNo;
        int totalRooms;
        int bookedRooms;
        int availableRooms;
        int roomCharges;

        hotelmanage(){
            roomNo = 0;
            totalRooms = 100;
            bookedRooms = 0;
            availableRooms = 100;
            roomCharges = 10000;
            choice();
        }

        choice c;
        customerDetail customer;

        void choice();
        void roomDetails();
        void checkdetails();
        void customerDetails();

        void registerRoom();
};

void hotelmanage ::choice()
{
    int choice = c.choose();
    if(choice == 1){
        roomDetails();
    }
    else if(choice == 2){
        customerDetails();
    }
    else if(choice == 3){
        checkdetails();
    }
    else if(choice == 4){
        registerRoom();
    }
    else{
        cout << "Invalid Choice\n";
    }
}

void hotelmanage ::roomDetails()
{
    cout << "Room Details ... \n";

    int Room_No;
    string Room_Type;
    int Room_Charges;
    int NoOfDays;
    int Total_Charges;

    cout << "Enter Room No: \n";
    cin >> Room_No;

    cout << "Enter Room Type: \n";
    cin >> Room_Type;

    cout << "Enter Room Charges: \n";
    cin >> Room_Charges;

    cout << "Enter No of Days: \n";
    cin >> NoOfDays;

    Total_Charges = Room_Charges * NoOfDays;
    cout << "Total Charges: " << Total_Charges << endl;

}

void hotelmanage::customerDetails() {
    fstream file;
    file.open("customer.txt", ios::app);
    //customerDetail customer;

    long long int Phone_No;
    string Name;
    string Address;
    int NoOfMembers;

    if (file.is_open()) { // Check if file opening succeeded
        file << "Adding New Customer Details\n";

        Phone_No = customer.Phone_No();
        file << "Phone No: " << Phone_No << "\n"; // Add newline character

        Name = customer.Name();
        file << "Name: " << Name << "\n"; // Add newline character

        Address = customer.Address();
        file << "Address: " << Address << "\n"; // Add newline character

        NoOfMembers = customer.NoOfMembers();
        file << "No of Members: " << NoOfMembers << "\n\n"; // Add newline character

        file.close(); // Close the file
    } 
    else {
        cout << "File is not open";
    }
}

void hotelmanage ::checkdetails()
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

    int Room_No;
    int Room_Charges;
    int NoOfDays;
    int Total_Charges;

    if(file.is_open()){
        file << "Registering New Room\n";

        cout << "Enter Room No: \n";
        cin >> Room_No;
        file << "Room No: " << Room_No << "\n";

        cout << "Enter No of Days: \n";
        cin >> NoOfDays;
        file << "No of Days: " << NoOfDays << "\n";

        Total_Charges = roomCharges * NoOfDays;
        file << "Total Charges: " << Total_Charges << "\n\n";
        cout << "Total Charges: " << Total_Charges << endl;

        

        file.close();
    }
    else{
        cout << "File is not open";
    }
}

int main(){
    hotelmanage h;

    return 0;
}