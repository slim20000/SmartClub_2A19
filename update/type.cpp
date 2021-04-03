#include "type.h"

#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QDate>

type::type()
{
id=0; nom=""; description="",description2="",description3="";
}
type::type(int id, QString nom , QString description,QString description2,QString description3)
{this->id=id;this->nom=nom;this->description=description ;this->description2=description2,this->description3=description3;}
int type::getid(){return id;}
QString type::getnom(){return nom;}
QString type::getdescription(){return description;}
QString type::getdescription2(){return description2;}
QString type::getdescription3(){return description3;}



void type::setid(int id){this->id=id;}

void type::setnom(QString nom){this->nom=nom;}
void type::setdescription(QString description){this->description=description;}
void type::setdescription2(QString description2){this->description2=description2;}

void type::setdescription3(QString description3){this->description3=description3;}

bool type::update1(int id){
    //QString res=QString::number(id);
    QSqlQuery query;

    query.prepare("update type SET id=:id,nom=:nom,description=:description,description2=:description2,description3=:description3 where id=:id");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":description", description);
    query.bindValue(":description2", description2);

    query.bindValue(":description3", description3);


     return query.exec();
}

bool type::ajouter1()
{
QString res=QString::number(id);

QSqlQuery query;

query.prepare("insert into type (id, nom, description,description2,description3) "
              "values (:id, :nom, :description,:description2,:description3)");
query.bindValue(0, res);
query.bindValue(1, nom);
query.bindValue(2, description);
query.bindValue(3, description2);
query.bindValue(4, description3);

 return query.exec();

}
bool type::supprimer1(int id)
{
    QSqlQuery query;

    query.prepare("Delete from type where id=:id");
    query.bindValue(0, id);

     return query.exec();
}
QSqlQueryModel * type::search(QString nom)
{
    QSqlQueryModel* model = new QSqlQueryModel();
     model->setQuery("select * from type where (nom LIKE '%"+nom+"%') ");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("description"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("description2"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("description3"));
     return model;
}
QSqlQueryModel * type::order()
{
    QSqlQueryModel* model = new QSqlQueryModel();
     model->setQuery("select * from type ORDER BY id ASC");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("description"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("description2"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("description3"));
     return model;
}
QSqlQueryModel * type::order2()
{
    QSqlQueryModel* model = new QSqlQueryModel();
     model->setQuery("select * from type ORDER BY nom ASC");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("description"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("description2"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("description3"));
     return model;
}
QSqlQueryModel * type::afficher1()
{
   QSqlQueryModel* model=new QSqlQueryModel();
   model->setQuery("select id,nom,description,description2,description3 from type");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("description"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("description2"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("description3"));


return model;
}

