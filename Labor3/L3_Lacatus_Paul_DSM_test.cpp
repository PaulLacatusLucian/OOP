#include "L3_Lacatus_Paul_DSM.h"
#include <iostream>
#include "cassert"

using namespace std;

//erste Konstruktor
void testCreate() {
    cout << "Test create mit 1 Konstruktor" << endl;
    DSM s(4);
    assert(s.size() == 4);
}

//zweite Konstruktor
void testCreate2() {
    cout << "Test create mit 2 Konstruktor" << endl;
    string name[] = {"a", "b", "c"};
    DSM g(name, 3);
    assert(g.size() == 3);
    assert(g.getName(0) == "a");
    assert(g.getName(1) == "b");
    assert(g.getName(2) == "c");

    try {
        g.getName(3);
        cerr << "Test Failed: Exception not thrown" << endl;
    }
    catch (const std::exception &e) {
        // Exception was thrown, test passed
        return;
    }

    cerr << "Test Failed: Exception not thrown" << endl;
}

void testCopyKonstruktor() {
    DSM a(3);
    DSM b(a);

    DSM c(9);
    c = a;
}

void testSize() {
    cout << "Test size" << endl;
    DSM m(5);
    assert(m.size() == 5);
}

void testGetName() {
    cout << "Test getName" << endl;
    string name[] = {"a", "b", "c"};
    DSM d(name, 3);

    assert(d.getName(0) == "a");

    try {
        d.getName(5);
        cerr << "Test Failed: Exception not thrown" << endl;
        assert(false);
    }
    catch (const std::exception &e) {
        // Exception was thrown, test passed
        return;
    }

    cerr << "Test Failed: Exception not thrown" << endl;
}

void testGetIndex() {
    cout << "Test getIndex" << endl;
    string name[] = {"a", "b", "c"};
    DSM d(name, 3);

    assert(d.getIndex("a") == 0);
    assert(d.getIndex("p") == -1);
}

void testSetElementName() {
    cout << "Test setElementName" << endl;
    string name[] = {"a", "b", "c"};
    DSM d(name, 3);

    assert(d.getName(0) == "a");
    d.setElementName(0, "correct");
    assert(d.getName(0) == "correct");

    try {
        d.setElementName(-1, "error");
        d.setElementName(100, "error");
        cerr << "Test Failed: Exception not thrown" << endl;
        assert(false);
    }
    catch (const std::exception &e) {
        // Exception was thrown, test passed
        return;
    }

    cerr << "Test Failed: Exception not thrown" << endl;
}

void testAddLink() {
    cout << "Test addLink" << endl;
    string name[] = {"a", "b", "c"};
    DSM d(name, 3);

    d.addLink("a", "b", 4);
    assert(d.hasLink("a", "b") == true);
    assert(d.hasLink("a", "c") == false);

    d.addLink("newA", "newB", 10);
    assert(d.hasLink("newA", "newB") == true);
}

void testDeleteLink() {
    cout << "Test deleteLink" << endl;
    string name[] = {"a", "b", "c"};
    DSM d(name, 3);

    d.addLink("a", "b", 4);
    assert(d.hasLink("a", "b") == true);

    d.deleteLink("a", "b");
    assert(d.hasLink("a", "b") == false);

    try {
        d.deleteLink("fakeName1", "fakeName2");
        cerr << "Test Failed: Exception not thrown" << endl;
        assert(false);
    }
    catch (const std::exception &e) {
        // Exception was thrown, test passed
        return;
    }

    cerr << "Test Failed: Exception not thrown" << endl;
}

void testHasLink() {
    cout << "Test hasLink" << endl;
    string name[] = {"a", "b", "c"};
    DSM d(name, 3);

    d.addLink("a", "b", 4);
    assert(d.hasLink("a", "b") == true);
    d.deleteLink("a", "b");
    assert(d.hasLink("a", "b") == false);

    d.addLink("newA", "newB", 10);
    assert(d.hasLink("newA", "newB") == true);

    try {
        d.hasLink("fakeName1", "fakeName2");
        cerr << "Test Failed: Exception not thrown" << endl;
        assert(false);
    }
    catch (const std::exception &e) {
        // Exception was thrown, test passed
        return;
    }

    cerr << "Test Failed: Exception not thrown" << endl;
}

void testLinkWeight() {
    cout << "Test linkWeight" << endl;
    string name[] = {"a", "b", "c"};
    DSM d(name, 3);
    d.addLink("a", "b", 3);

    assert(d.linkWeight("a", "b") == 3);

    try {
        d.linkWeight("fakeName1", "fakeName2");
        cerr << "Test Failed: Exception not thrown" << endl;
        assert(false);
    }
    catch (const std::exception &e) {
        // Exception was thrown, test passed
        return;
    }

    cerr << "Test Failed: Exception not thrown" << endl;
}

void testCountToLinks() {
    cout << "Test countToLinks" << endl;
    string name[] = {"a", "b", "c"};
    DSM d(name, 3);
    d.addLink("a", "b", 3);
    d.addLink("a","c", 8);

    assert(d.countToLinks("a") == 2);
    assert(d.countToLinks("b") == 0);

    try {
        d.countToLinks("d");
        cerr << "Test Failed: Exception not thrown" << endl;
        assert(false);
    }
    catch (const std::exception &e) {
        // Exception was thrown, test passed
        return;
    }

    cerr << "Test Failed: Exception not thrown" << endl;
}

void testCountFromLinks() {
    cout << "Test countFromLinks" << endl;
    string name[] = {"a", "b", "c"};
    DSM d(name, 3);
    d.addLink("a", "b", 3);
    d.addLink("a","c", 8);
    d.addLink("b","c",10);

    assert(d.countFromLinks("a") == 0);
    assert(d.countFromLinks("b") == 1);
    assert(d.countFromLinks("c") == 2);


    try {
        d.countFromLinks("d");
        cerr << "Test Failed: Exception not thrown" << endl;
        assert(false);
    }
    catch (const std::exception &e) {
        // Exception was thrown, test passed
        return;
    }

    cerr << "Test Failed: Exception not thrown" << endl;
}

void testCountAllLinks() {
    cout << "Test countAllLinks" << endl;
    string name[] = {"a", "b", "c"};
    DSM d(name, 3);
    d.addLink("a", "b", 3);
    d.addLink("a","c", 8);
    d.addLink("b","c",10);

    assert(d.countAllLinks() == 3);

    DSM a(3);
    assert(a.countAllLinks() == 0);

}

void testReadFromFile() {
    DSM test(0);
    test.readFromFile("CSV-Datei.txt");
    cout<<"\n";
    test.printDSM();
}

void testAll() {
    testCreate();
    testCreate2();
    testSize();
    testGetName();
    testGetIndex();
    testSetElementName();
    testAddLink();
    testDeleteLink();
    testHasLink();
    testLinkWeight();
    testCountToLinks();
    testCountFromLinks();
    testCountAllLinks();
}


int main() {
    testAll();

    cout << "\n \t Meine Representation \n";
    string namen[] = {"Lenkrad", "Motor", "Bremsen", "Gaspedal", "Kupplung", "Räder", "Kabine", "Scheinwerfer"};
    DSM d(namen, 8);

    d.addLink("Lenkrad", "Bremsen",2);
    d.addLink("Bremsen", "Lenkrad",2);
    d.addLink("Lenkrad", "Kupplung", 2);
    d.addLink("Kupplung", "Lenkrad", 2);
    d.addLink("Lenkrad", "Räder", 5);
    d.addLink("Räder", "Lenkrad", 5);
    d.addLink("Lenkrad", "Kabine", 3);
    d.addLink("Kabine","Lenkrad",3);
    d.addLink("Motor", "Bremsen", 4);
    d.addLink("Bremsen", "Motor", 4);
    d.addLink("Motor", "Kupplung", 4);
    d.addLink("Kupplung", "Motor", 4);
    d.addLink("Motor","Gaspedal", 5);
    d.addLink("Gaspedal","Motor", 5);
    d.addLink("Motor","Räder", 3);
    d.addLink("Räder","Motor", 3);
    d.addLink("Bremsen","Kupplung", 4);
    d.addLink("Kupplung","Bremsen", 4);
    d.addLink("Bremsen","Räder", 3);
    d.addLink("Bremsen", "Gaspedal", 5);
    d.addLink("Gaspedal", "Bremsen", 5);
    d.addLink("Räder","Bremsen", 3);
    d.addLink("Bremsen","Kabine", 0);
    d.addLink("Kabine","Bremsen", 0);
    d.addLink("Gaspedal", "Kupplung", 5);
    d.addLink("Kupplung", "Gaspedal", 5);
    d.addLink("Gaspedal", "Räder", 5);
    d.addLink("Räder", "Gaspedal", 5);
    d.addLink("Gaspedal", "Kabine", 1);
    d.addLink("Kabine", "Gaspedal", 1);
    d.addLink("Kupplung", "Räder", 5);
    d.addLink("Räder", "Kupplung", 5);
    d.addLink("Räder", "Kabine", 3);
    d.addLink("Kabine", "Räder", 3);

    d.printDSM();
    testReadFromFile();

    d.writeToFile("CSV-Out.txt");
}
