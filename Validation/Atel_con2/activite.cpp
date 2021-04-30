#include "activite.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>


Activite::Activite()
{
    CODE_ACT=0;
    TYPE_ACT="";
    LIBELLE_ACT="";
    DATE_H=0;

}

Activite::Activite(int CODE_ACT,QString TYPE_ACT,QString LIBELLE_ACT,int DATE_H)
{
    this->CODE_ACT=CODE_ACT;
    this->TYPE_ACT=TYPE_ACT;
    this->LIBELLE_ACT=LIBELLE_ACT;
    this->DATE_H=DATE_H;
}
int Activite::getCODE_ACT()
{
    return CODE_ACT;
}
QString Activite::getTYPE_ACT()
{
    return TYPE_ACT;
}
QString Activite::getLEBELLE_ACT()
{
    return LIBELLE_ACT;
}
int Activite::getDATE_H()
{
    return DATE_H;
}

void Activite::setCODE_ACT(int CODE_ACT)
{
    this->CODE_ACT=CODE_ACT;
}
void Activite::setTYPE_ACT(QString TYPE_ACT)
{
    this->TYPE_ACT=TYPE_ACT;
}
void Activite::setLIBELLE_ACT(QString LIBELLE_ACT)
{
    this->LIBELLE_ACT=LIBELLE_ACT;
}
void Activite::setDATE_H(int DATE_H)
{
    this->DATE_H=DATE_H;
}
bool Activite::ajouter()
{
    bool test=false;

    QSqlQuery query;
    QString CODE_ACT_str=QString::number(CODE_ACT);
    QString DATE_H_str=QString::number(DATE_H);
          query.prepare("INSERT INTO activite (CODE_ACT, TYPE_ACT,LIBELLE_ACT,DATE_H) "
                        "VALUES (:CODE_ACT, :TYPE_ACT, :LIBELLE_ACT, :DATE_H)");
          query.bindValue(":CODE_ACT", CODE_ACT_str);
          query.bindValue(":TYPE_ACT", TYPE_ACT);
          query.bindValue(":LIBELLE_ACT", LIBELLE_ACT);
          query.bindValue(":DATE_H", DATE_H_str);
          query.exec();


    return test;
}

QSqlQueryModel* Activite::afficher()
{
    QSqlQueryModel* model= new QSqlQueryModel();

          model->setQuery("SELECT* FROM ACTIVITE");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("Code"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("type act"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("libelle act"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_H"));

     return  model;

}

bool Activite::supprimer(int CODE_ACT)
{
    QSqlQuery query;

          query.prepare("DELETE FROM ACTIVITE WHERE CODE_ACT=:CODE_ACT");
          query.bindValue(":CODE_ACT", CODE_ACT);

          return query.exec();


}
bool Activite::modifier(int CODE_ACT)
{
    QSqlQuery query;
    QString res= QString::number(CODE_ACT);
    query.prepare("upDATE_H ACTIVITE set TYPE_ACT =:TYPE_ACT,LIBELLE_ACT =:LIBELLE_ACT,DATE_H=:DATE_H where CodeDepartement =:CodeDepartement2");
    query.bindValue(":CODE_ACT", res);
    query.bindValue(":TYPE_ACT",TYPE_ACT);
    query.bindValue(":LIBELLE_ACT",LIBELLE_ACT);
    query.bindValue(":DATE_H",DATE_H);

    return    query.exec();
}
QSqlQueryModel* Activite::chercher(int CODE_ACT)
{
    Activite A;
    QSqlQuery query;
    QString res=QString::number(CODE_ACT);
        query.prepare("Select * from ACTIVITE where CODE_ACT=:CODE_ACT");
        query.bindValue(":CODE_ACT",res);
    QSqlQueryModel * model = new QSqlQueryModel();
        query.exec();
        model->setQuery(query);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE_ACT"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr(" TYPE_ACT"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("  LIBELLE_ACT "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr(" DATE_H "));

    return model;
}
QSqlQueryModel* Activite::trier()
{

   QSqlQuery query;
        query.prepare("select * from ACTIVITE order By CODE_ACT");
   QSqlQueryModel * model = new QSqlQueryModel();
        query.exec();
        model->setQuery(query);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE_ACT"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr(" TYPE_ACT"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("  LIBELLE_ACT "));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("  DATE_H "));

    return model;

}
