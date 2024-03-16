#include<iostream>
#include<fstream>
using namespace std;

class choice{
    public:
        int choose();
};

int choice ::choose()
{
    int choice;
    cout << "1. Room Details \n";
    cout << "2. Customer Details \n";
    cout << "3. Check Details \n";
    cout << "4. Register Room \n";

    cout << "Enter your choice: \n";

    cin >> choice;
    cin.ignore();
    return choice;
}