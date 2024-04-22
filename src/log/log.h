/*
 * Project: server
 * Moudle: log
 * File: log.h
 * Created Date: 2024-04-22 15:00:56
 * Author: zhuzhu
 * Description: description
 * -----
 * todo: modified
 * -----
 * Copyright (c) 2024  Inc
 */
#ifndef LOG_LOG_H
#define LOG_LOG_H

#include "logger.h"

static myweb::log::Logger &LOGDEFAULT = myweb::log::Logger::instance();

#define LOGD(fmt, ...)                                                                                                 \
    do {                                                                                                               \
        LOGDEFAULT.Log(myweb::log::LogLevel::DEBUG, fmt, ##__VA_ARGS__);                                               \
    } while (0)
#define LOGI
#define LOGW
#define LOGE

namespace myweb::log {

// class LoggerHelper {
//   public:
//     LoggerHelper() = delete;
//     LoggerHelper(const LoggerHelper &) = delete;
//     LoggerHelper &operator=(const LoggerHelper &) = delete;
//     LoggerHelper(LoggerHelper &&) = delete;
//     LoggerHelper &operator=(LoggerHelper &&) = delete;
//     ~LoggerHelper() = default;
//     static bool printLog()
// };

class Log {
    static void log();
};

} // namespace myweb::log

#endif // LOG_LOG_H