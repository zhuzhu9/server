/*
 * Project: server
 * Moudle: utils
 * File: singleton.h
 * Created Date: 2024-04-22 11:30:59
 * Author: zhuzhu
 * Description: description
 * -----
 * todo: modified
 * -----
 * Copyright (c) 2024  Inc
 */
#ifndef UTILS_SINGLETON_H
#define UTILS_SINGLETON_H

namespace myweb::utils {
template <typename T>
class Singleton {
  public:
    static T &instance()
    {
        static T instance_;
        return instance_;
    }

    Singleton(const Singleton &) = delete;
    Singleton(Singleton &&) = delete;
    Singleton &operator=(const Singleton &) = delete;
    Singleton &operator=(Singleton &&) = delete;

  protected:
    Singleton() = default;
    virtual ~Singleton() = default;
};
} // namespace myweb::utils

#endif // UTILS_SINGLETON_H