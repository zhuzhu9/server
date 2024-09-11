file(GLOB_RECURSE log_src
        zlogger.cpp
        zlog_msg.cpp
)
# set(CMAKE_CXX_VISIBILITY_PRESET hidden)

# find_package(spdlog REQUIRED)
# include_directories(${PROJECT_SOURCE_DIR}/third_party/spdlog/include)
include_directories(${PROJECT_SOURCE_DIR}/third_party/fast_io/include)

add_library(log SHARED ${log_src})
# target_link_libraries(log spdlog::spdlog)