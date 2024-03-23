#include <iostream>

class choice
{
public:
    int choose();
};

int choice ::choose()
{
    int choice;
    std::cout << "Welcome to Hotel Management System\n";
    std::cout << "Choose from the following options: \n";
    std::cout << "1. Enter Data \n";
    std::cout << "2. Display Data \n";
    std::cout << "3. Update Data \n";
    std::cout << "4. Delete Data \n";
    std::cout << "Enter your choice: ";

    std::cin >> choice;
    std::cin.ignore();
    return choice;
}