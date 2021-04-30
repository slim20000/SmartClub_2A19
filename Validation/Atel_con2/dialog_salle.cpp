#include "dialog_salle.h"
#include "ui_dialog_salle.h"
#include "salle.h"
#include <QMessageBox>

Dialog_salle::Dialog_salle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_salle)
{
    ui->setupUi(this);
}

Dialog_salle::~Dialog_salle()
{
    delete ui;
}


void Dialog_salle::on_pushButton_ajouter_clicked()
{

     int CODE_SALLE = ui->lineEdit_Code->text().toInt();
     int NUM_TEL =ui->lineEdit_Num_Tel_1 ->text().toInt();
     QString LIBELLE_SALLE = ui->lineEdit_Libelle->text();
     QString ADRESSE = ui->lineEdit_Adresse->text();
     QString NOM_SALLE = ui->lineEdit_Nom->text();


    Salle S(CODE_SALLE,NUM_TEL,NOM_SALLE,LIBELLE_SALLE,ADRESSE);
    bool test=S.ajouter();
    if(test)

            {
                 ui->tablesalle->setModel(tmpsalle.afficher());//refresh
                  /*QMessageBox::information(nullptr, QObject::tr("Ajouter un Departement"),
                  QObject::tr("Departement ajouté.\n""Click Cancel to exit."), QMessageBox::Cancel);*/
                 QMessageBox::information(this,"Ajout","salle ajouté");


            }
  else
            {
                  /*QMessageBox::critical(nullptr, QObject::tr("Ajouter un Departement"),
                  QObject::tr("Erreur !.\n""Click Cancel to exit."), QMessageBox::Cancel);*/
        QMessageBox::warning(this,"Ajout","salle ajouté");

            }
}

void Dialog_salle::on_pushButton_modifier_clicked()
{
    int CODE_SALLE2 = ui->lineEdit_Code_modifier2->text().toInt();
    //int CodeDepartement = ui->lineEdit_Code_modifier->text().toInt();
    int NUM_TEL =ui->lineEdit_numTel_modifier ->text().toInt();
    QString LIBELLE_SALLE = ui->lineEdit_Libelle_modifier->text();
    QString ADRESSE = ui->lineEdit_adresse_modifier->text();
    QString NOM_SALLE = ui->lineEdit_nomSalle_modifier->text();
    Salle S(CODE_SALLE2,NUM_TEL,NOM_SALLE,LIBELLE_SALLE,ADRESSE);

     bool test=S.modifier(CODE_SALLE2);
     if(test)
     {
        ui->tablesalle->setModel(tmpsalle.afficher());//refresh

        QMessageBox::information(this, "modification","salle modifié");

     }
     else
     {

         QMessageBox::warning(this,"modification","Erreur ! ");

     }

}
/* supppression */

void Dialog_salle::on_pushButton_supprimer_clicked()
{
    int id = ui->lineEdit_ide_supp->text().toInt();
    bool test=tmpsalle.supprimer(id);
    if(test)
    {
          ui->tablesalle->setModel(tmpsalle.afficher());//refresh


          QMessageBox::information(this,"Suppression","salle Supprimé");


    }
    else
       {
        QMessageBox::warning(this,"Suppression"," Erreur");

         }
}



void Dialog_salle::on_pushButton_Trier_clicked()
{
    ui->tablesalle->setModel(tmpsalle.trier());

}

void Dialog_salle::on_pushButton_chercher_2_clicked()
{
    int CODE_SALLE=ui->lineEdit_identifiant->text().toInt();
    ui->tablesalle_chercher->setModel(tmpsalle.chercher(CODE_SALLE));

}
