#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//#warning

#ifdef Q_TREAT_OBSOLETE_AS_ERRORS
#define Q_OBSOLETE(X) \
        BOOST_STATIC_ASSERT(false); \
        X

#else
#define Q_OBSOLETE(X) X
#endif
#include <QPropertyAnimation>
#include "type.h"
#include "produit.h"
#include "equipement.h"

#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QPieSeries>
#include <QPieSlice>
#include <QLineSeries>
#include <QPercentBarSeries>
#include <QBarCategoryAxis>
#include<QBarSet>
#include<QBarSeries>
#include <QPainter>
#include <QValueAxis>
#include <QTableWidget>
#include <QMediaPlayer>
#include <QVideoWidget>

#include "tableprinter.h"
//#include <QWebView>
#include <QPageSize>


#include "etudiant.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //void print(QPrinter *printer);
void myfunction();

    void on_ajouter_clicked();

    void on_pb_id_supp_clicked();

    void on_update_clicked();

    void on_members_clicked();

    void on_commandLinkButton_clicked();

    void on_type_clicked();

    void on_commandLinkButton_2_clicked();

    void on_add_clicked();

    void on_supp1_clicked();


    void on_supp_clicked();

    void on_commandLinkButton_4_clicked();

    void on_commandLinkButton_3_clicked();

    void on_commandLinkButton_5_clicked();

    void on_commandLinkButton_6_clicked();

    void on_add1_clicked();

    void on_addt_clicked();

    void on_mod_clicked();

    void on_supp2_clicked();

    void on_pushButton_clicked();




    void on_order_clicked();

    void on_pushButton_2_clicked();

    void on_rech2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_actionImprimer_triggered();

    void on_pushButton_5_clicked();

    void on_commandLinkButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_commandLinkButton_8_clicked();

    void on_commandLinkButton_9_clicked();

    void on_pushButton_8_clicked();

    void on_actionImprimer_Type_triggered();

    void on_commandLinkButton_10_clicked();

    void on_actionQuitter_triggered();

    void on_actionAbout_triggered();

    void on_pushButton_9_clicked();

    void on_tab_etudiant_2_activated(const QModelIndex &index);


    void on_tab1_activated(const QModelIndex &index);

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_10_clicked();

    void on_actionIMP_triggered();

    void on_actionTeam_Website_triggered();

    void on_actionPlay_triggered();

    void on_actionStop_triggered();

    void on_pushButton_11_clicked();

    void on_actionstop_triggered();

    void on_pushButton_12_clicked();

    void on_commandLinkButton_11_clicked();



    void on_equip_clicked();

    void on_prod_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_add1_5_clicked();

    void on_ajouter_2_clicked();

    void on_commandLinkButton_12_clicked();

    void on_update_2_clicked();

    void on_pb_id_supp_2_clicked();

    void on_add1_6_clicked();

    void on_rech2_2_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_15_clicked();

    void on_commandLinkButton_13_clicked();

    void on_pushButton_16_clicked();

    void on_add1_7_clicked();

    void on_addt_2_clicked();

    void on_add1_2_clicked();

    void on_mod_2_clicked();

    void on_commandLinkButton_14_clicked();

    void on_commandLinkButton_15_clicked();

    void on_pb_id_supp_3_clicked();

    void on_rech2_3_clicked();

    void on_add1_3_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_commandLinkButton_16_clicked();

    void on_commandLinkButton_17_clicked();

    void on_actionCAPTURE_triggered();

private:


    QPropertyAnimation* animation;
    QPropertyAnimation* animation2;
    QPropertyAnimation* animation3;
QTimer *timer;
    Ui::MainWindow *ui;
    QMediaPlayer *player;
    QChart *chart=new QChart();

    client E;
    type t;
 produit P;
 equipement k;
};

#endif // MAINWINDOW_H
