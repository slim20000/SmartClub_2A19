#ifndef EVENEMENT_H
#define EVENEMENT_H
#include <QMainWindow>
#include <QMainWindow>
#include <QMessageBox>
#include <QtSql>
#include <QSqlDatabase>
#include <QtSql>
#include <QDebug>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "connexion.h"
#include <QApplication>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtDebug>
#include <QObject>
#include <QPrintDialog>
#include <QPrinter>

class Evenement
{
public:
    Evenement();
    Evenement(int,QString,QString);
    int getid();
    QString getnom();
    QString getprenom();
    void setid(int);
    void setnom(QString);
    void setprenom(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool update();
    QSqlQueryModel * search(QString);


private:
    int id_eve;
    QString nom_eve, type_eve;
};

#endif // EVENEMENT_H
