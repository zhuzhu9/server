/*
 * Project: server
 * Moudle:  * File: zlog_msg.hpp
 * Created Date: 2024-09-10 10:30:38
 * Author: zhuzhu
 * Description: description
 * -----
 * todo: modified
 * -----
 * Copyright (c) 2024  Inc
 */
#ifndef ZLOG_MSG_H
#define ZLOG_MSG_H

#include "zlog_default.h"
#include <chrono>
#include <cstddef>
#include <source_location>
#include <string_view>

namespace myweb::zlog {

struct ZlogMsg {
    ZlogMsg() = default;
    ZlogMsg(std::chrono::time_point<std::chrono::system_clock> log_time,
            std::source_location loc,
            std::string_view logger_name,
            LogLevel lvl,
            std::string_view msg);
    ZlogMsg(std::source_location loc, std::string_view logger_name, LogLevel lvl, std::string_view msg);
    ZlogMsg(std::string_view logger_name, LogLevel lvl, std::string_view msg);
    ZlogMsg(const ZlogMsg &other) = default;
    ZlogMsg &operator=(const ZlogMsg &other) = default;
    ZlogMsg(ZlogMsg &&other) noexcept = default;
    ZlogMsg &operator=(ZlogMsg &&other) noexcept = default;
    ~ZlogMsg() = default;

    std::string_view name_;
    LogLevel level_{LogLevel::none};
    std::chrono::time_point<std::chrono::system_clock> time_;
    std::size_t thread_id__{0};

    std::source_location loc_;
    std::string_view payload_;
};

} // namespace myweb::zlog

#endif // ZLOG_MSG_H
