#ifndef HOTELMANAGE_H
#define HOTELMANAGE_H

#include "choice.h"
#include "customerDetail.h"
#include<sqlite3.h>
#include<string>

struct customerVariables {
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

class HotelManager {
    public:
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

#endif // HOTELMANAGE_H