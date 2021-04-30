#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>


class Connection
{
    QSqlDatabase db;
public:
    Connection();
    bool createconnect();
    void fermerConnexion();
};

#endif // CONNECTION_H
