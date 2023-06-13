//
// Created by Paul on 5/10/2023.
//

#ifndef LAB5_SCOOTERCONTROLLER_H
#define LAB5_SCOOTERCONTROLLER_H

#include "Repository.h"
#include "memory"

using namespace Repository;

namespace Controller {

    class ScooterController {
    private:
        unique_ptr<Repository::CrudRepository> repo;

    public:
        ScooterController() = default;

        ScooterController(int &repoType);


        vector<Domain::Elektroscooter> standOrtSuche(const string &ort);

        vector<Domain::Elektroscooter> filterAlter(const string &date);

        vector<Domain::Elektroscooter> filterKilometer(int kilometer);

        vector<Domain::Elektroscooter> nachAlterSortieren();

        bool reservieren(const string& id);

        bool update(const string &id, int kilometer, const string& modell,
                    const string &inbetriebnahmedatum, const string &lezterStandort,
                    const string &actuellerZustand);

        void add(const string &id, int kilometer, const string& modell, const string &inbetriebnahmedatum,
                 const string &lezterStandort, const string &actuellerZustand);

        void remove(const string &id);

        bool checkID(const string& id);

        vector<Domain::Elektroscooter> getReservierteScooters();

        vector<Domain::Elektroscooter> getAll();

        bool parkScooter(const string& id);

        vector<Domain::Elektroscooter> getFreeScooters();
    };


} // Controller

#endif //LAB5_SCOOTERCONTROLLER_H
