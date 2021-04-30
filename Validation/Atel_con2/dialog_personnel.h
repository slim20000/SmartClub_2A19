#ifndef DIALOG_PERSONNEL_H
#define DIALOG_PERSONNEL_H
#include <personnel.h>
#include <QDialog>

namespace Ui {
class Dialog_personnel;
}

class Dialog_personnel : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_personnel(QWidget *parent = nullptr);
    ~Dialog_personnel();

private slots:
    void on_pushButton_ajouter_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_modifier_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Dialog_personnel *ui;
    personnel tmpPersonnel;
};

#endif // DIALOG_PERSONNEL_H
