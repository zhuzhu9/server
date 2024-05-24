/*
 * Project: server
 * Moudle: test timerlist
 * File: test_timerlist.cpp
 * Created Date: 2024-05-11 11:06:36
 * Author: zhuzhu
 * Description: description
 * -----
 * todo: modified
 * -----
 * Copyright (c) 2024  Inc
 */

#include "threadpool.h"
#include <iostream>
#include "log.h"

void func(int a)
{
    std::cout << a << "\n";
}

class A {
  public:
    void operator()() { std::cout << 10 << std::endl; }
};

int main()
{
    myweb::utils::ThreadPool t;
    t.commit(func, 10);
    t.commit([] { std::cout << 50 << "\n"; });

    A a;
    t.commit(a);
    // while (true) {
    // }

    return 0;
}
