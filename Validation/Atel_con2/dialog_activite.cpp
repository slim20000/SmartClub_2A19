#include "dialog_activite.h"
#include "ui_dialog_activite.h"
#include "activite.h"
#include <QMessageBox>
#include "connection.h"
Dialog_activite::Dialog_activite(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_activite)
{
    ui->setupUi(this);
}

Dialog_activite::~Dialog_activite()
{
    delete ui;
}

void Dialog_activite::on_pushButton_ajouter_clicked()
{

    int CODE_ACT  = ui->lineEdit_Code_act->text().toInt();
    QString TYPE_ACT = ui->lineEdit_Type_act->text();
    QString LIBELLE_ACT = ui->lineEdit_Libelle_act->text();
    //QString DATE_H= ui->lineEdit_DateH_act->text();
    int DATE_H  = ui->lineEdit_DateH_act->text().toInt();



    Activite A(CODE_ACT,TYPE_ACT,LIBELLE_ACT,DATE_H);

     bool test=A.ajouter();
     if(test)
     {
        ui->tableactivite->setModel(tmpactivite.afficher());//refresh
        //ui->comboBox_auteur->setModel(tmpauteur.Detailler());//refresh

        /*QMessageBox::information(nullptr, QObject::tr("Ajouter un auteur"),
        QObject::tr("auteur ajouté.\n""Click Cancel to exit."), QMessageBox::Cancel);*/
        QMessageBox::information(this,"Ajout","activite ajouté");

     }
     else
     {
        /*QMessageBox::critical(nullptr, QObject::tr("Ajouter un auteur"),
        QObject::tr("Erreur !.\n""Click Cancel to exit."), QMessageBox::Cancel);*/
        QMessageBox::warning(this,"Ajout","Erreur");


     }
}

void Dialog_activite::on_pushButton_supprimer_clicked()
{

  int id = ui->lineEdit_ide_4->text().toInt();
  bool test=tmpactivite.supprimer(id);
  if(test)
  {
        ui->tableactivite->setModel(tmpactivite.afficher());//refresh
        //ui->comboBox_auteur->setModel(tmpauteur.Detailler());//refresh

        /*QMessageBox::information(this, QObject::tr("Supprimer un auteur"),
                  QObject::tr("auteur supprimé.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);*/
        QMessageBox::information(this,"Suppression","activite Supprimé");


  }
  else
     { /*QMessageBox::critical(this, QObject::tr("Supprimer un auteur"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);*/
      QMessageBox::warning(this,"Suppression"," Erreur");

       }
}
void Dialog_activite::on_pushButton_modifier_clicked()
{

    int CODE_ACT  = ui->lineEdit_Code_act->text().toInt();
    QString TYPE_ACT = ui->lineEdit_Type_act->text();
    QString LIBELLE_ACT = ui->lineEdit_Libelle_act->text();
    //QString DATE_H= ui->lineEdit_DateH_act->text();
    int DATE_H  = ui->lineEdit_DateH_act->text().toInt();



    Activite A(CODE_ACT,TYPE_ACT,LIBELLE_ACT,DATE_H);








     bool test=A.modifier(CODE_ACT);
     if(test)
     {
        ui->tableactivite->setModel(tmpactivite.afficher());//refresh
        QMessageBox::information(this, "modification","activite modifié");
     }


     else
     {

        QMessageBox::warning(this,"modification","Erreur ! ");
     }

}


void Dialog_activite::on_comboBox_auteur_currentIndexChanged(const QString &arg1)
{
    QString type =ui->comboBox_activite->currentText();//refresh
    Connection conn;
     QSqlQuery query;
     query.prepare("select * from  Activite where  TYPE_ACT='"+type+"'");
     if(query.exec())
     {
        while(query.next())
                    {
                     ui->lineEdit_code_2->setText(query.value(0).toString());
                     ui->lineEdit_type_2->setText(query.value(1).toString());
                     ui->lineEdit_libelle_2->setText(query.value(2).toString());
                     ui->lineEdit_dateH_2->setText(query.value(3).toString());





     }
        //conn.fermerConnexion();
     }
     else
     {

        QMessageBox::warning(this,"chercher","Erreur");


     }

}





void Dialog_activite::on_pushButton_chercher_clicked()
{
    int ide=ui->lineEdit_identifiant->text().toInt();
    ui->tableactivite_chercher->setModel(tmpactivite.chercher(ide));

}

void Dialog_activite::on_pushButton_Trier_clicked()
{
    ui->tableactivite->setModel(tmpactivite.trier());

}
