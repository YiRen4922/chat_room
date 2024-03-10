#include "register_window.h"
#include "ui_register_window.h"

Register_window::Register_window(Login_window *login_w ,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Register_window)
    , login_window(login_w)
{
    ui->setupUi(this);
    ui->pwd_lineEdit->setEchoMode(QLineEdit::Password);
    this->setFixedSize(size());
}

Register_window::~Register_window()
{
    // qDebug() << "delete Register";
    delete ui;
}

void Register_window::on_login_pushButton_clicked()
{
    this->hide();
    login_window->show();
}

void Register_window::on_register_pushButton_clicked()
{
    QString user_name = ui->user_lineEdit->text();
    QString password = ui->pwd_lineEdit->text();
    qDebug() << user_name << password;
    QString inster_user_pwd = QString("INSERT INTO chat.user_info VALUES(NULL, '%1', '%2')").arg(user_name).arg(password);
    QString select_username = QString("SELECT * FROM chat.user_info WHERE username='%1'").arg(user_name);
    QSqlQuery query;
    query.exec(select_username);
    if(query.first())
    {
        QMessageBox::warning(this, "警告", "账号重复");
    }
    else
    {
        query.exec(inster_user_pwd);
        QMessageBox::information(this, "通知", "注册成功");
    }
}

