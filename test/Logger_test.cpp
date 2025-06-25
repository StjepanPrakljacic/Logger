/******************************************************************************
 * @file Logger_test.cpp
 * @brief Unit tests for the Logger project using Google Test.
 *****************************************************************************/

#include "gtest/gtest.h"

extern "C" {
#include "Logger.h"
}

class LoggerTest : public ::testing::Test {
protected:
    void SetUp() override {
        EXPECT_EQ(Logger_init(), E_OK);
        // Set default level to DEBUG for tests
        EXPECT_EQ(Logger_setLevel(LOG_DEBUG), E_OK);
    }
};

TEST_F(LoggerTest, InitReturnsOK) {
    EXPECT_EQ(Logger_init(), E_OK);
}

TEST_F(LoggerTest, SetLevelValidAndInvalid) {
    EXPECT_EQ(Logger_setLevel(LOG_INFO), E_OK);
    EXPECT_EQ(Logger_getLevel(), LOG_INFO);

    // Invalid level (e.g. 999) returns E_NOT_OK
    EXPECT_EQ(Logger_setLevel((LogLevel)999), E_NOT_OK);
}

TEST_F(LoggerTest, LogMessageReturnsCorrectStatus) {
    EXPECT_EQ(Logger_setLevel(LOG_WARNING), E_OK);

    // Messages below currentLevel return E_NOT_OK
    EXPECT_EQ(_log_message(LOG_DEBUG, "Debug message"), E_NOT_OK);

    // Messages at or above currentLevel return E_OK
    EXPECT_EQ(_log_message(LOG_WARNING, "Warning message"), E_OK);
    EXPECT_EQ(_log_message(LOG_ERROR, "Error message"), E_OK);
}