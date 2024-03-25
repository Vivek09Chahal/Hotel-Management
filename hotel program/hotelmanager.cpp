#include "choice.h"
#include "customerDetail.h"

#include <string>
#include <iostream>
#include <sqlite3.h>

static int callback(void *NotUsed, int argc, char **argv, char **azColName);

struct customerVariables
{
    long long int Phone_No;
    std::string Name;
    std::string Address;
    int NoOfMembers;
    std::string emailID;

    int roomNo;
    int roomCharges;
};

class hotelManager
{
public:
    std::string tableName;

    sqlite3 *db;
    std::string sql;
    char *errMsg = 0;
    int rc;

    hotelManager()
    {
        rc = sqlite3_open("HotelDB.db", &db);

        if (rc)
        {
            std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        }
        else
        {
            std::cout << "Opened database successfully" << std::endl;
        }
    }

    choice c;
    customerDetail customHeader;
    customerVariables customer;

    void createTable();

    void choice();
    void displayData();
    void enterData();
    void updateData();
    void deleteData();
};

void hotelManager ::choice()
{
    int choosen = c.choose();
    if (choosen == 1)
    {
        hotelManager:: enterData();
    }
    else if (choosen == 2)
    {
        hotelManager:: displayData();
    }
    else if (choosen == 3)
    {
        hotelManager:: updateData();
    }
    else if (choosen == 4)
    {
        hotelManager:: deleteData();
    }
    else
    {
        std::cout << "Invalid Choice\n";
    }
}

void hotelManager::createTable()
{

    // Open Database
    rc = sqlite3_open("HotelDB.db", &db);
    if (rc)
    {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
    }
    else
    {
        std::cout << "Opened database successfully" << std::endl;
    }

    // Create table
    sql = "CREATE TABLE HotelData("
                                    "Phone_No INT PRIMARY KEY     NOT NULL,"
                                    "Name           CHAR(24)    NOT NULL,"
                                    "Address        CHAR(50),"
                                    "NoOfMembers    INT     NOT NULL,"
                                    "emailID        CHAR(25)    NOT NULL,"
                                    "roomNo         INT     NOT NULL,"
                                    "roomCharges    INT     NOT NULL);";
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &errMsg);
}

void hotelManager::enterData()
{
    rc = sqlite3_open("HotelDB.db", &db);
    if (rc)
    {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
    }
    else
    {
        std::cout << "Opened database successfully" << std::endl;
    }

    // Insert data
    customer.Phone_No = customHeader.Phone_No();
    customer.Name = customHeader.Name();
    customer.Address = customHeader.Address();
    customer.NoOfMembers = customHeader.NoOfMembers();
    customer.emailID = customHeader.emailID();
    customer.roomNo = customHeader.roomNo();
    customer.roomCharges = customHeader.roomCharges();

    sql = "INSERT INTO HotelData (Phone_No, Name, Address, NoOfMembers, emailID, roomNo, noOfRoomRegistered, roomCharges) VALUES (" + std::to_string(customer.Phone_No) + ", '" + customer.Name + "', '" + customer.Address + "', " + std::to_string(customer.NoOfMembers) + ", '" + customer.emailID + "', " + std::to_string(customer.roomNo) + ", " + std::to_string(customer.roomCharges) + ");";

    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &errMsg);

    if (rc != SQLITE_OK)
    {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
    else
    {
        std::cout << "Records created successfully" << std::endl;
    }

    choice();
}

void hotelManager::displayData()
{
    // Open Database
    rc = sqlite3_open("HotelDB.db", &db);
    if (rc)
    {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
    }
    else
    {
        std::cout << "Opened database successfully" << std::endl;
    }

    // Select data
    std::string sql = "SELECT * FROM HotelData;";
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &errMsg);

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

void hotelManager::updateData()
{
    std::string condition;
    std::cout << "Enter the condition for the WHERE clause (e.g., 'Age > 25'): ";
    std::getline(std::cin, condition);

    // Open Database
    rc = sqlite3_open("HotelDB.db", &db);
    if (rc)
    {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
    }
    else
    {
        std::cout << "Opened database successfully" << std::endl;
    }

    // Select data
    std::string sql = "SELECT * FROM HotelData WHERE " + condition + ";";
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &errMsg);

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

void hotelManager::deleteData()
{
    std::string condition;
    std::cout << "Enter the condition for the WHERE clause (e.g., 'Age > 25'): ";
    std::getline(std::cin, condition);

    // Open Database
    rc = sqlite3_open("HotelDB.db", &db);
    if (rc)
    {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
    }
    else
    {
        std::cout << "Opened database successfully" << std::endl;
    }

    // Delete data
    std::string sql = "DELETE FROM HotelData WHERE " + condition + ";";
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &errMsg);

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

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    for (int i = 0; i < argc; i++)
    {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main()
{

    hotelManager h;
    h.choice();

    return 0;
}