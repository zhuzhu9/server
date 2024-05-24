cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
project(web_server LANGUAGES CXX)
project(web_server VERSION 0.0.1)


set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out/bin)
link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})


# foreach(source ${USER_SOURCES})
#     get_filename_component(file_name ${source} NAME)
#     set_source_files_properties(${source} PROPERTIES COMPILE_DEFINITIONS)
#     "FILE_NAME=\"${file_name}\";__FILE__=FILE_NAME"

# endforeach()


include_directories(${PROJECT_SOURCE_DIR}/utils)


set(CONFIG_LOG_USE_SPDLOG OFF)
set(CONFIG_LOG_USE_ZLOG ON)


if(CONFIG_LOG_USE_SPDLOG)
    add_compile_options(-DUSE_LOG_SPDLOG)
elseif(CONFIG_LOG_USE_ZLOG)
    add_compile_options(-DUSE_LOG_ZLOG)
endif()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

add_subdirectory(third_party)
add_subdirectory(src)
add_subdirectory(tests)