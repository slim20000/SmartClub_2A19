#ifndef SPONSOR_H
#define SPONSOR_H
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


class sponsor
{
public:
    sponsor();
    sponsor(int,QString);
    int getid();
    QString getnom();
    QString getprenom();
    void setid(int);
    void setnom(QString);
    void setprenom(QString);
    bool ajouter();
    QSqlQueryModel* affichersp();
    bool supprimer(int);
    bool update();
    QSqlQueryModel * search(QString);


private:
    int id_sp;
    QString nom_sp;
};

#endif // SPONSOR_H
