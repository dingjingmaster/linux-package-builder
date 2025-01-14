//
// Created by dingjing on 1/13/25.
//
#include <wait.h>
#include <unistd.h>
#include <QTextCodec>

#include "daemon.h"
#include "../common/log.h"
#include "../common/qlog.h"


static inline void creat_new_process()
{
    while (true) {
        const pid_t p = fork();
        if (-1 == p) {
            C_LOG_WARNING("fork failed");
            exit(-1);
        }
        else if (0 == p) {
            break;
        }
        else {
            int ret = 0;
            wait(&ret);
            C_LOG_WARNING("daemon exit, exit code: %d, restart...", ret);
            sleep(1); // 太频繁拉起会导致关机慢
        }
    }
}

int main(int argc, char* argv[])
{
    creat_new_process();

    signal(SIGPIPE, SIG_IGN);

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    C_LOG_INFO("daemon start...");
    qInstallMessageHandler(c_qlog_handler);

    Daemon app(argc, argv);

    return SingleApplication::exec();
}
