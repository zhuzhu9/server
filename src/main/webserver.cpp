/*
 * Project: server
 * Moudle: main
 * File: webserver.cpp
 * Created Date: 2024-04-22 11:36:33
 * Author: zhuzhu
 * Description: description
 * -----
 * todo: modified
 * -----
 * Copyright (c) 2024  Inc
 */

#include "webserver.h"
#include "config.h"
#include "log.h"

constexpr const char *DEFAULT_CONFIG_PATH = "1";

namespace myweb::webserver {

bool Webserver::init()
{
    logInit();

    auto &config = common::Config::instance();
    config.load(DEFAULT_CONFIG_PATH);

    port_ = config.port_;

    sqlInit();
    redisInit();

    listenInit();

    return false;
}

bool Webserver::logInit()
{
    LogInit("aaa");
    LOGD("log init succeed");
    return true;
}

bool Webserver::threadPoolInit()
{
    return true;
}

bool Webserver::sqlInit()
{
    return true;
}

bool Webserver::redisInit()
{
    return true;
}

bool Webserver::listenInit()
{
    return ep_.listenInit(port_);
}

void Webserver::start() {}

void Webserver::run()
{
    ep_.coreFun();
}

} // namespace myweb::webserver
