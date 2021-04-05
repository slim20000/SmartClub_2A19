#include "sponsor.h"
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

sponsor::sponsor()
{
  id_sp=0; nom_sp=" ";
}

sponsor::sponsor(int id_sp,QString nom_sp)
{
    this->id_sp=id_sp; this->nom_sp=nom_sp;
}

int sponsor::getid()
{
return id_sp;
}
QString sponsor::getnom()
{
    return nom_sp;
}

void sponsor::setid(int id_sp)
{
    this->id_sp=id_sp;
}
void sponsor::setnom(QString nom_sp)
{
    this->nom_sp=nom_sp;
}

