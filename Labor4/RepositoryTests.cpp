//
// Created by Paul on 4/26/2023.
//

#include "RepositoryTests.h"
#include "Fruit.h"
#include "Repo.h"
#include <iostream>
#include "cassert"
using namespace Repository;

void testAdd() {
    // add a simple product
    Fruit testProduct("Orange Juice", 2.49, "Beverage", "USA", "30-04-2023", 1.5, "Orange Juice Co.");
    Repo testingRepo;
    assert (testingRepo.size() == 0);
    testingRepo.add(testProduct);
    assert (testingRepo.size() == 1);

    // overwrite the product
    for (int i = 0; i < 50; i++)
        testingRepo.add(testProduct);
    assert (testingRepo.size() == 1);
    std::cout << "Test add passed \n";
}

void testRemove() {
    // remove a product
    Fruit testProduct1("Orange Juice", 2.49, "Beverage", "USA", "30-04-2023", 1.5, "Orange Juice Co.");
    Repo repoAux;
    assert(repoAux.size() == 0);
    repoAux.add(testProduct1);
    assert(repoAux.size() == 1);
    repoAux.deleteProd(testProduct1);
    assert(repoAux.size() == 0);

    // remove a inexistent product
    try {
        repoAux.deleteProd(testProduct1);
        cerr << "Test Failed: Exception not thrown" << endl;
    }
    catch (const std::exception &e) {
        std::cout << "Test remove passed \n";
        // Exception was thrown, test passed
        return;
    }
}

void testSize() {
    Fruit testProduct1("Orange Juice", 2.49, "Beverage", "USA", "30-04-2023", 1.5, "Orange Juice Co.");
    Repo repoAux;
    assert(repoAux.size() == 0);
    repoAux.add(testProduct1);
    assert(repoAux.size() == 1);
    repoAux.deleteProd(testProduct1);
    assert(repoAux.size() == 0);
    std::cout << "Test size passed \n";

}


void RepositoryTests::testAll() {
    testAdd();
    testRemove();
    testSize();
}
