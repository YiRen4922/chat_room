#ifndef LOGIN_WINDOW_H
#define LOGIN_WINDOW_H

#include <QWidget>
#include <Qtsql>
#include <QMessageBox>
#include <QKeyEvent>
#include "chat_window.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Login_window;
}
QT_END_NAMESPACE

class Login_window : public QWidget
{
    Q_OBJECT

public:
    Login_window(QWidget *parent = nullptr);
    ~Login_window();
//
private slots:
    void on_login_pushButton_clicked();

    void on_register_pushButton_clicked();

protected slots:
    void keyPressEvent(QKeyEvent *event) override;

private:
    Ui::Login_window *ui;
};
#endif // LOGIN_WINDOW_H
