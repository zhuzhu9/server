file(GLOB_RECURSE common_src
        config.cpp
)

add_library(common SHARED ${common_src})