//
// Created by dingjing on 1/14/25.
//

#include "daemon.h"

#include "src/common/defines.h"
#include "src/common/log.h"
#include "src/common/storage.h"


Daemon::Daemon(int argc, char * argv[], QObject * parent)
	: SingleApplication(argc, argv, false, System | SecondaryNotification)
{
}
