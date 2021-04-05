#include "mainwindow.h"
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
#include "evenement.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QPrintDialog>
#include <QPrinter>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connexion c;
    bool test=c.createconnection();
    MainWindow w;
    if(test)
    {
    w.show();
    QMessageBox::information(nullptr,QObject::tr("Database is open"),
     QObject::tr("Connection successful.\n"
                 "Click cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Database is not open"), QObject::tr("Connection failed.\n",
                              "Click Cancel to exit"), QMessageBox::Cancel);
    return a.exec();
}
