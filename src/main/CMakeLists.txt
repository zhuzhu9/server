link_libraries(-lpthread)

aux_source_directory(./ SRC)

include_directories(${SRC_DIR}/socket/ ${SRC_DIR}/common/ ${SRC_DIR}/log/ ${SRC_DIR}/event/)

add_executable(server ${SRC})
target_link_libraries(server socket common log event)
