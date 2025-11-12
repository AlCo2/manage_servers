#include "createnewserver.h"
#include "ui_createnewserver.h"

CreateNewServer::CreateNewServer(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CreateNewServer)
{
    ui->setupUi(this);
}

CreateNewServer::~CreateNewServer()
{
    delete ui;
}

void CreateNewServer::on_cancle_clicked()
{
    this->destroy();
}


void CreateNewServer::on_create_clicked()
{
    QString user = this->ui->user->toPlainText();
    QString ip  = this->ui->ip->toPlainText();
    QString password = this->ui->password->toPlainText();

    if (!Valid::isValidIp(ip.toStdString())) {
        return;
    }

    if (DatabaseManager::instance().open()) {
        QSqlQuery query(DatabaseManager::instance().database());
        query.prepare("INSERT INTO servers (user, ip, password) VALUES (:user, :ip, :password)");
        query.bindValue(":user", user);
        query.bindValue(":ip", ip);
        query.bindValue(":password", password);
        if (!query.exec())
            qDebug() << "Insert failed:" << query.lastError().text();
    }

    this->destroy();
}

