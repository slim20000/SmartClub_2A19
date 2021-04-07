#include "equipement.h"

#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QDate>

equipement::equipement()
{
id=0; nom=""; sport="",salle="",prix_achat="";
}
equipement::equipement(int id, QString nom , QString sport,QString salle,QString prix_achat)
{this->id=id;this->nom=nom;this->sport=sport ;this->salle=salle,this->prix_achat=prix_achat;}
int equipement::getid(){return id;}
QString equipement::getnom(){return nom;}
QString equipement::getsport(){return sport;}
QString equipement::getsalle(){return salle;}
QString equipement::getprix_achat(){return prix_achat;}



void equipement::setid(int id){this->id=id;}

void equipement::setnom(QString nom){this->nom=nom;}
void equipement::setsport(QString sport){this->sport=sport;}
void equipement::setsalle(QString salle){this->salle=salle;}

void equipement::setprix_achat(QString prix_achat){this->prix_achat=prix_achat;}

bool equipement::update1(int id){
    //QString res=QString::number(id);
    QSqlQuery query;

    query.prepare("update equipement SET id=:id,nom=:nom,sport=:sport,salle=:salle,prix_achat=:prix_achat where id=:id");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":sport", sport);
    query.bindValue(":salle", salle);

    query.bindValue(":prix_achat", prix_achat);


     return query.exec();
}

bool equipement::ajouter1()
{
QString res=QString::number(id);

QSqlQuery query;

query.prepare("insert into equipement (id, nom, sport,salle,prix_achat) "
              "values (:id, :nom, :sport,:salle,:prix_achat)");
query.bindValue(0, res);
query.bindValue(1, nom);
query.bindValue(2, sport);
query.bindValue(3, salle);
query.bindValue(4, prix_achat);

 return query.exec();

}
bool equipement::supprimer1(int id)
{
    QSqlQuery query;

    query.prepare("Delete from equipement where id=:id");
    query.bindValue(0, id);

     return query.exec();
}
QSqlQueryModel * equipement::search(QString nom)
{
    QSqlQueryModel* model = new QSqlQueryModel();
     model->setQuery("select * from equipement where (nom LIKE '%"+nom+"%') ");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("sport"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("salle"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix_achat"));
     return model;
}
QSqlQueryModel * equipement::order()
{
    QSqlQueryModel* model = new QSqlQueryModel();
     model->setQuery("select * from equipement ORDER BY id ASC");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("sport"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("salle"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix_achat"));
     return model;
}
QSqlQueryModel * equipement::order2()
{
    QSqlQueryModel* model = new QSqlQueryModel();
     model->setQuery("select * from equipement ORDER BY nom ASC");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("sport"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("salle"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix_achat"));
     return model;
}
QSqlQueryModel * equipement::afficher1()
{
   QSqlQueryModel* model=new QSqlQueryModel();
   model->setQuery("select id,nom,sport,salle,prix_achat from equipement");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("sport"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("salle"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix_achat"));


return model;
}

