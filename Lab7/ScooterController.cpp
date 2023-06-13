#include "ScooterController.h"
#include <iostream>
#include <algorithm>

using namespace Repository;
using namespace Domain;

namespace Controller {

    ScooterController::ScooterController(int &repoType) {
        if (repoType == 0)
            repo = make_unique<Repository::InMemoryRepository>();
        else {
            string fileName;
            cout << "Give a file name: ";
            cin >> fileName;
            if (fileName != "scooters.csv")
                throw invalid_argument("This CSV-File does not exist!");
            repo = make_unique<Repository::CSVFileRepository>();
        }
    }

    vector<Domain::Elektroscooter> ScooterController::getReservierteScooters() {
        return repo->getReservierteScooters();
    }

    vector<Domain::Elektroscooter> ScooterController::standOrtSuche(const string &ort) {
        vector<Domain::Elektroscooter> result;
        for (const auto &scooter: repo->readFromFile()) {
            string objectName = scooter.get_letzterStandort();
            auto checkIfSubstring = objectName.find(ort);
            if (checkIfSubstring != std::string::npos) {
                result.push_back(scooter);
            }
        }
        return result;
    }

    vector<Domain::Elektroscooter> ScooterController::nachAlterSortieren() {
        vector<Domain::Elektroscooter> result = repo->readFromFile();
        std::sort(result.begin(), result.end(), [](const Domain::Elektroscooter &a, const Domain::Elektroscooter &b) {
            Date date1 = a.convertDate();
            Date date2 = b.convertDate();
            if (date1.year != date2.year)
                return date1.year < date2.year;
            if (date1.month != date2.month)
                return date1.month < date2.month;
            return date1.day < date2.day;
        });
        return result;
    }

    vector<Domain::Elektroscooter> ScooterController::filterAlter(const string &date) {
        vector<Domain::Elektroscooter> result;
        Date datefin{};
        datefin.day = stoi(date.substr(0, 2));
        datefin.month = stoi(date.substr(3, 2));
        datefin.year = stoi(date.substr(6, 4));
        for (auto &scooter: repo->readFromFile()) {
            Date date1 = scooter.convertDate();
            if ((date1.year < datefin.year) ||
                (date1.year == datefin.year && date1.month < datefin.month) ||
                (date1.year == datefin.year && date1.month == datefin.month && date1.day <= datefin.day)) {
                result.push_back(scooter);
            }
        }
        return result;
    }

    vector<Domain::Elektroscooter> ScooterController::filterKilometer(int kilometer) {
        vector<Domain::Elektroscooter> result;
        for (const auto &scooter: repo->readFromFile()) {
            if (scooter.get_kilometer() >= kilometer) {
                result.push_back(scooter);
            }
        }
        return result;
    }

    bool ScooterController::reservieren(const string &id) {
        vector<Domain::Elektroscooter> scooters = repo->readFromFile();
        for (auto &scooter: scooters) {
            if (scooter.get_id() == id) {
                if (scooter.get_aktuellerZustand() == "reserviert") {
                    return false;
                } else {
                    scooter.set_aktuellerZustand("reserviert");
                    repo->writeToFile(scooters);
                    repo->addToReservierteScooters(id);
                    return true;
                }
            }
        }
        return false;
    }

    bool ScooterController::update(const string &id, int kilometer, const string &modell,
                                   const string &inbetriebnahmedatum, const string &letzterStandort,
                                   const string &aktuellerZustand) {
        vector<Domain::Elektroscooter> scooters = repo->readFromFile();
        for (int i = 0; i < scooters.size(); i++) {
            if (scooters[i].get_id() == id) {
                Domain::Elektroscooter snou(id, kilometer, modell, inbetriebnahmedatum, letzterStandort,
                                            aktuellerZustand);
                scooters[i] = snou;
                repo->writeToFile(scooters);
                return true;
            }
        }
        return false;
    }

    void ScooterController::add(const string &id, int kilometer, const string &modell,
                                const string &inbetriebnahmedatum, const string &letzterStandort,
                                const string &aktuellerZustand) {
        if (kilometer < 0 || !(typeid(id) == typeid(string)) || !(typeid(modell) == typeid(string)) ||
            !(typeid(inbetriebnahmedatum) == typeid(string)) || !(typeid(letzterStandort) == typeid(string)) ||
            !(typeid(aktuellerZustand) == typeid(string)))
            throw invalid_argument("INVALID ARGUMENT!");
        Domain::Elektroscooter aux(id, kilometer, modell, inbetriebnahmedatum, letzterStandort, aktuellerZustand);
        repo->create(aux);
    }

    void ScooterController::remove(const string &id) {
        vector<Domain::Elektroscooter> scooters = repo->readFromFile();
        for (int i = 0; i < scooters.size(); i++) {
            if (scooters[i].get_id() == id) {
                repo->remove(scooters[i]);
                break;
            }
        }
    }

    bool ScooterController::checkID(const string &id) {
        vector<Domain::Elektroscooter> scooters = repo->readFromFile();
        for (const auto &scooter: scooters) {
            if (scooter.get_id() == id) {
                return true;
            }
        }
        return false;
    }

    vector<Domain::Elektroscooter> ScooterController::getAll() {
        return repo->readFromFile();
    }

    bool ScooterController::parkScooter(const string &id) {
        auto allScooters = this->getAll();
        for (auto scooter: allScooters)
            if (scooter.get_id() == id) {
                if (scooter.get_aktuellerZustand() == "geparkt")
                    return false;
                else {
                    this->update(id, scooter.get_kilometer(), scooter.get_modell(), scooter.get_inbetriebnahmedatum(), scooter.get_letzterStandort(), "geparkt");
                    return true;
                }
            }
        return false;
    }

    vector<Domain::Elektroscooter> ScooterController::getFreeScooters() {
        vector<Domain::Elektroscooter> result;
        for (const auto& scooter: repo->readFromFile()) {
            if (scooter.get_aktuellerZustand() == "geparkt") {
                result.push_back(scooter);
            }
        }
        return result;
    }
} // Controller