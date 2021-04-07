#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#ifdef Q_TREAT_OBSOLETE_AS_ERRORS
#define Q_OBSOLETE(X) \
        BOOST_STATIC_ASSERT(false); \
        X

#else
#define Q_OBSOLETE(X) X
#endif
#include <QPropertyAnimation>
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
#include "tableprinter.h"


#include "produit.h"
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
    void print(QPrinter *printer);


    void on_ajouter_clicked();

    void on_pb_id_supp_clicked();

    void on_update_clicked();

    void on_members_clicked();

    void on_commandLinkButton_clicked();

    void on_prix_vente_clicked();

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

    void on_actionImprimer_prix_vente_triggered();

    void on_commandLinkButton_10_clicked();

    void on_actionQuitter_triggered();

    void on_actionAbout_triggered();

    void on_pushButton_9_clicked();

    void on_le_prenom_cursorPositionChanged(int arg1, int arg2);

private:


    QPropertyAnimation* animation;
    QPropertyAnimation* animation2;

    Ui::MainWindow *ui;
    produit E;
    equipement t;

};

#endif // MAINWINDOW_H
