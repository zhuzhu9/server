file(GLOB_RECURSE socket_src
        epoll.cpp
)

include_directories(${SRC_DIR}/common/ ${SRC_DIR}/log/)

add_library(socket SHARED ${socket_src})
target_link_libraries(socket common log)