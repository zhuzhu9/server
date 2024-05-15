/*
 * Project: server
 * Moudle: log
 * File: logger.cpp
 * Created Date: 2024-04-22 15:00:49
 * Author: zhuzhu
 * Description: description
 * -----
 * todo: modified
 * -----
 * Copyright (c) 2024  Inc
 */

#include "logger.h"
#include <iostream>
#include <thread>

namespace myweb::log {

void ZZLog::printConsole()
{
    std::string log;
    log_qu_.wait_pop(log);
    std::cout << log;
}

void ZZLog::init(std::string_view path)
{
    file_path_ = path;
    log_thread_ = std::thread(&ZZLog::print, this);
    log_thread_.detach();
}

void ZZLog::printFile() {}

} // namespace myweb::log
