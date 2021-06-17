#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QVariant>
#include <QObject>
#include <QSqlQuery>




class DatabaseManager: public QObject
{
    Q_OBJECT
public:
    DatabaseManager(QString DatabasePath);

public:
    bool IsItAnAllowedUser(QString UserName, QString UserPassword) const;
    void AddRowInDatabase(QString UserName, QString UserPassword) const;
    void RemoveRowInDatabase(QString UserName) const;
    QList<QString> GetClientsInDatabase() const;


signals:
    void DatabaseManagerServerLog(QString Log);

private:
    QSqlDatabase sqlitedb;
};

#endif // DATABASEMANAGER_H
