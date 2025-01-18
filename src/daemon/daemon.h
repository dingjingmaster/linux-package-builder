//
// Created by dingjing on 1/14/25.
//

#ifndef lpb_DAEMON_H
#define lpb_DAEMON_H
#include <QObject>
#include "SingleApplication/singleapplication.h"


class Daemon final : public SingleApplication
{
	Q_OBJECT

public:
	explicit Daemon(int argc, char * argv[], QObject * parent = nullptr);

private:
};



#endif // lpb_DAEMON_H
