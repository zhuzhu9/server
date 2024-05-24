/*
 * Project: server
 * Moudle: logger
 * File: logger.h
 * Created Date: 2024-04-22 16:13:14
 * Author: zhuzhu
 * Description: description
 * -----
 * todo: modified
 * -----
 * Copyright (c) 2024  Inc
 */
#ifndef LOGGER_H
#define LOGGER_H

#include "singleton.h"
#include "squeue.h"
#include <ostream>
#include <sstream>
#include <string>
#include <string_view>
#include <thread>

#include "spdlog/spdlog.h"

namespace myweb::log {

enum class LogLevel : unsigned int {
    NONE = 0,
    DEBUG = 1,
    INFO = 2,
    WARNING = 3,
    ERROR = 4,
    FATAL = 5,
};
class ZZLog {
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

class Logger : public utils::Singleton<Logger> {
  public:
    template <typename... Args>
    void Log(LogLevel l, Args &&...args);
    void init(std::string_view path) { log_.init(path); }

  private:
    ZZLog log_;
};

template <typename... Args>
void Logger::Log(LogLevel l, Args &&...args)
{
    // TODO: format success and parse failed (time file level line)
    // TODO: 在这组str存在性能问题，此处为业务线程，应该把组str转移到log线程中
#if __cplusplus > 202003L
    // c++20 std::format
    std::string fmt{std::format("[{} {}] ", "Hello", "world")};

    for (int i{}; i != sizeof...(Args); ++i) {
        fmt += "{} ";
    }

    std::string log = std::vformat(fmt, std::make_format_args(args...));
    log_(log);
#endif
    std::stringstream ss;
    ss << "[" << __TIME__ << " " << __BASE_FILE__ << " "
       << "] ";
    ((ss << args), ...) << "\n";

    // std::cout << ss.str() << "\n";
    log_(ss.str());
}

} // namespace myweb::log

#endif // LOGGER_H