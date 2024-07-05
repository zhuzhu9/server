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

#include "zlogger.h"

#if USE_LOG_SPDLOG
// #define LogInit(cfg)                                                                                                   \
//     do {                                                                                                               \
//         LOGDEFAULT.init(cfg);                                                                                          \
//     } while (0)

#define LOGD(fmt, ...)                                                                                                 \
    do {                                                                                                               \
        spdlog::debug(fmt, ##__VA_ARGS__);                                                                             \
    } while (0)
#define LOGI                                                                                                           \
    do {                                                                                                               \
        spdlog::info(fmt, ##__VA_ARGS__);                                                                              \
    } while (0)
#define LOGW                                                                                                           \
    do {                                                                                                               \
        spdlog::warning(fmt, ##__VA_ARGS__);                                                                           \
    } while (0)
#define LOGE(fmt, ...)                                                                                                 \
    do {                                                                                                               \
        spdlog::error(fmt, ##__VA_ARGS__);                                                                             \
    } while (0)
#endif

#if USE_LOG_ZLOG

static myweb::zlog::Logger &LOGDEFAULT = myweb::zlog::Logger::instance();

#define LogInit(cfg)                                                                                                   \
    do {                                                                                                               \
        LOGDEFAULT.init(cfg);                                                                                          \
    } while (0)

#define LOGT(fmt, ...)                                                                                                 \
    do {                                                                                                               \
        LOGDEFAULT.Log(myweb::zlog::LogLevel::trace, fmt, ##__VA_ARGS__);                                              \
    } while (0)
#define LOGD(fmt, ...)                                                                                                 \
    do {                                                                                                               \
        LOGDEFAULT.Log(myweb::zlog::LogLevel::debug, fmt, ##__VA_ARGS__);                                              \
    } while (0)
#define LOGI(fmt, ...)                                                                                                 \
    do {                                                                                                               \
        LOGDEFAULT.Log(myweb::zlog::LogLevel::info, fmt, ##__VA_ARGS__);                                               \
    } while (0)
#define LOGW(fmt, ...)                                                                                                 \
    do {                                                                                                               \
        LOGDEFAULT.Log(myweb::zlog::LogLevel::warining, fmt, ##__VA_ARGS__);                                           \
    } while (0)
#define LOGE(fmt, ...)                                                                                                 \
    do {                                                                                                               \
        LOGDEFAULT.Log(myweb::zlog::LogLevel::debug, fmt, ##__VA_ARGS__);                                              \
    } while (0)

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
#endif

#endif // LOG_LOG_H