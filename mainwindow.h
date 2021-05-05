#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "arduino.h"
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
#include <QApplication>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include "evenement.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QPrinter>
#include <QPrintDialog>
#include <QPrinterInfo>
#include <QtPrintSupport>
#include <ctime>
#include <dos.h>
#include "qcustomplot.h"


#include <QPixmap>
#include <QPainter>
#include "sponsor.h"
#include <QPrintPreviewDialog>
#include <QTextBrowser>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void update_label();

private slots:

    void on_b_ajouter_clicked();


    void on_b_supprimer_clicked();

    void on_b_search_clicked();

    void on_update_clicked();

    void on_actionImprimer_triggered();


    void on_pb_aj_clicked();

    void on_pb_mod_clicked();

    void on_pb_sup_clicked();


    void on_pb_recherche_clicked();

    void on_pushButton_3_clicked();

    void on_actionImprimer_client_triggered();

    void on_pushButton_4_clicked();

    void on_tri_eve_clicked();

    //void makePlot();

    void updateTime();

    void upTime();


    //void on_pushButton_4_clicked();

    //void on_pushButton_clicked();

    //void on_pushButton_2_clicked();


private:
    Ui::MainWindow *ui;
    Evenement Etmp;
    sponsor SP;
    QTimer *timer_1s;
    //arduino A;
    QByteArray data;
};
#endif // MAINWINDOW_H
