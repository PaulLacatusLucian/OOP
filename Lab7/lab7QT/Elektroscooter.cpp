//
// Created by Paul on 5/10/2023.
//

#include "Elektroscooter.h"
#include <iostream>

namespace Domain {

    Date Elektroscooter::convertDate() const {
        Date dateInt{};
        string date = this->inbetriebnahmedatum;
        string dayStr = date.substr(0, 2);
        string monthStr = date.substr(3, 2);
        string yearStr = date.substr(6, 4);

        dateInt.day = stoi(dayStr);
        dateInt.month = stoi(monthStr);
        dateInt.year = stoi(yearStr);

        return dateInt;
    }



    bool Elektroscooter::isValidDate(const string &dateStr) {
        // dd/mm/yyyy also len 10
        if (dateStr.length() != 10) {
            return false;
        }

        string dayStr = dateStr.substr(0, 2);
        string monthStr = dateStr.substr(3, 2);
        string yearStr = dateStr.substr(6, 4);

        int day, month, year;

        day = stoi(dayStr);
        month = stoi(monthStr);
        year = stoi(yearStr);

        if (month < 1 || month > 12) {
            return false;
        }

        int daysInMonth = 31;

        if (month == 2) {//februrarie
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {//an bisect
                daysInMonth = 29;
            } else {
                daysInMonth = 28;
            }
        } else if (month == 4 || month == 6 || month == 9 || month == 11) {
            daysInMonth = 30;
        }

        return day >= 1 && day <= daysInMonth;
    }
} // Domain