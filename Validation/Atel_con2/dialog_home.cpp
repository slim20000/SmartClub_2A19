#include "dialog_home.h"
#include "ui_dialog_home.h"
#include "son.h"

Dialog_home::Dialog_home(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_home)
{
    ui->setupUi(this);
}

Dialog_home::~Dialog_home()
{
    delete ui;
}

void Dialog_home::on_pushButton_Personnel_clicked()
{
    //mettreMusique();
    acces_perso= new Dialog_personnel(this);
    acces_perso->show();

}
void Dialog_home::on_pushButton_activite_clicked()
{
    mettreMusique();
    acces_act= new Dialog_activite(this);
    acces_act->show();

}

void Dialog_home::on_pushButton_salle_clicked()
{
    mettreMusique();
    acces_salle = new Dialog_salle(this);
    acces_salle->show();
}
