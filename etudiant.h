#ifndef ETUDIANT_H
#define ETUDIANT_H
#include <QString>
#include <QDate>
#include <QComboBox>
#include <QSqlQueryModel>
class client
{
public:
    client();
    client(int,QDate,QString,QString,QString,QString);
    int getid();
QTabWidget getclientsTable();
    QString getnom();
    QString getprenom();
    QString gettype();
    QString gettelephone();
   QDate getage();
    void setid(int);
    void setnom(QString);
    void setprenom(QString);
   void settype(QString);
    void settelephone(QString);
    void setclientTable(QTabWidget);
    void setage(QDate);
    bool ajouter();
    bool update(int);
    bool removeRows();
    //void printPDF(QTableView *clientsTable);
    QSqlQueryModel * pdf();

    QSqlQueryModel * afficher();
    bool supprimer(int);
    QSqlQueryModel * search1(QString);
    QSqlQueryModel * order1();
    QSqlQueryModel * order3();
QTabWidget* clientsTable;
private:
    int id;
    QDate age;
    QString nom,prenom,telephone,type;
};

#endif // ETUDIANT_H
