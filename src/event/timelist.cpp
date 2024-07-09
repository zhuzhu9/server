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
#include <functional>
#include <thread>

namespace myweb::event::timer {

using myweb::utils::time::GetMonotonicTime;

void TimerList::tick()
{
    using namespace std::chrono_literals;

    while (true) {
        int now_time = GetMonotonicTime<std::chrono::milliseconds, int>();
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
                    nh.key() = now_time + node.ms_;
                    map_.insert(std::move(nh));
                }
            } else {
                break;
            }
        }
        // TODO: 用条件变量来休眠，不用sleep
        std::this_thread::sleep_for(10ms);
    }
}

void TimerList::start()
{
    threadPool_.submit(&TimerList::tick, this);
}

} // namespace myweb::event::timer