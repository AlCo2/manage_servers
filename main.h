#ifndef MAIN_H
#define MAIN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class ServersManager;
}
QT_END_NAMESPACE

class Main : public QMainWindow
{
    Q_OBJECT

public:
    Main(QWidget *parent = nullptr);
    ~Main();

private slots:
    void on_new_server_clicked();

    void on_serverList_activated(const QModelIndex &index);

private:
    Ui::ServersManager *ui;
};

#endif // MAIN_H
