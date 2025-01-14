//
// Created by dingjing on 1/13/25.
//
#include <stdio.h>

#include "../common/log.h"
#include "../common/qlog.h"


int main(int argc, const char * argv[])
{
    C_LOG_INFO("daemon start...");

    qInstallMessageHandler(c_qlog_handler);

    return 0;
}
