#include "salle.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>


Salle::Salle()
{
    CODE_SALLE=0;
    NUM_TEL=0;
    NOM_SALLE="";
    ADRESSE="";
    LIBELLE_SALLE="";

}

Salle::Salle(int CODE_SALLE,int NUM_TEL,QString NOM_SALLE,QString ADRESSE,QString LIBELLE_SALLE)
{
    this->CODE_SALLE=CODE_SALLE;
    this->NUM_TEL=NUM_TEL;
    this->NOM_SALLE=NOM_SALLE;
    this->ADRESSE=ADRESSE;
    this->LIBELLE_SALLE=LIBELLE_SALLE;
}
int Salle::getCODE_SALLE()
{
    return CODE_SALLE;
}
int Salle::getNUM_TEL()
{
    return NUM_TEL;
}
QString Salle::getNOM_SALLE()
{
    return NOM_SALLE;
}
QString Salle::getADRESSE()
{
    return ADRESSE;
}
QString Salle::getLIBELLE_SALLE()
{
    return LIBELLE_SALLE;
}

void Salle::setCODE_SALLE(int CODE_SALLE)
{
    this->CODE_SALLE=CODE_SALLE;
}
void Salle::setNUM_TEL(int NUM_TEL)
{
    this->NUM_TEL=NUM_TEL;
}
void Salle::setNOM_SALLE(QString NOM_SALLE)
{
    this->NOM_SALLE=NOM_SALLE;
}
void Salle::setADRESSE(QString ADRESSE)
{
    this->ADRESSE=ADRESSE;
}
void Salle::setLIBELLE_SALLE(QString LIBELLE_SALLE)
{
    this->LIBELLE_SALLE=LIBELLE_SALLE;
}
bool Salle::ajouter()
{

    QSqlQuery query;
    QString CODE_SALLE_str=QString::number(CODE_SALLE);
    QString NUM_TEL_str=QString::number(NUM_TEL);
          query.prepare("INSERT INTO salle (CODE_SALLE, NUM_TEL,NOM_SALLE,ADRESSE,LIBELLE_SALLE) "
                        "VALUES (:CODE_SALLE, :NUM_TEL, :NOM_SALLE, :ADRESSE, :LIBELLE_SALLE)");
          query.bindValue(":CODE_SALLE", CODE_SALLE_str);
          query.bindValue(":NUM_TEL", NUM_TEL_str);
          query.bindValue(":NOM_SALLE", NOM_SALLE);
          query.bindValue(":ADRESSE", ADRESSE);
          query.bindValue(":LIBELLE_SALLE", LIBELLE_SALLE);
          query.exec();
}

QSqlQueryModel* Salle::afficher()
{
    QSqlQueryModel* model= new QSqlQueryModel();

          model->setQuery("SELECT* FROM SALLE");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("Code"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Num Telephone"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Adresse"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Code Postale"));


        return  model;

}

bool Salle::supprimer(int CODE_SALLE)
{
    QSqlQuery query;

          query.prepare("DELETE FROM SALLE WHERE CODE_SALLE=:CODE_SALLE");
          query.bindValue(":CODE_SALLE", CODE_SALLE);

          return query.exec();


}
bool Salle::modifier(int CODE_SALLE)
{
    QSqlQuery query;
    QString res= QString::number(CODE_SALLE);
    query.prepare("update SALLE set NUM_TEL =:NUM_TEL,NOM_SALLE =:NOM_SALLE,ADRESSE=:ADRESSE,LIBELLE_SALLE=:LIBELLE_SALLE where CodeDepartement =:CodeDepartement2");
    query.bindValue(":CODE_SALLE", res);
    query.bindValue(":NUM_TEL",NUM_TEL);
    query.bindValue(":NOM_SALLE",NOM_SALLE);
    query.bindValue(":ADRESSE",ADRESSE);
    query.bindValue(":LIBELLE_SALLE",LIBELLE_SALLE);
    return    query.exec();
}
QSqlQueryModel* Salle::chercher(int CODE_SALLE)
{
    Salle S;
    QSqlQuery query;
    QString res=QString::number(CODE_SALLE);
    query.prepare("Select * from SALLE where CODE_SALLE=:CODE_SALLE");
    query.bindValue(":CODE_SALLE",res);
    QSqlQueryModel * model = new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE_SALLE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr(" NUM_TEL"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("  NOM_SALLE "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("  ADRESSE "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("  LIBELLE_SALLE "));



return model;
}
QSqlQueryModel* Salle::trier()
{

    QSqlQuery query;
   query.prepare("select * from SALLE order By CODE_SALLE");
   QSqlQueryModel * model = new QSqlQueryModel();
   query.exec();
   model->setQuery(query);
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE_SALLE"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr(" NUM_TEL"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("  NOM_SALLE "));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("  ADRESSE "));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("  LIBELLE_SALLE "));


   return model;

}
