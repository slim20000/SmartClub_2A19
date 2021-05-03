#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connection.h"
#include "produit.h"

#include <QWidget>
#include "etudiant.h"
#include "type.h"
#include "equipement.h"
#include "evenement.h"
#include "sponsor.h"

#include "tableprinter.h"
#include <QPrintPreviewDialog>
#include <QPlainTextEdit>
#include <QTableWidget>
#include <QTableView>
#include <QTextBrowser>
#include <QTimer>
#include <QDateTime>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QDesktopServices>
#include <QUrl>
#include <QProgressBar>
#include <QSlider>

#include <QModelIndexList>
#include <QModelIndex>
#include <QString>
#include <QPageSize>
#include "qpainter.h"
#include <QPrinter>
#include <QPrintDialog>
#include <QPixmap>
#include <QPainter>
//#include <QWebView>

#include <QMessageBox>
#include <QIntValidator>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(11);
    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(myfunction()));
    timer->start(1000);
    player=new QMediaPlayer(this);
    QVideoWidget *vw=new QVideoWidget;
    player->setVideoOutput(vw);

    player->setMedia(QUrl::fromLocalFile("D:/exerciceee/NO LIMITS - Gym Motivation.mp4"));
    vw->setGeometry(60,50,900,500);
    player->setVolume(4);

    //vw->show();
    vw->setParent(ui->label_22);

    player->stop();


    QPixmap pix("C:/Users/AZIZAZAIEZ/Downloads/logo.png");
    ui->label_21->setPixmap(pix);

    //
   // QPieSeries *series4=new QPieSeries();

   // series4->append("Equipement de musculation ",80);
   // series4->append("Equipement de boxe ",70);
//
    //series4->append("karate",100);
   // series4->append("Velos",40);
   // series4->append("Tapis",30);
   // QPieSlice*slice4=series4->slices().at(2);
   // slice4->setLabelVisible(true);
   // slice4->setPen(QPen(Qt::darkGreen,2));

   // slice4->setBrush(Qt::red);
    //slice4->setLabel(QString("%1%").arg(100*slice4->percentage(), 1, 'f', 1));

   // QPieSlice*slice=series4->slices().at(1);

   // slice4->setExploded(true);


    //slice4->setLabelVisible(true);
    //slice4->setPen(QPen(Qt::darkGreen,2));
    //slice4->setPen(QPen(Qt::darkGreen,1));

    //slice4->setBrush(Qt::green);

       // slice4->setLabel(QString("%1%").arg(100*slice->percentage(), 1, 'f', 1));

//QChart *chart=new QChart();
//chart->addSeries(series4);
//chart->setTitle("Statistique des Equipement ");
//chart->setAnimationOptions(QChart::SeriesAnimations);
//QChartView *chartview=new  QChartView(chart);
//chartview->setGeometry(140, -8, 800, 600);

//chartview->setParent(ui->frame);
    //



    QPieSeries *series=new QPieSeries();

    series->append("Box ",80);
    series->append("fitness ",70);

    series->append("karate",100);
    series->append("yoga",40);
    series->append("judo",30);
    QPieSlice*slice2=series->slices().at(2);
    slice2->setLabelVisible(true);
    slice2->setPen(QPen(Qt::darkGreen,2));

    slice2->setBrush(Qt::red);
    //slice2->setLabel(QString("%1%").arg(100*slice2->percentage(), 1, 'f', 1));

    QPieSlice*slice=series->slices().at(1);

    slice->setExploded(true);


    slice->setLabelVisible(true);
    slice->setPen(QPen(Qt::darkGreen,2));
    slice->setPen(QPen(Qt::darkGreen,1));

    slice->setBrush(Qt::green);

        //slice->setLabel(QString("%1%").arg(100*slice->percentage(), 1, 'f', 1));

QChart *chart=new QChart();
chart->addSeries(series);
chart->setTitle("Statistique de Type des sports ");
chart->setAnimationOptions(QChart::SeriesAnimations);

QChartView *chartview=new  QChartView(chart);
chartview->setGeometry(100, -12, 800, 700);

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
QBarSet *set0 = new QBarSet("Blue Pass-sport");
    QBarSet *set1 = new QBarSet("Yellow Pass-sport");
    QBarSet *set2 = new QBarSet("Enfant");
    //QBarSet *set3 = new QBarSet("Doe");
   // QBarSet *set4 = new QBarSet("Ahmad");

    *set0 << 30 << 40 << 10 << 20 << 10 << 60 << 10 << 60<< 10 << 20 << 10<< 13 ;
    *set1 << 10 << 30 << 42 << 15 << 81 << 75 << 10 << 60<< 60 << 10<< 13 << 60;
    *set2 << 80 << 100 << 70 << 13 << 60 << 20 << 10 << 60<< 13 << 60<< 13 << 60;
   // *set3 << 30 << 10 << 80 << 70 << 60 << 45;
    //*set4 << 100 << 40 << 70 << 30 << 16 << 42;

    QBarSeries *series2 = new QBarSeries();
    series2->append(set0);
    series2->append(set1);
    series2->append(set2);
    //series2->append(set3);
    //series2->append(set4);

    QChart *chart2 = new QChart();
    chart2->addSeries(series2);
    chart2->setTitle("BarChart Pourcentage De présence du membres  ");
    chart2->setAnimationOptions(QChart::SeriesAnimations);


    QStringList categories;
    categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun"<< "JUIL"<< "Aout"<< "Sep"<< "Oct"<< "Nov"<< "Dec";
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart2->createDefaultAxes();
    chart2->setAxisX(axis, series2);
    chartview->setParent(ui->horizontalFrame);
        //ui->verticalLayoutWidget_2->hide();

        QPixmap p = QPixmap::grabWidget(chart);
        QImage image=p.toImage();
        image.save("C:/Users/AZIZAZAIEZ/Pictures/Uplay/chart_bar.png");

    QChartView *chartView2 = new QChartView(chart2);
    chartView2->setGeometry(1 ,-20, 1000, 600);

    chartView2->setParent(ui->pp);





//------------------------------//

        ui->commandLinkButton_2->setIcon(QIcon(":/images/undo.png"));
        ui->addt->setIcon(QIcon(":/images/add.png"));
        ui->mod->setIcon(QIcon(":/images/skills.png"));
         ui->supp2->setIcon(QIcon(":/images/remove (1).png"));

        ui->pushButton_5->setIcon(QIcon(":/images/customer (2).png"));
        ui->pushButton_9->setIcon(QIcon(":/images/sports.png"));

         ui->pushButton->setIcon(QIcon(":/images/search.png"));
         ui->rech2->setIcon(QIcon(":/images/search.png"));

        ui->ajouter->setIcon(QIcon(":/images/add.png"));
        ui->pb_id_supp->setIcon(QIcon(":/images/remove (1).png"));
        ui->update->setIcon(QIcon(":/images/skills.png"));

    ui->members->setIcon(QIcon(":/images/customer (2).png"));
    ui->type->setIcon(QIcon(":/images/sports.png"));
    ui->supp->setIcon(QIcon(":/images/skills.png"));
    ui->add->setIcon(QIcon(":/images/add.png"));
    ui->add1->setIcon(QIcon(":/images/skills.png"));
    ui->supp1->setIcon(QIcon(":/images/add.png"));
    animation =new QPropertyAnimation(ui->pushButton_5,"geometry");
    animation->setDuration(1000);
    animation->setStartValue(ui->pushButton_5->geometry());
    animation->setEndValue(QRect(290,120,450,120));
    animation->start();
    animation2 =new QPropertyAnimation(ui->pushButton_9,"geometry");
    animation2->setDuration(1000);
    animation2->setStartValue(ui->pushButton_9->geometry());
    animation2->setEndValue(QRect(290,285,450,120));
    animation2->start();
    animation3 =new QPropertyAnimation(ui->pushButton_8,"geometry");
    animation3->setDuration(1000);
    animation3->setStartValue(ui->pushButton_8->geometry());
    animation3->setEndValue(QRect(290,450,450,120));
    animation3->start();
    ui->le_id->setValidator(new QIntValidator(100,9999999,this));
    ui->le_telephone->setValidator(new QIntValidator(100,99999999,this));
    ui->tableView->setModel(E.pdf());
    ui->tab_etudiant_5->setModel(P.afficher3());
    ui->tab_etudiant_4->setModel(P.afficher3());

    ui->tab_etudiant_2->setModel(E.afficher());
    ui->tab_etudiant_3->setModel(E.afficher());
    ui->tab1->setModel(t.afficher1());
    ui->tab2->setModel(t.afficher1());
    //ui->combo->setModel(E.afficher());
    ui->tab1_2->setModel(k.afficher1());
    ui->tab_etudiant_6->setModel(k.afficher1());
    ui->table_eve->setModel(Ev.afficher());
    ui->table_sp->setModel(SP.affichersp());

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
    QString prenom=ui->le_prenom->text();
    QString telephone=ui->le_telephone->text();
//QComboBox type = ui->combo->text().toString();
    QString type=ui->le_type->text();

    client E(id,age,nom,prenom,type,telephone);
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
client E1;E1.setid(ui->le_id_supp->text().toInt());
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
QString type=ui->le_type->text();

QString nom=ui->le_nom->text();
QString prenom=ui->le_prenom->text();
//QString type=ui->combo->text();
QString telephone=ui->le_telephone->text();
//QString age=ui->age->text();

client E(id,age,nom,prenom,type,telephone);
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

void MainWindow::on_type_clicked()
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
        QString description=ui->desc->text();
        QString description2=ui->desc2->text();
        QString description3=ui->desc3->text();

        type t(id,nom,description,description2,description3);
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
    QString description=ui->desc->text();
    QString description2=ui->desc2->text();
    QString description3=ui->desc3->text();

    QString nom=ui->nom->text();

    type t(id,nom,description,description2,description3);
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
type t1;t1.setid(ui->suppp->text().toInt());
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
    QString description=ui->desc->text();
    QString description2=ui->desc2->text();
    QString description3=ui->desc3->text();

    QString nom=ui->rech->text();

    type t(id,nom,description,description2,description3);
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
    QString description=ui->desc->text();
    QString description2=ui->desc2->text();
    QString description3=ui->desc3->text();

    QString nom=ui->rech->text();

    type t(id,nom,description,description2,description3);
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
    QString description=ui->desc->text();
    QString description2=ui->desc2->text();
    QString description3=ui->desc3->text();

    QString nom=ui->rech->text();

    type t(id,nom,description,description2,description3);
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
    QString prenom=ui->le_prenom->text();
    QString telephone=ui->le_telephone->text();
//QComboBox type = ui->combo->text().toString();
    QString type=ui->le_type->text();

    client E(id,age,nom,prenom,type,telephone);
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
    QString prenom=ui->le_prenom->text();
    QString telephone=ui->le_telephone->text();
//QComboBox type = ui->combo->text().toString();
    QString type=ui->le_type->text();

    client E(id,age,nom,prenom,type,telephone);
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
    QString prenom=ui->le_prenom->text();
    QString telephone=ui->le_telephone->text();
    QString type=ui->le_type->text();

    client E(id,age,nom,prenom,type,telephone);
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

    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tab_etudiant_3->model()->rowCount();
    const int columnCount = ui->tab_etudiant_3->model()->columnCount();
QString refTitleName;
    out <<  "<html>\n"
                    "<head>\n"
                    "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                <<  QString("<title>%1</title>\n").arg(refTitleName)
                <<  "</head>\n"
                    "<body bgcolor=#ffffff link=#5000A0>\n"



                "<img src='D:/exerciceee/integration/Atelier_Connexion/logo.png'>"
"<h1>Tel: 29109983/45845634</h1>\n"
"<h2>Email :Fitnessgym@gmail.com</h2>\n"
"<center><h1>PDF client</h1></center>\n"

                    "<table width=80% height=100  border=1 cellspacing=0 cellpadding=2>\n";

    // headers
    out << "<thead><tr bgcolor=red>";
    QString m_journal ="<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\"><html><head><meta name=\"qrichtext\" content=\"1\" /><meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf8\" /></head><body><p>Ici le texte à emprimer</p></body></html>";

    for (int column = 0; column < columnCount; column++)
        if (!ui->tab_etudiant_3->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tab_etudiant_3->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tab_etudiant_3->isColumnHidden(column)) {
                QString data = ui->tab_etudiant_3->model()->data(ui->tab_etudiant_3->model()->index(row, column)).toString().simplified();
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
    QDate date;
                QTime time;
                date = date.currentDate();
                time = time.currentTime();
                QString modif ="\nFait le :\t" + date.toString("dddd dd MMMM yyyy") + " a " + time.toString();

    QPrinter printer;
    QPixmap pixmap("aza.jpg");



    QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
    if (dialog->exec() == QDialog::Accepted) {

        document->print(&printer);
    }

    delete document;}

void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

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
    ui->stackedWidget->setCurrentIndex(21);

}

void MainWindow::on_actionImprimer_Type_triggered()
{

    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tab2->model()->rowCount();
    const int columnCount = ui->tab2->model()->columnCount();
QString refTitleName;
    out <<  "<html>\n"
                    "<head>\n"
                    "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                <<  QString("<title>%1</title>\n").arg(refTitleName)
                <<  "</head>\n"
                    "<body bgcolor=#ffffff link=#5000A0>\n"
                "<img src='D:/exerciceee/integration/Atelier_Connexion/logo.png'>"
"<h1>Tel: 29109983/45845634</h1>\n"
"<h2>Email :Fitnessgym@gmail.com</h2>\n"
"<center><h1>PDF Type de sport </h1></center>\n"

                    "<table width=80% height=100  border=1 cellspacing=0 cellpadding=2>\n";

    // headers
    out << "<thead><tr bgcolor=red>";
    QString m_journal ="<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\"><html><head><meta name=\"qrichtext\" content=\"1\" /><meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf8\" /></head><body><p>Ici le texte à emprimer</p></body></html>";

    for (int column = 0; column < columnCount; column++)
        if (!ui->tab2->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tab2->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tab2->isColumnHidden(column)) {
                QString data = ui->tab2->model()->data(ui->tab2->model()->index(row, column)).toString().simplified();
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

    delete document;}

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


//void MainWindow::on_pushButton_9_clicked()
//{
   // int id=ui->le_id->text().toInt();
   // QDate age=ui->dateEdit->date();

   // QString nom=ui->find->text();
   // QString prenom=ui->le_prenom->text();
   // QString telephone=ui->le_telephone->text();
   // QString type=ui->le_type->text();

   // client E(id,age,nom,prenom,type,telephone);
    //bool test=E.printPDF(QTabWidget);

   // if (test)
    //{
      //  ui->tab_etudiant_3->setModel(E.printPDF(QTabWidget));
        //ui->combo->setModel(E.afficher());
        //QMessageBox::information(nullptr,QObject::tr("OK"),
             //   QObject::tr("ajout effectue\n"
                              //"Click cancel to exit ."),QMessageBox::Cancel);
   // }
  //  else

        //QMessageBox::critical(nullptr,QObject::tr("OK"),
               // QObject::tr("ajout effectue\n"
                              //"Click cancel to exit ."),QMessageBox::Cancel);
//}




void MainWindow::on_tab_etudiant_2_activated(const QModelIndex &index)
{
    QString val=ui->tab_etudiant_2->model()->data(index).toString();


    QSqlQuery qry;
    qry.prepare("select * from client where id='"+val+"' or nom='"+val+"' or prenom='"+val+"'");
    if (qry.exec())
    {
        while(qry.next()){

            ui->le_id->setText(qry.value(0).toString());
            ui->le_nom->setText(qry.value(1).toString());
            ui->le_prenom->setText(qry.value(2).toString());
            ui->le_telephone->setText(qry.value(3).toString());
            ui->le_type->setText(qry.value(4).toString());
            ui->dateEdit->setDate(qry.value(5).toDate());



        }
    }
}



void MainWindow::on_tab1_activated(const QModelIndex &index)
{
    QString val=ui->tab1->model()->data(index).toString();


    QSqlQuery qry;
    qry.prepare("select * from type where id='"+val+"' or nom='"+val+"' ");
    if (qry.exec())
    {
        while(qry.next()){
           // type t(id,nom,description,description2,description3);

            ui->id->setText(qry.value(0).toString());
            ui->nom->setText(qry.value(1).toString());
            ui->desc->setText(qry.value(2).toString());
            ui->desc2->setText(qry.value(3).toString());
            ui->desc3->setText(qry.value(4).toString());



        }
    }
}

//void MainWindow::on_pushButton_9_clicked()
//{ #ifndef QT_NO_PRINTER
         //   QTextBrowser *editor = static_cast(textBrowser);
    //QPrinter printer;
    //QPrintDialog *dialog = new QPrintDialog(&printer, this);
    //dialog->setWindowTitle(tr("Print Document"));
    //if (tab_etudiant_3->textCursor().hasSelection()) dialog->addEnabledOption(QAbstractPrintDialog::PrintSelection);
    //if (dialog->exec() != QDialog::Accepted) return;
    //editor->print(&printer); #endif }

void MainWindow::on_tableView_activated(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();


    QSqlQuery qry;
    qry.prepare("select * from client where id='"+val+"' or nom='"+val+"' ");
    if (qry.exec())
    {
        while(qry.next()){
           // type t(id,nom,description,description2,description3);

            ui->lineEdit->setText(qry.value(0).toString());
            ui->lineEdit->setText(qry.value(1).toString());
            ui->lineEdit->setText(qry.value(2).toString());
            ui->lineEdit->setText(qry.value(3).toString());
            ui->lineEdit->setText(qry.value(4).toString());



        }
    }
}


void MainWindow::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);

}
void MainWindow::myfunction(){
    QTime time=QTime::currentTime();
    QString time_text=time.toString("hh: mm: ss");
    ui->date_time->setText(time_text);
    ui->date_time_2->setText(time_text);
    ui->date_time_3->setText(time_text);
    ui->label_40->setText(time_text);


}

void MainWindow::on_pushButton_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);

}

void MainWindow::on_actionIMP_triggered()
{
    }


void MainWindow::on_actionTeam_Website_triggered()
{
    QString link="https://codeninja.co/team/";
    QDesktopServices::openUrl(QUrl(link));
}

void MainWindow::on_actionPlay_triggered()
{
    player->play();
    ui->statusBar->showMessage("playing..");
}

void MainWindow::on_actionStop_triggered()
{
    player->pause();
    ui->statusBar->showMessage("stop..");

}

void MainWindow::on_pushButton_11_clicked()
{
    player->pause();

}

void MainWindow::on_actionstop_triggered()
{

}

void MainWindow::on_pushButton_12_clicked()
{
    player->play();

}

void MainWindow::on_commandLinkButton_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}



void MainWindow::on_equip_clicked()
{
    ui->stackedWidget->setCurrentIndex(14);

}

void MainWindow::on_prod_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);

}

void MainWindow::on_pushButton_13_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);

}

void MainWindow::on_pushButton_14_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);

}

void MainWindow::on_add1_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(16);

}

void MainWindow::on_ajouter_2_clicked()
{
    {
        int id=ui->le_id_2->text().toInt();
        QDate age=ui->dateEdit_2->date();

        QString nom=ui->le_nom_2->text();
        QString prixachat=ui->le_prixachat->text();
        QString categorie=ui->le_categorie->text();
    //QComboBox type = ui->combo->text().toString();
        QString prix_vente=ui->le_prix_vente->text();

        produit P(id,age,nom,prixachat,prix_vente,categorie);
        bool test=P.ajouter();
        if (test)
        {
            ui->tab_etudiant_4->setModel(P.afficher3());
           // ui->tab_etudiant_3->setModel(E.afficher());
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

void MainWindow::on_commandLinkButton_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);

}

void MainWindow::on_update_2_clicked()
{
    {
    int id=ui->le_id_2->text().toInt();
    QDate age=ui->dateEdit_2->date();
    QString prix_vente=ui->le_prix_vente->text();

    QString nom=ui->le_nom_2->text();
    QString prixachat=ui->le_prixachat->text();
    //QString type=ui->combo->text();
    QString categorie=ui->le_categorie->text();
    //QString age=ui->age->text();

    produit P(id,age,nom,prixachat,prix_vente,categorie);
    bool test=P.update(E.getid());
    if (test)
    {
        ui->tab_etudiant_4->setModel(P.afficher3());
        //ui->tab_etudiant_3->setModel(E.afficher());

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


void MainWindow::on_pb_id_supp_2_clicked()
{
produit P1;P1.setid(ui->le_id_supp_2->text().toInt());
bool test=P1.supprimer(P1.getid());
if (test)
{
    ui->tab_etudiant_5->setModel(P.afficher3());
    //ui->tab_etudiant_3->setModel(E.afficher());

    QMessageBox::information(nullptr,QObject::tr("OK"),
            QObject::tr("suppression effectue\n"
                        "Click cancel to exit ."),QMessageBox::Cancel);
}
else

    QMessageBox::critical(nullptr,QObject::tr("OK"),
            QObject::tr("suppression effectue\n"
                          "Click cancel to exit ."),QMessageBox::Cancel);
}

void MainWindow::on_add1_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(17);

}

void MainWindow::on_rech2_2_clicked()

    {
        int id=ui->le_id_2->text().toInt();
        QDate age=ui->dateEdit_2->date();

        QString nom=ui->find_2->text();
        QString prixachat=ui->le_prixachat->text();
        QString categorie=ui->le_categorie->text();
    //QComboBox type = ui->combo->text().toString();
        QString prix_vente=ui->le_prix_vente->text();

        produit P (id,age,nom,prixachat,prix_vente,categorie);
        bool test=P.search1(P.getnom());
        if (test)
        {
            ui->tab_etudiant_5->setModel(P.search1(nom));
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


void MainWindow::on_pushButton_17_clicked()

    {

        QString strStream;
        QTextStream out(&strStream);

        const int rowCount = ui->tab_etudiant_5->model()->rowCount();
        const int columnCount = ui->tab_etudiant_5->model()->columnCount();
    QString refTitleName;
        out <<  "<html>\n"
                        "<head>\n"
                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                    <<  QString("<title>%1</title>\n").arg(refTitleName)
                    <<  "</head>\n"
                        "<body bgcolor=#ffffff link=#5000A0>\n"
                    "<img src='D:/exerciceee/integration/Atelier_Connexion/logo.png'>"
    "<h1>Tel: 29109983/45845634</h1>\n"
    "<h2>Email :Fitnessgym@gmail.com</h2>\n"
    "<center><h1>PDF produit </h1></center>\n"

                        "<table width=80% height=100  border=1 cellspacing=0 cellpadding=2>\n";

        // headers
        out << "<thead><tr bgcolor=red>";
        QString m_journal ="<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\"><html><head><meta name=\"qrichtext\" content=\"1\" /><meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf8\" /></head><body><p>Ici le texte à emprimer</p></body></html>";

        for (int column = 0; column < columnCount; column++)
            if (!ui->tab2->isColumnHidden(column))
                out << QString("<th>%1</th>").arg(ui->tab_etudiant_5->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";

        // data table
        for (int row = 0; row < rowCount; row++) {
            out << "<tr>";
            for (int column = 0; column < columnCount; column++) {
                if (!ui->tab2->isColumnHidden(column)) {
                    QString data = ui->tab_etudiant_5->model()->data(ui->tab_etudiant_5->model()->index(row, column)).toString().simplified();
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

        delete document;}


void MainWindow::on_pushButton_15_clicked()
{
    int id=ui->le_id_2->text().toInt();
    QDate age=ui->dateEdit_2->date();

    QString nom=ui->find_2->text();
    QString prixachat=ui->le_prixachat->text();
    QString categorie=ui->le_categorie->text();
//QComboBox type = ui->combo->text().toString();
    QString prix_vente=ui->le_prix_vente->text();

    produit P(id,age,nom,prixachat,prix_vente,categorie);
    bool test=P.order1();
    if (test)
    {
        ui->tab_etudiant_5->setModel(P.order1());
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


void MainWindow::on_commandLinkButton_13_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);
}

void MainWindow::on_pushButton_16_clicked()
{
    int id=ui->le_id_2->text().toInt();
    QDate age=ui->dateEdit_2->date();

    QString nom=ui->find_2->text();
    QString prixachat=ui->le_prixachat->text();
    QString categorie=ui->le_categorie->text();
//QComboBox type = ui->combo->text().toString();
    QString prix_vente=ui->le_prix_vente->text();

    produit P(id,age,nom,prixachat,prix_vente,categorie);
    bool test=P.order3();
    if (test)
    {
        ui->tab_etudiant_5->setModel(P.order3());
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

void MainWindow::on_add1_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(17);

}

void MainWindow::on_addt_2_clicked()
{
    {
        int id=ui->id_2->text().toInt();

        QString nom=ui->nom_2->text();
        QString sport=ui->desc_2->text();
        QString salle=ui->desc2_2->text();
        QString prix_achat=ui->desc3_2->text();

        equipement k(id,nom,sport,salle,prix_achat);
        bool test=k.ajouter1();
        if (test)
        {
            ui->tab1_2->setModel(k.afficher1());
            ui->tab1_2->setModel(k.afficher1());
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

void MainWindow::on_add1_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(19);

}

void MainWindow::on_mod_2_clicked()
{

    int id=ui->id_2->text().toInt();

    QString nom=ui->nom_2->text();
    QString sport=ui->desc_2->text();
    QString salle=ui->desc2_2->text();
    QString prix_achat=ui->desc3_2->text();

    equipement k(id,nom,sport,salle,prix_achat);
    bool test=k.update1(k.getid());
    if (test)
    {
        ui->tab1_2->setModel(k.afficher1());
        //ui->tab2->setModel(k.afficher1());

        QMessageBox::information(nullptr,QObject::tr("OK"),
                QObject::tr("ajout effectue\n"
                              "Click cancel to exit ."),QMessageBox::Cancel);
    }
    else

        QMessageBox::critical(nullptr,QObject::tr("OK"),
                QObject::tr("ajout effectue\n"
                              "Click cancel to exit ."),QMessageBox::Cancel);


}

void MainWindow::on_commandLinkButton_14_clicked()
{
    ui->stackedWidget->setCurrentIndex(14);

}

void MainWindow::on_commandLinkButton_15_clicked()
{
    ui->stackedWidget->setCurrentIndex(14);

}

void MainWindow::on_pb_id_supp_3_clicked()
{
equipement k1;k1.setid(ui->le_id_supp_3->text().toInt());
bool test=k1.supprimer1(k1.getid());
if (test)
{
    ui->tab_etudiant_6->setModel(k.afficher1());
    //ui->tab_etudiant_3->setModel(E.afficher());

    QMessageBox::information(nullptr,QObject::tr("OK"),
            QObject::tr("suppression effectue\n"
                        "Click cancel to exit ."),QMessageBox::Cancel);
}
else

    QMessageBox::critical(nullptr,QObject::tr("OK"),
            QObject::tr("suppression effectue\n"
                          "Click cancel to exit ."),QMessageBox::Cancel);
}

void MainWindow::on_rech2_3_clicked()
{
    int id=ui->id_2->text().toInt();

    QString sport=ui->desc_2->text();
    QString salle=ui->desc2_2->text();
    QString prix_achat=ui->desc3_2->text();

    QString nom=ui->find_3->text();

//QComboBox type = ui->combo->text().toString();

 equipement k(id,nom,sport,salle,prix_achat);
 bool test=k.search(k.getnom());
    if (test)
    {
        ui->tab_etudiant_6->setModel(k.search(nom));
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

void MainWindow::on_add1_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);

}

void MainWindow::on_pushButton_20_clicked()
{

    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tab_etudiant_6->model()->rowCount();
    const int columnCount = ui->tab_etudiant_6->model()->columnCount();
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
"<center><h1>PDF produit </h1></center>\n"

                    "<table width=80% height=100  border=1 cellspacing=0 cellpadding=2>\n";

    // headers
    out << "<thead><tr bgcolor=red>";
    QString m_journal ="<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\"><html><head><meta name=\"qrichtext\" content=\"1\" /><meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf8\" /></head><body><p>Ici le texte à emprimer</p></body></html>";

    for (int column = 0; column < columnCount; column++)
        if (!ui->tab_etudiant_6->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tab_etudiant_6->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tab_etudiant_6->isColumnHidden(column)) {
                QString data = ui->tab_etudiant_6->model()->data(ui->tab_etudiant_6->model()->index(row, column)).toString().simplified();
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

    delete document;}

void MainWindow::on_pushButton_18_clicked()
{
    int id=ui->id_2->text().toInt();

    QString nom=ui->nom_2->text();
    QString sport=ui->desc_2->text();
    QString salle=ui->desc2_2->text();
    QString prix_achat=ui->desc3_2->text();
//QComboBox type = ui->combo->text().toString();
    //QString prix_vente=ui->le_prix_vente->text();

    equipement k(id,nom,sport,salle,prix_achat);
    bool test=k.order();
    if (test)
    {
        ui->tab_etudiant_6->setModel(k.order());
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

void MainWindow::on_pushButton_19_clicked()
{
    int id=ui->id_2->text().toInt();

    QString nom=ui->nom_2->text();
    QString sport=ui->desc_2->text();
    QString salle=ui->desc2_2->text();
    QString prix_achat=ui->desc3_2->text();
//QComboBox type = ui->combo->text().toString();
    //QString prix_vente=ui->le_prix_vente->text();

    equipement k(id,nom,sport,salle,prix_achat);
    bool test=k.order2();
    if (test)
    {
        ui->tab_etudiant_6->setModel(k.order2());
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

void MainWindow::on_commandLinkButton_16_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);

}

void MainWindow::on_commandLinkButton_17_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);

}

void MainWindow::on_actionCAPTURE_triggered()
{

}

void MainWindow::on_equip_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(22);

}

void MainWindow::on_prod_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(23);

}

void MainWindow::on_commandLinkButton_18_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);

}

void MainWindow::on_commandLinkButton_19_clicked()
{
    ui->stackedWidget->setCurrentIndex(21);

}

void MainWindow::on_commandLinkButton_20_clicked()
{
    ui->stackedWidget->setCurrentIndex(21);

}

void MainWindow::on_b_ajouter_clicked()
{
        int id_eve=ui->le_id_3->text().toInt();
        QDate day_eve=ui->dateEdit_3->date();
        QString nom_eve=ui->le_nom_3->text();
        QString type_eve=ui->le_prenom_2->text();
        Evenement Ev(id_eve,nom_eve,type_eve,day_eve);
        bool test=Ev.ajouter();
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("OK"),
                                     QObject::tr("Ajout effectué\n"
                                                 "Click Cancel  to exit."), QMessageBox::Cancel);
            ui->table_eve->setModel(Ev.afficher());
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                  QObject::tr("Ajout non effectué\n"
                                              "Click Cancel to exit"), QMessageBox::Cancel);
}


void MainWindow::on_add1_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(24);

}

void MainWindow::on_b_supprimer_clicked()
{
    Evenement Ev1;
    Ev1.setid(ui->le_id_supp_4->text().toInt());
    bool test=Ev1.supprimer(Ev1.getid());
    QMessageBox msgBox;

    if (test)
    {
        ui->table_eve->setModel(Ev.afficher());
        //ui->tab_etudiant_3->setModel(E.afficher());

        QMessageBox::information(nullptr,QObject::tr("OK"),
                QObject::tr("suppression effectue\n"
                            "Click cancel to exit ."),QMessageBox::Cancel);
    }
    else

        QMessageBox::critical(nullptr,QObject::tr("OK"),
                QObject::tr("suppression effectue\n"
                              "Click cancel to exit ."),QMessageBox::Cancel);
    }

void MainWindow::on_b_search_clicked()
{
    int id_eve=ui->chercher->text().toInt();

    QDate day_eve=ui->dateEdit_3->date();

        QString nom_eve=ui->chercher->text();
        QString type_eve=ui->chercher->text();

        Evenement Ev(id_eve,type_eve,nom_eve,day_eve);
        bool test=Ev.search(Ev.getnom());
        if (test)
        {
            ui->table_eve->setModel(Ev.afficher());
          ui->table_eve->setModel(Ev.search(nom_eve));

           // QMessageBox::information(nullptr,QObject::tr("OK"),
                   // QObject::tr("ajout effectue\n"
                                 // "Click cancel to exit ."),QMessageBox::Cancel);
        }
        //else

            //QMessageBox::critical(nullptr,QObject::tr("OK"),
                    //QObject::tr("ajout effectue\n"
                                //  "Click cancel to exit ."),QMessageBox::Cancel);

}

void MainWindow::on_pushButton_23_clicked()
{

    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->table_eve->model()->rowCount();
    const int columnCount = ui->table_eve->model()->columnCount();
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
"<center><h1>PDF produit </h1></center>\n"

                    "<table width=80% height=100  border=1 cellspacing=0 cellpadding=2>\n";

    // headers
    out << "<thead><tr bgcolor=red>";
    QString m_journal ="<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\"><html><head><meta name=\"qrichtext\" content=\"1\" /><meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf8\" /></head><body><p>Ici le texte à emprimer</p></body></html>";

    for (int column = 0; column < columnCount; column++)
        if (!ui->table_eve->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->table_eve->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->table_eve->isColumnHidden(column)) {
                QString data = ui->table_eve->model()->data(ui->table_eve->model()->index(row, column)).toString().simplified();
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

    delete document;}

void MainWindow::on_tri_eve_clicked()
{
    int id_eve=ui->chercher->text().toInt();

    QDate day_eve=ui->dateEdit_3->date();

        QString nom_eve=ui->chercher->text();
        QString type_eve=ui->chercher->text();

        Evenement Ev1(id_eve,nom_eve,type_eve,day_eve);
        bool test=Ev1.Tri();
        if (test)
        {
            ui->table_eve->setModel(Ev1.afficher());
          ui->table_eve->setModel(Ev1.Tri());

}

}

void MainWindow::on_update_3_clicked()
{
    int id_eve=ui->le_id->text().toInt();
    QDate day_eve=ui->dateEdit_3->date();
    QString nom_eve=ui->le_nom->text();
    QString type_eve=ui->le_prenom->text();
    Evenement Ev(id_eve,nom_eve,type_eve,day_eve);
    bool test=Ev.update();
    if (test)
    {
        ui->table_eve->setModel(Ev.afficher());

        QMessageBox::information(nullptr,QObject::tr("OK"),
                QObject::tr("Modification effectue\n"
                              "Click cancel to exit ."),QMessageBox::Cancel);
        ui->table_eve->setModel(Ev.afficher());
    }
    else

        QMessageBox::critical(nullptr,QObject::tr("OK"),
                QObject::tr("Modification non effectue\n"
                              "Click cancel to exit ."),QMessageBox::Cancel);
}

void MainWindow::on_commandLinkButton_21_clicked()
{
    ui->stackedWidget->setCurrentIndex(22);

}

void MainWindow::on_add1_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(25);

}

void MainWindow::on_pb_aj_clicked()
{
    int id_sp=ui->el_id->text().toInt();
    QString nom_sp=ui->el_nom->text();
    sponsor SP(id_sp,nom_sp);
    bool test=SP.ajouter();
    if(test)
    {
        //QMessageBox::information(nullptr, QObject::tr("OK"),
                              //   QObject::tr("Ajout effectué\n"
                                            // "Click Cancel  to exit."), QMessageBox::Cancel);
        ui->table_sp->setModel(SP.affichersp());
    }
    //else
      //  QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                             // QObject::tr("Ajout non effectué\n"
                                         // "Click Cancel to exit"), QMessageBox::Cancel);
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

    if (test)
    {
        ui->table_sp->setModel(SP.affichersp());

        QMessageBox::information(nullptr,QObject::tr("OK"),
                QObject::tr("supp effectue\n"
                              "Click cancel to exit ."),QMessageBox::Cancel);
        ui->table_sp->setModel(SP.affichersp());
    }
    else

        QMessageBox::critical(nullptr,QObject::tr("OK"),
                QObject::tr("supp non effectue\n"
                              "Click cancel to exit ."),QMessageBox::Cancel);
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

void MainWindow::on_pushButton_24_clicked()
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
                "<img src='D:/exerciceee/integration/Atelier_Connexion/logo.png'>"
"<h1>Tel: 29109983/45845634</h1>\n"
"<h2>Email :Fitnessgym@gmail.com</h2>\n"
"<center><h1>PDF sponsort </h1></center>\n"

                    "<table width=80% height=100  border=1 cellspacing=0 cellpadding=2>\n";

    // headers
    out << "<thead><tr bgcolor=red>";
    QString m_journal ="<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\"><html><head><meta name=\"qrichtext\" content=\"1\" /><meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf8\" /></head><body><p>Ici le texte à emprimer</p></body></html>";

    for (int column = 0; column < columnCount; column++)
        if (!ui->table_eve->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->table_sp->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->table_eve->isColumnHidden(column)) {
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

    delete document;}

void MainWindow::on_pushButton_25_clicked()
{
    int id_sp=ui->recherche->text().toInt();


        QString nom_sp=ui->el_nom->text();

        sponsor SP(id_sp,nom_sp);
        bool test=SP.Tri2();
        if (test)
        {
            ui->table_sp->setModel(SP.affichersp());
          ui->table_sp->setModel(SP.Tri2());

}

}

void MainWindow::on_commandLinkButton_22_clicked()
{
    ui->stackedWidget->setCurrentIndex(23);

}
