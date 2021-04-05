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


Evenement::Evenement()
{
id_eve=0; nom_eve=" "; type_eve="";
}

Evenement::Evenement(int id_eve,QString nom_eve,QString type_eve)
{
this->id_eve=id_eve; this->nom_eve=nom_eve; this->type_eve=type_eve;
}
int Evenement::getid()
{
return id_eve;
}
QString Evenement::getnom()
{
    return nom_eve;
}
QString Evenement::getprenom()
{
    return type_eve;
}
void Evenement::setid(int id_eve)
{
    this->id_eve=id_eve;
}
void Evenement::setnom(QString nom_eve)
{
    this->nom_eve=nom_eve;
}
void Evenement::setprenom(QString type_eve)
{
    this->type_eve=type_eve;
}

bool Evenement::update(){
    QString res=QString::number(id_eve);
    QSqlQuery query;

    query.prepare("UPDATE Evenement SET id_eve=:id_eve, nom_eve=:nom_eve,type_eve=:type_eve where id_eve=:id_eve");
    query.bindValue(":id_eve", res);
    query.bindValue(":nom_eve", nom_eve);
    query.bindValue(":type_eve", type_eve);
    query.bindValue(":id_eve", res);
     return query.exec();
}

bool Evenement::ajouter()
{
    bool test = true;

    QSqlQuery query;
    QString res= QString::number(id_eve);
          query.prepare("INSERT INTO Evenement (id_eve, nom_eve, type_eve) "
                        "VALUES (:id_eve, :nom_eve, :type_eve)");
          query.bindValue(":id_eve", res);
          query.bindValue(":nom_eve", nom_eve);
          query.bindValue(":type_eve", type_eve);
          query.exec();
    return test;
}

QSqlQueryModel* Evenement::afficher()
{
QSqlQueryModel* model=new QSqlQueryModel();

model->setQuery("SELECT* FROM Evenement");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_eve"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_eve"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));

return model;
}

bool Evenement::supprimer(int id_eve)
{
QSqlQuery query;


query.prepare("Delete from Evenement  where id_eve=:id_eve");
query.bindValue(0, id_eve);
return query.exec();
}

QSqlQueryModel * Evenement::search(QString nom_eve)
{
    QSqlQueryModel* model = new QSqlQueryModel();
     model->setQuery("select * from Evenement where (nom_eve LIKE '%"+nom_eve+"%') ");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_eve"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_eve"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("type_eve"));

     return model;
}
