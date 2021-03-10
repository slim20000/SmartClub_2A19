#include "etudiant.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QDate>
#include <QPrinter>
#include <QPrinter>
#include <QTextDocument>

#include "qpainter.h"
#include "qtablewidget.h"
#include "tableprinter.h"

client::client()
{
id=0; nom=""; prenom="",telephone="",type="";
}
client::client(int id,QDate age, QString nom , QString prenom,QString type,QString telephone)
{this->id=id;this->nom=nom;this->prenom=prenom;this->telephone=telephone;this->age=age;this->type=type; }
int client::getid(){return id;}
QDate client::getage(){return age;}

QString client::gettype(){return type;}
QString client::gettelephone(){return telephone;}
//QDate Etudiant::getdatenes(){return datenes;}

QString client::getnom(){return nom;}
QString client::getprenom(){return prenom;}
//QString client::gettelephone(){return telephone;}
//QString client::gettype(){return type;}

//QString client::getage(){return age;}
void client::setid(int id){this->id=id;}
void client::setage(QDate age){this->age=age;}

void client::setnom(QString nom){this->nom=nom;}
void client::setprenom(QString prenom){this->prenom=prenom;}
void client::settelephone(QString telephone){this->telephone=telephone;}
void client::settype(QString type){this->type=type;}

//void client::setage(QString age){this->age=age;}

bool client::update(int id){
    //QString res=QString::number(id);
    QSqlQuery query;

    query.prepare("update client SET id=:id,nom=:nom,prenom=:prenom,type=:type,telephone=:telephone,age=:age where id=:id");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":type", type);
    query.bindValue(":telephone", telephone);
    query.bindValue(":age", age);


     return query.exec();
}

bool client::ajouter()
{
QString res=QString::number(id);
//QString agee=QString::number(age);

QSqlQuery query;

query.prepare("insert into client (id, nom, prenom,type,telephone,age) "
              "values (:id, :nom, :prenom,:telephone,:type,:age)");
query.bindValue(0, res);
query.bindValue(1, nom);
query.bindValue(2, prenom);
query.bindValue(3, telephone);
query.bindValue(4, type);
query.bindValue(5, age);

 return query.exec();

}
bool client::supprimer(int id)
{
    QSqlQuery query;

    query.prepare("Delete from client where id=:id");
    query.bindValue(0, id);

     return query.exec();
}
QSqlQueryModel * client::search1(QString nom)
{
    QSqlQueryModel* model = new QSqlQueryModel();
     model->setQuery("select * from client where (nom LIKE '%"+nom+"%') ");

     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("telephone"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("date naissance"));

     return model;
}
QSqlQueryModel * client::order1()
{
    QSqlQueryModel* model = new QSqlQueryModel();
     model->setQuery("select * from client ORDER BY id ASC");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("telephone"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("date naissance"));

     return model;
}
QSqlQueryModel * client::order3()
{
    QSqlQueryModel* model = new QSqlQueryModel();
     model->setQuery("select * from client ORDER BY nom ASC");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("telephone"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("date naissance"));

     return model;
}
QSqlQueryModel * client::pdf()
{
    QSqlQueryModel* model = new QSqlQueryModel();
     model->setQuery("select * from client ORDER BY nom ASC");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("telephone"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("date naissance"));

     return model;
}
QSqlQueryModel * client::afficher()
{
   QSqlQueryModel* model=new QSqlQueryModel();
   //QSqlQueryModel *view;
   model->setQuery("select id,nom,prenom,telephone,type,age from client");

   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("telephone"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("date naissance"));

return model;
}
//void client::printPDF(QTableView*clientsTable)
//{
    //QPixmap pix(clientsTable->size());
      //QPainter painter(&pix);
     // clientsTable->render(&painter);
     // painter.end();
     // QPrinter printer(QPrinter::HighResolution);
      //printer.setOrientation(QPrinter::Landscape);
      //printer.setOutputFormat(QPrinter::PdfFormat);
     // printer.setPaperSize(QPrinter::A4);
      //printer.setOutputFileName("clientss.pdf"); // will be in build folder

      //painter.begin(&printer);
     // double xscale = printer.pageRect().width() / double(pix.width());
      //double yscale = printer.pageRect().height() / double(pix.height());
      //double scale = qMin(xscale, yscale);
      //painter.translate(printer.paperRect().x() + printer.pageRect().width() / 2,
               //         printer.paperRect().y() + printer.pageRect().height() / 2);
      //painter.scale(scale, scale);
     // painter.translate(-clientsTable->width() / 2, -clientsTable->height() / 2);
     // painter.drawPixmap(0, 0, pix);

   // QTextDocument doc;

   // doc.setHtml("");
    //doc.drawContents(&painter);

     // painter.end();

//}
