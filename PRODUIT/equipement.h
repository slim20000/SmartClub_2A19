#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H
#include <QString>
#include <QDate>
#include <QComboBox>
#include <QSqlQueryModel>
class equipement
{
public:
    equipement();
    equipement(int,QString,QString,QString,QString);
    int getid();
    QString getnom();
    QString getsport();
    QString getsalle();
    QString getprix_achat();

    void setid(int);
    void setnom(QString);
    void setsport(QString);
    void setsalle(QString);
    void setprix_achat(QString);
    QSqlQueryModel* model;

    bool ajouter1();
    bool update1(int);
    QSqlQueryModel * afficher1();
    bool supprimer1(int);
QSqlQueryModel * search(QString);
QSqlQueryModel * order();
QSqlQueryModel * order2();


private:
    int id;
    QString nom,sport,salle,prix_achat;
};


#endif // EQUIPEMENT_H
