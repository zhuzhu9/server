/*
 * Project: server
 * Moudle:
 * File: timerwheel.h
 * Created Date: 2024-05-15 09:01:21
 * Author: zhuzhu
 * Description: description
 * -----
 * todo: modified
 * -----
 * Copyright (c) 2024  Inc
 */
#ifndef TIMERWHEEL_H
#define TIMERWHEEL_H

#include "threadpool.h"
#include <cstddef>
#include <list>
#include <mutex>
#include <thread>
namespace myweb::event::timer {

class TimerWheel {
  private:
    struct Node {
        std::function<void()> fn_{};
        long ms_;
        int repeat_;
    };

  public:
    template <typename Fn, typename... Args>
    void add_timer(int ms, int repeat, Fn &&fn, Args &&...args);
    
  private:
    void start();
    void tick();
    constexpr static std::size_t COUNT = 60; // 60个
    constexpr static int SI = 1;             // 1s

    std::size_t cur_ = 0;
    std::array<std::list<Node>, COUNT> taskLinks_;
    utils::ThreadPool threadPool_;
    std::thread thread_;
    std::mutex mtx_;
};

} // namespace myweb::event::timer

#endif // TIMERWHEEL_H