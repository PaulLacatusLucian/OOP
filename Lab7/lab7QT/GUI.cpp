#include "GUI.h"
#include "ScooterUI.h"
#include <QMessageBox>
#include <QPushButton>
#include "ScooterUIWidgetAdmin.h"
#include "ScooterUIWidgetClient.h"
#include <QLabel>
#include <QInputDialog>
#include <QCoreApplication>
#include <QDialog>
#include <QFormLayout>
#include <QLineEdit>

using namespace UI;
using namespace std;


GUI::GUI(QWidget *parent) : QMainWindow(parent) {

    setWindowTitle("SUS");

    setWindowIcon(QIcon("C:\\Users\\Paul\\CLionProjects\\oop\\lab7QT\\SUS_Team.png"));


    QPixmap backgroundImage("C:\\Users\\Paul\\CLionProjects\\oop\\lab7QT\\wp8922917-electric-scooter-wallpapers.jpg");
    QLabel *backgroundLabel = new QLabel(this);
    backgroundLabel->setPixmap(backgroundImage.scaled(size(), Qt::KeepAspectRatioByExpanding));
    setCentralWidget(backgroundLabel);

    adminButton = new QPushButton("Admin", this);
    userButton = new QPushButton("User", this);
    goBackButton = new QPushButton("Exit", this);

    QString buttonStyle =
            "QPushButton {"
            "  background-color: #2f4358;"
            "  color: #fff;"
            "  border: none;"
            "  padding: 10px 20px;"
            "  text-align: center;"
            "  text-decoration: none;"
            "  font-size: 20px;"
            "  border-radius: 30px;"
            "}"
            "QPushButton:hover {"
            "  background-color: #fff;"
            "color:#000;"
            "}"
            "QPushButton:pressed {"
            "  background-color: #2f4358;"
            "}";

    adminButton->setStyleSheet(buttonStyle);
    userButton->setStyleSheet(buttonStyle);
    goBackButton->setStyleSheet(buttonStyle);

    adminButton->setFixedSize(200, 60);
    userButton->setFixedSize(200, 60);
    goBackButton->setFixedSize(200, 60);

    adminButton->move(width() - adminButton->width() + 150, 20);
    userButton->move(width() - userButton->width() + 150, adminButton->y() + adminButton->height() + 20);
    goBackButton->move(width() - goBackButton->width() + 150, userButton->y() + userButton->height() + 20);

    connect(adminButton, &QPushButton::clicked, this, &GUI::onAdminClicked);
    connect(userButton, &QPushButton::clicked, this, &GUI::onUserClicked);
    connect(goBackButton, &QPushButton::clicked, this, &GUI::onGoBackClicked);
}

GUI::~GUI() {
    delete goBackButton;
}

void GUI::onAdminClicked() {
    bool ok;
    QString password = QInputDialog::getText(this, "Admin Login", "Enter password:", QLineEdit::Password, "", &ok);
    if (ok && password == "s8cr8t") {
        inputRepositoryAdmin();
    } else {
        showMessage("Invalid password");
    }
}

void GUI::onUserClicked() {
    bool ok;
    QString password = QInputDialog::getText(this, "User Login", "Enter password:", QLineEdit::Password, "", &ok);
    if (ok && password == "tr1ck") {
        inputRepositoryClient();
    } else {
        showMessage("Invalid password");
    }
}


void GUI::showAdminActions(int repoType) {
    auto controller = std::make_shared<Controller::ScooterController>(repoType);

    ScooterUIWidgetAdmin *adminWidget = new ScooterUIWidgetAdmin(controller);
    adminWidget->show();
}

int GUI::inputRepositoryAdmin() {
    bool ok;
    QStringList items;
    items << "inMemoryRepository" << "CSVRepository";

    QInputDialog dialog(this);
    dialog.setWindowTitle("Repository Type");
    dialog.setLabelText("Please pick the type of the Repository:");
    dialog.setComboBoxItems(items);
    dialog.setComboBoxEditable(false);

    dialog.setStyleSheet("QDialog { background-color: #2f4358; }"
                         "QComboBox { color: blue; }"
    );

    QList<QAbstractButton *> buttons = dialog.findChildren<QAbstractButton *>();

    for (QAbstractButton *button: buttons) {
        button->setStyleSheet("QPushButton { border-radius: 10px; }"
        );
    }

    if (dialog.exec() == QDialog::Accepted) {
        int repoType = items.indexOf(dialog.textValue());
        showAdminActions(repoType);
    }
}

int GUI::inputRepositoryClient() {
    bool ok;
    QStringList items;
    items << "inMemoryRepository" << "CSVRepository";

    QInputDialog dialog(this);
    dialog.setWindowTitle("Repository Type");
    dialog.setLabelText("Please pick the type of the Repository:");
    dialog.setComboBoxItems(items);
    dialog.setComboBoxEditable(false);

    dialog.setStyleSheet("QDialog { background-color: #2f4358; }"
                         "QComboBox { color: blue; }"
    );

    QList<QAbstractButton *> buttons = dialog.findChildren<QAbstractButton *>();

    for (QAbstractButton *button: buttons) {
        button->setStyleSheet("QPushButton { border-radius: 10px; }"
        );
    }

    if (dialog.exec() == QDialog::Accepted) {
        int repoType = items.indexOf(dialog.textValue());
        showClientActions(repoType);
    }
}

void GUI::showClientActions(int repoType) {
    auto controller = std::make_shared<Controller::ScooterController>(repoType);

    ScooterUIWidgetClient *ClientWidget = new ScooterUIWidgetClient(controller);
    ClientWidget->show();
}

void GUI::showMessage(const QString &message) {
    QMessageBox::information(this, "Role Selection", message);
}

void GUI::onGoBackClicked() {
    QCoreApplication::quit();
}