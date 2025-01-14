//
// Created by dingjing on 1/14/25.
//

#ifndef lpb_STORAGE_H
#define lpb_STORAGE_H
#include <QMap>
#include <QMutex>
#include <QString>
#include <QVariant>

#include "macros/macros.h"


class StoragePrivate;
class Storage final : private QObject
{
    Q_OBJECT
public:
    static Storage* getInstance();

    void setTcpPort(cuint32 port);
    cuint32 getTcpPort() const;

    void setUdpPort(cuint32 port);
    cuint32 getUdpPort() const;

    void setUseProxy(bool useProxy);
    bool getUseProxy() const;

private:
    explicit Storage(QObject* parent=nullptr);
    ~Storage() override;

private:
    StoragePrivate*             d_ptr;
    static Storage*             gInstance;
    Q_DECLARE_PRIVATE(Storage);
};



#endif // lpb_STORAGE_H
