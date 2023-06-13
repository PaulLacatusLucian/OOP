//
// Created by Paul on 4/16/2023.
//

#ifndef LABOR4_SHOPCONTROLLER_H
#define LABOR4_SHOPCONTROLLER_H

#include "memory"
#include <string>
#include <utility>
#include "Fruit.h"
#include "Repo.h"

namespace ShopControllerNamespace {
    class ShopController {
    private:
        shared_ptr<Repository::Repo> repo;

    public:
        ShopController(shared_ptr<Repository::Repo> otherRepo) {
            repo = otherRepo;
        }

        void printAllObjects(int rol);

        void searchForObject(const string &name, int rol);

        void addProduct();

        void removeProduct();

        void expDateCheck(const std::string &finalDate);

        void sortedByExp();

    };
}


#endif //LABOR4_SHOPCONTROLLER_H
