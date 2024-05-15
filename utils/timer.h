/*
 * Project: server
 * Moudle: utils
 * File: timer.h
 * Created Date: 2024-05-11 08:54:01
 * Author: zhuzhu
 * Description: description
 * -----
 * todo: modified
 * -----
 * Copyright (c) 2024  Inc
 */
#ifndef UTILS_TIMER_H
#define UTILS_TIMER_H

#include <chrono>
namespace myweb::utils::time {

template <typename D = std::chrono::seconds, typename T = double>
inline T GetMonotonicTime()
{
    return (std::chrono::duration_cast<std::chrono::duration<T, typename D::period>>(
                std::chrono::steady_clock::now().time_since_epoch()))
        .count();
}

template <typename D = std::chrono::seconds, typename T = double>
inline T GetTimestamp()
{
    return (std::chrono::duration_cast<std::chrono::duration<T, typename D::period>>(
                std::chrono::system_clock::now().time_since_epoch()))
        .count();
}

} // namespace myweb::utils::time

#endif // UTILS_TIMER_H