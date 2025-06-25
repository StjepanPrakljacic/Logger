enable_testing()

add_executable(runTests Logger_test.cpp)

target_link_libraries(runTests PRIVATE gtest gtest_main Logger_lib)

target_include_directories(runTests PUBLIC
    ${PROJECT_SOURCE_DIR}/api
)

if(COMMON_CONFIG_PATH)
    target_include_directories(runTests PUBLIC ${COMMON_CONFIG_PATH})
endif()
