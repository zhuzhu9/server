/*
 * Project: server
 * Moudle: test_log
 * File: test_log.cpp
 * Created Date: 2024-10-14 14:00:36
 * Author: zhuzhu
 * Description: description
 * -----
 * todo: modified
 * -----
 * Copyright (c) 2024  Inc
 */

#include "log.h"
#include "spdlog/common.h"

int main()
{
    using namespace std::chrono_literals;
    LogInit("aaa");
    myweb::zlog::LOGDEFAULT->set_level(spdlog::level::debug);
    LOGT("log trace");
    LOGD("log debug");
    LOGI("log info");
    LOGW("log warning");
    LOGE("log error");

    std::string info("log info");
    std::string info4("log 4");
    std::string info5("log 5");

    std::vector<int> vec{1, 2, 3};

    // LOGI("LOG Vector: {}", vec); // TODO

    LOGI("INFO: {2}, {1}, {0}", info, info4, info5);

    int i = 250;
    LOGD("hex: {:x}, {:X}, {:8X}, {:08X}", i, i, i, i);
    double d = 1.123456789f;
    LOGD("hex: {:f}, {:.3f}, {:10.3f}", d, d, d);

    // 打印指针
    int a = 10;
    void *pa = &a;
    LOGI("a: {}", a);
    LOGI("*pa: {}", *(int *)pa);
    LOGI("pa: {}", pa);
    LOGI("(void *)(&a): {}", (void *)(&a));
    LOGI("static_cast<void *>(&a): {}", static_cast<void *>(&a));

    LOGP("&a: {}", &a);

    std::logic_error le("logic error");
    // LOGE("le: {}", le); // TODO

    // myweb::zlog::LogLevel log_level{myweb::zlog::LogLevel::debug};
    // LOGD("log level: {}", log_level);

    return 0;
}
