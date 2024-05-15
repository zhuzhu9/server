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

#include "timelist.h"
#include <iostream>

void func(int a)
{
    std::cout << a << "\n";
}

int main()
{
    using namespace myweb::event::timer;
    TimerList &timer = TimerList::instance();

    timer.commit(1000, -1, func, 1);
    timer.commit(2000, -1, func, 2);
    timer.commit(
        2000,
        5,
        [](int m) { std::cout << m << "\n"; },
        10);
    timer.start();

    while (true)
        ;

    return 0;
}
