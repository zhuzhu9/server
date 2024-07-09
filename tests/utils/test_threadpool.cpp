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

#include "log.h"
#include "threadpool.h"
#include <iostream>
#include <thread>

using namespace std::chrono_literals;

void func(int a)
{
    std::this_thread::sleep_for(3s);
    std::cout << a << "\n";
}

class A {
  public:
    void operator()() { std::cout << 10 << std::endl; }
    void test() { poll.submit(&A::operator(), this); }

    myweb::utils::ThreadPool poll;
};

class B {
  public:
    void operator()() { std::cout << 30 << std::endl; }
};

int main()
{
    myweb::utils::ThreadPool t;
    t.submit(func, 10);

    t.submit([] { std::cout << 50 << "\n"; });

    A a;
    a.test();

    B b;
    t.submit(b);
    return 0;
}
