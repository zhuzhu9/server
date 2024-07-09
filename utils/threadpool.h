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
#include <tuple>
#include <utility>
#include <vector>
namespace myweb::utils {
class ThreadPool {
  public:
    // TODO: 按照thread封闭，现在不能接收类对象
    template <typename Fn, typename... Args>
    [[deprecated("please use submit")]] void commit(Fn &&fn, Args &&...args);

    template <typename Fn, typename... Args>
    void submit(Fn &&fn, Args &&...args);

    template <typename Tuple, size_t... Indices>
    static unsigned int Invoke(void *arg)
    {
        std::unique_ptr<Tuple> FnArg(static_cast<Tuple *>(arg));
        Tuple &Tup = *FnArg.get();
        std::invoke(std::move(std::get<Indices>(Tup))...);

        return 0;
    }

    template <typename Tuple, size_t... Indices>
    static constexpr auto star(std::index_sequence<Indices...>)
    {
        return Invoke<Tuple, Indices...>;
    }

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
                std::function<void()> fun{};
                {
                    std::unique_lock<std::mutex> ul(mtx_);
                    cv_.wait(ul, [this] { return !tasks_.empty() || stop_.load(); });
                    if (tasks_.empty())
                        return;

                    fun = std::move(tasks_.front());
                    tasks_.pop();
                }
                fun();
            }
        });
    }
}

inline void ThreadPool::stop()
{
    stop_.store(true);
    cv_.notify_all();
    for (auto &i : threads_) {
        if (i.joinable())
            i.join();
    }
}

template <typename Fn, typename... Args>
void ThreadPool::commit(Fn &&fn, Args &&...args)
{
    using RetType = decltype((std::forward<Fn>(fn))(std::forward<Args>(args)...));
    auto fun = std::make_shared<std::function<RetType()>>(
        std::bind<RetType>(std::forward<Fn>(fn), std::forward<Args>(args)...));
    {
        std::lock_guard<std::mutex> a(mtx_);
        tasks_.emplace([fun] { (*fun)(); });
    }
    cv_.notify_one();
}

template <typename Fn, typename... Args>
void ThreadPool::submit(Fn &&fn, Args &&...args)
{
    using Tuple = std::tuple<std::decay_t<Fn>, std::decay_t<Args>...>;
    auto DoCopy = std::make_unique<Tuple>(std::forward<Fn>(fn), std::forward<Args>(args)...);
    auto Func = star<Tuple>(std::make_index_sequence<1 + sizeof...(Args)>{});
    void *arg = DoCopy.release();
    {
        std::lock_guard<std::mutex> a(mtx_);
        tasks_.emplace([Func, arg] { Func(arg); });
    }
    cv_.notify_one();
}

} // namespace myweb::utils

#endif // UTILS_THREADPOOL_H