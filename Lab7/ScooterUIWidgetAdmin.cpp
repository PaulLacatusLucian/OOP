#include "ScooterUIWidgetAdmin.h"
#include "ScooterController.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>
#include <QInputDialog>
#include <QListWidget>
#include <QFormLayout>
#include <QTableWidget>
#include <QDialogButtonBox>
#include "Elektroscooter.h"

ScooterUIWidgetAdmin::ScooterUIWidgetAdmin(std::shared_ptr<Controller::ScooterController> controller, QWidget *parent)
        : QWidget(parent), controller(controller) {
    setupUI();
}

void ScooterUIWidgetAdmin::setupUI() {
    setWindowTitle("SUS");

    setWindowIcon(QIcon("C:\\Users\\Paul\\CLionProjects\\oop\\lab7QT\\SUS_Team.png"));

    resize(600, 400);
    QHBoxLayout *layout = new QHBoxLayout();
    resultList = new QListWidget(this);

    QVBoxLayout *leftLayout = new QVBoxLayout();
    leftLayout->addWidget(resultList);

    QLabel *titleLabel = new QLabel("Admin Actions", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    leftLayout->addWidget(titleLabel);

    QPushButton *searchButton = new QPushButton("Search Scooters", this);
    searchButton->setStyleSheet(
            "QPushButton { background-color: #2f4358; color: white; border-radius: 10px; height: 60px; }");
    connect(searchButton, &QPushButton::clicked, this, &ScooterUIWidgetAdmin::onSearchButtonClicked);
    leftLayout->addWidget(searchButton);

    QPushButton *kilometerFilterButton = new QPushButton("Filter Scooters by Kilometers", this);
    kilometerFilterButton->setStyleSheet(
            "QPushButton { background-color: #2f4358; color: white; border-radius: 10px; height: 60px; }");
    connect(kilometerFilterButton, &QPushButton::clicked, this, &ScooterUIWidgetAdmin::onKilometerFilterButtonClicked);
    leftLayout->addWidget(kilometerFilterButton);

    QPushButton *ageFilterButton = new QPushButton("Filter Scooters by Age", this);
    ageFilterButton->setStyleSheet(
            "QPushButton { background-color: #2f4358; color: white; border-radius: 10px; height: 60px; }");
    connect(ageFilterButton, &QPushButton::clicked, this, &ScooterUIWidgetAdmin::onAgeFilterButtonClicked);
    leftLayout->addWidget(ageFilterButton);

    QPushButton *addButton = new QPushButton("Add Scooter", this);
    addButton->setStyleSheet(
            "QPushButton { background-color: #2f4358; color: white; border-radius: 10px; height: 60px; }");
    connect(addButton, &QPushButton::clicked, this, &ScooterUIWidgetAdmin::onAddButtonClicked);
    leftLayout->addWidget(addButton);

    QPushButton *removeButton = new QPushButton("Remove Scooter", this);
    removeButton->setStyleSheet(
            "QPushButton { background-color: #2f4358; color: white; border-radius: 10px; height: 60px; }");
    connect(removeButton, &QPushButton::clicked, this, &ScooterUIWidgetAdmin::onRemoveButtonClicked);
    leftLayout->addWidget(removeButton);

    QPushButton *editButton = new QPushButton("Edit Scooter", this);
    editButton->setStyleSheet(
            "QPushButton { background-color: #2f4358; color: white; border-radius: 10px; height: 60px; }");
    connect(editButton, &QPushButton::clicked, this, &ScooterUIWidgetAdmin::onEditButtonClicked);
    leftLayout->addWidget(editButton);

    QPushButton *sortButton = new QPushButton("Sort Scooters by Age", this);
    sortButton->setStyleSheet(
            "QPushButton { background-color: #2f4358; color: white; border-radius: 10px; height: 60px; }");
    connect(sortButton, &QPushButton::clicked, this, &ScooterUIWidgetAdmin::onSortButtonClicked);
    leftLayout->addWidget(sortButton);

    QPushButton *goBackButton = new QPushButton("Go Back", this);
    goBackButton->setStyleSheet(
            "QPushButton { background-color: #2f4358; color: white; border-radius: 10px; height: 60px; }");
    connect(goBackButton, &QPushButton::clicked, this, &ScooterUIWidgetAdmin::onGoBackButtonClicked);
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

void ScooterUIWidgetAdmin::updateTable(QTableWidget *table) {
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


void ScooterUIWidgetAdmin::onSearchButtonClicked() {
    QString location = QInputDialog::getText(this, "Search Scooters", "Enter a location:");

    std::string locationString = location.toStdString();

    if (!location.isEmpty()) {

        std::vector<Domain::Elektroscooter> searchResults = controller->standOrtSuche(locationString);

        resultList->clear();

        for (auto &scooter: searchResults) {
            QString scooterInfo = QString(
                    "ID: %1, Modell: %2, Inbertriebsannahmedatum: %3, Kilometer: %4, Standort: %5, Lezter Zustand: %6 ")
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

void ScooterUIWidgetAdmin::onKilometerFilterButtonClicked() {
    bool ok;
    int kilometers = QInputDialog::getInt(this, "Filter Scooters by Kilometers", "Enter how many kilometers you need:",
                                          0, 0, 1000000, 1, &ok);

    std::vector<Domain::Elektroscooter> searchResults = controller->filterKilometer(kilometers);

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

void ScooterUIWidgetAdmin::onAgeFilterButtonClicked() {
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

void ScooterUIWidgetAdmin::onAddButtonClicked() {
    QDialog dialog(this);
    dialog.setWindowTitle("Add Scooter");
    dialog.setMinimumWidth(300);

    QLineEdit *idLineEdit = new QLineEdit(&dialog);
    QLineEdit *kilometerLineEdit = new QLineEdit(&dialog);
    QLineEdit *modellLineEdit = new QLineEdit(&dialog);
    QLineEdit *inbetriebnahmedatumLineEdit = new QLineEdit(&dialog);
    QLineEdit *letzterStandortLineEdit = new QLineEdit(&dialog);
    QLineEdit *aktuellerZustandLineEdit = new QLineEdit(&dialog);

    QLabel *idLabel = new QLabel("ID:", &dialog);
    QLabel *kilometerLabel = new QLabel("Kilometer:", &dialog);
    QLabel *modellLabel = new QLabel("Modell:", &dialog);
    QLabel *inbetriebnahmedatumLabel = new QLabel("Inbetriebnahmedatum:", &dialog);
    QLabel *letzterStandortLabel = new QLabel("Letzter Standort:", &dialog);
    QLabel *aktuellerZustandLabel = new QLabel("Aktueller Zustand:", &dialog);

    QFormLayout *formLayout = new QFormLayout(&dialog);
    formLayout->setLabelAlignment(Qt::AlignLeft);
    formLayout->addRow(idLabel, idLineEdit);
    formLayout->addRow(kilometerLabel, kilometerLineEdit);
    formLayout->addRow(modellLabel, modellLineEdit);
    formLayout->addRow(inbetriebnahmedatumLabel, inbetriebnahmedatumLineEdit);
    formLayout->addRow(letzterStandortLabel, letzterStandortLineEdit);
    formLayout->addRow(aktuellerZustandLabel, aktuellerZustandLineEdit);

    QPushButton *okButton = new QPushButton("OK", &dialog);
    okButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

    connect(okButton, &QPushButton::clicked, &dialog, &QDialog::accept);

    QVBoxLayout *buttonLayout = new QVBoxLayout;
    buttonLayout->addWidget(okButton);

    QVBoxLayout *mainLayout = new QVBoxLayout(&dialog);
    mainLayout->addLayout(formLayout);
    mainLayout->addLayout(buttonLayout);

    if (dialog.exec() == QDialog::Accepted) {
        QString id = idLineEdit->text();
        int kilometer = kilometerLineEdit->text().toInt();
        QString modell = modellLineEdit->text();
        QString inbetriebnahmedatum = inbetriebnahmedatumLineEdit->text();
        QString letzterStandort = letzterStandortLineEdit->text();
        QString aktuellerZustand = aktuellerZustandLineEdit->text();

        controller->add(id.toStdString(), kilometer, modell.toStdString(), inbetriebnahmedatum.toStdString(),
                        letzterStandort.toStdString(), aktuellerZustand.toStdString());
    }
    updateTable(scooterTable);

}

void ScooterUIWidgetAdmin::onRemoveButtonClicked() {
    QString id = QInputDialog::getText(this, "Remove Scooter", "Enter the ID of the scooter:");
    std::string idString = id.toStdString();
    controller->remove(idString);
    updateTable(scooterTable);

}

void ScooterUIWidgetAdmin::onEditButtonClicked() {
    QDialog dialog(this);
    dialog.setWindowTitle("Edit Scooter");
    dialog.setMinimumWidth(300);

    QLineEdit *idLineEdit = new QLineEdit(&dialog);
    QLineEdit *kilometerLineEdit = new QLineEdit(&dialog);
    QLineEdit *modellLineEdit = new QLineEdit(&dialog);
    QLineEdit *inbetriebnahmedatumLineEdit = new QLineEdit(&dialog);
    QLineEdit *letzterStandortLineEdit = new QLineEdit(&dialog);
    QLineEdit *aktuellerZustandLineEdit = new QLineEdit(&dialog);

    QLabel *idLabel = new QLabel("ID:", &dialog);
    QLabel *kilometerLabel = new QLabel("New Kilometer:", &dialog);
    QLabel *modellLabel = new QLabel("New Modell:", &dialog);
    QLabel *inbetriebnahmedatumLabel = new QLabel("New Inbetriebnahmedatum:", &dialog);
    QLabel *letzterStandortLabel = new QLabel("New Letzter Standort:", &dialog);
    QLabel *aktuellerZustandLabel = new QLabel("New Aktueller Zustand:", &dialog);

    QFormLayout *formLayout = new QFormLayout(&dialog);
    formLayout->setLabelAlignment(Qt::AlignLeft);
    formLayout->addRow(idLabel, idLineEdit);
    formLayout->addRow(kilometerLabel, kilometerLineEdit);
    formLayout->addRow(modellLabel, modellLineEdit);
    formLayout->addRow(inbetriebnahmedatumLabel, inbetriebnahmedatumLineEdit);
    formLayout->addRow(letzterStandortLabel, letzterStandortLineEdit);
    formLayout->addRow(aktuellerZustandLabel, aktuellerZustandLineEdit);

    QPushButton *okButton = new QPushButton("OK", &dialog);
    okButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

    connect(okButton, &QPushButton::clicked, &dialog, &QDialog::accept);

    QVBoxLayout *buttonLayout = new QVBoxLayout;
    buttonLayout->addWidget(okButton);

    QVBoxLayout *mainLayout = new QVBoxLayout(&dialog);
    mainLayout->addLayout(formLayout);
    mainLayout->addLayout(buttonLayout);

    if (dialog.exec() == QDialog::Accepted) {
        QString id = idLineEdit->text();
        int kilometer = kilometerLineEdit->text().toInt();
        QString modell = modellLineEdit->text();
        QString inbetriebnahmedatum = inbetriebnahmedatumLineEdit->text();
        QString letzterStandort = letzterStandortLineEdit->text();
        QString aktuellerZustand = aktuellerZustandLineEdit->text();

        controller->add(id.toStdString(), kilometer, modell.toStdString(), inbetriebnahmedatum.toStdString(),
                        letzterStandort.toStdString(), aktuellerZustand.toStdString());
    }
    updateTable(scooterTable);

}

void ScooterUIWidgetAdmin::onSortButtonClicked() {
    resultList->clear();

    auto searchResults = controller->nachAlterSortieren();

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
        updateTable(scooterTable);

    }


    resize(600, 400);
    QHBoxLayout *layout = new QHBoxLayout();
    resultList = new QListWidget(this);

    QVBoxLayout *leftLayout = new QVBoxLayout();
    leftLayout->
            addWidget(resultList);

    QLabel *titleLabel = new QLabel("Admin Actions", this);
    titleLabel->
            setAlignment(Qt::AlignCenter);
    leftLayout->
            addWidget(titleLabel);

    QPushButton *searchButton = new QPushButton("Search Scooters", this);
    searchButton->setStyleSheet(
            "QPushButton { background-color: #2f4358; color: white; border-radius: 10px; height: 60px; }");
    connect(searchButton, &QPushButton::clicked,
            this, &ScooterUIWidgetAdmin::onSearchButtonClicked);
    leftLayout->
            addWidget(searchButton);

    QPushButton *kilometerFilterButton = new QPushButton("Filter Scooters by Kilometers", this);
    kilometerFilterButton->setStyleSheet(
            "QPushButton { background-color: #2f4358; color: white; border-radius: 10px; height: 60px; }");
    connect(kilometerFilterButton, &QPushButton::clicked,
            this, &ScooterUIWidgetAdmin::onKilometerFilterButtonClicked);
    leftLayout->
            addWidget(kilometerFilterButton);

    QPushButton *ageFilterButton = new QPushButton("Filter Scooters by Age", this);
    ageFilterButton->setStyleSheet(
            "QPushButton { background-color: #2f4358; color: white; border-radius: 10px; height: 60px; }");
    connect(ageFilterButton, &QPushButton::clicked,
            this, &ScooterUIWidgetAdmin::onAgeFilterButtonClicked);
    leftLayout->
            addWidget(ageFilterButton);

    QPushButton *addButton = new QPushButton("Add Scooter", this);
    addButton->setStyleSheet(
            "QPushButton { background-color: #2f4358; color: white; border-radius: 10px; height: 60px; }");
    connect(addButton, &QPushButton::clicked,
            this, &ScooterUIWidgetAdmin::onAddButtonClicked);
    leftLayout->
            addWidget(addButton);

    QPushButton *removeButton = new QPushButton("Remove Scooter", this);
    removeButton->setStyleSheet(
            "QPushButton { background-color: #2f4358; color: white; border-radius: 10px; height: 60px; }");
    connect(removeButton, &QPushButton::clicked,
            this, &ScooterUIWidgetAdmin::onRemoveButtonClicked);
    leftLayout->
            addWidget(removeButton);

    QPushButton *editButton = new QPushButton("Edit Scooter", this);
    editButton->setStyleSheet(
            "QPushButton { background-color: #2f4358; color: white; border-radius: 10px; height: 60px; }");
    connect(editButton, &QPushButton::clicked,
            this, &ScooterUIWidgetAdmin::onEditButtonClicked);
    leftLayout->
            addWidget(editButton);

    QPushButton *sortButton = new QPushButton("Sort Scooters by Age", this);
    sortButton->setStyleSheet(
            "QPushButton { background-color: #2f4358; color: white; border-radius: 10px; height: 60px; }");
    connect(sortButton, &QPushButton::clicked,
            this, &ScooterUIWidgetAdmin::onSortButtonClicked);
    leftLayout->
            addWidget(sortButton);

    QVBoxLayout *rightLayout = new QVBoxLayout();

    QTableWidget *scooterTable = new QTableWidget(this);
    scooterTable->setRowCount(0);
    scooterTable->setColumnCount(6);
    scooterTable->

            setHorizontalHeaderLabels(
            QStringList()

                    << "ID" << "Brand" << "Model" << "Kilometers" << "StandOrt" << "Zustand");
    scooterTable->setSortingEnabled(true);
    rightLayout->
            addWidget(scooterTable);

    std::vector<Domain::Elektroscooter> scooters = controller->getAll();

    for (
        const auto &scooter
            : scooters) {
        int row = scooterTable->rowCount();
        scooterTable->
                insertRow(row);

        QTableWidgetItem *idItem = new QTableWidgetItem(QString::fromStdString(scooter.get_id()));
        QTableWidgetItem *modellItem = new QTableWidgetItem(QString::fromStdString(scooter.get_modell()));
        QTableWidgetItem *inbetriebnahmedatumItem = new QTableWidgetItem(
                QString::fromStdString(scooter.get_inbetriebnahmedatum()));
        QTableWidgetItem *kilometerItem = new QTableWidgetItem(QString::number(scooter.get_kilometer()));
        QTableWidgetItem *ortItem = new QTableWidgetItem(QString::fromStdString(scooter.get_letzterStandort()));
        QTableWidgetItem *zustandItem = new QTableWidgetItem(QString::fromStdString(scooter.get_aktuellerZustand()));


        scooterTable->
                setItem(row,
                        0, idItem);
        scooterTable->
                setItem(row,
                        1, modellItem);
        scooterTable->
                setItem(row,
                        2, inbetriebnahmedatumItem);
        scooterTable->
                setItem(row,
                        3, kilometerItem);
        scooterTable->
                setItem(row,
                        4, ortItem);
        scooterTable->
                setItem(row,
                        5, zustandItem);
    }

    layout->
            addLayout(leftLayout);
    layout->
            addLayout(rightLayout);


    setLayout(layout);
}

void ScooterUIWidgetAdmin::onGoBackButtonClicked() {
    close();
}