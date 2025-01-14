//
// Created by dingjing on 1/14/25.
//

#ifndef lpb_QLOG_H
#define lpb_QLOG_H
#include <QDebug>

#include "log.h"

#ifndef C_LOG_TAG
#define C_LOG_TAG       "qlog"
#endif

#ifndef C_LOG_SIZE
#define C_LOG_SIZE      (200 * 2 << 10)         // 200mb
#endif

#ifndef C_LOG_DIR
#define C_LOG_DIR       "/tmp/"
#endif

#ifdef DEBUG
#define C_LOG_LEVEL    C_LOG_LEVEL_VERB
#else
#define C_LOG_LEVEL    C_LOG_LEVEL_INFO
#endif

#if QT_VERSION >= QT_VERSION_CHECK(5,0,0)
#define C_QLOG_INIT_IF_NOT_INIT \
{ \
    if (G_UNLIKELY(!(0 != c_log_is_inited()))) { \
        c_log_init (C_LOG_LEVEL, C_LOG_SIZE, C_LOG_DIR, C_LOG_TAG, "log", 0); \
        qInstallMessageHandler(c_qlog_handler); \
    } \
};

void c_qlog_handler (QtMsgType type, const QMessageLogContext &context, const QString &msg);

#elif QT_VERSION >= QT_VERSION_CHECK(4,0,0)
#define C_QLOG_INIT_IF_NOT_INIT \
{ \
    if (C_UNLIKELY(!(0 != c_log_is_inited()))) { \
        c_log_init (C_LOG_TYPE_FILE, C_LOG_LEVEL, C_LOG_SIZE, C_LOG_DIR, C_LOG_TAG, "log", 0); \
        qInstallMsgHandler(c_qlog_handler); \
    } \
};

void c_qlog_handler (QtMsgType type, const QString &msg);

#endif
#endif // lpb_QLOG_H
