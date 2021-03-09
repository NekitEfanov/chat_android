#ifndef CHAT_H
#define CHAT_H

#include "client_server.h"
#include <QKeyEvent>

#include <QWidget>
#include <memory>
#include <QMetaObject>
#include <QString>

namespace Ui {
class chat;
}

class chat : public QWidget
{
    Q_OBJECT

protected:
    QString version_this = "0002";
    QString version_server = "";

public:
    explicit chat(QWidget *parent = nullptr);
    ~chat();
    void tryToConnect(const QString &login);
    bool eventFilter(QObject *obj, QEvent *event);
    QString login;
    QString data;
    void writeMessage();
    void chat_history();
    void connect_status();
private slots:
    void on_setTextChatButton_clicked();

private:
    Ui::chat *ui;
    std::shared_ptr<Client_server>  m_client;
};

#endif // CHAT_H
