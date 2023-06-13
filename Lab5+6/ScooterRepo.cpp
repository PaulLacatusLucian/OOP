//
// Created by Paul on 5/10/2023.
//

#include "ScooterRepo.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <exception>

using namespace std;
using namespace Domain;
using namespace scooterRepo;


vector<Elektroscooter> ScooterRepo::readFromFile() {
    ifstream file("scooters.txt");
    vector<Elektroscooter> scootersVector;
    string line;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            istringstream iss(line);
            string modell, kilometerStr, inbetriebnahmedatum, letzterStandort, aktuellerZustand,id;

            if (getline(iss, id, ',') && getline(iss, kilometerStr, ',') && getline(iss, modell, ',') &&
                getline(iss, inbetriebnahmedatum, ',') && getline(iss, letzterStandort, ',') &&
                getline(iss, aktuellerZustand)) {
                int kilometer = stoi(kilometerStr);
                Elektroscooter aux(id, kilometer, modell, inbetriebnahmedatum, letzterStandort, aktuellerZustand);
                scootersVector.push_back(aux);
            }
        }
        file.close();
    } else {
        throw std::exception();
    }
    return scootersVector;
}


void ScooterRepo::writeToFile(const vector<Elektroscooter>& scootersVector) {
    ofstream file("scooters.txt");

    if (file.is_open()) {
        for (auto scooter : scootersVector) {
            file << scooter.get_id() << ", "
                 << scooter.get_kilometer() << ","
                 << scooter.get_modell() << ","
                 << scooter.get_inbetriebnahmedatum() << ","
                 << scooter.get_letzterStandort() << ","
                 << scooter.get_aktuellerZustand();
            file << endl;
        }
        file.close();
    } else {
        throw exception();
    }
}



void ScooterRepo::add(Elektroscooter &elektroscooter) {
    bool ok = false;
    auto auxVect = readFromFile();
    for (auto scooter: auxVect) {
        if (scooter.get_id() == elektroscooter.get_id()) {
            scooter = elektroscooter;
            ok = true;
        }
    }
    if (!ok)
        auxVect.push_back(elektroscooter);
    writeToFile(auxVect);
}

void ScooterRepo::deleteProd(Elektroscooter &elektroscooter) {
    bool deleted = false;
    auto auxVect = readFromFile();

    for (auto it = auxVect.begin(); it != auxVect.end(); ++it) {
        if (elektroscooter.get_id() == it->get_id()) {
            auxVect.erase(it);
            deleted = true;
            break;
        }
    }

    if (!deleted) {
        cerr << "No element was deleted";
    }

    writeToFile(auxVect);
}
