//
// Created by dingjing on 1/14/25.
//

#include "storage.h"

#include <QSettings>

#include <gio/gio.h>


class StoragePrivate
{
#define CONFIG_FILE             INSTALL_DIR"/lpb.conf"
public:
    ~StoragePrivate();
    explicit StoragePrivate(Storage* other);

    QVariant getConfigValue(const QString& group, const QString& key) const;
    void setConfigValue(const QString& group, const QString& key, const QVariant& value) const;

private:
    Storage*                    q_ptr;
    QSettings*                  mSettings = nullptr;
    Q_DECLARE_PUBLIC(Storage);
};

Storage* Storage::gInstance = nullptr;

StoragePrivate::~StoragePrivate()
{
    q_ptr = nullptr;
    delete mSettings;
}

StoragePrivate::StoragePrivate(Storage* other)
    : q_ptr(other), mSettings(new QSettings(CONFIG_FILE, QSettings::IniFormat))
{
}

QVariant StoragePrivate::getConfigValue(const QString& group, const QString& key) const
{
    mSettings->sync();
    mSettings->beginGroup(group);
    auto val = mSettings->value(key);
    mSettings->endGroup();
    mSettings->sync();

    return val;
}

void StoragePrivate::setConfigValue(const QString& group, const QString& key, const QVariant& value) const
{
    mSettings->sync();
    mSettings->beginGroup(group);
    mSettings->setValue(key, value);
    mSettings->endGroup();
    mSettings->sync();
}

Storage * Storage::getInstance()
{
    static bool inited = false;

    if (!inited) {
        static QMutex locker;
        locker.lock();
        if (!gInstance) {
            gInstance = new Storage();
        }
        locker.unlock();
    }

    return gInstance;
}

Storage::Storage(QObject* parent)
    : QObject(parent), d_ptr(new StoragePrivate(this))
{
}

Storage::~Storage()
{
    delete d_ptr;
}
