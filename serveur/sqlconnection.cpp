#include "sqlconnection.h"
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>

SqlConnection::SqlConnection()
{

}


QString SqlConnection::connection(QString id){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("bdd_pri");
    db.setUserName("root");
    db.setPassword("");
    int i=0;

    QString rec;
    rec="";
    if(!db.open())
    {
         //QMessageBox::critical(this, "Erreur", "Erreur de connexion à la bdd.");
    } else {
        QSqlQuery query("SELECT * FROM clients where id= ? ");// Ici associer la clé à l'id pour identifier les données à afficher.
        query.addBindValue(id.toInt());//Transformation d'id en int pour l'utiliser dans le programme ,!!!! verifier si int marche avec clé binaire
        if (! query.exec()){
             return QString(); // erreur
        }

        if(query.first()){
              while(i<6){//  Recuperation des 6 lignes de la table client pour police
                rec.append(query.value(i).toString());
                rec.append("  ");
                i=i+1;








            }

        //else{
           // while(i<2){
             //   rec.append(query.value(i).toString());

              }
            //}
        return rec;
       // }
         //QMessageBox::information(this, "Connexion réussie", "La connexion avec la base de donnée s'est bien déroulée !");

    }
}
