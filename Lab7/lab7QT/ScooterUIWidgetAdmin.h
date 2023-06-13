#ifndef SCOOTERUIWIDGETADMIN_H
#define SCOOTERUIWIDGETADMIN_H

#include <QWidget>
#include <memory>
#include <QListWidget>
#include <QTableWidget>
#include "ScooterController.h"

class QVBoxLayout;
class QLabel;
class QPushButton;
class QLineEdit;

class ScooterUIWidgetAdmin : public QWidget
{
Q_OBJECT

public:

    QListWidget* resultList;
    ScooterUIWidgetAdmin(std::shared_ptr<Controller::ScooterController> controller, QWidget* parent = nullptr);

private:
    QTableWidget *scooterTable;


private slots:


    void onSearchButtonClicked();
    void onKilometerFilterButtonClicked();
    void onAgeFilterButtonClicked();
    void onAddButtonClicked();
    void onRemoveButtonClicked();
    void onEditButtonClicked();
    void onSortButtonClicked();
    void onGoBackButtonClicked();


private:
    void setupUI();

    std::shared_ptr<Controller::ScooterController> controller;
    QVBoxLayout* layout;
    QLineEdit* idLineEdit;
    QLineEdit* kilometersLineEdit;
    QLineEdit* modelLineEdit;
    QLineEdit* dateLineEdit;
    QLineEdit* locationLineEdit;
    QLineEdit* statusLineEdit;


    void updateTable();

    void updateTable(QTableWidget *table);
};

#endif // SCOOTERUIWIDGETADMIN_H