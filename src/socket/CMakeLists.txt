file(GLOB_RECURSE socket_src
        epoll.cpp
)

add_library(socket SHARED ${socket_src})