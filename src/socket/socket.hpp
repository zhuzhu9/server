/*
 * Project: server
 * Moudle: SOCKET
 * File: socket.hpp
 * Created Date: 2024-08-07 11:18:36
 * Author: zhuzhu
 * Description: description
 * -----
 * todo: modified
 * -----
 * Copyright (c) 2024  Inc
 */
#ifndef SOCKET_SOCKET_H
#define SOCKET_SOCKET_H

#include "log.h"
#include "string_view"

namespace myweb::socket::socket {
using namespace std::string_view_literals;

class Socket {
  public:
    Socket() = default;
    Socket(const Socket &) = default;
    Socket(Socket &&) noexcept = default;
    Socket &operator=(const Socket &) = default;
    Socket &operator=(Socket &&) noexcept = default;
    ~Socket()
    {
        if (fd_ != 0) {
            close(fd_);
            fd_ = 0;
        }
    }

    explicit Socket(int fd, std::string_view sv = ""sv) : name_(sv), fd_(fd){};

    [[nodiscard]] int recv() const
    {
        if (fd_ == 0) {
            LOGE("Socket is not connect");
            return -1;
        }
        return 0;
    }

    [[nodiscard]] int send(char *msg) const
    {
        if (fd_ == 0) {
            LOGE("Socket is not connect");
            return -1;
        }
        return 0;
    }

    [[nodiscard]] int fd() const { return fd_; }

  private:
    std::string_view name_;
    int fd_{0};
};
} // namespace myweb::socket::socket

#endif // SOCKET_SOCKET_H