#include "client_server.h"

#include <stdexcept>
#include <iostream>

using namespace std;


Client_server::Client_server()
{
    socket = new QTcpSocket(this);

    connect(socket,
            &QTcpSocket::connected,
            this,
            &Client_server::connectSuccess);

    connect(socket,
            &QTcpSocket::disconnected,
            this,
            &Client_server::sockDisc);

    socket->connectToHost(IpServer, 60111);
}

void Client_server::connectSuccess()
{
    socket->waitForReadyRead(500);
    socket->write(Key);
    emit connect_status();
    if (!(socket->waitForReadyRead(5000)))
        socket->deleteLater();
    else
    {
        DataSocket = socket->readAll();
        for (size_t i = 0; i < 4; i++)
            version_server = version_server + DataSocket.data()[i];

        if (version_server.toInt() == version_client.toInt()) {
            DataSocket.remove(0, 4);
            emit history_chat();

            connect(socket,
                    &QTcpSocket::readyRead,
                    this,
                    &Client_server::sockReady);
            }

        else
            throw runtime_error("Server to response.");
    }
}

void Client_server::sockDisc()
{
    socket->deleteLater();
}

void Client_server::sockReady()
{
    if(socket->waitForConnected(500))
    {
       DataSocket = socket->readAll();
    }
}

void Client_server::WriteMessage(QString data)
{
    socket->write(data.toUtf8());
}

QByteArray Client_server::get_DataSocket()
{
    return DataSocket;
}
void Client_server::DataSocket_clear()
{
    DataSocket.clear();
}
