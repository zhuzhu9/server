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

#if USE_LOG_SPDLOG
#include "spdlog/async.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/spdlog.h"
namespace myweb::zlog {
// static auto LOGDEFAULT = spdlog::stdout_logger_mt<spdlog::async_factory>("serverqqq");
static auto LOGDEFAULT = spdlog::default_logger_raw();

inline void spdlog_init(std::string_view)
{
    // spdlog::set_default_logger(LOGDEFAULT);
}

#define LogInit(cfg) myweb::zlog::spdlog_init(cfg);

#define LOGT(fmt, ...) spdlog::trace(fmt, ##__VA_ARGS__);
#define LOGD(fmt, ...) spdlog::debug(fmt, ##__VA_ARGS__);
#define LOGI(fmt, ...) spdlog::info(fmt, ##__VA_ARGS__);
#define LOGW(fmt, ...) spdlog::warn(fmt, ##__VA_ARGS__);
#define LOGE(fmt, ...) spdlog::error(fmt, ##__VA_ARGS__);

#endif

#if USE_LOG_ZLOG
#include "zlogger.h"

static myweb::zlog::Logger &LOGDEFAULT = myweb::zlog::Logger::instance();

#define LogInit(cfg) LOGDEFAULT.init(cfg);

#define LOGT(fmt, ...) LOGDEFAULT.Log(myweb::zlog::LogLevel::trace, fmt, ##__VA_ARGS__);
#define LOGD(fmt, ...) LOGDEFAULT.Log(myweb::zlog::LogLevel::debug, fmt, ##__VA_ARGS__);
#define LOGI(fmt, ...) LOGDEFAULT.Log(myweb::zlog::LogLevel::info, fmt, ##__VA_ARGS__);
#define LOGW(fmt, ...) LOGDEFAULT.Log(myweb::zlog::LogLevel::warin, fmt, ##__VA_ARGS__);
#define LOGE(fmt, ...) LOGDEFAULT.Log(myweb::zlog::LogLevel::debug, fmt, ##__VA_ARGS__);

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

// class Log {
//     static void log();
// };

#endif // USE_LOG_ZLOG

// log point, only one param
#define LOGP(fmt, p) LOGD(fmt, reinterpret_cast<const void *>(p));

} // namespace myweb::zlog

#endif // LOG_LOG_H