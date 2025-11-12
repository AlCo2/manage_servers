#include "main.h"
#include "./ui_main.h"
#include "createnewserver.h"

Main::Main(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ServersManager)
{
    ui->setupUi(this);
    setupServersTable();
}

Main::~Main()
{
    delete ui;
}


int qMain(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Main window;
    window.show();

    return app.exec();
}

void Main::on_new_server_clicked()
{
    CreateNewServer* createNewServer = new CreateNewServer(this);

    connect(createNewServer, &CreateNewServer::serverCreated, this, [=]() {
        QSqlTableModel* model = static_cast<QSqlTableModel*>(ui->serverList->model());
        if (model) {
            model->select();
        }
    });

    createNewServer->show();
}

void Main::setupServersTable() {
    QSqlTableModel *model = new QSqlTableModel(this, DatabaseManager::instance().database());
    model->setTable("servers");

    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    if (!model->select()) {
        qDebug() << "Failed to select table:" << model->lastError().text();
    } else {
        qDebug() << "Model columns:" << model->columnCount();
        qDebug() << "Model rows:" << model->rowCount();
    }

    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, "User");
    model->setHeaderData(2, Qt::Horizontal, "IP Address");
    model->setHeaderData(3, Qt::Horizontal, "Password");

    ui->serverList->setModel(model);
    ui->serverList->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->serverList->horizontalHeader()->setVisible(true);
    ui->serverList->verticalHeader()->setVisible(true);
}
