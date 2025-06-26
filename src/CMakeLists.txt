# Build the main library from your source code
add_library(Logger_lib STATIC Logger.c)

target_include_directories(Logger_lib PUBLIC
    ${CMAKE_SOURCE_DIR}/api
    ${CMAKE_SOURCE_DIR}/inc
    ${common_config_SOURCE_DIR}/inc
)
