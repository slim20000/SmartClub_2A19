#include "mainwindow.h"
#include "ui_mainwindow.h"
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

#include <QtGui/qtguiglobal.h>
#include <QtGui/qcolor.h>
#include <QtGui/qfont.h>
#include <QtCore/qshareddata.h>
#include <QtCore/qvector.h>
#include <QtCore/qvariant.h>
#include <QtGui/qpen.h>
#include <QtGui/qbrush.h>
#include <QtGui/qtextoption.h>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->table_eve->setModel(Etmp.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}






void MainWindow::on_b_ajouter_clicked()
{
        int id=ui->le_id->text().toInt();
        QString nom=ui->le_nom->text();
        QString prenom=ui->le_prenom->text();
        Evenement E(id,nom,prenom);
        bool test=E.ajouter();
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("OK"),
                                     QObject::tr("Ajout effectué\n"
                                                 "Click Cancel  to exit."), QMessageBox::Cancel);
            ui->table_eve->setModel(Etmp.afficher());
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                  QObject::tr("Ajout non effectué\n"
                                              "Click Cancel to exit"), QMessageBox::Cancel);
}

void MainWindow::on_b_supprimer_clicked()
{
    Evenement E1;
    E1.setid(ui->le_id_supp->text().toInt());
    bool test=E1.supprimer(E1.getid());
    QMessageBox msgBox;

if(test)
   { msgBox.setText("Suppression avec succes");
ui->table_eve->setModel(Etmp.afficher());
}
else
    msgBox.setText("Echec de suppression");
    msgBox.exec();
}

void MainWindow::on_update_clicked()
{
    int id=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    Evenement E(id,nom,prenom);
    bool test=E.update();
    if (test)
    {
        ui->table_eve->setModel(E.afficher());

        QMessageBox::information(nullptr,QObject::tr("OK"),
                QObject::tr("Modification effectue\n"
                              "Click cancel to exit ."),QMessageBox::Cancel);
        ui->table_eve->setModel(Etmp.afficher());
    }
    else

        QMessageBox::critical(nullptr,QObject::tr("OK"),
                QObject::tr("Modification non effectue\n"
                              "Click cancel to exit ."),QMessageBox::Cancel);
}

//void MainWindow::on_b_search_clicked()
//{
//    ui->setupUi(this);
//    ui->table_eve->setModel(Etmp.search(QString nom));
//}
