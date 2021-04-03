#ifndef TYPE_H
#define TYPE_H
#include <QString>
#include <QDate>
#include <QComboBox>
#include <QSqlQueryModel>
class type
{
public:
    type();
    type(int,QString,QString,QString,QString);
    int getid();
    QString getnom();
    QString getdescription();
    QString getdescription2();
    QString getdescription3();

    void setid(int);
    void setnom(QString);
    void setdescription(QString);
    void setdescription2(QString);
    void setdescription3(QString);
    QSqlQueryModel* model;

    bool ajouter1();
    bool update1(int);
    QSqlQueryModel * afficher1();
    bool supprimer1(int);
QSqlQueryModel * search(QString);
QSqlQueryModel * order();
QSqlQueryModel * order2();


private:
    int id;
    QString nom,description,description2,description3;
};


#endif // TYPE_H
