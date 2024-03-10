#ifndef CHAT_WINDOW_H
#define CHAT_WINDOW_H

#include <QWidget>
#include <QTcpSocket>
#include <QTime>

namespace Ui {
class Chat_window;
}

class Chat_window : public QWidget
{
    Q_OBJECT

public:
    explicit Chat_window(QWidget *parent = nullptr);
    ~Chat_window();

private:
    Ui::Chat_window *ui;
    QTcpSocket *chat_tcp_socket;

private slots:
    void on_readyRead();

    void on_pushButton_clicked();
};

#endif // CHAT_WINDOW_H
