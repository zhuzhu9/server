/*
 * Project: server
 * Moudle: zlog
 * File: zlogger.cpp
 * Created Date: 2024-04-22 15:00:49
 * Author: zhuzhu
 * Description: description
 * -----
 * todo: modified
 * -----
 * Copyright (c) 2024  Inc
 */

#include "zlogger.h"
#include "fast_io.h"
#include "zlog_msg.h"
#include <cstring>
#include <iostream>
#include <thread>

namespace myweb::zlog {

void ZLog::printConsole()
{
    ZlogMsg msg{};
    log_qu_.wait_pop(msg);
    std::string file_name = ZLOG_FILE_NAME(msg.loc_.file_name());

    ::fast_io::io::println("[", msg.thread_id__, " ", file_name, ":", msg.loc_.line(), "]", msg.payload_);
}

void ZLog::init(std::string_view path)
{
    file_path_ = path;
    log_thread_ = std::thread(&ZLog::print, this);
}

void ZLog::printFile() {} // 3s swap double buffer

} // namespace myweb::zlog
