link_libraries(-lpthread)

include_directories(${PROJECT_SOURCE_DIR}/src/event/
                    ${PROJECT_SOURCE_DIR}/src/log/
)

add_executable(test_timerlist test_timerlist.cpp)
target_link_libraries(test_timerlist event common log)
