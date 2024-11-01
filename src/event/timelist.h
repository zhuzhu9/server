/*
 * Project: server
 * Moudle:
 * File: timelist.h
 * Created Date: 2024-05-10 17:27:06
 * Author: zhuzhu
 * Description: description
 * -----
 * todo: modified
 * -----
 * Copyright (c) 2024  Inc
 */
#ifndef TIMELIST_H
#define TIMELIST_H

#include "singleton.h"
#include "threadpool.h"
#include "timer.h"
#include <functional>
#include <map>
#include <semaphore>

namespace myweb::event::timer {
using namespace std::chrono_literals;

class TimerList final : public utils::Singleton<TimerList> {
  private:
    struct Node {
        std::function<void()> fn_{};
        long ms_;
        int repeat_;
    };

  public:
    template <typename Fn, typename... Args>
    void commit(int ms, int repeat, Fn &&fn, Args &&...args);
    void start();

    TimerList() : threadPool_("timelist"){};

  private:
    void tick(); // 10ms tick

    std::multimap<long, Node> map_;
    utils::ThreadPool threadPool_;

    std::chrono::milliseconds time_ = 10ms;
};

template <typename Fn, typename... Args>
void TimerList::commit(int ms, int repeat, Fn &&fn, Args &&...args)
{
    using RetType = decltype(std::forward<Fn>(fn)(std::forward<Args>(args)...));
    auto callback = std::bind<RetType>(std::forward<Fn>(fn), std::forward<Args>(args)...);
    map_.insert({ms + myweb::utils::time::GetMonotonicTime<std::chrono::milliseconds, long>(), {callback, ms, repeat}});
}

} // namespace myweb::event::timer

#endif // TIMELIST_H