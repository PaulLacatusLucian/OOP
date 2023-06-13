//
// Created by Paul on 5/16/2023.
//

#ifndef LAB5_SCOOTERUI_H
#define LAB5_SCOOTERUI_H

#include "ScooterController.h"
#include "memory"

namespace ScooterUINamespace {
    class ScooterUI {

    private:
        shared_ptr<scooterController::ScooterController> controller;

    public:
        ScooterUI(shared_ptr<scooterController::ScooterController>
                  otherController) {
            controller = otherController;
        }

        void start();
    };
}

#endif //LAB5_SCOOTERUI_H
