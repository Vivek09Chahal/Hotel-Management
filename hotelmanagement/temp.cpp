#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <iomanip>

using namespace std;

// Interface Functions Here =>
void intro();
void head();
void time();

class hotel {
private:
    int room_no;
    char name[30];
    char address[50];
    char phone[15];
    int days;
    float fare;

public:
    void main_menu();          // to display the main menu
    void add();                // to book a room
    void display();            // to display the customer record
    void rooms();              // to display allotted rooms
    void edit();               // to edit the customer record
    int check(int);            // to check room status
    void modify(int);          // to modify the record
    void delete_rec(int);      // to delete the record
};

void hotel::main_menu() {
    int choice;
    while (choice != 5) {
        system("clear"); // Change "clear" to "cls" if using Windows
        head();
        cout << "\n\t\t\t\t*************";
        cout << "\n\t\t\t\t* MAIN MENU *";
        cout << "\n\t\t\t\t*************";
        cout << "\n\n\n\t\t\t1.Book A Room";
        cout << "\n\t\t\t2.Customer Record";
        cout << "\n\t\t\t3.Rooms Allotted";
        cout << "\n\t\t\t4.Edit Record";
        cout << "\n\t\t\t5.Exit";
        cout << "\n\n\t\t\tEnter Your Choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            add();
            break;
        case 2:
            display();
            break;
        case 3:
            rooms();
            break;
        case 4:
            edit();
            break;
        case 5:
            break;
        default:
            cout << "\n\n\t\t\tWrong choice.....!!!";
            cout << "\n\t\t\tPress any key to continue....!!";
            cin.ignore();
            cin.get();
        }
    }
}

void hotel::add() {
    system("clear");
    head();
    int r, flag;
    ofstream fout("Record.dat", ios::app);
    cout << "\n Enter Customer Details";
    cout << "\n ----------------------";
    cout << "\n\n Room no: ";
    cin >> r;
    flag = check(r);
    if (flag)
        cout << "\n Sorry..!!!Room is already booked";
    else {
        room_no = r;
        cout << " Name: ";
        cin.ignore();
        cin.getline(name, 30);
        cout << " Address: ";
        cin.getline(address, 50);
        cout << " Phone No: ";
        cin.getline(phone, 15);
        cout << " No of Days to Checkout: ";
        cin >> days;
        fare = days * 900; // 900 is currently set as the default price per day
        fout.write((char *)this, sizeof(hotel));
        cout << "\n Room is booked...!!!";
    }

    cout << "\n Press any key to continue.....!!";
    cin.ignore();
    cin.get();
    fout.close();
}

// Define other member functions similarly

int main() {
    hotel h;
    system("clear"); // Change "clear" to "cls" if using Windows
    cout << "\n\n\n";
    intro();
    time();
    cout << "\n\n\n\t\t\tPress any key to continue....!!";

    cin.ignore();
    cin.get();
    system("clear"); // Change "clear" to "cls" if using Windows
    head();
    char id[5], pass[7];
    cout << "\n\n\t\t\t\tusername => ";
    cin >> id;
    cout << "\n\t\t\t\tpassword => ";
    cin >> pass;
    cout << "\n\n\t";
    time();
    cout << "\t";
    if (strcmp(id, "admin") == 0 && strcmp(pass, "******") == 0)
        cout << "\n\n\t\t\t  !!!Login Successfull!!!";
    else {
        cout << "\n\n\t\t\t!!!INVALID CREDENTIALS!!!";
        cin.ignore();
        cin.get();
        exit(-1);
    }
    system("clear"); // Change "clear" to "cls" if using Windows
    h.main_menu();
    return 0;
}
