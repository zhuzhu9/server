if(CONFIG_LOG_USE_SPDLOG)
add_subdirectory(spdlog)
endif()

if(CONFIG_YAML_CPP)
add_subdirectory(yaml-cpp)
endif()

add_subdirectory(fast_io)