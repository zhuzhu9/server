/*
 * Project: server
 * Moudle: epoll
 * File: epoll.cxx
 * Created Date: 2024-04-22 11:32:16
 * Author: zhuzhu
 * Description: description
 * -----
 * todo: modified
 * -----
 * Copyright (c) 2024  Inc
 */

#include "epoll.h"
#include "log.h"
#include <asm-generic/socket.h>
#include <netinet/in.h>
#include <stdexcept>
#include <sys/epoll.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <unistd.h>

namespace myweb::socket::epoll {

bool Epoll::listenInit(int port)
{
    listenFd_ = ::socket(AF_INET, SOCK_STREAM, 0);

    bool opt = true;
    setsockopt(listenFd_, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(port);

    int ret = 0;
    ret = bind(listenFd_, (sockaddr *)&addr, sizeof(addr));
    if (ret < 0)
        throw std::runtime_error("listen socket bind failed");

    ret = listen(listenFd_, 128);
    if (ret < 0)
        throw std::runtime_error("listen socket listen failed");

    epollFd_ = epoll_create(1024);
    epoll_event ev{EPOLLIN, {.fd = listenFd_}};
    epoll_ctl(epollFd_, EPOLL_CTL_ADD, listenFd_, &ev);

    LOGD("listen success");

    return true;
}

void Epoll::coreFun()
{
    while (true) {
        int ret = epoll_wait(epollFd_, events, MAX_EVENT_NUMBER, -1);
        for (int i = 0; i < ret; ++i) {
            if (events[i].data.fd == listenFd_) {
                int fd = 0;
                sockaddr caddr{};
                socklen_t len = sizeof(caddr);
                fd = accept(events[i].data.fd, &caddr, &len);

                epoll_event temp{EPOLLIN | EPOLLHUP, {.fd = fd}};
                epoll_ctl(epollFd_, EPOLL_CTL_ADD, fd, &temp);
                LOGD("connect success");
            } else if (events[i].events & (EPOLLRDHUP | EPOLLHUP | EPOLLERR)) {
                close(events[i].data.fd);
                epoll_ctl(epollFd_, EPOLL_CTL_DEL, events[i].data.fd, nullptr);
                LOGD("close connect success");
            } else {
            }
        }
    }
}

} // namespace myweb::socket::epoll