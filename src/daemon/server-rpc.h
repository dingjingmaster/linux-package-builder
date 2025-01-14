//
// Created by dingjing on 1/14/25.
//

#ifndef lpb_SERVER_RPC_H
#define lpb_SERVER_RPC_H
#include <QObject>


class ServerRPCPrivate;
class ServerRPC final : public QObject
{
    Q_OBJECT
public:
    static ServerRPC* getInstance();

private:
    explicit ServerRPC(QObject* parent=nullptr);


private:
    static ServerRPC*               gInstance;
    ServerRPCPrivate*               d_ptr;

    Q_DECLARE_PRIVATE(ServerRPC);
};



#endif // lpb_SERVER_RPC_H
