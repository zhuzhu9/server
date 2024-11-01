/*
 * Project: server
 * Moudle:  * File: zlog_enhance.h
 * Created Date: 2024-09-10 10:30:13
 * Author: zhuzhu
 * Description: description
 * -----
 * todo: modified
 * -----
 * Copyright (c) 2024  Inc
 */
#ifndef ZLOG_ENHANCE_H
#define ZLOG_ENHANCE_H

#include "zlog_default.h"
#include <format>

template <typename CharT>
struct std::formatter<myweb::zlog::LogLevel, CharT> : std::formatter<char, CharT> {
    template <typename FormatContext>
    auto format(myweb::zlog::LogLevel t, FormatContext &fc) const
    {
        switch (t) {
        case myweb::zlog::LogLevel::trace:
            return std::formatter<char, CharT>::format('T', fc);
        case myweb::zlog::LogLevel::debug:
            return std::formatter<char, CharT>::format('D', fc);
        case myweb::zlog::LogLevel::info:
            return std::formatter<char, CharT>::format('I', fc);
        case myweb::zlog::LogLevel::warin:
            return std::formatter<char, CharT>::format('W', fc);
        case myweb::zlog::LogLevel::error:
            return std::formatter<char, CharT>::format('E', fc);
        case myweb::zlog::LogLevel::fatal:
            return std::formatter<char, CharT>::format('F', fc);
        default:
            return std::formatter<char, CharT>::format(' ', fc);
        }
        return std::formatter<char, CharT>::format(' ', fc);
    }
};

#endif // ZLOG_ENHANCE_H