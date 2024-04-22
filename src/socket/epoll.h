/*
 * Project: server
 * Moudle: SOCKET
 * File: epoll.h
 * Created Date: 2024-04-22 11:30:18
 * Author: zhuzhu
 * Description: description
 * -----
 * todo: modified
 * -----
 * Copyright (c) 2024  Inc
 */
#ifndef SOCKET_EPOLL_H
#define SOCKET_EPOLL_H

#include <arpa/inet.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <unistd.h>

namespace myweb::socket::epoll {

constexpr int MAX_EVENT_NUMBER = 10000;

class Epoll {
  public:
  private:
    int listenFd = 0;
    epoll_event events[MAX_EVENT_NUMBER]{};
};

} // namespace myweb::socket::epoll
#endif // SOCKET_EPOLL_H
