#include "sqlconnection.h"
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>

SqlConnection::SqlConnection()
{

}


QString SqlConnection::connection(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL3");
    db.setHostName("localhost");
    db.setDatabaseName("bdd_pri");
    db.setUserName("root");
    db.setPassword("");
    if(!db.open())
    {
         //QMessageBox::critical(this, "Erreur", "Erreur de connexion à la bdd.");
    } else {
         QSqlQuery query("select *  from clients ");
        if (! query.exec())
             return QString(); // erreur
        if (query.first())
             return query.value(0).toString();
        return QString();
         //QMessageBox::information(this, "Connexion réussie", "La connexion avec la base de donnée s'est bien déroulée !");
    }
}
