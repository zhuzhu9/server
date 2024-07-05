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
#include <format>
#include <source_location>
#include <sstream>
#include <string>
#include <string_view>
#include <thread>
#include <utility>

#define ZLOG_FOREACH_LOG_LEVEL(f) f(trace) f(debug) f(info) f(warining) f(error) f(fatal)

namespace myweb::zlog {

enum class LogLevel : unsigned int {
#define ZLOG_FUNCTION(x) x,
    ZLOG_FOREACH_LOG_LEVEL(ZLOG_FUNCTION)
#undef ZLOG_FUNCTION
        none,
};

class ZLog {
  public:
    void print()
    {
        while (true) {
            printConsole();
            printFile();
        }
    };

    void printConsole();
    void printFile();
    void init(std::string_view path);
    void operator()(std::string str) { log_qu_.emplace(std::move(str)); }

  private:
    myweb::utils::SQueue<std::string> log_qu_;
    std::string_view file_path_;
    std::thread log_thread_;
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

    // TODO: 在这组str存在性能问题，此处为业务线程，应该把组str转移到log线程中
#define ZLOG_FUNCTION(x)                                                                                               \
    template <class... Types>                                                                                          \
    void log_##x(Temp<std::format_string<Types...>> fmt, Types &&...args)                                              \
    {                                                                                                                  \
        auto &loc_ = fmt.location();                                                                                   \
        std::stringstream ss;                                                                                          \
        ss << "[" << loc_.file_name() << ":" << loc_.line() << " " #x "] "                                             \
           << std::vformat(fmt.format().get(), std::make_format_args(args...)) << "\n";                                \
        log_(ss.str());                                                                                                \
    }
    ZLOG_FOREACH_LOG_LEVEL(ZLOG_FUNCTION)
#undef ZLOG_FUNCTION

  private:
    ZLog log_;
};

template <typename... Args>
void Logger::Log(LogLevel l, Temp<std::format_string<Args...>> &&fmt, Args &&...args)
{
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

#endif // ZLOGGER_H