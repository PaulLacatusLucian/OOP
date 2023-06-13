#include <iostream>
#include "Elektroscooter.h"
#include "Repository.h"
#include "ScooterController.h"
#include "ScooterUI.h"
#include "memory"

using namespace Repository;
using namespace Domain;
using namespace Controller;
using namespace UI;

#include <QApplication>
#include "GUI.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    GUI gui;
    gui.show();
    return app.exec();
}


