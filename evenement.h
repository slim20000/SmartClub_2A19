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
#include "sponsor.h"
#include <ctime>
#include <dos.h>
#include "qcustomplot.h"


class Evenement
{
public:
    Evenement();
    Evenement(int,QString,QString,int);
    int getid();
    QString getnom();
    QString gettype();
    int getday();
    void setid(int);
    void setnom(QString);
    void settype(QString);
    void setday(int);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool update();
    QSqlQueryModel * search(QString);
    QSqlQueryModel * Tri();
    void upTime();


private:
    int id_eve,day_eve;
    QString nom_eve, type_eve;
    QDate date_eve;
};

#endif // EVENEMENT_H
