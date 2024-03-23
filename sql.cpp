#include <iostream>
#include <sqlite3.h>

using namespace std;

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    for (int i = 0; i < argc; i++)
    {
        cout << azColName[i] << ": " << (argv[i] ? argv[i] : "NULL") << endl;
    }
    cout << endl;
    return 0;
}

int main()
{
    sqlite3 *db;
    char *errMsg = 0;
    int rc;

    // Open Database
    rc = sqlite3_open("test.db", &db);

    if (rc)
    {
        cerr << "Can't open database: " << sqlite3_errmsg(db) << endl;
        return (0);
    }
    else
    {
        cout << "Opened database successfully" << endl;
    }

    // Create table
    string sql = "CREATE TABLE COMPANY("
                "ID INT PRIMARY KEY     NOT NULL,"
                "NAME           TEXT    NOT NULL,"
                "AGE            INT     NOT NULL,"
                "ADDRESS        CHAR(50),"
                "SALARY         REAL );";
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &errMsg);

    if (rc != SQLITE_OK)
    {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    }
    else
    {
        cout << "Table created successfully" << endl;
    }

    // Insert data
    int id, age;
    string name, address;
    double salary;

    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Age: ";
    cin >> age;
    cout << "Enter Address: ";
    cin >> address;
    cout << "Enter Salary: ";
    cin >> salary;

    sql = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "
          "VALUES (" + to_string(id) + ", '" + name + "', " + to_string(age) + ", '" + address + "', " + to_string(salary) + ");";

    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &errMsg);

    if (rc != SQLITE_OK)
    {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    }
    else
    {
        cout << "Records created successfully" << endl;
    }

    // Display data
    sql = "SELECT * from COMPANY";
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &errMsg);

    if (rc != SQLITE_OK)
    {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    }
    else
    {
        cout << "Operation done successfully" << endl;
    }

    sqlite3_close(db);
    return;
}