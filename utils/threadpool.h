/*
 * Project: server
 * Moudle: utils
 * File: threadpool.h
 * Created Date: 2024-05-11 14:28:22
 * Author: zhuzhu
 * Description: description
 * -----
 * todo: modified
 * -----
 * Copyright (c) 2024  Inc
 */
#ifndef UTILS_THREADPOOL_H
#define UTILS_THREADPOOL_H

#include <atomic>
#include <condition_variable>
#include <functional>
#include <memory>
#include <mutex>
#include <queue>
#include <thread>
#include <utility>
#include <vector>
namespace myweb::utils {
class ThreadPool {
  public:
    template <typename Fn, typename... Args>
    void commit(Fn &&fn, Args &&...args);

    explicit ThreadPool(int num = 5) : thread_num_(num) { init(); }
    ~ThreadPool() { stop(); };

  private:
    void init();
    void stop();

    std::queue<std::function<void()>> tasks_;
    std::atomic<bool> stop_{false};
    std::atomic<int> active_num_{0};
    std::vector<std::thread> threads_;
    mutable std::mutex mtx_;
    std::condition_variable cv_;

    int thread_num_ = 0;
};

inline void ThreadPool::init()
{
    for (int i = 0; i < thread_num_; i++) {
        threads_.emplace_back([this] {
            while (!stop_) {
                std::unique_lock<std::mutex> ul(mtx_);
                cv_.wait(ul, [this] { return !tasks_.empty() || stop_.load(); });
                if (tasks_.empty())
                    return;

                auto fun = std::move(tasks_.front());
                fun();
                tasks_.pop();
            }
        });
    }
}

inline void ThreadPool::stop()
{
    stop_.store(true);
    for (auto &i : threads_) {
        if (i.joinable())
            i.join();
    }
}

template <typename Fn, typename... Args>
void ThreadPool::commit(Fn &&fn, Args &&...args)
{
    using RetType = decltype(std::forward<Fn>(fn)(std::forward<Args>(args)...));
    auto fun = std::make_shared<std::function<RetType()>>(
        std::bind<RetType>(std::forward<Fn>(fn), std::forward<Args>(args)...));
    {
        std::lock_guard<std::mutex> a(mtx_);
        tasks_.emplace([fun] { (*fun)(); });
    }
    cv_.notify_one();
}

} // namespace myweb::utils

#endif // UTILS_THREADPOOL_H