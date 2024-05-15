/*
 * Project: server
 * Moudle: main
 * File: webserver.h
 * Created Date: 2024-04-22 11:36:17
 * Author: zhuzhu
 * Description: description
 * -----
 * todo: modified
 * -----
 * Copyright (c) 2024  Inc
 */
#ifndef MAIN_WEBSERVER_H
#define MAIN_WEBSERVER_H

#include "epoll.h"
#include "singleton.h"

namespace myweb::webserver {

using namespace myweb::socket::epoll;

class Webserver : public utils::Singleton<Webserver> {
  public:
    bool init();
    void start();
    void run();

  private:
    bool logInit();
    bool threadPoolInit();
    bool sqlInit();
    bool redisInit();
    bool listenInit();

    int port_ = 0;
    int listenFd_ = 0;
    int epollFd_ = 0;
    Epoll ep_;
};

} // namespace myweb::webserver

#endif // MAIN_WEBSERVER_H