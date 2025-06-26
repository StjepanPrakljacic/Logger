cmake_minimum_required(VERSION 3.10)
project(Logger)

include(FetchContent)

FetchContent_Declare(
  common_config
  GIT_REPOSITORY https://github.com/StjepanPrakljacic/common-config.git
  GIT_TAG main
)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.11.0
)

FetchContent_MakeAvailable(common_config googletest)

add_subdirectory(src)
add_subdirectory(test)
