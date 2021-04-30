#ifndef DIALOG_INSCRIPTION_H
#define DIALOG_INSCRIPTION_H

#include <QDialog>

namespace Ui {
class Dialog_inscription;
}

class Dialog_inscription : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_inscription(QWidget *parent = nullptr);
    ~Dialog_inscription();

private slots:
    void on_pushButton_ajouter_clicked();

private:
    Ui::Dialog_inscription *ui;
};

#endif // DIALOG_INSCRIPTION_H
