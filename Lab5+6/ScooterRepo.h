//
// Created by Paul on 5/10/2023.
//

#ifndef LAB5_SCOOTERREPO_H
#define LAB5_SCOOTERREPO_H

#include "Elektroscooter.h"
#include "vector"

using namespace Domain;

namespace scooterRepo {

    class ScooterRepo {
    private:
        vector<Elektroscooter> scootersVect;

    public:
        ScooterRepo() = default;;

        void writeToFile(const vector<Elektroscooter> &scootersVect);

        vector<Elektroscooter> readFromFile();

        void add(Elektroscooter &elektroScooter);

        void deleteProd(Elektroscooter &elektroScooter);
    };
}

#endif //LAB5_SCOOTERREPO_H
