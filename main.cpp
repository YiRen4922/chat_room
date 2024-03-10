#include "login_window.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login_window w;
    qDebug() << QSqlDatabase::drivers();
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName("192.168.137.137");
    db.setPort(3306);
    db.setUserName("root");
    db.setPassword("123");
    db.setDatabaseName("chat");

    bool result = db.open();
    if(result)
    {
        // QMessageBox::information(nullptr, "数据库", "连接成功");
        qDebug() << "连接数据库成功";
        w.show();
    }
    else
    {
        qDebug() << db.lastError().text();
        QMessageBox::information(nullptr, "数据流库", "连接失败");
    }


    return a.exec();
}
