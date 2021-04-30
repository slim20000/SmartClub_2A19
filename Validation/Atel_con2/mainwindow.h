#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <dialog_home.h>
#include <dialog_inscription.h>
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
    void on_pushButton_connex_clicked();

    void on_pushButton_inscr_clicked();

    void showTime();


private:
    Ui::MainWindow *ui;
    Dialog_home *connexion;
    Dialog_inscription *inscrire;
};

#endif // MAINWINDOW_H
