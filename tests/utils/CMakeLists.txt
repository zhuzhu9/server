link_libraries(-lpthread)

include_directories(${PROJECT_SOURCE_DIR}/utils/ ${PROJECT_SOURCE_DIR}/src/log)

add_executable(test_threadpool test_threadpool.cpp)
target_link_libraries(test_threadpool common log)
