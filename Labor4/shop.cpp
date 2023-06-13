#include "Repo.h"
#include "RepositoryTests.h"
#include "ShopUI.h"
#include "ShopController.h"
#include "ControllerTests.h"
#include "memory"
using namespace Repository;
using namespace ProductNamespace;
using namespace ShopUINamespace;
using namespace ShopControllerNamespace;

int main() {
    RepositoryTests::testAll();
    ControllerTests::testAll();
    shared_ptr<Repo> repo = make_shared<Repo>();
    // creez 10 obiecte si le adaug in repository
    Fruit prod1("Apples", 1.99, "Fruit", "Spain", "30-04-2023", 10.0, "Apple Farms Inc.");
    Fruit prod2("Bananas", 0.99, "Fruit", "Mexico", "10-05-2023", 15.0, "Banana Co.");
    Fruit prod3("Milk", 2.49, "Dairy", "USA", "01-05-2023", 1.0, "Milk Farms LLC");
    Fruit prod4("Eggs", 1.79, "Dairy", "Canada", "25-04-2023", 12.0, "Egg Co.");
    Fruit prod5("Bread", 3.49, "Bakery", "France", "26-04-2023", 1.0, "Bread Inc.");
    Fruit prod6("Chicken", 5.99, "Meat", "Brazil", "03-05-2025", 2.5, "Chicken Farms Ltd.");
    Fruit prod7("Salmon", 9.99, "Fish", "Norway", "15-05-2023", 0.5, "Salmon Inc.");
    Fruit prod8("Pasta", 1.29, "Pasta", "Italy", "01-06-2023", 2.0, "Pasta Co.");
    Fruit prod9("Rice", 2.99, "Grains", "China", "01-07-2023", 5.0, "Rice Farms Ltd.");
    Fruit prod10("Orange Juice", 2.49, "Beverage", "USA", "30-04-2023", 1.5, "Orange Juice Co.");
    repo->add(prod1);
    repo->add(prod2);
    repo->add(prod3);
    repo->add(prod4);
    repo->add(prod5);
    repo->add(prod6);
    repo->add(prod7);
    repo->add(prod8);
    repo->add(prod9);
    repo->add(prod10);
    // ShopController-ul primeste ca parametru un repository drept smartPointer
    shared_ptr<ShopController> controller = make_shared<ShopController>(repo);
    // ShopUI-ul primeste ca parametru un controller drept smartPointer
    ShopUI ui(controller);
    ui.start();

}
