//
// Created by dingjing on 1/14/25.
//

#include "server-rpc.h"

#include <QMutex>
#include <QUdpSocket>
#include <QWebSocketServer>
#include <QNetworkProxyFactory>

#include "src/common/storage.h"


class ServerRPCPrivate final
{
protected:
	~ServerRPCPrivate() = default;

public:
	explicit ServerRPCPrivate(ServerRPC * q);

private:
	void initUdpServer();

private:
	ServerRPC *			q_ptr;
	QUrl				mMaster;
	QSet<QString>		mCurrentIp;
	QUdpSocket *		mUdpSocket;
	QSet<QString>		mOthersItems;
	QWebSocketServer *	mWebSocketServer;
	Q_DECLARE_PUBLIC(ServerRPC);
};

ServerRPC * ServerRPC::gInstance = nullptr;


ServerRPCPrivate::ServerRPCPrivate(ServerRPC * q)
	: q_ptr(q)
{
	mUdpSocket = new QUdpSocket(q);
	mWebSocketServer = new QWebSocketServer("unknown", QWebSocketServer::SecureMode);
	mWebSocketServer->setSslConfiguration(QSslConfiguration::defaultConfiguration());

	QNetworkProxyFactory::setUseSystemConfiguration(Storage::getInstance()->getUseProxy());

	if (!mWebSocketServer->listen(QHostAddress::Any, Storage::getInstance()->getTcpPort())) {
		qWarning() << "ServerRPC::gInstance->listen() failed";
		exit(1);
	}
}

void ServerRPCPrivate::initUdpServer()
{
	Q_Q(ServerRPC);
}

ServerRPC* ServerRPC::getInstance()
{
	static bool inited = false;

	if (!inited) {
		static QMutex locker;
		locker.lock();
		if (!gInstance) {
			gInstance = new ServerRPC();
		}
		locker.unlock();
	}

	return gInstance;
}

ServerRPC::ServerRPC(QObject * parent)
	: QObject(parent), d_ptr(new ServerRPCPrivate(this))
{
}
