#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QTimer>
#include "connection.h"
#include <QMessageBox>
#include <QDateTime>
#include "son.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *timer =new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start();

    //LOGO


    QPixmap pic("C:/Users/DELL/Pictures/Saved Pictures/logo.png");
    int w=ui->label_4->width();
    int h=ui->label_4->height();
    ui->label_4->setPixmap(pic.scaled(w,h,Qt::KeepAspectRatio));
}

void MainWindow::showTime()
{
    QTime time=QTime::currentTime();
    QString time_text=time.toString("hh : mm : ss");
    ui->label_5->setText(time_text);


}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_connex_clicked()
{


         QSqlQuery query;
         QString Pseudo ,Mot_de_passe ;
         Pseudo=ui->lineEdit_Pseudo->text();
         Mot_de_passe=ui->lineEdit_Mdp->text();
         if(query.exec(("select * from PERSONNEL where Pseudo ='"+Pseudo+"'and  Mot_de_passe = '"+Mot_de_passe+"'")))
         {
             int count=0;
             while (query.next())
             {
                 count++;
             }
             if(count==1)
             {
                 hide();
                 mettreMusique();
               connexion= new Dialog_home(this);
               connexion->show();

             }
               else
             {mettreMusique2();QMessageBox::warning(this,"Login","Username Or Password is not correct");}

         }
}

void MainWindow::on_pushButton_inscr_clicked()
{
       mettreMusique();
       inscrire= new Dialog_inscription(this);
       inscrire->show();
}
