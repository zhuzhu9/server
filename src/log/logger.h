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
    wyweb::utils::SQueue<std::string> log_qu_;
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
#if __cplusplus > 202003L
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