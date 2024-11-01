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
#include "timer.h"
#include <chrono>
#include <thread>

namespace myweb::event::timer {

using myweb::utils::time::GetMonotonicTime;

void TimerList::tick()
{
    std::chrono::milliseconds sleep_time = time_;
    while (true) {
        long now_time = GetMonotonicTime<std::chrono::milliseconds, long>();
        for (auto it = map_.begin(); it != map_.end();) {
            auto &[time, node] = *it;
            if (now_time > time) {
                threadPool_.submit(node.fn_);
                if (node.repeat_ > 0)
                    --node.repeat_;

                if (node.repeat_ == 0) {
                    it = map_.erase(it);
                } else {
                    auto nh = map_.extract(time);
                    nh.key() += node.ms_;
                    map_.insert(std::move(nh));
                }
            } else {
                sleep_time = std::chrono::milliseconds{map_.begin()->first - now_time};
                break;
            }
        }
        std::this_thread::sleep_for(sleep_time);
    }
}

void TimerList::start()
{
    threadPool_.submit(&TimerList::tick, this);
}

} // namespace myweb::event::timer