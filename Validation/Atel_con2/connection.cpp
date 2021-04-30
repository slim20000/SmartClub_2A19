#include "connection.h"

Connection::Connection()
{

}
bool Connection::createconnect()
{
        bool test=false;
            db = QSqlDatabase::addDatabase("QSQLITE");
            db.setDatabaseName("Projet_2A");
            db.setUserName("borji");//inserer nom de l'utilisateur
            db.setPassword("emahm");//inserer mot de passe de cet utilisateur
            db.setHostName("localhost");


            if (db.open())
                return true;

            return  test;

}
