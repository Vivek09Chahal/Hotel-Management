#include "choice.h"
#include "customerDetail.h"

#include <string>
#include <iostream>
#include <sqlite3.h>

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    int i;
    for (i = 0; i < argc; i++)
    {
        std::cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << std::endl;
    }
    std::cout << std::endl;
    return 0;
}

struct customerVariables
{
    long long int Phone_No;
    std::string Name;
    std::string Address;
    int NoOfMembers;
    std::string emailID;

    int roomNo;
    int totalRooms;
    int bookedRooms;
    int availableRooms;
    int roomCharges;
    int noOfRoomRegistered;
};

class hotelManager
{
public:
    std::string tableName;
    hotelManager()
    {
        std::cout << "Enter the table name: ";
        std::cin >> tableName;
    }

    sqlite3 *listOfUser;
    std::string sql;
    char *errMsg = 0;
    int rc;

    choice c;
    customerDetail customHeader;
    customerVariables customer;

    void createTable();

    void choice();
    void enterData();
    void displayData();
};

void hotelManager ::choice()
{
    int choice = c.choose();
    if (choice == 1)
    {
        enterData();
    }
    else if (choice == 2)
    {
        displayData();
    }
    else if (choice == 3)
    {
        createTable();
    }
    else
    {
        std::cout << "Invalid Choice\n";
    }
}

void hotelManager::createTable()
{

    // Open Database
    rc = sqlite3_open((tableName + ".db").c_str(), &listOfUser);
    if (rc)
    {
        std::cerr << "Can't open database: " << sqlite3_errmsg(listOfUser) << std::endl;
    }
    else
    {
        std::cout << "Opened database successfully" << std::endl;
    }

    // Create table
    sql = "CREATE TABLE " + tableName + "("
                                        "Phone_No INT PRIMARY KEY     NOT NULL,"
                                        "Name           CHAR(24)    NOT NULL,"
                                        "Address        CHAR(50),"
                                        "NoOfMembers    INT     NOT NULL,"
                                        "emailID        CHAR(25)    NOT NULL,"
                                        "roomNo         INT     NOT NULL,"
                                        "noOfRoomRegistered INT NOT NULL,"
                                        "roomCharges    INT     NOT NULL);";
    rc = sqlite3_exec(listOfUser, sql.c_str(), callback, 0, &errMsg);
}

void hotelManager::enterData()
{

    if (rc != SQLITE_OK)
    {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
    else
    {
        std::cout << "Table created successfully" << std::endl;
    }

    // Insert data
    customer.Phone_No = customHeader.Phone_No();
    customer.Name = customHeader.Name();
    customer.Address = customHeader.Address();
    customer.NoOfMembers = customHeader.NoOfMembers();
    customer.emailID = customHeader.emailID();
    customer.roomNo = 0;
    customer.noOfRoomRegistered = 0;
    customer.roomCharges = 0;

    sql = "INSERT INTO" + tableName + "(Phone_No, Name, Address, NoOfMembers, emailID, roomNo, noOfRoomRegistered, roomCharges) VALUES (" + std::to_string(customer.Phone_No) + ", '" + customer.Name + "', '" + customer.Address + "', " + std::to_string(customer.NoOfMembers) + ", '" + customer.emailID + "', " + std::to_string(customer.roomNo) + ", " + std::to_string(customer.noOfRoomRegistered) + ", " + std::to_string(customer.roomCharges) + ");";

    rc = sqlite3_exec(listOfUser, sql.c_str(), callback, 0, &errMsg);

    if (rc != SQLITE_OK)
    {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
    else
    {
        std::cout << "Records created successfully" << std::endl;
    }
}

void hotelManager::displayData()
{
    sqlite3 *listOfUser;
    char *errMsg = 0;
    int rc;

    // Open Database
    rc = sqlite3_open("listOfUser.db", &listOfUser);
    if (rc)
    {
        std::cerr << "Can't open database: " << sqlite3_errmsg(listOfUser) << std::endl;
    }
    else
    {
        std::cout << "Opened database successfully" << std::endl;
    }

    // Select data
    std::string sql = "SELECT * FROM CUSTOMER;";
    rc = sqlite3_exec(listOfUser, sql.c_str(), callback, 0, &errMsg);

    if (rc != SQLITE_OK)
    {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
    else
    {
        std::cout << "Operation done successfully" << std::endl;
    }
}

int main()
{

    hotelManager h;
    h.createTable();
    h.choice();

    return 0;
}