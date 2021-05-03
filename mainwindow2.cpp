#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connection.h"
#include "produit.h"
#include "equipement.h"
#include "tableprinter.h"
#include <QPrintPreviewDialog>

#include <QPlainTextEdit>
#include <QModelIndexList>
#include <QModelIndex>
#include <QString>
#include <QPrinter>
#include <QPrintDialog>
#include <QPixmap>
#include <QPainter>

#include <QMessageBox>
#include <QIntValidator>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(1);
   // QPixmap pix("C:/Users/AZIZAZAIEZ/Downloads/new logo mana.png");
    //ui->label_20->setPixmap(pix);

    QPieSeries *series=new QPieSeries();

    series->append("Equipement de musculation ",80);
    series->append("Equipement de boxe ",70);

    series->append("karate",100);
    series->append("Velos",40);
    series->append("Tapis",30);
    QPieSlice*slice2=series->slices().at(2);
    slice2->setLabelVisible(true);
    slice2->setPen(QPen(Qt::darkGreen,2));

    slice2->setBrush(Qt::red);
    slice2->setLabel(QString("%1%").arg(100*slice2->percentage(), 1, 'f', 1));

    QPieSlice*slice=series->slices().at(1);

    slice->setExploded(true);


    slice->setLabelVisible(true);
    slice->setPen(QPen(Qt::darkGreen,2));
    slice->setPen(QPen(Qt::darkGreen,1));

    slice->setBrush(Qt::green);

        slice->setLabel(QString("%1%").arg(100*slice->percentage(), 1, 'f', 1));

QChart *chart=new QChart();
chart->addSeries(series);
chart->setTitle("Statistique des Equipement ");
chart->setAnimationOptions(QChart::SeriesAnimations);

QChartView *chartview=new  QChartView(chart);
chartview->setGeometry(140, -8, 800, 600);

chartview->setParent(ui->horizontalFrame);
//------------------------------//
//QLineSeries *series2=new QLineSeries();
//series2->append(0,6);
//series2->append(2,4);

//series2->append(3,8);
//series2->append(7,4);
//series2->append(10,5);
//*series2 << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3)
           //<< QPointF(20, 2);

   //QChart *chart2 = new QChart();
   //chart2->legend()->hide();
   //chart2->addSeries(series2);
   //chart2->createDefaultAxes();
  // chart2->setTitle("Line Chart Example");


  // chart2->legend()->setVisible(true);
   //chart2->legend()->setAlignment(Qt::AlignBottom);



  // QChartView *chartView2 = new QChartView(chart2);
   //chartView2->setRenderHint(QPainter::Antialiasing);
   //chartView2->setParent(ui->pp);
   //------------------------------//
QBarSet *set0 = new QBarSet("Jus");
    QBarSet *set1 = new QBarSet("Eaux");
    QBarSet *set2 = new QBarSet("Café");
    QBarSet *set3 = new QBarSet("Boissons");
   // QBarSet *set4 = new QBarSet("Ahmad");

    *set0 << 30 << 40 << 10 << 20 << 10 << 60 << 10 << 60;
    *set1 << 10 << 30 << 42 << 15 << 81 << 75 << 10 << 60;
    *set2 << 80 << 100 << 70 << 13 << 60 << 20 << 10 << 60;
    *set3 << 30 << 10 << 80 << 70 << 60 << 45;
    //*set4 << 100 << 40 << 70 << 30 << 16 << 42;

    QBarSeries *series2 = new QBarSeries();
    series2->append(set0);
    series2->append(set1);
    series2->append(set2);
   series2->append(set3);
    //series2->append(set4);

    QChart *chart2 = new QChart();
    chart2->addSeries(series2);
    chart2->setTitle("Les produits les plus consommé  ");
    chart2->setAnimationOptions(QChart::SeriesAnimations);


    QStringList categories;
    categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun"<< "JUIL"<< "Aout"<< "Sep"<< "Oct"<< "Nov"<< "Dec";
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart2->createDefaultAxes();
    chart2->setAxisX(axis, series2);


    QChartView *chartView2 = new QChartView(chart2);
    chartView2->setGeometry(1 ,-20, 1000, 600);

    chartView2->setParent(ui->pp);





//------------------------------//

        ui->commandLinkButton_2->setIcon(QIcon(":/images/undo.png"));
        ui->addt->setIcon(QIcon(":/images/add.png"));
        ui->mod->setIcon(QIcon(":/images/skills.png"));
         ui->supp2->setIcon(QIcon(":/images/remove (1).png"));

         ui->pushButton->setIcon(QIcon(":/images/search.png"));
         ui->rech2->setIcon(QIcon(":/images/search.png"));

        ui->ajouter->setIcon(QIcon(":/images/add.png"));
        ui->pb_id_supp->setIcon(QIcon(":/images/remove (1).png"));
        ui->update->setIcon(QIcon(":/images/skills.png"));

    ui->members->setIcon(QIcon(":/images/customer (2).png"));
    ui->prix_vente->setIcon(QIcon(":/images/sports.png"));
    ui->supp->setIcon(QIcon(":/images/skills.png"));
    ui->add->setIcon(QIcon(":/images/add.png"));
    ui->add1->setIcon(QIcon(":/images/skills.png"));
    ui->supp1->setIcon(QIcon(":/images/add.png"));
    animation =new QPropertyAnimation(ui->members,"geometry");
    animation->setDuration(1000);
    animation->setStartValue(ui->members->geometry());
    animation->setEndValue(QRect(335,160,350,120));
    animation->start();
    animation2 =new QPropertyAnimation(ui->prix_vente,"geometry");
    animation2->setDuration(1000);
    animation2->setStartValue(ui->prix_vente->geometry());
    animation2->setEndValue(QRect(335,320,350,120));
    animation2->start();
    ui->le_id->setValidator(new QIntValidator(100,9999999,this));
    ui->le_categorie->setValidator(new QIntValidator(100,99999999,this));

    ui->tab_etudiant_2->setModel(E.afficher());
    ui->tab_etudiant_3->setModel(E.afficher());
    ui->tab1->setModel(t.afficher1());
    ui->tab2->setModel(t.afficher1());
    //ui->combo->setModel(E.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_ajouter_clicked()
{
    int id=ui->le_id->text().toInt();
    QDate age=ui->dateEdit->date();

    QString nom=ui->le_nom->text();
    QString prixachat=ui->le_prixachat->text();
    QString categorie=ui->le_categorie->text();
//QComboBox type = ui->combo->text().toString();
    QString prix_vente=ui->le_prix_vente->text();

    produit E(id,age,nom,prixachat,prix_vente,categorie);
    bool test=E.ajouter();
    if (test)
    {
        ui->tab_etudiant_2->setModel(E.afficher());
        ui->tab_etudiant_3->setModel(E.afficher());
        //ui->combo->setModel(E.afficher());
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
produit E1;E1.setid(ui->le_id_supp->text().toInt());
bool test=E1.supprimer(E1.getid());
if (test)
{
    ui->tab_etudiant_2->setModel(E.afficher());
    ui->tab_etudiant_3->setModel(E.afficher());

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
QDate age=ui->dateEdit->date();
QString prix_vente=ui->le_prix_vente->text();

QString nom=ui->le_nom->text();
QString prixachat=ui->le_prixachat->text();
//QString type=ui->combo->text();
QString categorie=ui->le_categorie->text();
//QString age=ui->age->text();

produit E(id,age,nom,prixachat,prix_vente,categorie);
bool test=E.update(E.getid());
if (test)
{
    ui->tab_etudiant_2->setModel(E.afficher());
    ui->tab_etudiant_3->setModel(E.afficher());

    QMessageBox::information(nullptr,QObject::tr("OK"),
            QObject::tr("ajout effectue\n"
                          "Click cancel to exit ."),QMessageBox::Cancel);
}
else

    QMessageBox::critical(nullptr,QObject::tr("OK"),
            QObject::tr("ajout effectue\n"
                          "Click cancel to exit ."),QMessageBox::Cancel);
}

void MainWindow::on_members_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}

void MainWindow::on_commandLinkButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_prix_vente_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_commandLinkButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_add_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void MainWindow::on_supp1_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);

}





void MainWindow::on_supp_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

}

void MainWindow::on_commandLinkButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}

void MainWindow::on_commandLinkButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}

void MainWindow::on_commandLinkButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_commandLinkButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_add1_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}

void MainWindow::on_addt_clicked()
{
    {
        int id=ui->id->text().toInt();

        QString nom=ui->nom->text();
        QString sport=ui->desc->text();
        QString salle=ui->desc2->text();
        QString prix_achat=ui->desc3->text();

        equipement t(id,nom,sport,salle,prix_achat);
        bool test=t.ajouter1();
        if (test)
        {
            ui->tab1->setModel(t.afficher1());
            ui->tab2->setModel(t.afficher1());
            //ui->combo->setModel(E.afficher());
            QMessageBox::information(nullptr,QObject::tr("OK"),
                    QObject::tr("ajout effectue\n"
                                  "Click cancel to exit ."),QMessageBox::Cancel);
        }
        else

            QMessageBox::critical(nullptr,QObject::tr("OK"),
                    QObject::tr("ajout effectue\n"
                                  "Click cancel to exit ."),QMessageBox::Cancel);
    }


}

void MainWindow::on_mod_clicked()
{

    int id=ui->id->text().toInt();
    QString sport=ui->desc->text();
    QString salle=ui->desc2->text();
    QString prix_achat=ui->desc3->text();

    QString nom=ui->nom->text();

    equipement t(id,nom,sport,salle,prix_achat);
    bool test=t.update1(t.getid());
    if (test)
    {
        ui->tab1->setModel(t.afficher1());
        ui->tab2->setModel(t.afficher1());

        QMessageBox::information(nullptr,QObject::tr("OK"),
                QObject::tr("ajout effectue\n"
                              "Click cancel to exit ."),QMessageBox::Cancel);
    }
    else

        QMessageBox::critical(nullptr,QObject::tr("OK"),
                QObject::tr("ajout effectue\n"
                              "Click cancel to exit ."),QMessageBox::Cancel);


}

void MainWindow::on_supp2_clicked()
{
equipement t1;t1.setid(ui->suppp->text().toInt());
bool test=t1.supprimer1(t1.getid());
if (test)
{
    ui->tab1->setModel(t.afficher1());
    ui->tab2->setModel(t.afficher1());

    QMessageBox::information(nullptr,QObject::tr("OK"),
            QObject::tr("suppression effectue\n"
                        "Click cancel to exit ."),QMessageBox::Cancel);
}
else

    QMessageBox::critical(nullptr,QObject::tr("OK"),
            QObject::tr("suppression effectue\n"
                          "Click cancel to exit ."),QMessageBox::Cancel);
}

void MainWindow::on_pushButton_clicked()
{
    int id=ui->id->text().toInt();
    QString sport=ui->desc->text();
    QString salle=ui->desc2->text();
    QString prix_achat=ui->desc3->text();

    QString nom=ui->rech->text();

    equipement t(id,nom,sport,salle,prix_achat);
    bool test=t.search(t.getnom());
    if (test)
    {
        //ui->tab1->setModel(t.afficher1());
      ui->tab2->setModel(t.search(nom));

       // QMessageBox::information(nullptr,QObject::tr("OK"),
               // QObject::tr("ajout effectue\n"
                             // "Click cancel to exit ."),QMessageBox::Cancel);
    }
    //else

        //QMessageBox::critical(nullptr,QObject::tr("OK"),
                //QObject::tr("ajout effectue\n"
                            //  "Click cancel to exit ."),QMessageBox::Cancel);

}





void MainWindow::on_order_clicked()
{
    int id=ui->id->text().toInt();
    QString sport=ui->desc->text();
    QString salle=ui->desc2->text();
    QString prix_achat=ui->desc3->text();

    QString nom=ui->rech->text();

    equipement t(id,nom,sport,salle,prix_achat);
    bool test=t.order();
    if (test)
    {
        //ui->tab1->setModel(t.afficher1());
      ui->tab2->setModel(t.order());

       // QMessageBox::information(nullptr,QObject::tr("OK"),
               // QObject::tr("ajout effectue\n"
                             // "Click cancel to exit ."),QMessageBox::Cancel);
    }

        //QMessageBox::critical(nullptr,QObject::tr("OK"),
                //QObject::tr("ajout effectue\n"
                            //  "Click cancel to exit ."),QMessageBox::Cancel);

}

void MainWindow::on_pushButton_2_clicked()
{
    int id=ui->id->text().toInt();
    QString sport=ui->desc->text();
    QString salle=ui->desc2->text();
    QString prix_achat=ui->desc3->text();

    QString nom=ui->rech->text();

    equipement t(id,nom,sport,salle,prix_achat);
    bool test=t.order2();
    if (test)
    {
        //ui->tab1->setModel(t.afficher1());
      ui->tab2->setModel(t.order2());

       // QMessageBox::information(nullptr,QObject::tr("OK"),
               // QObject::tr("ajout effectue\n"
                             // "Click cancel to exit ."),QMessageBox::Cancel);
    }

        //QMessageBox::critical(nullptr,QObject::tr("OK"),
                //QObject::tr("ajout effectue\n"
                            //  "Click cancel to exit ."),QMessageBox::Cancel);
}

void MainWindow::on_rech2_clicked()
{
    int id=ui->le_id->text().toInt();
    QDate age=ui->dateEdit->date();

    QString nom=ui->find->text();
    QString prixachat=ui->le_prixachat->text();
    QString categorie=ui->le_categorie->text();
//QComboBox type = ui->combo->text().toString();
    QString prix_vente=ui->le_prix_vente->text();

    produit E(id,age,nom,prixachat,prix_vente,categorie);
    bool test=E.search1(E.getnom());
    if (test)
    {
        ui->tab_etudiant_3->setModel(E.search1(nom));
        //ui->combo->setModel(E.afficher());
        //QMessageBox::information(nullptr,QObject::tr("OK"),
             //   QObject::tr("ajout effectue\n"
                              //"Click cancel to exit ."),QMessageBox::Cancel);
   // }
  //  else

        //QMessageBox::critical(nullptr,QObject::tr("OK"),
               // QObject::tr("ajout effectue\n"
                              //"Click cancel to exit ."),QMessageBox::Cancel);
}}




void MainWindow::on_pushButton_3_clicked()
{
    int id=ui->le_id->text().toInt();
    QDate age=ui->dateEdit->date();

    QString nom=ui->find->text();
    QString prixachat=ui->le_prixachat->text();
    QString categorie=ui->le_categorie->text();
//QComboBox type = ui->combo->text().toString();
    QString prix_vente=ui->le_prix_vente->text();

    produit E(id,age,nom,prixachat,prix_vente,categorie);
    bool test=E.order1();
    if (test)
    {
        ui->tab_etudiant_3->setModel(E.order1());
        //ui->combo->setModel(E.afficher());
        //QMessageBox::information(nullptr,QObject::tr("OK"),
             //   QObject::tr("ajout effectue\n"
                              //"Click cancel to exit ."),QMessageBox::Cancel);
   // }
  //  else

        //QMessageBox::critical(nullptr,QObject::tr("OK"),
               // QObject::tr("ajout effectue\n"
                              //"Click cancel to exit ."),QMessageBox::Cancel);
}}



void MainWindow::on_pushButton_4_clicked()
{
    int id=ui->le_id->text().toInt();
    QDate age=ui->dateEdit->date();

    QString nom=ui->find->text();
    QString prixachat=ui->le_prixachat->text();
    QString categorie=ui->le_categorie->text();
    QString prix_vente=ui->le_prix_vente->text();

    produit E(id,age,nom,prixachat,prix_vente,categorie);
    bool test=E.order3();
    if (test)
    {
        ui->tab_etudiant_3->setModel(E.order3());
        //ui->combo->setModel(E.afficher());
        //QMessageBox::information(nullptr,QObject::tr("OK"),
             //   QObject::tr("ajout effectue\n"
                              //"Click cancel to exit ."),QMessageBox::Cancel);
   // }
  //  else

        //QMessageBox::critical(nullptr,QObject::tr("OK"),
               // QObject::tr("ajout effectue\n"
                              //"Click cancel to exit ."),QMessageBox::Cancel);
}
}

void MainWindow::on_actionImprimer_triggered()
{
QPrinter printer;
printer.setPrinterName("produit PDF");
QPrintDialog dialog(&printer,this);
if (dialog.exec() ==QDialog::Rejected) return;
ui->plainTextEdit->print(&printer);

}

void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);

}

void MainWindow::on_commandLinkButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}

void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);

}

void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);

}

void MainWindow::on_commandLinkButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_commandLinkButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}

void MainWindow::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);

}

void MainWindow::on_actionImprimer_prix_vente_triggered()
{
    QPrinter printer;
    printer.setPrinterName("type PDF");
    QPrintDialog dialog(&printer,this);
    if (dialog.exec() ==QDialog::Rejected) return;
    ui->plainTextEdit_2->print(&printer);
}

void MainWindow::on_commandLinkButton_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_actionQuitter_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::information(this,"This a smart gym management software ","By NinjaCode 2021");
}
void MainWindow::print(QPrinter *printer) {

    // ------------------ simplest example --------------------------

    QPainter painter;

    if(!painter.begin(printer)) {
        qWarning() << "can't start printer";
        return;
    }}
    // print table

   /* TablePrinter TablePrinter(&painter, printer);
    QVector<int> columnStretch = QVector<int>() << 2 << 5 << 10 << 15;
    if(!TablePrinter.printTable(ui->tab_etudiant_3->model(), columnStretch)) {
        qDebug() << TablePrinter.lastError();
    }
    painter.end();
}

void MainWindow::on_pushButton_9_clicked()
{
    QPrintPreviewDialog dialog;
    connect(&dialog, SIGNAL(paintRequested(QPrinter*)), this, SLOT(print(QPrinter*)));
    dialog.exec();
}*/




