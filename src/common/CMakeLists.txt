file(GLOB_RECURSE common_src
        config.cpp
)

include_directories(../socket/ ../common/ ../log/)

add_library(common SHARED ${common_src})
target_link_libraries(common log)