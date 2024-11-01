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
#include "timelist.h"
#include <thread>

void func(int a)
{
    LOGI("{}", a);
}

int main()
{
    using namespace std::chrono_literals;
    LogInit("aaa");
    using namespace myweb::event::timer;
    TimerList &timer = TimerList::instance();
    timer.commit(1000, -1, func, 501);
    timer.start();

    timer.commit(100, -1, func, 2);
    // timer.commit(
    //     2000,
    //     5,
    //     [](int m) { std::cout << m << "\n"; },
    //     10);

    while (true) {
        std::this_thread::sleep_for(10s);
    };

    return 0;
}
