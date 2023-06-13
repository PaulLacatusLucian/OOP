//
// Created by Paul on 5/16/2023.
//

#ifndef LAB5_SCOOTERUI_H
#define LAB5_SCOOTERUI_H

#include "ScooterController.h"
#include "memory"

namespace UI {
    class ScooterUI {

    private:
        shared_ptr<Controller::ScooterController> controller;

    public:
        ScooterUI(shared_ptr<Controller::ScooterController>
                  otherController) {
            controller = otherController;
        }
        void start();


    };

    int inputRepository();
}

#endif //LAB5_SCOOTERUI_H
