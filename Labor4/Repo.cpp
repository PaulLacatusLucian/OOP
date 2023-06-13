//
// Created by Paul on 4/14/2023.
//

#include "Repo.h"
#include <iostream>

using namespace std;
using namespace Repository;


void Repo::add(Fruit &prod) {
    bool check = false;
    // verificam daca produsul se afla deja in lista
    for (auto &prod2: repo) {
        if (prod.get_name() == prod2.get_name()) {
            // daca se afla deja in lista ii schimbam datele
            check = true;
            prod2 = prod;
            break;
        }
    }
    // daca nu se afla il adaugam
    if (!check)
        repo.push_back(prod);
}

void Repo::deleteProd(Fruit &prod) {
    bool deleted = false;

    // cautam produsul in lista folosind iteratorul
    for (auto it = repo.begin(); it != repo.end(); ++it) {
        if (prod.get_name() == it->get_name()) {
            // daca il gasim il stergem si modificam semaforul
            repo.erase(it);
            deleted = true;
            break;
        }
    }

    // daca semaforul nu a fost modificat atunci aruncam o exceptie
    if (!deleted) {
//        cerr << "No element was deleted";
        throw exception();
    }
}

vector<Fruit> Repo::getAll() {
    // returnam intreg repository-ul
    return repo;
}

int Repo::size(){
    // returnam lungimea
    return repo.size();
}