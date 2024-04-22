cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
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

add_subdirectory(src)