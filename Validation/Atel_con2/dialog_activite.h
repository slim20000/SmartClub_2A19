#ifndef DIALOG_ACTIVITE_H
#define DIALOG_ACTIVITE_H

#include<activite.h>
#include <QDialog>

namespace Ui {
class Dialog_activite;
}

class Dialog_activite : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_activite(QWidget *parent = nullptr);
    ~Dialog_activite();

private slots:
    void on_pushButton_ajouter_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_modifier_clicked();

    void on_pushButton_chercher_clicked();

    void on_comboBox_auteur_currentIndexChanged(const QString &arg1);


    void on_pushButton_Trier_clicked();

private:
    Ui::Dialog_activite *ui;
    Activite tmpactivite;
};

#endif // DIALOG_ACTIVITE_H
