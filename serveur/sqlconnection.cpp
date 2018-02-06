#include "sqlconnection.h"
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
#include<iostream>

using namespace std;

SqlConnection::SqlConnection()
{

}


QString SqlConnection::connection(QString mdp){// mdp---> mess (mess0)
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("bdd_pri");
    db.setUserName("root");
    db.setPassword("");
    int A[3]; //definition de tableau pour ressortir les données souhaitées
    int M[7];
    int P[5];
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
    /*

    DEFINIR ID ICI

    */
    int id=1;
    //int i=0;
    QString qui = mdp.left(3); //med mis automatique ou med au dbt du mdp
    mdp = mdp.right(3);
    QString rec;
    rec="";
    if(!db.open())
    {
         //QMessageBox::critical(this, "Erreur", "Erreur de connexion à la bdd.");
    } else {
        QSqlQuery query2("SELECT * FROM mdp where mdp= ? ");//id--> id  Ici associer la clé à l'id pour identifier les données à afficher.
        query2.addBindValue(mdp.toInt());//Transformation d'id en int pour l'utiliser dans le programme ,!!!! verifier si int marche avec clé binaire
        QSqlQuery query("SELECT * FROM clients where id= ? ");//id--> id  Ici associer la clé à l'id pour identifier les données à afficher.
        query.addBindValue(id);//Transformation d'id en int pour l'utiliser dans le programme ,!!!! verifier si int marche avec clé binaire
        if (! query.exec()){
             return QString(); // erreur
        }
        if (! query2.exec()){
             return QString(); // erreur
        }
    if(!query2.exec()){
        cout<<'Mot de passe incorrecte';
    }
    if(query2.exec()){
        if(query.first()){
           /*   while(i<7){//  Recuperation des 7 lignes de la table client
                rec.append(query.value(i).toString());
                rec.append("  ");
                i=i+1;
            }*/
                              if(qui=="med"){
                                for(int i=0; i<=6; i++){
                                    rec.append(query.value(M[i]).toString());
                                    rec.append(" - ");

                                }
                              }
                                if(qui=="pol"){
                                     for(int i=0; i<=4; i++){
                                         rec.append(query.value(P[i]).toString());
                                         rec.append(" - ");
                                     }
                                }
                                if(qui=="aut"){
                                     for(int i=0; i<=2; i++){
                                         rec.append(query.value(A[i]).toString());
                                         rec.append(" - ");
                                     }
                                }
                           //  Fin du codage pour les differents cas




        //else{
           // while(i<2){
             //   rec.append(query.value(i).toString());

              }
    }
            //}
        return rec;
       // }
         //QMessageBox::information(this, "Connexion réussie", "La connexion avec la base de donnée s'est bien déroulée !");

    }
}


