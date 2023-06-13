//
// Created by Paul on 4/18/2023.
//

#include "Fruit.h"
#include <iostream>
using namespace ProductNamespace;

void Fruit::printForEmplyee() {
    cout << "\nName: " << this->get_name() << "   Type: " << this->get_typ() << "   Price: "
         << this->get_price() << " Euro" <<endl
         << "Expiring date: " << this->get_expDate() << "   Origin: " << this->get_origin()
         << "   Quantity: "
         << this->get_quantity() << "   Manufacturer: " << this->get_manufacturer() << endl;
}

void Fruit::printForCustomer() {
    cout << "\nName: " << this->get_name() << "   Type: " << this->get_typ() << "   Price: "
         << this->get_price() << " Euro" << endl
         << "Expiring date: " << this->get_expDate() << endl;
}

Date Fruit::convertDate() {
    Date dateInt{};
    string date = this->get_expDate();
    string dayStr = date.substr(0, 2);
    string monthStr = date.substr(3, 2);
    string yearStr = date.substr(6, 4);

    dateInt.day = stoi(dayStr);
    dateInt.month = stoi(monthStr);
    dateInt.year = stoi(yearStr);

    return dateInt;
}
