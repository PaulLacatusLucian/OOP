//
// Created by Paul on 4/16/2023.
//

#ifndef LABOR4_SHOPUI_H
#define LABOR4_SHOPUI_H
#include "Repo.h"
#include "memory"
#include "ShopController.h"
namespace ShopUINamespace {
    class ShopUI {
    private:
        shared_ptr<ShopControllerNamespace::ShopController> controller;

    public:
        ShopUI(shared_ptr<ShopControllerNamespace::ShopController> otherController) {
            controller = otherController;
        }
        void start();
    };
}


#endif //LABOR4_SHOPUI_H
