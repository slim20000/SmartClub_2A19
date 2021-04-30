#ifndef ACTIVITE_H
#define ACTIVITE_H
#include <QString>
#include <QSqlQueryModel>

class Activite
{
public:
    Activite();
    Activite(int,QString,QString,int);

    int getCODE_ACT();
    QString getTYPE_ACT();
    QString getLEBELLE_ACT();
    int getDATE_H();

    void setCODE_ACT(int);
    void setTYPE_ACT(QString);
    void setLIBELLE_ACT(QString);
    void setDATE_H(int);

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel* chercher(int);
    QSqlQueryModel* trier();

private:
        int CODE_ACT;
        QString TYPE_ACT;
        QString LIBELLE_ACT;
        int DATE_H;

};

#endif // ACTIVITE_H
