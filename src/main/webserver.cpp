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

bool WebServer::init()
{

    auto &config = common::Config::instance();
    config.load(DEFAULT_CONFIG_PATH);

    port_ = config.port_;

    sqlInit();
    redisInit();

    listenInit();

    return false;
}

bool WebServer::threadPoolInit()
{
    return true;
}

bool WebServer::sqlInit()
{
    return true;
}

bool WebServer::redisInit()
{
    return true;
}

bool WebServer::listenInit()
{
    return ep_.listenInit(port_);
}

void WebServer::start() {}

void WebServer::run()
{
    ep_.coreFun();
}

} // namespace myweb::webserver
