# Build the main library from your source code
add_library(Logger_lib STATIC Logger.c)

target_include_directories(Logger_lib PUBLIC
    ${CMAKE_SOURCE_DIR}/api
    ${CMAKE_SOURCE_DIR}/srvc-api
    ${CMAKE_SOURCE_DIR}/inc
)

if(COMMON_CONFIG_PATH)
    target_include_directories(Logger_lib PUBLIC ${COMMON_CONFIG_PATH})
endif()
