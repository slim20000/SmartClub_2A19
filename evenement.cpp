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


Evenement::Evenement()
{
id=0; nom=" "; prenom="";
}

Evenement::Evenement(int id,QString nom,QString prenom)
{
this->id=id; this->nom=nom; this->prenom=prenom;
}
int Evenement::getid()
{
return id;
}
QString Evenement::getnom()
{
    return nom;
}
QString Evenement::getprenom()
{
    return prenom;
}
void Evenement::setid(int id)
{
    this->id=id;
}
void Evenement::setnom(QString nom)
{
    this->nom=nom;
}
void Evenement::setprenom(QString prenom)
{
    this->prenom=prenom;
}

bool Evenement::update(){
    QString res=QString::number(id);
    QSqlQuery query;

    query.prepare("UPDATE Evenement SET id=:id, nom=:nom,prenom=:prenom where id=:id");
    query.bindValue(0, res);
    query.bindValue(1, nom);
    query.bindValue(2, prenom);
     return query.exec();
}

bool Evenement::ajouter()
{
    bool test = true;

    QSqlQuery query;
    QString res= QString::number(id);
          query.prepare("INSERT INTO Evenement (id, nom, prenom) "
                        "VALUES (:id, :nom, :prenom)");
          query.bindValue(":id", res);
          query.bindValue(":nom", nom);
          query.bindValue(":prenom", prenom);
          query.exec();
    return test;
}

QSqlQueryModel* Evenement::afficher()
{
QSqlQueryModel* model=new QSqlQueryModel();

model->setQuery("SELECT* FROM Evenement");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));

return model;
}

bool Evenement::supprimer(int id)
{
QSqlQuery query;


query.prepare("Delete from Evenement  where id=:ID");
query.bindValue(0, id);
return query.exec();
}

//QSqlQueryModel * Evenement::search(QString nom)
//{
//    QSqlQueryModel* model = new QSqlQueryModel();
//     model->setQuery("select * from Evenement where (nom LIKE '%"+nom+"%') ");
//     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
//     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
//     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));

//     return model;
//}
