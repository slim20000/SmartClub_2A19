#ifndef SALLE_H
#define SALLE_H
#include <QString>
#include <QSqlQueryModel>

class Salle
{
public:
    Salle();
    Salle(int,int,QString,QString,QString);

    int getCODE_SALLE();
    int getNUM_TEL();
    QString getNOM_SALLE();
    QString getADRESSE();
    QString getLIBELLE_SALLE();

    void setCODE_SALLE(int);
    void setNUM_TEL(int);
    void setNOM_SALLE(QString);
    void setADRESSE(QString);
    void setLIBELLE_SALLE(QString);

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel* chercher(int);
    QSqlQueryModel* trier();

private:
        int CODE_SALLE;
        int NUM_TEL;
        QString NOM_SALLE;
        QString ADRESSE;
        QString LIBELLE_SALLE;

};

#endif // SALLE_H
