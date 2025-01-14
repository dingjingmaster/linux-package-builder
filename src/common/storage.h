//
// Created by dingjing on 1/14/25.
//

#ifndef lpb_STORAGE_H
#define lpb_STORAGE_H
#include <QMap>
#include <QMutex>
#include <QString>
#include <QVariant>


class StoragePrivate;
class Storage final : private QObject
{
    Q_OBJECT
public:
    static Storage* getInstance();

private:
    explicit Storage(QObject* parent=nullptr);
    ~Storage() override;

private:
    StoragePrivate*             d_ptr;
    static Storage*             gInstance;
    Q_DECLARE_PRIVATE(Storage);
};



#endif // lpb_STORAGE_H
