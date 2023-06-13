// Created by Paul on 4/16/2023.

#include "ShopUI.h"
#include <iostream>
#include "ShopController.h"
#include "Repo.h"

using namespace std;
using namespace ShopControllerNamespace;
using namespace ShopUINamespace;

void ShopUI::start() {
    const int CUSTOMER_ROLE = 1;
    const int EMPLOYEE_ROLE = 2;
    const int SEARCH_PRODUCT = 1;
    const int VIEW_ALL_PRODUCTS = 2;
    const int ADD_PRODUCT = 3;
    const int REMOVE_PRODUCT = 4;
    const int EXP_DATE_LIST = 5;
    const int ALL_SORTED_BY_EXPDATE = 6;

    int userRole, selectedOption;
    string productName, finalDate;

    cout << "\t Welcome to the shop" << endl << "Choose your role:\t1. Customer \t2. Employees" << endl;
    cin >> userRole;

    if (userRole == CUSTOMER_ROLE) {
        cout << "What would you like to do? \nChoose from the actions below:\n";
        cout << "1. Search for a product \n2. View all products\n";
        cin >> selectedOption;

        if (selectedOption == SEARCH_PRODUCT) {
            cout << "Enter a product name or manufacturer:  ";
            cin >> productName;
            controller->searchForObject(productName, 0);
        } else if (selectedOption == VIEW_ALL_PRODUCTS) {
            controller->printAllObjects(0);
        } else {
            cout << "Invalid option" << endl;
        }

    } else if (userRole == EMPLOYEE_ROLE) {
        cout << "What would you like to do? \nChoose from the actions below: \n";
        cout << "1. Search for a product \n2. View all products\n3. Add a product \n4. Remove a product \n5. See Products which expire soon \n6. See all sorted by expiration date";
        cin >> selectedOption;

        switch(selectedOption) {
            case SEARCH_PRODUCT:
                cout << "Enter a product name or manufacturer:  ";
                cin >> productName;
                controller->searchForObject(productName, 1);
                break;
            case VIEW_ALL_PRODUCTS:
                controller->printAllObjects(1);
                break;
            case ADD_PRODUCT:
                controller->addProduct();
                break;
            case REMOVE_PRODUCT:
                controller->removeProduct();
                break;
            case EXP_DATE_LIST:
                cout << "Enter final date: ";
                cin >> finalDate;
                controller->expDateCheck(finalDate);
                break;
            case ALL_SORTED_BY_EXPDATE:
                controller->sortedByExp();
                break;
            default:
                cout << "Invalid option" << endl;
                break;
        }

    } else {
        cout << "Invalid role" << endl;
    }

    int exitOption;
    cout << "Enter 0 to exit or any other number to continue: ";
    cin >> exitOption;

    if (exitOption != 0) {
        start();
    }
}
