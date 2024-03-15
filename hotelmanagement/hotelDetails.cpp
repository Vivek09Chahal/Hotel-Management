#include "customerDetail.h"
#include "choice.h"

#include<fstream>
#include<iostream>
using namespace std;

class hotelmanage{
    public:
        void choice();
        void roomDetails();
        void checkdetails();
        void customerDetails();
};

void hotelmanage ::choice()
{
    

    int choice;
    cout << "1. Room Details \n";
    cout << "2. Customer Details \n";
    cout << "3. Check Details \n";

    cout << "Enter your choice: \n";

    cin >> choice;
    switch(choice){
        case 1:
            roomDetails();
            break;
        case 2:
            customerDetails();
            break;
        case 3:
            checkdetails();
            break;
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

void hotelmanage ::customerDetails()
{
    fstream file;
    file.open("customer.txt", ios::app);

    customerDetail customer;

    if(file.is_open()){
        file << "Adding New Customer Details\n";
    }

    int Phone_No;
    string Name;
    string Address;
    int NoOfMembers;

    if(file.is_open()){
        Phone_No = customer.Phone_No();
        file << "\nPhone No: " << Phone_No;
        getchar();
    
        Name = customer.Name();
        file << "\nName: " << Name;
        getchar();
    
        Address = customer.Address();
        file << "\nAddress: " << Address;
        getchar();

        NoOfMembers = customer.NoOfMembers();
        file << "\nNo of Members: " << NoOfMembers;
        getchar();
    
        file << "\n\n\n\n\n\n";
    }
    else{
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

int main(){
    hotelmanage h;

    h.choice();

    return 0;
}