link_libraries(-lpthread)

include_directories(../../utils/)

add_executable(test_threadpool test_threadpool.cpp)
target_link_libraries(test_threadpool common log)
