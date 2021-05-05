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
#include <ctime>
#include <dos.h>


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

bool sponsor::update(){
    QString res=QString::number(id_sp);
    QSqlQuery query;

    query.prepare("UPDATE Sponsor SET id_sp=:id_sp, nom_sp=:nom_sp where id_sp=:id_sp");
    query.bindValue(":id_sp", res);
    query.bindValue(":nom_sp", nom_sp);
    query.bindValue(":id_sp", res);
     return query.exec();
}

bool sponsor::ajouter()
{
    bool test = true;

    QSqlQuery query;
    QString res= QString::number(id_sp);
          query.prepare("INSERT INTO Sponsor (id_sp, nom_sp) "
                        "VALUES (:id_sp, :nom_sp)");
          query.bindValue(":id_sp", res);
          query.bindValue(":nom_sp", nom_sp);
          query.exec();
    return test;
}

QSqlQueryModel* sponsor::affichersp()
{
QSqlQueryModel* model=new QSqlQueryModel();

model->setQuery("SELECT* FROM Sponsor");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));

return model;
}

bool sponsor::supprimer(int id_sp)
{
QSqlQuery query;


query.prepare("Delete from Sponsor  where id_sp=:id_sp");
query.bindValue(0, id_sp);
return query.exec();
}

QSqlQueryModel * sponsor::search(QString nom_sp)
{
    QSqlQueryModel* model = new QSqlQueryModel();
     model->setQuery("select * from Sponsor where (nom_sp LIKE '%"+nom_sp+"%') ");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_sp"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_sp"));

     return model;
}


QSqlQueryModel * sponsor::Tri2()
{
    QSqlQueryModel* model = new QSqlQueryModel();
     model->setQuery("select * from Sponsor ORDER BY nom_sp ASC");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_sp"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom_sp"));

     return model;
}
