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
#include "connection.h"
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
#include <ctime>
#include <dos.h>


class Evenement
{
public:
    Evenement();
    Evenement(int,QString,QString,QDate);
    int getid();
    QString getnom();
    QString getprenom();
    QDate getday();
    void setid(int);
    void setnom(QString);
    void setprenom(QString);
    void setday(QDate);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool update();
    QSqlQueryModel * search(QString);
    QSqlQueryModel * Tri();


private:
    int id_eve;
    QString nom_eve, type_eve;
    QDate day_eve;
};

#endif // EVENEMENT_H
