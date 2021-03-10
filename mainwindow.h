#ifndef MAINWINDOW_H
#define MAINWINDOW_H
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


    void on_ajouter_clicked();

    void on_pb_id_supp_clicked();

    void on_update_clicked();

private:
    Ui::MainWindow *ui;
    Etudiant E;
};

#endif // MAINWINDOW_H
