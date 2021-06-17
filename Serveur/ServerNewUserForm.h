#ifndef SERVERNEWUSERFORM_H
#define SERVERNEWUSERFORM_H

#include <QtWidgets>
#include <QSqlQuery>

#include "DatabaseManager.h"

/*---------------------------------  ServerNewUserForm  ----------------------------------
 * The database must be successfully opened before this object creating
 * It Open a window to manage the database, add or remove rows (allowed users)
 *-----------------------------------------------------------------------------------------*/
class ServerNewUserForm: public QWidget
{
    Q_OBJECT
public:
    ServerNewUserForm(DatabaseManager *SQLDatabaseManager);

private:
    QLabel *UserNameLabel;
    QLineEdit *UserName;
    QLabel *UserPasswordLabel;
    QLineEdit *UserPassword;
    QPushButton *AddToDatabase;
    QLabel *WarningMessage;

    DatabaseManager *SQLDatabaseManager;


private slots:
    void on_AddToDatabase_clicked();
    void on_UserName_returnPressed();       // Pressing the Enter key has the same behavior as clicking the "AddToDatabase" button.
    void on_UserPassword_returnPressed();   // Pressing the Enter key has the same behavior as clicking the "AddToDatabase" button.

};

#endif // SERVERNEWUSERFORM_H

