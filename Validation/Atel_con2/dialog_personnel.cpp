#include "dialog_personnel.h"
#include "ui_dialog_personnel.h"
#include "personnel.h"
#include <QMessageBox>

Dialog_personnel::Dialog_personnel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_personnel)
{
    ui->setupUi(this);
    ui->tablePersonnel->setModel(tmpPersonnel.afficher());//refresh
}

Dialog_personnel::~Dialog_personnel()
{
    delete ui;
}


void Dialog_personnel::on_pushButton_ajouter_clicked()
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
       ui->tablePersonnel->setModel(tmpPersonnel.afficher());//refresh
       /*QMessageBox::information(nullptr, QObject::tr("Ajouter un personnel"),
       QObject::tr("personnel ajouté.\n""Click Cancel to exit."), QMessageBox::Cancel);*/
       QMessageBox::information(this,"Ajout","Personnel ajouté");

   }
 else
   {
       /*QMessageBox::critical(nullptr, QObject::tr("Ajouter un personnel"),
       QObject::tr("Erreur !.\n""Click Cancel to exit."), QMessageBox::Cancel);*/
     QMessageBox::warning(this,"Ajout"," Erreur !");

   }
}




void Dialog_personnel::on_pushButton_supprimer_clicked()
{

    int id = ui->lineEdit_ide_4->text().toInt();
    bool test=tmpPersonnel.supprimer(id);
    if(test)
    {
        ui->tablePersonnel->setModel(tmpPersonnel.afficher());//refresh
        /*QMessageBox::information(nullptr, QObject::tr("Supprimer un personnel"),
        QObject::tr("personnel supprimé.\n""Click Cancel to exit."), QMessageBox::Cancel);*/
        QMessageBox::information(this,"Suppression","personnel supprimé");


    }
    else
    {
        /*QMessageBox::critical(nullptr, QObject::tr("Supprimer un personnel"),
        QObject::tr("Erreur !.\n""Click Cancel to exit."), QMessageBox::Cancel);*/
    }
}

void Dialog_personnel::on_pushButton_modifier_clicked()
{
    int CIN2 =              ui->lineEdit_ide_3->text().toInt();
    //int CIN =              ui->lineEdit_Cin_4->text().toInt();
    int Num_Tel  =         ui->lineEdit_Num_Tel_4->text().toInt();
    int code_postal =      ui->lineEdit_Cp_4->text().toInt();
    QString Nom =          ui->lineEdit_Nom_4->text();
    QString Prenom =       ui->lineEdit_Prenom_4->text();
    QString Role=          ui->lineEdit_Role_4->text();
    QString Adresse=       ui->lineEdit_Adresse_4->text();
    QString Pseudo=        ui->lineEdit_Pseudo_4->text();
    QString Mot_de_passe = ui->lineEdit_Mdp_4->text();
    personnel P(CIN2,code_postal,Num_Tel,Nom,Prenom,Role,Adresse,Pseudo,Mot_de_passe);

     bool test=P.modifier(CIN2);
     if(test)
     {
        ui->tablePersonnel->setModel(tmpPersonnel.afficher());//refresh
        QMessageBox::information(this, "modification","auteur modifié");
     }


     else
     {

        QMessageBox::warning(this,"modification","Erreur ! ");
     }
}



void Dialog_personnel::on_pushButton_clicked()
{
    int CIN=ui->lineEdit->text().toInt();
    ui->tablePersonnel_2->setModel(tmpPersonnel.chercher(CIN));

}

void Dialog_personnel::on_pushButton_2_clicked()
{
    ui->tablePersonnel->setModel(tmpPersonnel.trier());


}
