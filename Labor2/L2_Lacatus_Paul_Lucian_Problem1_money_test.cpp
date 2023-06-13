//
// Created by Paul on 3/16/2023.
//
#include <iostream>
#include <cassert>
#include "L2_Lacatus_Paul_Lucian_Problem1_money.h"

using namespace std;


void test_all() {
    double test_result_int;
    string test_result_string;
    short test_result_short;

    Money m(100.314234, "euro");
    assert (m.get_value() == 100.314234);
    assert (m.get_currency() == "euro");
    cout << "Test 1 passed successfully!" << endl;

    Money m2(322.43214, "euro");
    Money testMoney = m.add(m2);
    assert (testMoney.get_value() == 422.74);
    cout << "Test 2 passed successfully!" << endl;

    m2.set_value(100.3);
    Money testMoney1 = m.substract(m2);
    assert (testMoney1.get_value() == 0.01);
    cout << "Test 3 passed successfully!" << endl;


    Money testMoney3 = m.scale(100);
    assert (testMoney3.get_value() == 10031.42);
    cout << "Test 4 passed successfully!" << endl;


    test_result_int = m.divide(100);
    assert (test_result_int == 1.00);
    cout << "Test 5 passed successfully!" << endl;


    test_result_string = m.text();
    assert (test_result_string == "100.31 euro");
    cout << "Test 6 passed successfully!" << endl;

    m2.set_value(100.314234);
    test_result_short = m.compare(m2);
    assert (test_result_short == 0);
    cout << "Test 7 passed successfully!" << endl;


    m2.set_value(111.314234);
    test_result_short = m.compare(m2);
    assert (test_result_short == -1);
    cout << "Test 8 passed successfully!" << endl;

    m2.set_value(99.314234);
    test_result_short = m.compare(m2);
    assert (test_result_short == 1);
    cout << "Test 9 passed successfully!" << endl;

}

int main() {
    test_all();

    double value;
    string currency;
    double valueOfTheCurrency;
    string konversion_status;

    cout << "Geben Sie den Betrag ein und eine Wahrung: " << endl;
    cin >> valueOfTheCurrency >> currency;
    Money money1(valueOfTheCurrency, currency);

    cout << "Geben Sie den Betrag ein und eine Wahrung: " << endl;
    cin >> valueOfTheCurrency >> currency;
    Money money2(valueOfTheCurrency, currency);

    cout << "Gebem Sie einen Wert: " << endl;
    cin >> value;

    Money m3 = money1.add(money2);
    cout << "Ergebniss der ADD Funktion: " << m3.get_value() << endl;
    m3 = money1.substract(money2);
    cout << "Ergebniss der SUB Funktion: " << m3.get_value() << endl;
    m3 = money1.scale(value);
    cout << "Ergebniss der SCALE Funktion: " << m3.get_value() << endl;
    cout << "Ergebniss der COMPARE Funktion: " << money1.compare(money2) << endl;
    cout << "Ergebniss der DIVIDE Funktion: " << money1.divide(value) << endl;
    cout << "Ergebniss der TEXT Funktion: " << money1.text() << endl;

    cout << "Wollen sie eine Konversion machen?" << endl;
    cin >> konversion_status;

    if (konversion_status == "ja") {
        string konversion_currency;
        cout << "in welche Wahrung mochten Sie umtauschen?" << endl;
        cin >> konversion_currency;
        cout << money1.text() << " -> ";
        money1.konversion(konversion_currency);
        cout << money1.text() << endl;
    }

    Money test(100, "euro");
    Money test2(20, "euro");
    Money c = test + test2;
    Money c1 = test - test2;
    Money c2 = test / test2;
    Money c3 = test * test2;
    cout << c.text() << endl;
    cout << c1.text() << endl;
    cout << c2.text() << endl;
    cout << c3.text() << endl;
}


