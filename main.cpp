#include "mainwindow.h"
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
#include <QSqlDatabase>
#include <QMessageBox>
#include "evenement.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QPrintDialog>
#include <QPrinter>
#include "sponsor.h"
#include <ctime>
#include <dos.h>


#include <QApplication>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QTableView>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connexion c;
    bool test=c.createconnection();
    MainWindow w;
    if(test)
    {
    w.show();
    QMessageBox::information(nullptr,QObject::tr("Database is open"),
     QObject::tr("Connection successful.\n"
                 "Click cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Database is not open"), QObject::tr("Connection failed.\n",
                              "Click Cancel to exit"), QMessageBox::Cancel);


//        QTableView table_sp;
//        QStandardItemModel model{ 0, 1 };
//        QStandardItem insertRow{ "<Click to add new item>" };
//        insertRow.setEditable(false);

//        table_sp.setModel(&model);
//        model.insertRow(0, &insertRow);

//        QApplication::connect(&table_sp, &QTableView::doubleClicked,
//                [&model](const QModelIndex index)
//        {
//            int rowCount = model.rowCount();
//            if (index.row() == rowCount - 1)
//                model.insertRow(rowCount - 1, new QStandardItem{ "New item" });
//        });

//            table_sp.show();

            return a.exec();
}
