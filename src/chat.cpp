#include "chat.h"
#include "ui_chat.h"

chat::chat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chat)
{
    ui->setupUi(this);
    QImage img(":/img/image_res/message.jpg");
    QPixmap pm = QPixmap::fromImage(img);
    QIcon ButtonIcon(pm);

    ui->setTextChatButton->setIcon(ButtonIcon);
    ui->setTextChatButton->setIconSize(ui->setTextChatButton->rect().size());
    ui->setTextChatLine->installEventFilter(this);
    ui->chatQT->setAlignment(Qt::AlignLeft);
    ui->chatQT->setReadOnly(true);
    ui->connected_status->setStyleSheet("background-color: white;");

}

chat::~chat()
{
    delete ui;
}

void chat::on_setTextChatButton_clicked()
{
    writeMessage();
}

void chat::tryToConnect(const QString &login)
{
    this->login = login;
    m_client.reset(new Client_server());

    connect(m_client.get(),
            &Client_server::history_chat,
            this,
            &chat::chat_history);

    connect(m_client.get(),
            &Client_server::connect_status,
            this,
            &chat::connect_status);

}

bool chat::eventFilter(QObject *obj, QEvent *event)
{

if(event->type() == QEvent::KeyRelease)
 {
  QKeyEvent *key = static_cast<QKeyEvent*>(event);

  if(key->key() ==  Qt::Key_Return)
         writeMessage();
 }
  return QWidget::eventFilter(obj, event);
}

void chat::writeMessage()
{
    if (!(ui->setTextChatLine->text().isEmpty())) {
    data.clear();
    data = login + " :: " + ui->setTextChatLine->text();
    ui->chatQT->append(data);
    ui->setTextChatLine->clear();
    m_client->WriteMessage(data);
    m_client->DataSocket_clear();
    }
}

void chat::chat_history()
{
    ui->chatQT->append(QString(m_client->get_DataSocket()));
    m_client->DataSocket_clear();
}

void chat::connect_status()
{
    ui->connected_status->setText("status - connected");
}
