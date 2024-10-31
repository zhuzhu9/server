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
#include "os.h"
#include "zlog_msg.h"
#include <cstring>
#include <thread>

namespace myweb::zlog {
#define ZLOG_FILE_NAME(name) (std::strrchr(name, '/') ? (std::strrchr(name, '/') + 1) : name)

void ZLog::printConsole()
{
    using namespace std::chrono_literals;
    ZlogMsg msg{};
    if (log_qu_.wait_for_pop(msg, 100ms)) {
        std::string file_name = ZLOG_FILE_NAME(msg.loc_.file_name());

        fast_io::io::println("[", msg.thread_id__, " ", file_name, ":", msg.loc_.line(), "]", msg.payload_);
    }
}

void ZLog::init(std::string_view path)
{
    file_path_ = path;
    log_thread_ = std::thread{&ZLog::print, this};
}

void ZLog::print()
{
    os::system::SetThreadName("Zlog_async");
    do {

        printConsole();
        printFile();
    } while (!stop_.load() || !log_qu_.empty());
};

void ZLog::printFile() {} // 3s swap double buffer

} // namespace myweb::zlog
