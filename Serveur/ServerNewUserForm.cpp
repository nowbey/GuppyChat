#include "ServerNewUserForm.h"

ServerNewUserForm::ServerNewUserForm(DatabaseManager *SQLDatabaseManager){

    this->SQLDatabaseManager = SQLDatabaseManager;

    QFormLayout *formLayout = new QFormLayout;
    UserNameLabel = new QLabel("Username");
    UserName = new QLineEdit();
    UserPasswordLabel = new QLabel("Password");
    UserPassword = new QLineEdit();
    WarningMessage = new QLabel("");
    WarningMessage->hide();
    formLayout->addRow(UserNameLabel, UserName);
    formLayout->addRow(UserPasswordLabel,UserPassword);
    formLayout->addRow(WarningMessage);

    AddToDatabase = new QPushButton(tr("Create user"));
    connect(AddToDatabase, SIGNAL(clicked()), this, SLOT(on_AddToDatabase_clicked()));
    connect(UserName, SIGNAL(returnPressed()), this, SLOT(on_UserName_returnPressed()));
    connect(UserPassword, SIGNAL(returnPressed()), this, SLOT(on_UserPassword_returnPressed()));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addLayout(formLayout);
    layout->addWidget(AddToDatabase);

    setLayout(layout);

    setWindowTitle(tr("Create new account"));
}

void ServerNewUserForm::on_AddToDatabase_clicked(){
    this->SQLDatabaseManager->AddRowInDatabase(UserName->text(), UserPassword->text());
    UserName->clear();
    UserPassword->clear();
    this->close();

}
// Pressing the Enter key has the same behavior as clicking the "AddToDatabase" button.
void ServerNewUserForm::on_UserName_returnPressed(){
    on_AddToDatabase_clicked();
}
// Pressing the Enter key has the same behavior as clicking the "AddToDatabase" button.
void ServerNewUserForm::on_UserPassword_returnPressed(){
    on_AddToDatabase_clicked();
}
