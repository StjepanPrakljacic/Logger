cmake_minimum_required(VERSION 3.10)
project(Logger)

option(COMMON_CONFIG_PATH "Path to common-config include directory" "")

include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.11.0
)

FetchContent_MakeAvailable(googletest)

add_subdirectory(src)
add_subdirectory(test)

add_executable(Logger main.c)
target_link_libraries(Logger PRIVATE Logger_lib)

if(COMMON_CONFIG_PATH)
    target_include_directories(Logger PUBLIC ${COMMON_CONFIG_PATH})
endif()
