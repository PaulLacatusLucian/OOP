//
// Created by Paul on 5/10/2023.
//

#ifndef LAB5_SCOOTERCONTROLLER_H
#define LAB5_SCOOTERCONTROLLER_H

#include "ScooterRepo.h"
#include "memory"

using namespace scooterRepo;

namespace scooterController {

    class ScooterController {
    private:
        shared_ptr<scooterRepo::ScooterRepo> repo;

    public:
        ScooterController(shared_ptr<ScooterRepo> otherRepo) {
            repo = otherRepo;
        }

        void standOrtSuche(const string &ort);

        void filterAlter(const string &date);

        void filterKilometer(int kilometer);

        void nachAlterSortieren();

        void reservieren(const string& id);

        void update(const string &id, int kilometer, const string& modell,
                    const string &inbetriebnahmedatum, const string &lezterStandort,
                    const string &actuellerZustand);

        void add(const string &id, int kilometer, const string& modell, const string &inbetriebnahmedatum,
                 const string &lezterStandort, const string &actuellerZustand);

        void remove(const string &id);

        bool checkID(const string& id);
    };


} // scooterController

#endif //LAB5_SCOOTERCONTROLLER_H
