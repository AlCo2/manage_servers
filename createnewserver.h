#ifndef CREATENEWSERVER_H
#define CREATENEWSERVER_H
#include <QDialog>
#include "valid.h"
#include "databasemanager.h"

namespace Ui {
class CreateNewServer;
}

class CreateNewServer : public QDialog
{
    Q_OBJECT

public:
    explicit CreateNewServer(QWidget *parent = nullptr);
    ~CreateNewServer();

private slots:
    void on_cancle_clicked();

    void on_create_clicked();

signals:
    void serverCreated();
private:
    Ui::CreateNewServer *ui;
};

#endif // CREATENEWSERVER_H
