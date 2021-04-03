#include "connection.h"
Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
     db = QSqlDatabase::addDatabase("QODBC");

db.setDatabaseName("test1");//inserer le nom de la source de données ODBC
db.setUserName("medaziz");//inserer nom de l'utilisateur
db.setPassword("esprit18");//inserer mot de passe de cet utilisateur
//db.setHostName("localhost");

//db.setPort(1521);


if (db.open())
test=true;





    return  test;
}
