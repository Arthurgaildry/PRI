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
              while(i<7){//  Recuperation des 7 lignes de la table client
                rec.append(query.value(i).toString());
                rec.append("  ");
                i=i+1;




            }
              /*
                              int A[2]; definition de tableau pour ressortir les données souhaitées
                              int M[6];
                              int P[4];
                              A[0]=1;
                              A[1]=2;
                              A[2]=5;
                              M[0]=0;
                              M[1]=1;
                              M[2]=2;
                              M[3]=3;
                              M[4]=4;
                              M[5]=5;
                              M[6]=7;
                              P[0]=1;
                              P[1]=2;
                              P[2]=4;
                              P[3]=5;
                              P[4]=6;
                              if(choix=medecin){
                                for(int i=0; i<6; i++){
                                    rec.append(query.value(M[i]).toString());
                                    rec.append("  ");
                                }
                              }
                                if(choix=police){
                                     for(int i=0; i<4; i++){
                                         rec.append(query.value(P[i]).toString());
                                         rec.append("  ");
                                     }
                                }
                                if(choix=autre){
                                     for(int i=0; i<2; i++){
                                         rec.append(query.value(A[i]).toString());
                                         rec.append("  ");
                                     }
                                }
                             Fin du codage pour les differents cas
                              */



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
