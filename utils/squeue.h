/*
 * Project: server
 * Moudle: utils
 * File: squeue.h
 * Created Date: 2024-04-25 10:29:00
 * Author: zhuzhu
 * Description: description
 * -----
 * todo: modified
 * -----
 * Copyright (c) 2024  Inc
 */
#ifndef SQUEUE_H
#define SQUEUE_H

#include <condition_variable>
#include <memory>
#include <mutex>
#include <queue>

namespace myweb::utils {

template <typename T>
class SQueue {
  public:
    void push(const T &value)
    {
        std::lock_guard<std::mutex> lg(lock_);
        qu_.push(value);
        cv_.notify_one();
    };

    void emplace(T &&value)
    {
        std::lock_guard<std::mutex> lg(lock_);
        qu_.emplace(value);
        cv_.notify_one();
    }

    [[__nodiscard__]] bool empty() const
    {
        std::lock_guard<std::mutex> lg(lock_);
        return qu_.empty();
    }

    std::shared_ptr<T> wait_pop()
    {
        std::unique_lock<std::mutex> ul(lock_);
        cv_.wait(ul, [this] { return !qu_.empty(); });
        auto res = std::make_shared<T>(qu_.front());
        qu_.pop();
        return res;
    }

    void wait_pop(T &dst)
    {
        std::unique_lock<std::mutex> ul(lock_);
        cv_.wait(ul, [this] { return !qu_.empty(); });
        dst = qu_.front();
        qu_.pop();
    }

    SQueue() = default;
    SQueue(const SQueue &other)
    {
        std::lock_guard<std::mutex> lg(other.lock_);
        qu_ = other.qu_;
    }

    SQueue(SQueue &&other) noexcept
    {
        std::lock_guard<std::mutex> lg(other.lock_);
        qu_ = std::move(other.qu_);
    }

    SQueue &operator=(const SQueue &other)
    {
        std::lock_guard<std::mutex> lg(other.lock_);
        qu_ = other.qu_;
    }

    SQueue &operator=(SQueue &&other) noexcept
    {
        std::lock_guard<std::mutex> lg(other.lock_);
        qu_ = std::move(other.qu_);
    }

    ~SQueue() = default;

  private:
    std::queue<T> qu_{};
    mutable std::mutex lock_{};
    std::condition_variable cv_{};
};

} // namespace wyweb::utils

#endif // SQUEUE_H