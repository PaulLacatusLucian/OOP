//
// Created by Paul on 5/10/2023.
//

#include "Elektroscooter.h"
#include <iostream>

namespace Domain {

    Date Elektroscooter::convertDate() {
        Date dateInt{};
        string date = this->inbetriebnahmedatum;
        string dayStr = date.substr(1, 2);
        string monthStr = date.substr(4, 2);
        string yearStr = date.substr(7, 4);

        dateInt.day = stoi(dayStr);
        dateInt.month = stoi(monthStr);
        dateInt.year = stoi(yearStr);

        return dateInt;
    }

    void Elektroscooter::printScooter() {
        std::cout << "\nScooters ID: " << id << " Kilometers: " << kilometer << " Modell:" << modell
                  << "\nletzter Standort: " <<
                  letzterStandort << " Status:" << aktuellerZustand << "\nInbetriebnahmedatum:" << inbetriebnahmedatum
                  << endl;
    }

} // Domain