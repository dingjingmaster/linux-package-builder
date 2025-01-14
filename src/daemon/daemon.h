//
// Created by dingjing on 1/14/25.
//

#ifndef lpb_DAEMON_H
#define lpb_DAEMON_H
#include <QObject>


class Daemon final : public QObject
{
    Q_OBJECT
public:
    explicit Daemon(QObject* parent=nullptr);

};



#endif // lpb_DAEMON_H
