file(GLOB_RECURSE common_src
        config.cpp
)

include_directories(${SRC_DIR}/socket/ ${SRC_DIR}/common/ ${SRC_DIR}/log/)

add_library(common SHARED ${common_src})
target_link_libraries(common log yaml-cpp)