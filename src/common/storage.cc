//
// Created by dingjing on 1/14/25.
//

#include "storage.h"

#include <QFile>
#include <QDebug>
#include <QSettings>

#include <gio/gio.h>

#include "defines.h"


class StoragePrivate
{
#define CONFIG_FILE             INSTALL_DIR"/lpb.conf"

public:
	~StoragePrivate();
	explicit StoragePrivate(Storage * other);

	QVariant getConfigValue(const QString& group, const QString& key) const;
	void setConfigValue(const QString& group, const QString& key, const QVariant& value) const;

protected:
	void initConfigureValue();

private:
	Storage * q_ptr;
	QSettings * mSettings = nullptr;
	Q_DECLARE_PUBLIC(Storage);
};

Storage * Storage::gInstance = nullptr;

StoragePrivate::~StoragePrivate()
{
	q_ptr = nullptr;
	delete mSettings;
}

StoragePrivate::StoragePrivate(Storage * other)
	: q_ptr(other), mSettings(new QSettings(CONFIG_FILE, QSettings::IniFormat))
{
	if (!QFile::exists(CONFIG_FILE)) {
		qInfo() << "Create configure file: " << CONFIG_FILE;
		QFile file(CONFIG_FILE);
		file.open(QIODevice::NewOnly);
		file.flush();
		file.close();

		initConfigureValue();
	}
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

void StoragePrivate::initConfigureValue()
{
	Q_Q(Storage);

	q->setTcpPort(TCP_SERVER_PORT);
	q->setUdpPort(TCP_SERVER_PORT);
	q->setUseProxy(false);
}

Storage* Storage::getInstance()
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

void Storage::setTcpPort(cuint32 port)
{
	Q_D(Storage);

	d->setConfigValue("TcpServer", "port", port);
}

cuint32 Storage::getTcpPort() const
{
	Q_D(const Storage);

	return d->getConfigValue("TcpServer", "port").toUInt();
}

void Storage::setUdpPort(cuint32 port)
{
	Q_D(Storage);

	d->setConfigValue("UdpServer", "port", port);
}

cuint32 Storage::getUdpPort() const
{
	Q_D(const Storage);

	return d->getConfigValue("UdpServer", "port").toUInt();
}

void Storage::setUseProxy(bool useProxy)
{
	Q_D(Storage);

	d->setConfigValue("TcpServer", "useProxy", useProxy);
}

bool Storage::getUseProxy() const
{
	Q_D(const Storage);

	return d->getConfigValue("TcpServer", "useProxy").toBool();
}

Storage::Storage(QObject * parent)
	: QObject(parent), d_ptr(new StoragePrivate(this))
{
}

Storage::~Storage()
{
	delete d_ptr;
}
