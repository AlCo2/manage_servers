#include "main.h"
#include "./ui_main.h"
#include "createnewserver.h"

Main::Main(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ServersManager)
{
    ui->setupUi(this);
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
    createNewServer->show();
}

