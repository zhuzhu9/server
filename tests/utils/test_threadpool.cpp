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

void func(int a)
{
    std::cout << a << "\n";
}

int main()
{
    myweb::utils::ThreadPool t;
    t.commit(func, 10);

    while (true)
        ;

    return 0;
}
