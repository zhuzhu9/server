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

void func(int a)
{
    std::cout << a << "\n";
}

class A {
  public:
    void operator()() { std::cout << 10 << std::endl; }
    // void test() { poll.commit(&A::operator(), this); }

    myweb::utils::ThreadPool poll;
};

int main()
{
    myweb::utils::ThreadPool t;
    t.commit(func, 10);
    t.commit([] { std::cout << 50 << "\n"; });

    // A a;
    // t.commit(a);

    // A b;
    // b.test();

    return 0;
}
