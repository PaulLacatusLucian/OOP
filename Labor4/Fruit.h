//
// Created by Paul on 4/14/2023.
//

#include <string>

using namespace std;

#ifndef LABOR4_FRUIT_H
#define LABOR4_FRUIT_H
namespace ProductNamespace {

    struct Date {
        int day;
        int month;
        int year;
    };

    class Fruit {
    private:
        string name, origin, expiryDate, manufacturer, typ;
        float quantity, price;

    public:
        Fruit(string name, float price, string typ, string origin, string expDate, float quant, string manu) {
            if (quant < 0 || price < 0)
                throw exception();
            else {
                this->quantity = quant;
                this->price = price;
            }
            if (name != " " && origin != " " && expDate != " " && manu != " " && typ != " ") {
                this->name = name;
                this->origin = origin;
                this->expiryDate = expDate;
                this->typ = typ;
                this->manufacturer = manu;
            } else
                throw exception();


        }

        string get_name() {
            return this->name;
        }

        string get_type() {
            return this->typ;
        }

        string get_origin() {
            return this->origin;
        }

        string get_expDate() {
            return this->expiryDate;
        }

        string get_manufacturer() {
            return this->manufacturer;
        }

        string get_typ() {
            return this->typ;
        }

        float get_price() const {
            return this->price;
        }

        float get_quantity() const {
            return this->quantity;
        }

        Fruit &operator=(const Fruit &other) {
            if (this != &other) {
                name = other.name;
                origin = other.origin;
                expiryDate = other.expiryDate;
                manufacturer = other.manufacturer;
                typ = other.typ;
                quantity = other.quantity;
                price = other.price;
            }
            return *this;
        }

        void printForCustomer();

        void printForEmplyee();

        Date convertDate();

    };
}

#endif //LABOR4_FRUIT_H
