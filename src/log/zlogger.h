/*
 * Project: server
 * Moudle: zlogger
 * File: zlogger.h
 * Created Date: 2024-04-22 16:13:14
 * Author: zhuzhu
 * Description: description
 * -----
 * todo: modified
 * -----
 * Copyright (c) 2024  Inc
 */
#ifndef ZLOGGER_H
#define ZLOGGER_H

#include "singleton.h"
#include "squeue.h"
#include "zlog_default.h"
#include "zlog_enhance.h"
#include "zlog_msg.h"
#include <atomic>
#include <format>
#include <source_location>
#include <string_view>
#include <thread>
#include <utility>

#define ZLOG_FOREACH_LOG_LEVEL(f) f(trace) f(debug) f(info) f(warining) f(error) f(fatal)

namespace myweb::zlog {

class ZLog {
  public:
    // TODO: 分别插入不用写入方式的接口
    void print();
    void printConsole();
    void printFile();
    void init(std::string_view path);
    void operator()(const ZlogMsg &msg) { log_qu_.push(msg); }

    bool should_log(LogLevel msg_level) const { return msg_level >= lvl_; }
    void set_level(LogLevel msg_level) { lvl_ = msg_level; }

    ZLog() = default;
    ZLog(const ZLog &) = delete;
    ZLog(ZLog &&) noexcept = delete;
    ZLog &operator=(const ZLog &) = delete;
    ZLog &operator=(ZLog &&) noexcept = delete;

    ~ZLog()
    {
        stop_.store(true);
        if (log_thread_.joinable()) {
            log_thread_.join();
        }
    }

  private:
    myweb::utils::SQueue<ZlogMsg> log_qu_; // TODO: double buffer or ring buffer
    std::string_view file_path_;
    std::thread log_thread_;
    std::atomic_bool stop_{false};
    LogLevel lvl_{LogLevel::debug};
};

template <typename T>
struct Temp {
  public:
    T inner_;
    std::source_location loc_;

    template <typename U>
        requires(std::constructible_from<T, U>)
    consteval Temp(U &&inner, std::source_location loc = std::source_location::current())
        : inner_(std::forward<U>(inner)), loc_(loc){};

    constexpr T const &format() const { return inner_; };
    [[nodiscard]] constexpr std::source_location const &location() const { return loc_; };
};

class Logger : public utils::Singleton<Logger> {
  public:
    void init(std::string_view path) { log_.init(path); }
    template <typename... Args>
    void Log(LogLevel l, Temp<std::format_string<Args...>> &&fmt, Args &&...args);
    void set_level(LogLevel msg_level) { log_.set_level(msg_level); }

// TODO: 在这组str存在性能问题，此处为业务线程，应该把组str转移到log线程中
#define ZLOG_FUNCTION(x)                                                                                               \
    template <typename... Types>                                                                                       \
    void log_##x(Temp<std::format_string<Types...>> fmt, Types &&...args)                                              \
    {                                                                                                                  \
        auto &loc = fmt.location();                                                                                    \
        auto context = std::vformat(fmt.format().get(), std::make_format_args(args...));                               \
        ZlogMsg msg(loc, "", LogLevel::x, context);                                                                    \
        log_(msg);                                                                                                     \
    }
    ZLOG_FOREACH_LOG_LEVEL(ZLOG_FUNCTION)
#undef ZLOG_FUNCTION

  private:
    ZLog log_;
};

template <typename... Args>
void Logger::Log(LogLevel l, Temp<std::format_string<Args...>> &&fmt, Args &&...args)
{
    if (!log_.should_log(l))
        return;
    switch (l) {
#define ZLOG_FUNCTION(x)                                                                                               \
    case LogLevel::x:                                                                                                  \
        log_##x(std::forward<Temp<std::format_string<Args...>>>(fmt), std::forward<Args>(args)...);                    \
        break;
        ZLOG_FOREACH_LOG_LEVEL(ZLOG_FUNCTION)
#undef ZLOG_FUNCTION
    case LogLevel::none:
        break;
    }
}

} // namespace myweb::zlog

#undef ZLOG_FOREACH_LOG_LEVEL

#endif // ZLOGGER_H