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
#include <QPageSize>
#include <QPrinterInfo>
//#include <QPrintSupport>
#include <ctime>
#include <dos.h>
#include <QtPrintSupport/QPrinterInfo>
#include <QTimer>


#include <QSqlDatabase>
#include <QMessageBox>
#include "sponsor.h"
#include "evenement.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QPrinter>
#include <QPrintDialog>
#include <QPixmap>
#include <QPainter>
#include <QPrintPreviewDialog>
#include <QTextBrowser>

#include <QtGui/qtguiglobal.h>
#include <QtGui/qcolor.h>
#include <QtGui/qfont.h>
#include <QtCore/qshareddata.h>
#include <QtCore/qvector.h>
#include <QtCore/qvariant.h>
#include <QtGui/qpen.h>
#include <QtGui/qbrush.h>
#include <QtGui/qtextoption.h>

#include<QApplication>
#include <QWidget>
#include <QPushButton>
#include <QtGui>
#include <QFont>
#include <QtGui/QImage>
#include <QImage>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->table_eve->setModel(Etmp.afficher());
    ui->table_sp->setModel(SP.affichersp());
   // MainWindow::makePlot();
//    timer_1s = new QTimer(this);
//    QObject::connect(time_1s,SIGNAL(timeout()),this,SLOT(updateTime()));
//    timer_1s->start(1000);

//    int ret=A.connect_arduino();
//    switch (ret)
//    {
//      case(0):qDebug() <<"Arduino is available and connected to :" << A.getarduino_port_name();
//        break;
//    case(1): qDebug() <<"Arduino is available but not connected to:" << A.getarduino_port_name();
//        break;
//    case(-1): qDebug() <<"Arduino is not available";
//    }
//    QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT()).
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::updateTime()
{
    ui->lbl_time->setText(QTime::currentTime().toString("hh:mm:ss"));
}


void MainWindow::on_b_ajouter_clicked()
{
        int id_eve=ui->le_id->text().toInt();
        int day_eve=ui->le_day->text().toInt();
        QString nom_eve=ui->le_nom->text();
        QString type_eve=ui->le_prenom->text();
        Evenement E(id_eve,nom_eve,type_eve,day_eve);
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
{
    msgBox.setText("Echec de suppression");
    msgBox.exec();
}
}

void MainWindow::on_update_clicked()
{
    int id_eve=ui->le_id->text().toInt();
    int day_eve=ui->le_day->text().toInt();
    QString nom_eve=ui->le_nom->text();
    QString type_eve=ui->le_prenom->text();
    Evenement E(id_eve,nom_eve,type_eve,day_eve);
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

void MainWindow::on_b_search_clicked()
{
    int id_eve=ui->chercher->text().toInt();


        QString nom_eve=ui->chercher->text();
        QString type_eve=ui->chercher->text();
        int day_eve=ui->chercher->text().toInt();

        Evenement Etmp(id_eve,type_eve,nom_eve,day_eve);
        bool test=Etmp.search(Etmp.getnom());
        if (test)
        {
            ui->table_eve->setModel(Etmp.afficher());
          ui->table_eve->setModel(Etmp.search(nom_eve));

           // QMessageBox::information(nullptr,QObject::tr("OK"),
                   // QObject::tr("ajout effectue\n"
                                 // "Click cancel to exit ."),QMessageBox::Cancel);
        }
        //else

            //QMessageBox::critical(nullptr,QObject::tr("OK"),
                    //QObject::tr("ajout effectue\n"
                                //  "Click cancel to exit ."),QMessageBox::Cancel);

}



void MainWindow::on_pb_aj_clicked()
{
    int id_sp=ui->el_id->text().toInt();
    QString nom_sp=ui->el_nom->text();
    sponsor SP(id_sp,nom_sp);
    bool test=SP.ajouter();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectué\n"
                                             "Click Cancel  to exit."), QMessageBox::Cancel);
        ui->table_sp->setModel(SP.affichersp());
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Ajout non effectué\n"
                                          "Click Cancel to exit"), QMessageBox::Cancel);
}


void MainWindow::on_pb_mod_clicked()
{
    int id_sp=ui->el_id->text().toInt();
    QString nom_sp=ui->el_nom->text();
    sponsor SP(id_sp,nom_sp);
    bool test=SP.update();
    if (test)
    {
        ui->table_sp->setModel(SP.affichersp());

        QMessageBox::information(nullptr,QObject::tr("OK"),
                QObject::tr("Modification effectue\n"
                              "Click cancel to exit ."),QMessageBox::Cancel);
        ui->table_sp->setModel(SP.affichersp());
    }
    else

        QMessageBox::critical(nullptr,QObject::tr("OK"),
                QObject::tr("Modification non effectue\n"
                              "Click cancel to exit ."),QMessageBox::Cancel);
}

void MainWindow::on_pb_sup_clicked()
{
    sponsor SP1;
    SP1.setid(ui->el_id->text().toInt());
    bool test=SP1.supprimer(SP1.getid());
    QMessageBox msgBox;

if(test)
   { msgBox.setText("Suppression avec succes");
ui->table_sp->setModel(SP.affichersp());
}
else
{
    msgBox.setText("Echec de suppression");
    msgBox.exec();
}
}

void MainWindow::on_pb_recherche_clicked()
{
    int id_sp=ui->recherche->text().toInt();


        QString nom_sp=ui->recherche->text();

        sponsor SP(id_sp,nom_sp);
        bool test=SP.search(SP.getnom());
        if (test)
        {
            ui->table_sp->setModel(SP.affichersp());
          ui->table_sp->setModel(SP.search(nom_sp));

           // QMessageBox::information(nullptr,QObject::tr("OK"),
                   // QObject::tr("ajout effectue\n"
                                 // "Click cancel to exit ."),QMessageBox::Cancel);
        }
        //else

            //QMessageBox::critical(nullptr,QObject::tr("OK"),
                    //QObject::tr("ajout effectue\n"
                                //  "Click cancel to exit ."),QMessageBox::Cancel);
}

void MainWindow::on_actionImprimer_triggered()
{
    QString strStream;
       QTextStream out(&strStream);

       const int rowCount = ui->table_sp->model()->rowCount();
       const int columnCount = ui->table_sp->model()->columnCount();
   QString refTitleName;
       out <<  "<html>\n"
                       "<head>\n"
                       "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                   <<  QString("<title>%1</title>\n").arg(refTitleName)
                   <<  "</head>\n"
                       "<body bgcolor=#ffffff link=#5000A0>\n"
                   "<img src='D:/exerciceee/Atelier_Connexion/logo.png'>"
   "<h1>Tel: 29109983/45845634</h1>\n"
   "<h2>Email :Fitnessgym@gmail.com</h2>\n"
   "<center><h1>PDF client</h1></center>\n"

                       "<table width=80% height=100  border=1 cellspacing=0 cellpadding=2>\n";

       // headers
       out << "<thead><tr bgcolor=red>";
       QString m_journal ="<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\"><html><head><meta name=\"qrichtext\" content=\"1\" /><meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf8\" /></head><body><p>Ici le texte à emprimer</p></body></html>";

       for (int column = 0; column < columnCount; column++)
           if (!ui->table_sp->isColumnHidden(column))
               out << QString("<th>%1</th>").arg(ui->table_sp->model()->headerData(column, Qt::Horizontal).toString());
       out << "</tr></thead>\n";

       // data table
       for (int row = 0; row < rowCount; row++) {
           out << "<tr>";
           for (int column = 0; column < columnCount; column++) {
               if (!ui->table_sp->isColumnHidden(column)) {
                   QString data = ui->table_sp->model()->data(ui->table_sp->model()->index(row, column)).toString().simplified();
                   out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
               }
           }
           out << "</tr>\n";
       }

       out <<  "</table>\n"
   "\n"
   "\n"
   "\n"
   "\n"
   "\n"


           "</body>\n"
           "</html>\n";

       QTextDocument *document = new QTextDocument();
       document->setHtml(strStream);

       QPrinter printer;
       QPixmap pixmap("aza.jpg");



       QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
       if (dialog->exec() == QDialog::Accepted) {
           //QDate date;
                     //  QTime time;
                     //  date = date.currentDate();
                     //  time = time.currentTime();
                      // QString modif ="\nFait le :\t" + date.toString("dddd dd MMMM yyyy") + " a " + time.toString();

           document->print(&printer);

       }
       delete document;
}


void MainWindow::on_pushButton_3_clicked()
{
    QString strStream;
       QTextStream out(&strStream);

       const int rowCount = ui->table_sp->model()->rowCount();
       const int columnCount = ui->table_sp->model()->columnCount();
   QString refTitleName;
       out <<  "<html>\n"
                       "<head>\n"
                       "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                   <<  QString("<title>%1</title>\n").arg(refTitleName)
                   <<  "</head>\n"
                       "<body bgcolor=#ffffff link=#5000A0>\n"
                   "<img src='D:/exerciceee/Atelier_Connexion/logo.png'>"
   "<h1>Tel: 29109983/45845634</h1>\n"
   "<h2>Email :Fitnessgym@gmail.com</h2>\n"
   "<center><h1>PDF client</h1></center>\n"

                       "<table width=80% height=100  border=1 cellspacing=0 cellpadding=2>\n";

       // headers
       out << "<thead><tr bgcolor=red>";
       QString m_journal ="<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\"><html><head><meta name=\"qrichtext\" content=\"1\" /><meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf8\" /></head><body><p>Ici le texte à emprimer</p></body></html>";

       for (int column = 0; column < columnCount; column++)
           if (!ui->table_sp->isColumnHidden(column))
               out << QString("<th>%1</th>").arg(ui->table_sp->model()->headerData(column, Qt::Horizontal).toString());
       out << "</tr></thead>\n";

       // data table
       for (int row = 0; row < rowCount; row++) {
           out << "<tr>";
           for (int column = 0; column < columnCount; column++) {
               if (!ui->table_sp->isColumnHidden(column)) {
                   QString data = ui->table_sp->model()->data(ui->table_sp->model()->index(row, column)).toString().simplified();
                   out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
               }
           }
           out << "</tr>\n";
       }

       out <<  "</table>\n"
   "\n"
   "\n"
   "\n"
   "\n"
   "\n"


           "</body>\n"
           "</html>\n";

       QTextDocument *document = new QTextDocument();
       document->setHtml(strStream);

       QPrinter printer;
       QPixmap pixmap("aza.jpg");



       QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
       if (dialog->exec() == QDialog::Accepted) {
           QDate date;
                       QTime time;
                       date = date.currentDate();
                       time = time.currentTime();
                       QString modif ="\nFait le :\t" + date.toString("dddd dd MMMM yyyy") + " a " + time.toString();

           document->print(&printer);

       }
       delete document;
}

void MainWindow::upTime()
{


int day_eve=ui->le_day->text().toInt();
if(day_eve<=10)
{
    QMessageBox::warning(nullptr, QObject::tr("Not OK"),
                          QObject::tr("Il ne reste que 10 jours ou moins!!!\n"
                                      "Click Cancel to exit"), QMessageBox::Cancel);
}
     }



void MainWindow::on_actionImprimer_client_triggered()
{


           QPrinter printer;
           QPixmap pixmap("aza.jpg");



           QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
           if (dialog->exec() == QDialog::Accepted) {
               //QDate date;
                         //  QTime time;
                         //  date = date.currentDate();
                         //  time = time.currentTime();
                          // QString modif ="\nFait le :\t" + date.toString("dddd dd MMMM yyyy") + " a " + time.toString();

               //document->print(&printer);

           }
          // delete document;
    }


//    void MainWindow::on_pushButton_3_clicked()
//    {


//          QPrinter printer;
//           QPixmap pixmap("");



//           QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
//           if (dialog->exec() == QDialog::Accepted) {
//               QDate date;
//                         QTime time;
//                        time = time.currentTime();
//                         QString modif ="\nFait le :\t" + date.toString("dddd dd MMMM yyyy") + " a " + time.toString();

//           document->print(&printer);

//           }
//         delete document;
//    }


void MainWindow::on_pushButton_4_clicked()
{
    int id_sp=ui->recherche->text().toInt();


        QString nom_sp=ui->recherche->text();

        sponsor SP(id_sp,nom_sp);
        bool test=SP.Tri2();
        if (test)
        {
            ui->table_sp->setModel(SP.affichersp());
          ui->table_sp->setModel(SP.Tri2());

}
}

void MainWindow::on_tri_eve_clicked()
{
    int id_eve=ui->chercher->text().toInt();


        QString nom_eve=ui->chercher->text();
        QString type_eve=ui->chercher->text();
        int day_eve=ui->chercher->text().toInt();

        Evenement Etmp(id_eve,nom_eve,type_eve,day_eve);
        bool test=Etmp.Tri();
        if (test)

        {
            ui->table_eve->setModel(Etmp.afficher());
          ui->table_eve->setModel(Etmp.Tri());

}

}

//void MainWindow::makePlot()
//{
//    // generate some data:
//    QVector<double> x(101), y(101); // initialize with entries 0..100
//    for (int i=0; i<101; ++i)
//    {
//      x[i] = i/50.0 - 1; // x goes from -1 to 1
//      y[i] = x[i]*x[i]; // let's plot a quadratic function
//    }
//    // create graph and assign data to it:
//    ui->customPlot->addGraph();
//    ui->customPlot->graph(0)->setData(x, y);
//    // give the axes some labels:
//    ui->customPlot->xAxis->setLabel("x");
//    ui->customPlot->yAxis->setLabel("y");
//    // set axes ranges, so we see all data:
//    ui->customPlot->xAxis->setRange(-1, 1);
//    ui->customPlot->yAxis->setRange(0, 1);
//    ui->customPlot->replot();
//}

//void MainWindow::on_pushButton_3_clicked()
//{
//    A.write_to_arduino("1");
//}

//void MainWindow::on_pushButton_4_clicked()
//{
//    A.write_to_arduino("0");
//}

//void MainWindow::on_pushButton_clicked()
//{
//    A.write_to_arduino("2");
//}

//void MainWindow::on_pushButton_2_clicked()
//{
//    A.write_to_arduino("3");
//}

//void MainWindow::update_label()
//{
//    data=A.read_from_arduino();
//    if(data=="1")
//        ui->label_4->setText("ON");
//    else if(data=="0")
//        ui->label_4->setText("OFF");
//}
