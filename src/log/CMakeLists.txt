file(GLOB_RECURSE log_src
        log.cpp
)

add_library(log SHARED ${log_src})