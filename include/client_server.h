#ifndef CLIENT_SERVER_H
#define CLIENT_SERVER_H

#include <QObject>
#include <QString>
#include <QTcpSocket>
#include <QHostAddress>
#include <QByteArray>
#include <QDebug>

class Client_server : public QObject
{
    Q_OBJECT

public:
    Client_server();
    QString IpServer = "95.72.168.85";
    void DataSocket_clear();

public slots:
    void connectSuccess();
    void sockReady();
    void sockDisc();
    void WriteMessage(QString data);
    QByteArray get_DataSocket();

signals:
    void history_chat();
    void connect_status();

private:
    QByteArray DataSocket;
    QString ServerAddress;
    QTcpSocket * socket;
    QByteArray Key = "GJ4tkdGielaI4jgmE8700GejgFfPERnFgotRI54342JG523FJ546fkgKGK";
    QByteArray Message;
    QByteArray version_server;
    QByteArray version_client = "0002";;
};

#endif // CLIENT_SERVER_H
