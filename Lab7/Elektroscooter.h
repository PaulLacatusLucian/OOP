//
// Created by Paul on 5/10/2023.
//

#ifndef LAB5_ELEKTROSCOOTER_H
#define LAB5_ELEKTROSCOOTER_H

#include <cstdio>
#include <string>
#include <stdexcept>

using namespace std;

struct Date {
    int day;
    int month;
    int year;
};


namespace Domain {

    class Elektroscooter {
    private:
        int kilometer;
        string modell, inbetriebnahmedatum, letzterStandort, id;
        string aktuellerZustand;

    public:



        Elektroscooter(const string& id, int km, const string& modell1, const string& inbetribnahmedatum1, const string& letzterStandort1,
                       const string& aktuellerZustand1) {
            if (id.length() > 3 || typeid(id) != typeid(string)) {
                throw invalid_argument("Invalid id: Empty string");
            } else {
                this->id = id;
            }
            if (km < 0 || typeid(km) != typeid(int)) {
                throw invalid_argument("Invalid kilometer: Negative value");
            } else {
                this->kilometer = km;
            }
            if (typeid(modell1) != typeid(string)) {
                throw invalid_argument("Invalid modell: Empty string");
            } else {
                this->modell = modell1;
            }
            if (typeid(inbetribnahmedatum1) != typeid(string) || !isValidDate(inbetribnahmedatum1)) {
                throw invalid_argument("Invalid inbetribnahmedatum: Empty string");
            } else {
                this->inbetriebnahmedatum = inbetribnahmedatum1;
            }
            if (typeid(letzterStandort1) != typeid(string)) {
                throw invalid_argument("Invalid letzterStandort: Empty string");
            } else {
                this->letzterStandort = letzterStandort1;
            }
            if (typeid(aktuellerZustand1) != typeid(string)) {
                throw invalid_argument("Invalid aktuellerZustand: Empty string");
            } else {
                this->aktuellerZustand = aktuellerZustand1;
            }
        };

        Elektroscooter &operator=(const Elektroscooter &other) {
            if (this != &other) {
                id = other.id;
                kilometer = other.kilometer;
                modell = other.modell;
                inbetriebnahmedatum = other.inbetriebnahmedatum;
                letzterStandort = other.letzterStandort;
                aktuellerZustand = other.aktuellerZustand;
            }
            return *this;
        }

        Date convertDate() const;

        string get_id() const {
            return this->id;
        }

        int get_kilometer() const {
            return this->kilometer;
        }

        string get_modell() const {
            return this->modell;
        }

        string get_inbetriebnahmedatum() const {
            return this->inbetriebnahmedatum;
        }

        string get_letzterStandort() const {
            return this->letzterStandort;
        }

        string get_aktuellerZustand() const {
            return this->aktuellerZustand;
        }

        void set_aktuellerZustand(string newZustand) {
            this->aktuellerZustand = newZustand;
        }

        bool isValidDate(const string &dateStr);
    };

}

#endif //LAB5_ELEKTROSCOOTER_H
