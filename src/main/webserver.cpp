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
#include <chrono>
#include <cstring>
#include <netinet/in.h>
#include <stdexcept>
#include <sys/epoll.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <thread>

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

    return false;
}

bool Webserver::logInit()
{
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
    listen_fd_ = ::socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in addr{};
    std::memset(&addr, 0, sizeof(sockaddr_in));
    addr.sin_family = AF_INET;

    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(port_);

    int ret = 0;
    ret = bind(listen_fd_, (sockaddr *)&addr, sizeof(addr));
    if (ret < 0)
        throw std::runtime_error("listen socket bind failed");

    ret = listen(listen_fd_, 5);
    if (ret < 0)
        throw std::runtime_error("listen socket listen failed");

    // epollfd_ = epoll_create(1);
    // epoll_event events[MAX_EVENT_NUMBER];

    // epollfd_ = select(listen_fd_+1, fd_set *__restrict readfds, fd_set *__restrict writefds, fd_set *__restrict
    // exceptfds, struct timeval *__restrict timeout)

    return true;
}

void Webserver::start() {}

void Webserver::run()
{

    while (true) {

        using namespace std::chrono_literals;
        std::this_thread::sleep_for(10ms);
    }
}

} // namespace myweb::webserver
