link_libraries(-lpthread)

include_directories(${PROJECT_SOURCE_DIR}/src/log/)

add_executable(test_log test_log.cpp)
target_link_libraries(test_log event common log)
