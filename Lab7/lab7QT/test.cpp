#include "ScooterController.h"
#include "Repository.h"
#include "cassert"
#include <iostream>

using namespace Repository;
using namespace Controller;
using namespace std;

void testRepository() {
    cout << "Testing CSV-Repository!" << endl;
    Repository::CSVFileRepository csvRepo();
    auto listOfScooters = csvRepo.readFromFile();
    assert (!listOfScooters.empty());
    assert (listOfScooters.size() == 10);

    Domain::Elektroscooter newScooter("NEW", 28, "NEWMODELL", "28-07-2028", "-", "geparkt");
    csvRepo.create(newScooter);
    assert (csvRepo.searchForID("NEW"));

    csvRepo.remove(newScooter);
    assert(!csvRepo.searchForID("NEW"));

    cout << "Test CSV-Repository passed!" << endl;

    cout << "Testing inMemoryRepository-Repository!" << endl;
    Repository::InMemoryRepository inMemoryRepo;

    auto listOfScooters1 = inMemoryRepo.readFromFile();
    assert(listOfScooters1.size() == 10);

    Domain::Elektroscooter newScooter2("NEW", 28, "NEWMODELL", "28-07-2028", "-", "geparkt");
    inMemoryRepo.create(newScooter2);
    assert(inMemoryRepo.searchForID("NEW"));

    inMemoryRepo.remove(newScooter2);
    assert(!inMemoryRepo.searchForID("NEW"));

    cout << "Test inMemoryRepository-Repository passed!" << endl;
    cout << endl;
};

void testScooterController() {
    ///de facut !!!
    cout << "Test Controller started" << endl;
    cout<<"Test Controller passed!" << endl;
}



void testAll() {
    testScooterController();
    testRepository();
}