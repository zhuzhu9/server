file(GLOB_RECURSE log_src
        zlogger.cpp
)

# find_package(spdlog REQUIRED)
# include_directories(${PROJECT_SOURCE_DIR}/third_party/spdlog/include)

add_library(log SHARED ${log_src})
# target_link_libraries(log spdlog::spdlog)