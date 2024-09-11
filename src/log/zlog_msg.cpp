/*
 * Project: server
 * Moudle: module_name
 * File: zlog_msg.cpp
 * Created Date: 2024-09-10 11:28:05
 * Author: zhuzhu
 * Description: description
 * -----
 * todo: modified
 * -----
 * Copyright (c) 2024  Inc
 */

#include "zlog_msg.h"
#include "timer.h"
#include <source_location>
#include <utility>
#include <syscall.h>
#include <unistd.h>

namespace myweb::zlog {
using namespace myweb::utils::time;

ZlogMsg::ZlogMsg(std::chrono::time_point<std::chrono::system_clock> log_time,
                 std::source_location loc,
                 std::string_view logger_name,
                 LogLevel lvl,
                 std::string msg)
    : name_(logger_name), level_(lvl), time_(log_time), thread_id__(static_cast<size_t>(::syscall(SYS_gettid))),
      loc_(loc), payload_(std::move(msg))
{}

ZlogMsg::ZlogMsg(std::source_location loc, std::string_view logger_name, LogLevel lvl, std::string msg)
    : ZlogMsg(GetTimeNow(), loc, logger_name, lvl, std::move(msg))
{}

ZlogMsg::ZlogMsg(std::string_view logger_name, LogLevel lvl, std::string msg)
    : ZlogMsg(GetTimeNow(), std::source_location::current(), logger_name, lvl, std::move(msg))
{}

} // namespace myweb::zlog