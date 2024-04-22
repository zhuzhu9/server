link_libraries(-lpthread)

aux_source_directory(./ SRC)

include_directories(../socket/ ../common/ ../log/)

add_executable(server ${SRC})
target_link_libraries(server socket common log)
