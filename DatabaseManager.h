#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

class DatabaseManager {
public:
    static DatabaseManager& instance() {
        static DatabaseManager instance;
        return instance;
    }

    bool open() {
        if (db.isOpen())
            return true;

        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("database.db");
        if (!db.open()) {
            qDebug() << "Database error:" << db.lastError().text();
            return false;
        }

        return this->migrate();
    }

    void close() {
        if (db.isOpen()) {
            db.close();
        }
    }

    bool migrate(){
        QSqlQuery query(db);

        bool success = query.exec("CREATE TABLE IF NOT EXISTS servers (id INTEGER PRIMARY KEY AUTOINCREMENT, user VARCHAR(60) DEFAULT 'root', ip VARCHAR(60), password VARCHAR(60) NULL)");
        if (!success) {
            qDebug() << "Migrate failed:" << query.lastError().text();
            return false;
        }
        return true;
    }

    QSqlDatabase database() { return db; }

private:
    DatabaseManager() = default;
    ~DatabaseManager() { close(); }

    QSqlDatabase db;
};


#endif // DATABASEMANAGER_H
