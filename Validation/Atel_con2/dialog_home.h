#ifndef DIALOG_HOME_H
#define DIALOG_HOME_H

#include <dialog_personnel.h>
#include <dialog_activite.h>
#include <dialog_salle.h>
#include <QDialog>

namespace Ui {
class Dialog_home;
}

class Dialog_home : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_home(QWidget *parent = nullptr);
    ~Dialog_home();

private slots:
    void on_pushButton_Personnel_clicked();
    void on_pushButton_salle_clicked();
    void on_pushButton_activite_clicked();


private:
    Ui::Dialog_home *ui;
    Dialog_personnel *acces_perso;
    Dialog_activite *acces_act;
    Dialog_salle *acces_salle;
};

#endif // DIALOG_HOME_H
