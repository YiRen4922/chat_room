#include "chat_window.h"
#include "ui_chat_window.h"

Chat_window::Chat_window(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Chat_window)
{
    ui->setupUi(this);
    chat_tcp_socket = new QTcpSocket(this);
    chat_tcp_socket->connectToHost("192.168.137.137", 6666);

    connect(chat_tcp_socket, &QTcpSocket::readyRead, this, &Chat_window::on_readyRead);
}

Chat_window::~Chat_window()
{
    delete ui;
}

void Chat_window::on_readyRead()
{
    QString data = chat_tcp_socket->readAll();
    // QTime current_time = QTime::currentTime();
    // QString current_time_str = current_time.toString("hh:mm:ss");
    // ui->textBrowser->append(current_time_str);
    ui->textBrowser->append(data);
}

void Chat_window::on_pushButton_clicked()
{
    QString data = ui->textEdit->toPlainText();
    chat_tcp_socket->write(data.toUtf8());
    ui->textEdit->clear();
}

