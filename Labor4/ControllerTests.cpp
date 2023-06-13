//
// Created by Paul on 5/4/2023.
//

#include "ControllerTests.h"
#include "Fruit.h"
#include "Repo.h"
#include "ShopController.h"
#include "memory"
#include "cassert"

using namespace std;
using namespace ShopControllerNamespace;
using namespace Repository;

void testRemove1() {
    Fruit testProduct("Orange Juice", 2.49, "Beverage", "USA", "30-04-2023", 1.5, "Orange Juice Co.");
    shared_ptr<Repo> testingRepo = make_shared<Repo>();
    testingRepo->add(testProduct);
    shared_ptr<ShopController> testingController = make_shared<ShopController>(testingRepo);
    assert (testingRepo->size() == 1);
}

void ControllerTests::testAll() {
    testRemove1();
}