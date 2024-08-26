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
#include <memory>
#include <netinet/in.h>
#include <stdexcept>
#include <sys/epoll.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <unistd.h>

namespace myweb::socket::epoll {

bool Epoll::listenInit(int port)
{
    listen_fd_ = std::make_shared<Socket>(::socket(AF_INET, SOCK_STREAM, 0));

    int opt = 1;
    setsockopt(listen_fd_->fd(), SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(port);

    int ret = 0;
    ret = bind(listen_fd_->fd(), (sockaddr *)&addr, sizeof(addr));
    if (ret < 0)
        throw std::runtime_error("listen socket bind failed");

    ret = listen(listen_fd_->fd(), 128);
    if (ret < 0)
        throw std::runtime_error("listen socket listen failed");

    epoll_fd_ = std::make_shared<Socket>(epoll_create(1024));
    epoll_event ev{EPOLLIN, {.fd = listen_fd_->fd()}};
    epoll_ctl(epoll_fd_->fd(), EPOLL_CTL_ADD, listen_fd_->fd(), &ev);

    LOGD("listen success");

    return true;
}

void Epoll::coreFun()
{
    // TODO: 只处理了监听的fd，连接的fd都没有处理
    while (true) {
        int ret = epoll_wait(epoll_fd_->fd(), events_, MAX_EVENT_NUMBER, -1);
        for (int i = 0; i < ret; ++i) {
            if (events_[i].data.fd == listen_fd_->fd()) {
                int fd = 0;
                sockaddr caddr{};
                socklen_t len = sizeof(caddr);
                fd = accept(events_[i].data.fd, &caddr, &len);

                addFd(fd);
                LOGD("connect success");
            } else if (events_[i].events & (EPOLLRDHUP | EPOLLHUP | EPOLLERR)) {
                deleteFd(events_[i].data.fd);
                LOGD("close connect success");
            } else {
            }
        }
    }
}

void Epoll::addFd(int fd) const
{
    epoll_event temp{EPOLLIN | EPOLLHUP, {.fd = fd}};
    epoll_ctl(epoll_fd_->fd(), EPOLL_CTL_ADD, fd, &temp);
}

void Epoll::addFd(int fd, bool flag) const
{
    epoll_event temp{EPOLLIN | EPOLLHUP | EPOLLET | EPOLLONESHOT, {.fd = fd}};
    epoll_ctl(epoll_fd_->fd(), EPOLL_CTL_ADD, fd, &temp);
}

void Epoll::deleteFd(int fd) const
{
    close(fd);
    epoll_ctl(epoll_fd_->fd(), EPOLL_CTL_DEL, fd, nullptr);
}

} // namespace myweb::socket::epoll