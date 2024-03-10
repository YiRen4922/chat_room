#ifndef REGISTER_WINDOW_H
#define REGISTER_WINDOW_H

#include <QWidget>
#include "login_window.h"

namespace Ui {
class Register_window;
}

class Register_window : public QWidget
{
    Q_OBJECT

public:
    explicit Register_window(Login_window *login_w,QWidget *parent = nullptr);
    ~Register_window();

private slots:
    void on_login_pushButton_clicked();


    void on_register_pushButton_clicked();

private:
    Ui::Register_window *ui;
    Login_window *login_window;
};

#endif // REGISTER_WINDOW_H
