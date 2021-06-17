#include "DatabaseManager.h"

#include <QFileInfo>
#include <QDebug>

DatabaseManager::DatabaseManager(QString DatabasePath)
{
    this->sqlitedb = QSqlDatabase::addDatabase("QSQLITE");
    sqlitedb.setDatabaseName(DatabasePath);

    // If the database already exists, open it
    if(QFileInfo::exists(DatabasePath)){
        if(sqlitedb.open()) {
            emit DatabaseManagerServerLog("Database successfully opened");
        }else{
            emit DatabaseManagerServerLog("Database <strong>" + DatabasePath + "</strong> exists but can't be openned... ");
        }
    // else create it
    }else{
        if(sqlitedb.open()) {
            emit DatabaseManagerServerLog("Database just created <strong>" + DatabasePath + "</strong>");
            sqlitedb.exec("CREATE TABLE Clients(ID integer primary key autoincrement  not null , user VARCHAR(25), password VARCHAR(25));");
        }else{
            emit DatabaseManagerServerLog("Database can't be created on path <strong>" + DatabasePath + "</strong>");
        }
    }
}

bool DatabaseManager::IsItAnAllowedUser(QString UserName, QString UserPassword) const{
    bool UserValidation = false;
    QSqlQuery query;
    query.exec("SELECT * FROM Clients where (user = '" + UserName + "' and password = '" + UserPassword + "') limit 1");
    while (query.next())
        UserValidation = true;
    return UserValidation;
}

void DatabaseManager::AddRowInDatabase(QString UserName, QString UserPassword) const{
    sqlitedb.exec("insert into clients(user, password) values('"+UserName+"', '"+UserPassword+"');");
}

void DatabaseManager::RemoveRowInDatabase(QString UserName) const{
    qDebug() << UserName;
    sqlitedb.exec("DELETE FROM clients WHERE user='"+UserName+"';");
}

QList<QString> DatabaseManager::GetClientsInDatabase() const{
    QList<QString> allowedClients ={};
    QSqlQuery queryRequest;
    queryRequest.exec("SELECT * FROM Clients");
    while (queryRequest.next())
        allowedClients.append(queryRequest.value("user").toString());
    return allowedClients;
}
