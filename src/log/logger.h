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
#include <iostream>
#include <ostream>

namespace myweb::log {

enum class LogLevel : unsigned int {
    NONE = 0,
    DEBUG = 1,
    INFO = 2,
    WARNING = 3,
    ERROR = 4,
    FATAL = 5,
};

class Logger : public utils::Singleton<Logger> {
  public:
    template <typename... Args>
    void Log(LogLevel l, Args &&...args);
};

template <typename... Args>
void Logger::Log(LogLevel l, Args &&...args)
{
    std::cout << "[" << __TIME__ << " " << __BASE_FILE__ << " " << __LINE__ << "] ";
    ((std::cout << args), ...) << "\n";
}
} // namespace myweb::log

#endif // LOGGER_H