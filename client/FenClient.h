#ifndef HEADER_FENCLIENT
#define HEADER_FENCLIENT

#include <QtGui>
#include <QtNetwork>
#include "ui_FenClient.h"
#include<Qwidget>
#include<QtWidgets>



class FenClient : public QWidget, private Ui::FenClient
{
    Q_OBJECT

    public:
        FenClient();

    private slots:
        void on_boutonConnexion_clicked();
        void on_boutonEnvoyer_clicked();
        void on_message_returnPressed();
        void donneesRecues();
        void connecte();
        void deconnecte();
        void erreurSocket(QAbstractSocket::SocketError erreur);

        void on_radioButton_Po_toggled(bool checked);

        void on_radioButton_Aut_toggled(bool checked);

        void on_radioButton_Aut_clicked();

        void on_radioButton_Med_clicked();

private:
        QTcpSocket *socket; // Repr�sente le serveur
        quint16 tailleMessage;
};

#endif
