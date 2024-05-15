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
#include <thread>

namespace myweb::event::timer {

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
    ~TimerList()
    {
        if (th_.joinable())
            th_.join();
    }

  private:
    void tick(); // 10ms tick

    // FIXME: thread save
    std::multimap<long, Node> map_;
    std::thread th_;
    utils::ThreadPool threadPool_;
};

template <typename Fn, typename... Args>
void TimerList::commit(int ms, int repeat, Fn &&fn, Args &&...args)
{
    using RetType = decltype(std::forward<Fn>(fn)(std::forward<Args>(args)...));
    auto callback = std::bind<RetType>(std::forward<Fn>(fn), std::forward<Args>(args)...);
    map_.emplace(std::make_pair<long, Node>(ms + myweb::utils::time::GetMonotonicTime<std::chrono::milliseconds, int>(),
                                            {callback, ms, repeat}));
}

} // namespace myweb::event::timer

#endif // TIMELIST_H