#include <QMainWindow>
#include <QMainWindow>
#include <QMessageBox>
#include <QtSql>
#include <QSqlDatabase>
#include <QtSql>
#include <QDebug>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "connexion.h"
#include <QApplication>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include "evenement.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QPrintDialog>
#include <QPrinter>

//Test tuto Git


connexion::connexion()
{

}

bool connexion::createconnection()
{
    db = QSqlDatabase::addDatabase("QODBC");
    bool test=false;
    db.setHostName("testbd");
        db.setUserName("system");
        db.setPassword("admin");
        db.setDatabaseName("testbd");
        if(db.open()) test = true;
        return test;
}

void connexion::closeconnection()
{
    db.close();
}
