file(GLOB_RECURSE event_src
        timelist.cpp
)

include_directories(../common/ ../log/)

add_library(event SHARED ${event_src})
target_link_libraries(event common log -lpthread)