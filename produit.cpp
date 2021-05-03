#include "produit.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QDate>

produit::produit()
{
id=0; nom=""; prixachat="",categorie="",prix_vente="";
}
produit::produit(int id,QDate age, QString nom , QString prixachat,QString prix_vente,QString categorie)
{this->id=id;this->nom=nom;this->prixachat=prixachat;this->categorie=categorie;this->age=age;this->prix_vente=prix_vente; }
int produit::getid(){return id;}
QDate produit::getage(){return age;}

QString produit::getprix_vente(){return prix_vente;}
QString produit::getcategorie(){return categorie;}
//QDate Etudiant::getdatenes(){return datenes;}

QString produit::getnom(){return nom;}
QString produit::getprixachat(){return prixachat;}
//QString produit::getcategorie(){return categorie;}
//QString produit::getprix_vente(){return prix_vente;}

//QString produit::getage(){return age;}
void produit::setid(int id){this->id=id;}
void produit::setage(QDate age){this->age=age;}

void produit::setnom(QString nom){this->nom=nom;}
void produit::setprixachat(QString prixachat){this->prixachat=prixachat;}
void produit::setcategorie(QString categorie){this->categorie=categorie;}
void produit::setprix_vente(QString prix_vente){this->prix_vente=prix_vente;}

//void produit::setage(QString age){this->age=age;}

bool produit::update(int id){
    //QString res=QString::number(id);
    QSqlQuery query;

    query.prepare("update produit SET id=:id,nom=:nom,prixachat=:prixachat,prix_vente=:prix_vente,categorie=:categorie,age=:age where id=:id");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":prixachat", prixachat);
    query.bindValue(":prix_vente", prix_vente);
    query.bindValue(":categorie", categorie);
    query.bindValue(":age", age);


     return query.exec();
}

bool produit::ajouter()
{
QString res=QString::number(id);
//QString agee=QString::number(age);

QSqlQuery query;

query.prepare("insert into produit (id, nom, prixachat,prix_vente,categorie,age) "
              "values (:id, :nom, :prixachat,:categorie,:prix_vente,:age)");
query.bindValue(0, res);
query.bindValue(1, nom);
query.bindValue(2, prixachat);
query.bindValue(3, categorie);
query.bindValue(4, prix_vente);
query.bindValue(5, age);

 return query.exec();

}
bool produit::supprimer(int id)
{
    QSqlQuery query;

    query.prepare("Delete from produit where id=:id");
    query.bindValue(0, id);

     return query.exec();
}
QSqlQueryModel * produit::search1(QString nom)
{
    QSqlQueryModel* model = new QSqlQueryModel();
     model->setQuery("select id,nom,prixachat,categorie,prix_vente,age from produit where (nom LIKE '%"+nom+"%') ");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("prixachat"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix_vente"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("categorie"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("date d'Expiration"));
     return model;
}
QSqlQueryModel * produit::order1()
{
    QSqlQueryModel* model = new QSqlQueryModel();
     model->setQuery("select id,nom,prixachat,categorie,prix_vente,age from produit ORDER BY id ASC");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("prixachat"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix_vente"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("categorie"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("date d'Expiration"));
     return model;
}
QSqlQueryModel * produit::order3()
{
    QSqlQueryModel* model = new QSqlQueryModel();
     model->setQuery("select id,nom,prixachat,categorie,prix_vente,age from produit ORDER BY nom ASC");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("prixachat"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix_vente"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("categorie"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("date d'Expiration"));

     return model;
}
QSqlQueryModel * produit::afficher3()
{
   QSqlQueryModel* model=new QSqlQueryModel();
   model->setQuery("select id,nom,prixachat,categorie,prix_vente,age from produit");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("prixachat"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix_vente"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("categorie"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("date d'Expiration"));

return model;
}



