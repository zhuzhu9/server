file(GLOB_RECURSE log_src
        zlogger.cpp
        zlog_msg.cpp
)

include_directories(${PROJECT_SOURCE_DIR}/third_party/fast_io/include)
if(CONFIG_LOG_USE_SPDLOG)
    include_directories(${PROJECT_SOURCE_DIR}/third_party/spdlog/include)
endif()

add_library(log SHARED ${log_src})
if(CONFIG_LOG_USE_SPDLOG)
    target_link_libraries(log spdlog)
endif()
