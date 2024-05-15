file(GLOB_RECURSE socket_src
        epoll.cpp
)

include_directories(../common/ ../log/)

add_library(socket SHARED ${socket_src})
target_link_libraries(socket common log)