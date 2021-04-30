#include "dialog_inscription.h"
#include "ui_dialog_inscription.h"
#include "son.h"
#include "personnel.h"
#include <QMessageBox>
Dialog_inscription::Dialog_inscription(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_inscription)
{
    ui->setupUi(this);
}

Dialog_inscription::~Dialog_inscription()
{
    delete ui;
}

void Dialog_inscription::on_pushButton_ajouter_clicked()
{
    int CIN =              ui->lineEdit_Cin->text().toInt();
    int Num_Tel  =         ui->lineEdit_Num_Tel->text().toInt();
    int code_postal =      ui->lineEdit_Cp->text().toInt();
    QString Nom =          ui->lineEdit_Nom->text();
    QString Prenom =       ui->lineEdit_Prenom->text();
    QString Role=          ui->lineEdit_Role->text();
    QString Adresse=       ui->lineEdit_Adresse->text();
    QString Pseudo=        ui->lineEdit_Pseudo->text();
    QString Mot_de_passe = ui->lineEdit_Mdp->text();

 personnel P(CIN,code_postal,Num_Tel,Nom,Prenom,Role,Adresse,Pseudo,Mot_de_passe);
 bool test=P.ajouter();
 if(test)
   {
     mettreMusique();

       QMessageBox::information(nullptr, QObject::tr("Ajouter un personnel"),
       QObject::tr("personnel ajouté.\n""Click Cancel to exit."), QMessageBox::Cancel);
   }
 else
   {
     mettreMusique2();

       QMessageBox::critical(nullptr, QObject::tr("Ajouter un personnel"),
       QObject::tr("Erreur !.\n""Click Cancel to exit."), QMessageBox::Cancel);
   }

}
