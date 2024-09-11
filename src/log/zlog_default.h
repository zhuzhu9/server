/*
 * Project: server
 * Moudle:  * File: zlog_default.h
 * Created Date: 2024-09-10 10:30:56
 * Author: zhuzhu
 * Description: description
 * -----
 * todo: modified
 * -----
 * Copyright (c) 2024  Inc
 */
#ifndef ZLOG_DEFAULT_H
#define ZLOG_DEFAULT_H

#define ZLOG_FOREACH_LOG_LEVEL(f) f(trace) f(debug) f(info) f(warining) f(error) f(fatal)
namespace myweb::zlog {

enum class LogLevel : unsigned int {
#define ZLOG_FUNCTION(x) x,
    ZLOG_FOREACH_LOG_LEVEL(ZLOG_FUNCTION)
#undef ZLOG_FUNCTION
        none
};
} // namespace myweb::zlog
#undef ZLOG_FOREACH_LOG_LEVEL

#endif // ZLOG_DEFAULT_H
