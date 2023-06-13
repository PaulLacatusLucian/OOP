//
// Created by Paul on 4/14/2023.
//
#include "Fruit.h"
#include <vector>

using namespace std;
using namespace ProductNamespace;

#ifndef LABOR4_REPO_H
#define LABOR4_REPO_H

namespace Repository {
    class Repo {
    private:
        vector<Fruit> repo;

    public:
        void add(Fruit& prod);

        void deleteProd(Fruit& prod);

        int size();

        vector<Fruit> getAll();

        Repo& operator=(const Repo& other) {
            if (this != &other) {
                repo = other.repo;
            }
            return *this;
        }
    };
}

#endif //LABOR4_REPO_H