link_libraries(-lpthread)

include_directories(${PROJECT_SOURCE_DIR}/utils/
                    ${PROJECT_SOURCE_DIR}/src/log
                    ${PROJECT_SOURCE_DIR}/third_party/magic_enum/include
)

add_executable(test_magic_enum test_magic_enum.cpp)
target_link_libraries(test_magic_enum common log)