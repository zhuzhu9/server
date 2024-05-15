/*
 * Project: server
 * Moudle: time list
 * File: timelist.cpp
 * Created Date: 2024-05-10 19:35:46
 * Author: zhuzhu
 * Description: description
 * -----
 * todo: modified
 * -----
 * Copyright (c) 2024  Inc
 */

#include "timelist.h"
#include "log.h"
#include "timer.h"
#include <chrono>
#include <functional>
#include <iostream>
#include <thread>

namespace myweb::event::timer {

using myweb::utils::time::GetMonotonicTime;

void TimerList::tick()
{
    while (true) {
        int now_time = GetMonotonicTime<std::chrono::milliseconds, int>();
        auto &[time, node] = *map_.begin();
        // FIXME: 多个fn，没有处理
        if (now_time > time) {
            node.fn_();
            if (node.repeat_ > 0)
                --node.repeat_;

            auto nh = map_.extract(time);
            nh.key() = now_time + node.ms_;
            map_.insert(std::move(nh));
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

void TimerList::start()
{
    th_ = std::thread(&TimerList::tick, this);
    th_.detach();
}

} // namespace myweb::event::timer