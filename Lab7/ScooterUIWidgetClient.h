#ifndef SCOOTERUIWIDGETCLIENT_H
#define SCOOTERUIWIDGETCLIENT_H

#include <QWidget>
#include <memory>
#include <QListWidget>
#include <QTableWidget>
#include "ScooterController.h"

class QVBoxLayout;
class QLabel;
class QPushButton;
class QLineEdit;

class ScooterUIWidgetClient : public QWidget
{
Q_OBJECT

public:

    QListWidget* resultList;
    ScooterUIWidgetClient(std::shared_ptr<Controller::ScooterController> controller, QWidget* parent = nullptr);

private slots:
    void onSearchButtonClicked();
    void onKilometerFilterButtonClicked();
    void onAgeFilterButtonClicked();
    void onReserveButtonClicked();
    void onAvalibleButtonClicked();
    void onParkButtonClicked();
    void onGoBackButtonClicked();


private:
    void setupUI();
    void updateTable(QTableWidget* table);

    QTableWidget *scooterTable;

    std::shared_ptr<Controller::ScooterController> controller;
    QVBoxLayout* layout;
    QLineEdit* idLineEdit;
    QLineEdit* kilometersLineEdit;
    QLineEdit* modelLineEdit;
    QLineEdit* dateLineEdit;
    QLineEdit* locationLineEdit;
    QLineEdit* statusLineEdit;
    QLineEdit* parkButton;
};

#endif // SCOOTERUIWIDGETCLIENT_H