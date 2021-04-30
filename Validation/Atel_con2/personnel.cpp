#include "personnel.h"
#include <QDebug>

personnel::personnel()
{
 Nom="";
 Prenom="";
 Adresse="";
 Role="";
 Pseudo="";
 Mot_de_passe="";
 CIN=0;
 code_postal=0;
 Num_Tel=0;
}

personnel::personnel(int CIN ,int code_postal,int Num_Tel,QString Nom,QString Prenom,QString Role,QString Adresse,QString Pseudo,QString Mot_de_passe)
{
  this->CIN=CIN;
  this->code_postal=code_postal;
  this->Num_Tel=Num_Tel;
  this->Nom=Nom;
  this->Prenom=Prenom;
  this->Adresse=Adresse;
  this->Role=Role;
  this->Pseudo=Pseudo;
  this->Mot_de_passe=Mot_de_passe;
}
QString personnel::get_Nom(){return  Nom;}
QString personnel::get_Prenom(){return  Prenom;}
QString personnel::get_Adresse(){return  Adresse;}
QString personnel::get_Role(){return  Role;}
QString personnel::get_Pseudo(){return  Pseudo;}
QString personnel::get_Mdp(){return  Mot_de_passe;}
int personnel::get_Cin(){return  CIN;}
int personnel::get_Cdpostale(){return  code_postal;}
int personnel::get_Numtel(){return  Num_Tel;}

bool personnel::ajouter()
{
QSqlQuery query;

QString res= QString::number(CIN);
query.prepare("INSERT INTO PERSONNEL (CIN,code_postal,Num_Tel,Nom,Prenom,Adresse,Role,Pseudo,Mot_de_passe)"
                             "VALUES (:CIN,:code_postal,:Num_Tel,:Nom,:Prenom,:Adresse,:Role,:Pseudo,:Mot_de_passe)");
query.bindValue(":CIN", res);
query.bindValue(":code_postal", code_postal);
query.bindValue(":Num_Tel", Num_Tel);
query.bindValue(":Nom", Nom);
query.bindValue(":Prenom", Prenom);
query.bindValue(":Adresse", Adresse);
query.bindValue(":Role", Role);
query.bindValue(":Pseudo", Pseudo);
query.bindValue(":Mot_de_passe", Mot_de_passe);

return  query.exec();
}

QSqlQueryModel * personnel::afficher()
{
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from PERSONNEL");
model->setHeaderData(0, Qt::Vertical, QObject::tr("CIN"));
model->setHeaderData(1, Qt::Vertical, QObject::tr("code_postal"));
model->setHeaderData(2, Qt::Vertical, QObject::tr("Num_Tel"));
model->setHeaderData(3, Qt::Vertical, QObject::tr("Nom"));
model->setHeaderData(4, Qt::Vertical, QObject::tr("Prenom"));
model->setHeaderData(5, Qt::Vertical, QObject::tr("Adresse"));
model->setHeaderData(6, Qt::Vertical, QObject::tr("Role"));
model->setHeaderData(7, Qt::Vertical, QObject::tr("Pseudo"));
model->setHeaderData(8, Qt::Vertical, QObject::tr("Mot_de_passe"));
return model;
}

bool personnel::supprimer(int CIN)
{
QSqlQuery query;
QString res= QString::number(CIN);
query.prepare("Delete from PERSONNEL where CIN = :CIN ");
query.bindValue(":CIN",res);
return    query.exec();
}

bool personnel::modifier(int CIN2)
{
    QSqlQuery query;
    QString res= QString::number(CIN2);
    query.prepare("update PERSONNEL set code_postal=:code_postal,Num_Tel =:Num_Tel,Nom = '"+Nom+"',Prenom = '"+Prenom+"',Adresse = '"+Adresse+"',Role = '"+Role+"',Pseudo = '"+Pseudo+"',Mot_de_passe = '"+Mot_de_passe+"' where CIN =:CIN2");
    query.bindValue(":CIN2", res);
    query.bindValue(":code_postal",code_postal);
    query.bindValue(":Num_Tel",Num_Tel);
    query.bindValue(":Nom", Nom);
    query.bindValue(":Prenom", Prenom);
    query.bindValue(":Adresse", Adresse);
    query.bindValue(":Role", Role);
    query.bindValue(":Pseudo", Pseudo);
    query.bindValue(":Mot_de_passe", Mot_de_passe);

    return    query.exec();
}

QSqlQueryModel * personnel::chercher(int CIN)
{
personnel p;
    QSqlQuery query;
    QString res=QString::number(CIN);
    query.prepare("Select * from PERSONNEL where CIN=:CIN");
    query.bindValue(":CIN",res);
    QSqlQueryModel * model = new QSqlQueryModel();
    query.exec();
    model->setQuery(query);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Code_postale "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Mot_de_passe"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Num_tel"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Pseudo "));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Adresse "));

return model;
}
QSqlQueryModel *personnel::trier()
{

    QSqlQuery query;
   query.prepare("select * from PERSONNEL order By CIN");
   QSqlQueryModel * model = new QSqlQueryModel();
   query.exec();
   model->setQuery(query);
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom "));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("Code_postale "));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("Mot_de_passe"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("Num_tel"));
   model->setHeaderData(6, Qt::Horizontal, QObject::tr("Pseudo "));
   model->setHeaderData(7, Qt::Horizontal, QObject::tr("Adresse "));
   return model;

}
