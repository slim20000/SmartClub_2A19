#ifndef PRODUIT_H
#define PRODUIT_H
#include <QString>
#include <QDate>
#include <QComboBox>
#include <QSqlQueryModel>
class produit
{
public:
    produit();
    produit(int,QDate,QString,QString,QString,QString);
    int getid();

    QString getnom();
    QString getprixachat();
    QString getprix_vente();
    QString getcategorie();
    QDate getage();
    void setid(int);
    void setnom(QString);
    void setprixachat(QString);
   void setprix_vente(QString);
    void setcategorie(QString);
    void setage(QDate);
    bool ajouter();
    bool update(int);
    bool removeRows();
    QSqlQueryModel * afficher3();
    bool supprimer(int);
    QSqlQueryModel * search1(QString);
    QSqlQueryModel * order1();
    QSqlQueryModel * order3();

private:
    int id;
    QDate age;
    QString nom,prixachat,categorie,prix_vente;
};

#endif // PRODUIT_H
