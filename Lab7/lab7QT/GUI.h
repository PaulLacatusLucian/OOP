#ifndef GUI_H
#define GUI_H

#include <QMainWindow>
#include <QMessageBox>
#include <QPushButton>
#include "ScooterUIWidgetAdmin.h"

namespace UI {

    class GUI : public QMainWindow
    {
    Q_OBJECT

    public:
        GUI(QWidget *parent = nullptr);
        ~GUI();

    private slots:
        void onAdminClicked();
        void onUserClicked();
        void onGoBackClicked();
        int inputRepositoryAdmin();

    private:
        QPushButton *adminButton; // Admin button
        QPushButton *userButton; // User button
        QPushButton *goBackButton;

        void showAdminActions();
        void showMessage(const QString& message);

        void showAdminActions(int repoType);

        int inputRepositoryClient();

        void showClientActions(int repoType);

        void showLoginWindow();

        void onLoginClicked(const QString &username, const QString &password);
    };

} // namespace UI

#endif // GUI_H
