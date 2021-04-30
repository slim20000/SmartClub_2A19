#ifndef PERSONNEL_H
#define PERSONNEL_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class personnel
{
private:
    int CIN,code_postal,Num_Tel ;
    QString Nom,Prenom,Role,Adresse,Pseudo,Mot_de_passe;

public:
    personnel();
    personnel(int,int,int,QString,QString,QString,QString,QString,QString);

    int get_Cin();
    int get_Cdpostale();
    int get_Numtel();
    QString get_Nom();
    QString get_Prenom();
    QString get_Role();
    QString get_Adresse();
    QString get_Pseudo();
    QString get_Mdp();
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel * trier();
    QSqlQueryModel * chercher(int);
};

#endif // PERSONNEL_H

