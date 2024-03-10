#include "login_window.h"
#include "ui_login_window.h"
#include "register_window.h"

Login_window::Login_window(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login_window)
{
    ui->setupUi(this);
    ui->pwd_lineEdit->setEchoMode(QLineEdit::Password);
    this->setFixedSize(size());
}

Login_window::~Login_window()
{
    delete ui;
}

void Login_window::on_login_pushButton_clicked()
{
    // 1123
    QString user_name = ui->user_lineEdit->text();
    QString password = ui->pwd_lineEdit->text();
    QString query_user_pwd = QString(
"SELECT * FROM chat.user_info WHERE username='%1' AND password='%2'").arg(user_name).arg(password);
    QSqlQuery query;
    query.exec(query_user_pwd);

    if(query.first())
    {
        QMessageBox::information(nullptr, "登录","登录成功");
        this->hide();
        Chat_window *chat_window = new Chat_window();
        chat_window->show();
    }
    else
    {
        QMessageBox::warning(nullptr, "登录","登录失败");
    }
    qDebug() << user_name << password;
}

void Login_window::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Return)
    {
        on_login_pushButton_clicked();
    }
}

void Login_window::on_register_pushButton_clicked()
{
    this->hide();

    Register_window *register_w = new Register_window(this);
    register_w->show();
}

