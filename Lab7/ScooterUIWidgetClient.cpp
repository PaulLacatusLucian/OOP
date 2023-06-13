#include "ScooterUIWidgetClient.h"
#include "ScooterController.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include <QInputDialog>
#include <QListWidget>
#include <QDialogButtonBox>
#include <QTableWidgetItem>
#include "Elektroscooter.h"

void updateTable(QTableWidget *table);

ScooterUIWidgetClient::ScooterUIWidgetClient(std::shared_ptr<Controller::ScooterController> controller, QWidget *parent)
        : QWidget(parent), controller(controller) {
    setupUI();
}

void ScooterUIWidgetClient::setupUI() {

    setWindowTitle("SUS");

    setWindowIcon(QIcon("C:\\Users\\Paul\\CLionProjects\\oop\\lab7QT\\SUS_Team.png"));

    resize(600, 400);
    QHBoxLayout *layout = new QHBoxLayout();
    resultList = new QListWidget(this);

    QVBoxLayout *leftLayout = new QVBoxLayout();
    leftLayout->addWidget(resultList);

    QLabel *titleLabel = new QLabel("Client Actions", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    leftLayout->addWidget(titleLabel);

    QPushButton *searchButton = new QPushButton("Search Scooters", this);
    searchButton->setStyleSheet(
            "QPushButton { background-color: #2f4358; color: white; border-radius: 10px; height: 60px; }");
    connect(searchButton, &QPushButton::clicked, this, &ScooterUIWidgetClient::onSearchButtonClicked);
    leftLayout->addWidget(searchButton);

    QPushButton *kilometerFilterButton = new QPushButton("Filter Scooters by Kilometers", this);
    kilometerFilterButton->setStyleSheet(
            "QPushButton { background-color: #2f4358; color: white; border-radius: 10px; height: 60px; }");
    connect(kilometerFilterButton, &QPushButton::clicked, this, &ScooterUIWidgetClient::onKilometerFilterButtonClicked);
    leftLayout->addWidget(kilometerFilterButton);

    QPushButton *ageFilterButton = new QPushButton("Filter Scooters by Age", this);
    ageFilterButton->setStyleSheet(
            "QPushButton { background-color: #2f4358; color: white; border-radius: 10px; height: 60px; }");
    connect(ageFilterButton, &QPushButton::clicked, this, &ScooterUIWidgetClient::onAgeFilterButtonClicked);
    leftLayout->addWidget(ageFilterButton);

    QPushButton *reserveButton = new QPushButton("Reserve Scooter", this);
    reserveButton->setStyleSheet(
            "QPushButton { background-color: #2f4358; color: white; border-radius: 10px; height: 60px; }");
    connect(reserveButton, &QPushButton::clicked, this, &ScooterUIWidgetClient::onReserveButtonClicked);
    leftLayout->addWidget(reserveButton);

    QPushButton *avalibleButton = new QPushButton("See avalible Scooters", this);
    avalibleButton->setStyleSheet(
            "QPushButton { background-color: #2f4358; color: white; border-radius: 10px; height: 60px; }");
    connect(avalibleButton, &QPushButton::clicked, this, &ScooterUIWidgetClient::onAvalibleButtonClicked);
    leftLayout->addWidget(avalibleButton);

    QPushButton *parkButton = new QPushButton("Park Scooter", this);
    parkButton->setStyleSheet(
            "QPushButton { background-color: #2f4358; color: white; border-radius: 10px; height: 60px; }"
    );
    connect(parkButton, &QPushButton::clicked, this, &ScooterUIWidgetClient::onParkButtonClicked);
    leftLayout->addWidget(parkButton);

    QPushButton *goBackButton = new QPushButton("Go Back", this);
    goBackButton->setStyleSheet(
            "QPushButton { background-color: #2f4358; color: white; border-radius: 10px; height: 60px; }");
    connect(goBackButton, &QPushButton::clicked, this, &ScooterUIWidgetClient::onGoBackButtonClicked);
    leftLayout->addWidget(goBackButton);

    QVBoxLayout *rightLayout = new QVBoxLayout();

    scooterTable = new QTableWidget(this);
    scooterTable->setRowCount(0);
    scooterTable->setColumnCount(6);
    scooterTable->setHorizontalHeaderLabels(
            QStringList() << "ID" << "Brand" << "Model" << "Kilometers" << "StandOrt" << "Zustand");
    scooterTable->setSortingEnabled(true);
    rightLayout->addWidget(scooterTable);

    std::vector<Domain::Elektroscooter> scooters = controller->getAll();

    for (const auto &scooter: scooters) {
        int row = scooterTable->rowCount();
        scooterTable->insertRow(row);

        QTableWidgetItem *idItem = new QTableWidgetItem(QString::fromStdString(scooter.get_id()));
        QTableWidgetItem *modellItem = new QTableWidgetItem(QString::fromStdString(scooter.get_modell()));
        QTableWidgetItem *inbetriebnahmedatumItem = new QTableWidgetItem(
                QString::fromStdString(scooter.get_inbetriebnahmedatum()));
        QTableWidgetItem *kilometerItem = new QTableWidgetItem(QString::number(scooter.get_kilometer()));
        QTableWidgetItem *ortItem = new QTableWidgetItem(QString::fromStdString(scooter.get_letzterStandort()));
        QTableWidgetItem *zustandItem = new QTableWidgetItem(QString::fromStdString(scooter.get_aktuellerZustand()));


        scooterTable->setItem(row, 0, idItem);
        scooterTable->setItem(row, 1, modellItem);
        scooterTable->setItem(row, 2, inbetriebnahmedatumItem);
        scooterTable->setItem(row, 3, kilometerItem);
        scooterTable->setItem(row, 4, ortItem);
        scooterTable->setItem(row, 5, zustandItem);
    }

    layout->addLayout(leftLayout);
    layout->addLayout(rightLayout);


    setLayout(layout);

}

void ScooterUIWidgetClient::updateTable(QTableWidget *table) {
    table->clearContents();
    table->setRowCount(0);

    std::vector<Domain::Elektroscooter> scooters = controller->getAll();

    for (const auto &scooter: scooters) {
        int row = table->rowCount();
        table->insertRow(row);

        QTableWidgetItem *idItem = new QTableWidgetItem(QString::fromStdString(scooter.get_id()));
        QTableWidgetItem *modellItem = new QTableWidgetItem(QString::fromStdString(scooter.get_modell()));
        QTableWidgetItem *inbetriebnahmedatumItem = new QTableWidgetItem(
                QString::fromStdString(scooter.get_inbetriebnahmedatum()));
        QTableWidgetItem *kilometerItem = new QTableWidgetItem(QString::number(scooter.get_kilometer()));
        QTableWidgetItem *ortItem = new QTableWidgetItem(QString::fromStdString(scooter.get_letzterStandort()));
        QTableWidgetItem *zustandItem = new QTableWidgetItem(QString::fromStdString(scooter.get_aktuellerZustand()));

        table->setItem(row, 0, idItem);
        table->setItem(row, 1, modellItem);
        table->setItem(row, 2, inbetriebnahmedatumItem);
        table->setItem(row, 3, kilometerItem);
        table->setItem(row, 4, ortItem);
        table->setItem(row, 5, zustandItem);
    }
}

void ScooterUIWidgetClient::onParkButtonClicked() {
    QString id = QInputDialog::getText(this, "Park a Scooter", "Enter the ID:");
    std::string idString = id.toStdString();
    bool parked = controller->parkScooter(idString);
    if (parked) {
        QMessageBox::information(this, "Parking", "Scooter parked successfully!");
    } else {
        QMessageBox::information(this, "Parking", "Failed to park the scooter. Please check the ID and try again.");
    }
    updateTable(scooterTable);
}

void ScooterUIWidgetClient::onSearchButtonClicked() {
    QString location = QInputDialog::getText(this, "Search Scooters", "Enter a location:");

    std::string locationString = location.toStdString();

    if (!location.isEmpty()) {

        std::vector<Domain::Elektroscooter> searchResults = controller->standOrtSuche(locationString);

        resultList->clear();

        for (auto &scooter: searchResults) {
            QString scooterInfo = QString(
                    "ID: %1, Modell: %2, Inbertriebsannahmedatum: %3, Kilometer: %4, Standort: %5, Aktueller Zustand: %6 ")
                    .arg(QString::fromStdString(scooter.get_id()))
                    .arg(QString::fromStdString(scooter.get_modell()))
                    .arg(QString::fromStdString(scooter.get_inbetriebnahmedatum()))
                    .arg(QString::number(scooter.get_kilometer()))
                    .arg(QString::fromStdString(scooter.get_letzterStandort()))
                    .arg(QString::fromStdString(scooter.get_aktuellerZustand()));

            resultList->addItem(scooterInfo);
        }
    }
    updateTable(scooterTable);

}

void ScooterUIWidgetClient::onAvalibleButtonClicked() {

    std::vector<Domain::Elektroscooter> searchResults = controller->getFreeScooters();

    resultList->clear();

    for (auto &scooter: searchResults) {
        QString scooterInfo = QString(
                "ID: %1, Modell: %2, Inbertriebsannahmedatum: %3, Kilometer: %4, Standort: %5, Aktueller Zustand: %6 ")
                .arg(QString::fromStdString(scooter.get_id()))
                .arg(QString::fromStdString(scooter.get_modell()))
                .arg(QString::fromStdString(scooter.get_inbetriebnahmedatum()))
                .arg(QString::number(scooter.get_kilometer()))
                .arg(QString::fromStdString(scooter.get_letzterStandort()))
                .arg(QString::fromStdString(scooter.get_aktuellerZustand()));

        resultList->addItem(scooterInfo);

    }
    updateTable(scooterTable);

}

void ScooterUIWidgetClient::onKilometerFilterButtonClicked() {
    bool ok;
    int kilometers = QInputDialog::getInt(this, "Filter Scooters by Kilometers", "Enter how many kilometers you need:",
                                          0, 0, 1000000, 1, &ok);

    std::vector<Domain::Elektroscooter> searchResults = controller->filterKilometer(kilometers);

    resultList->clear();

    for (auto &scooter: searchResults) {
        QString scooterInfo = QString(
                "ID: %1, Modell: %2, Inbertriebsannahmedatum: %3, Kilometer: %4, Standort: %5 << Zustand: %6 ")
                .arg(QString::fromStdString(scooter.get_id()))
                .arg(QString::fromStdString(scooter.get_modell()))
                .arg(QString::fromStdString(scooter.get_inbetriebnahmedatum()))
                .arg(QString::number(scooter.get_kilometer()))
                .arg(QString::fromStdString(scooter.get_letzterStandort()))
                .arg(QString::fromStdString(scooter.get_aktuellerZustand()));

        QListWidgetItem *item = new QListWidgetItem(scooterInfo);
        QFont font = item->font();
        font.setPointSize(14);
        font.setBold(true);
        item->setFont(font);

        resultList->addItem(scooterInfo);
    }
    updateTable(scooterTable);

}

void ScooterUIWidgetClient::onAgeFilterButtonClicked() {
    QString finalDate = QInputDialog::getText(this, "Filter Scooters by Age", "Enter a date:");
    std::string finalDateString = finalDate.toStdString();
    std::vector<Domain::Elektroscooter> searchResults = controller->filterAlter(finalDateString);

    resultList->clear();

    for (auto &scooter: searchResults) {
        QString scooterInfo = QString(
                "ID: %1, Modell: %2, Inbertriebsannahmedatum: %3, Kilometer: %4, Standort: %5 ")
                .arg(QString::fromStdString(scooter.get_id()))
                .arg(QString::fromStdString(scooter.get_modell()))
                .arg(QString::fromStdString(scooter.get_inbetriebnahmedatum()))
                .arg(QString::number(scooter.get_kilometer()))
                .arg(QString::fromStdString(scooter.get_letzterStandort()));

        QListWidgetItem *item = new QListWidgetItem(scooterInfo);
        QFont font = item->font();
        font.setPointSize(14);
        font.setBold(true);
        item->setFont(font);

        resultList->addItem(scooterInfo);
    }
    updateTable(scooterTable);

}

void ScooterUIWidgetClient::onReserveButtonClicked() {
    QString id = QInputDialog::getText(this, "Reserve a Scooter", "Enter the ID:");
    std::string idString = id.toStdString();
    bool reserved = controller->reservieren(idString);
    if (reserved) {
        QMessageBox::information(this, "Reservation", "Scooter reserved!");
    } else {
        QMessageBox::information(this, "Reservation", "Scooter allready reserved!");
    }
    updateTable(scooterTable);
}

void ScooterUIWidgetClient::onGoBackButtonClicked() {
    close();
}