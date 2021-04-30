#ifndef DIALOG_SALLE_H
#define DIALOG_SALLE_H

#include<salle.h>
#include <QDialog>

namespace Ui {
class Dialog_salle;
}

class Dialog_salle : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_salle(QWidget *parent = nullptr);
    ~Dialog_salle();

private slots:
    void on_pushButton_ajouter_clicked();

    void on_pushButton_modifier_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_Trier_clicked();

    void on_pushButton_chercher_2_clicked();

private:
    Ui::Dialog_salle *ui;
    Salle tmpsalle;
};

#endif // DIALOG_SALLE_H
