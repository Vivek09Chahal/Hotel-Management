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
    cout << "1.  Register Room \n";
    cout << "2. Customer Details \n";
    cout << "3. Check List of Users \n";

    cout << "Enter your choice: \n";

    cin >> choice;
    cin.ignore();
    return choice;
}