#include "choice.h"
#include "customerDetail.h"

#include <iostream>
#include <sqlite3.h>
#include <string>

// Use constant variables for database file extension and default column sizes
const std::string DB_EXTENSION = ".db";
const int NAME_SIZE = 24;
const int ADDRESS_SIZE = 50;
const int EMAIL_SIZE = 25;

// Forward declaration of callback function
static int callback(void *NotUsed, int argc, char **argv, char **azColName);

struct CustomerVariables {
    long long int Phone_No;
    std::string Name;
    std::string Address;
    int NoOfMembers;
    std::string emailID;

    int roomNo;
    int noOfRoomRegistered;
    int roomCharges;
};

class HotelManager {
public:
    void start();

private:
    sqlite3 *db;
    int rc;
    std::string tableName;

    void createTable();
    void enterData();
    void displayData();
    void handleSQLError(const char *errMsg);
};

void HotelManager::start() {
    std::cout << "Enter the table name: ";
    std::getline(std::cin, tableName);
    choice c;
    int choice = c.choose();

    switch (choice) {
        case 1:
            enterData();
            break;
        case 2:
            displayData();
            break;
        case 3:
            createTable();
            break;
        default:
            std::cout << "Invalid Choice\n";
            break;
    }
}

void HotelManager::createTable() {
    rc = sqlite3_open((tableName + DB_EXTENSION).c_str(), &db);
    if (rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    std::string sql = "CREATE TABLE " + tableName + "("
                      "Phone_No INT PRIMARY KEY NOT NULL,"
                      "Name CHAR(" + std::to_string(NAME_SIZE) + ") NOT NULL,"
                      "Address CHAR(" + std::to_string(ADDRESS_SIZE) + "),"
                      "NoOfMembers INT NOT NULL,"
                      "emailID CHAR(" + std::to_string(EMAIL_SIZE) + ") NOT NULL,"
                      "roomNo INT NOT NULL,"
                      "noOfRoomRegistered INT NOT NULL,"
                      "roomCharges INT NOT NULL);";
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, nullptr);
    if (rc != SQLITE_OK) {
        handleSQLError(sqlite3_errmsg(db));
    } else {
        std::cout << "Table created successfully" << std::endl;
    }
}

void HotelManager::enterData() {
    // Implementation remains the same
}

void HotelManager::displayData() {
    // Implementation remains the same
}

void HotelManager::handleSQLError(const char *errMsg) {
    std::cerr << "SQL error: " << errMsg << std::endl;
    sqlite3_free(const_cast<char *>(errMsg)); // Free error message
    sqlite3_close(db); // Close database connection
}

static int callback(void *, int argc, char **argv, char **) {
    for (int i = 0; i < argc; i++) {
        printf("%s = %s\n", argv[i * 2], argv[i * 2 + 1] ? argv[i * 2 + 1] : "NULL");
    }
    printf("\n");
    return 0;
}

int main() {
    HotelManager h;
    h.start();
    return 0;
}
