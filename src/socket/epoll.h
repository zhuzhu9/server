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

class Epoll {
  public:
    constexpr static int MAX_EVENT_NUMBER = 10000;
    bool listenInit(int port);
    void coreFun();
    Epoll() = default;
    Epoll(const Epoll &) = default;
    Epoll(Epoll &&) noexcept = default;
    Epoll &operator=(const Epoll &) = default;
    Epoll &operator=(Epoll &&) noexcept = default;

    ~Epoll()
    {
        if (listen_fd_ != 0)
            close(listen_fd_);

        if (epoll_fd_ != 0)
            close(epoll_fd_);
    }

  private:
    void addFd(int fd) const;
    void addFd(int fd, bool flag) const; // Epoll one shot
    void deleteFd(int fd) const;

    int listen_fd_ = 0;
    int epoll_fd_ = 0;
    epoll_event events_[MAX_EVENT_NUMBER]{};
};

} // namespace myweb::socket::epoll
#endif // SOCKET_EPOLL_H
