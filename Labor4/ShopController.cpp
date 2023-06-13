//
// Created by Paul on 4/16/2023.
//

#include "ShopController.h"
#include "Repo.h"
#include "Fruit.h"
#include "iostream"
using namespace Repository;
using namespace ShopControllerNamespace;

using namespace std;

void ShopController::printAllObjects(int rol) {
    // printam toate obiectele in functie de rolul utilizatorului
    for (auto product:repo->getAll())
        if (rol == 0)
            product.printForCustomer();
        else
            product.printForEmplyee();
}

void ShopController::searchForObject(const string &name, int rol) {
    int checkIfSubstring;
    auto aux = repo->getAll();
    // verificam daca am primit un string gol drept input
    if (name.empty()) {
        // in caz afirmativ sortam toate produsele in ordine alfabetica
       for (int i = 0; i < aux.size() - 1; i++) {
            for (int j = i + 1; j < aux.size(); j++) {
                if (aux[i].get_name() > aux[j].get_name()) {
                    auto aux2 = aux[i];
                    aux[i] = aux[j];
                    aux[j] = aux2;
                }
            }
        }
        // dupa sortare le afisam
        for (auto product: repo->getAll()) {
            if (rol == 0)
                product.printForCustomer();
            else
                product.printForEmplyee();
        }
    } else {
        // altfel verificam daca numele obiectului cautat coincide cu numele obiectelor noastre
        for (auto product: repo->getAll()) {
            string objectName = product.get_name();
            checkIfSubstring = objectName.find(name);
            if (checkIfSubstring != std::string::npos) {
                if (rol == 0)
                    product.printForCustomer();
                else
                    product.printForEmplyee();
            }
        }
    }
}


void ShopController::addProduct() {
    // citim datele necesare
    string name, origin, typ, exprDate, manu;
    float quant, price;
    cout << "Give name: ";
    cin >> name;
    cout << "Give origin: ";
    cin >> origin;
    cout << "Give type: ";
    cin >> typ;
    cout << "Give expDate: ";
    cin >> exprDate;
    cout << "Give manufacturer: ";
    cin >> manu;
    cout << "Give quantity: ";
    cin >> quant;
    cout << "Give price: ";
    cin >> price;
    // creem si adaugam obiectul
    Fruit aux(name, price, typ, origin, exprDate, quant, manu);
    repo->add(aux);
}

void ShopController::removeProduct() {
    string name;
    // citim numele sau producatroul obiectului pe care vrem sa il stergem
    cout << "Give the name of the object or the manufacturer: ";
    cin >> name;
    for (auto product: repo->getAll())
        // daca il gasim il stergem din lista
        if (name == product.get_manufacturer() || name == product.get_name())
            repo->deleteProd(product);
}

void ShopController::expDateCheck(const std::string &finalDate) {
    // sustragem datele de care avem nevoie
    string finalDay = finalDate.substr(0, 2);
    string finalMonth = finalDate.substr(3, 2);
    string finalYear = finalDate.substr(6, 4);

    // le transformam in numere intregi
    int fDay = stoi(finalDay);
    int fMonth = stoi(finalMonth);
    int fYear = stoi(finalYear);
    for (auto product: repo->getAll()) {
        // comparam fiecare pentru a le putea afisa in functie de data de expirare
        Date productDate = product.convertDate();
        if (productDate.year < fYear)
            product.printForEmplyee();
        else if (productDate.month < fMonth && productDate.year == fYear)
            product.printForEmplyee();
        else if (productDate.day < fDay && productDate.year == fYear && productDate.month == fMonth)
            product.printForEmplyee();
    }
}

void ShopController::sortedByExp() {
    // sortam toate produsele dupa daca de expirare
    auto aux = repo->getAll();
    for (int i = 0; i < repo->size() - 1; i++) {
        for (int j = i + 1; j < repo->size(); j++) {
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

    for (auto prod : repo->getAll()) {
        prod.printForEmplyee();
    }
}

