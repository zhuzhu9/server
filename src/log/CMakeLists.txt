file(GLOB_RECURSE log_src
        logger.cpp
)

add_library(log SHARED ${log_src})