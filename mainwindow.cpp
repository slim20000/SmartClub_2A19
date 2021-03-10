#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connection.h"
#include "etudiant.h"
#include <QMessageBox>
#include <QIntValidator>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_id->setValidator(new QIntValidator(100,9999999,this));
    ui->tab_etudiant->setModel(E.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_ajouter_clicked()
{
    int id=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    Etudiant E(id,nom,prenom);
    bool test=E.ajouter();
    if (test)
    {
        ui->tab_etudiant->setModel(E.afficher());

        QMessageBox::information(nullptr,QObject::tr("OK"),
                QObject::tr("ajout effectue\n"
                              "Click cancel to exit ."),QMessageBox::Cancel);
    }
    else

        QMessageBox::critical(nullptr,QObject::tr("OK"),
                QObject::tr("ajout effectue\n"
                              "Click cancel to exit ."),QMessageBox::Cancel);
}



void MainWindow::on_pb_id_supp_clicked()
{
Etudiant E1;E1.setid(ui->le_id_supp->text().toInt());
bool test=E1.supprimer(E1.getid());
if (test)
{
    ui->tab_etudiant->setModel(E.afficher());

    QMessageBox::information(nullptr,QObject::tr("OK"),
            QObject::tr("suppression effectue\n"
                          "Click cancel to exit ."),QMessageBox::Cancel);
}
else

    QMessageBox::critical(nullptr,QObject::tr("OK"),
            QObject::tr("suppression effectue\n"
                          "Click cancel to exit ."),QMessageBox::Cancel);
}


void MainWindow::on_update_clicked()
{
int id=ui->le_id->text().toInt();
QString nom=ui->le_nom->text();
QString prenom=ui->le_prenom->text();
Etudiant E(id,nom,prenom);
bool test=E.update();
if (test)
{
    ui->tab_etudiant->setModel(E.afficher());

    QMessageBox::information(nullptr,QObject::tr("OK"),
            QObject::tr("ajout effectue\n"
                          "Click cancel to exit ."),QMessageBox::Cancel);
}
else

    QMessageBox::critical(nullptr,QObject::tr("OK"),
            QObject::tr("ajout effectue\n"
                          "Click cancel to exit ."),QMessageBox::Cancel);
}
