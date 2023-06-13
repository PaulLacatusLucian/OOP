//
// Created by Paul on 5/10/2023.
//

#include "ScooterController.h"
#include <iostream>

using namespace scooterRepo;
using namespace Domain;

namespace scooterController {

    void scooterController::ScooterController::standOrtSuche(const string &ort) {
        for (auto scooter: repo->readFromFile()) {
            string objectName = scooter.get_letzterStandort();
            auto checkIfSubstring = objectName.find(ort);
            if (checkIfSubstring != std::string::npos) {
                scooter.printScooter();
            }
        }
    }

    void scooterController::ScooterController::nachAlterSortieren() {
        // sortam toate produsele dupa daca de expirare
        auto aux = repo->readFromFile();
        for (int i = 0; i < aux.size(); i++) {
            for (int j = i + 1; j < aux.size(); j++) {
                Date date1 = aux[i].convertDate();
                Date date2 = aux[j].convertDate();
                if (date1.year > date2.year ||
                    (date1.year == date2.year && date1.month > date2.month) ||
                    (date1.year == date2.year && date1.month == date2.month && date1.day > date2.day)) {
                    auto aux2 = aux[i];
                    aux[i] = aux[j];
                    aux[j] = aux2;
                }
            }
        }
        for (auto scooter:aux)
            scooter.printScooter();
    }

    void scooterController::ScooterController::filterAlter(const string &date) {
        auto aux = repo->readFromFile();
        for (auto & i : aux) {
            Date date1 = i.convertDate();
            Date datefin{};
            datefin.day = stoi(date.substr(0, 2));
            datefin.month = stoi(date.substr(3, 2));
            datefin.year = stoi(date.substr(6, 4));
            if (date1.year <= datefin.year || (date1.month <= datefin.month && date1.year == datefin.year) ||
                (date1.day <= datefin.day && date1.year == datefin.year && date1.month == datefin.month))
                i.printScooter();
        }
    }

    void scooterController::ScooterController::filterKilometer(int kilometer) {
        auto aux = repo->readFromFile();
        for (int i = 0; i < aux.size(); i++) {
            if (aux[i].get_kilometer() >= kilometer)
                aux[i].printScooter();
        }
    }

    void scooterController::ScooterController::reservieren(const string &id) {
        auto aux = repo->readFromFile();
        for (auto &i: aux) {
            if (i.get_id() == id) {
                if (i.get_aktuellerZustand() == " reserviert") {
                    std::cout << "The scooter is already in use\n";
                } else {
                    i.set_aktuellerZustand(" reserviert");
                    repo->writeToFile(aux);
                }
            }
        }
    }

    void scooterController::ScooterController::update(const string &id, int kilometer, const string &modell,
                                                      const string &inbetriebnahmedatum, const string &lezterStandort,
                                                      const string &actuellerZustand) {
        auto aux = repo->readFromFile();
        for (int i = 0; i < aux.size() - 1; i++) {
            if (aux[i].get_id() == id) {
                Domain::Elektroscooter snou(id, kilometer, modell, inbetriebnahmedatum, lezterStandort,
                                            actuellerZustand);
                aux[i] = snou;
                repo->writeToFile(aux);
            }
        }
    }

    void scooterController::ScooterController::add(const string &id, int kilometer, const string &modell,
                                                   const string &inbetriebnahmedatum, const string &lezterStandort,
                                                   const string &actuellerZustand) {
        Elektroscooter aux(id, kilometer, modell, inbetriebnahmedatum, lezterStandort, actuellerZustand);
        repo->add(aux);
    }

    void scooterController::ScooterController::remove(const string &id) {
        auto aux = repo->readFromFile();
        for (auto scooter: aux)
            if (scooter.get_id() == id)
                repo->deleteProd(scooter);
    }

    bool scooterController::ScooterController::checkID(const string& id) {
        auto aux = repo->readFromFile();
        for (auto scooter: aux)
            if (scooter.get_id() == id)
                return true;
        return false;
    }
} // scooterController