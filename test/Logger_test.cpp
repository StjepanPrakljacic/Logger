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
        ASSERT_EQ(Logger_init(), E_OK);
    }
};

TEST_F(LoggerTest, InitReturnsOK) {
    EXPECT_EQ(Logger_init(), E_OK);
}

TEST_F(LoggerTest, SetAndGetLevel) {
    EXPECT_EQ(Logger_setLevel(LOG_DEBUG), E_OK);
    EXPECT_EQ(Logger_getLevel(), LOG_DEBUG);

    EXPECT_EQ(Logger_setLevel(LOG_INFO), E_OK);
    EXPECT_EQ(Logger_getLevel(), LOG_INFO);

    // Invalid level should fail
    EXPECT_EQ(Logger_setLevel((LogLevel)999), E_NOT_OK);
}

TEST_F(LoggerTest, LogFunctionsReturnOKWhenLevelAllows) {
    Logger_setLevel(LOG_DEBUG);
    EXPECT_EQ(Log_DebugMessage("Debug message %d", 123), E_OK);
    EXPECT_EQ(Log_InfoMessage("Info message %s", "abc"), E_OK);
    EXPECT_EQ(Log_WarningMessage("Warning message"), E_OK);
    EXPECT_EQ(Log_ErrorMessage("Error message"), E_OK);
}

TEST_F(LoggerTest, LogFunctionsReturnNotOKWhenLevelFiltersOut) {
    Logger_setLevel(LOG_ERROR);
    EXPECT_EQ(Log_DebugMessage("Debug message %d", 123), E_NOT_OK);
    EXPECT_EQ(Log_InfoMessage("Info message %s", "abc"), E_NOT_OK);
    EXPECT_EQ(Log_WarningMessage("Warning message"), E_NOT_OK);
    EXPECT_EQ(Log_ErrorMessage("Error message"), E_OK);
}

TEST_F(LoggerTest, LogWithNullFormat) {
    EXPECT_EQ(Log_DebugMessage(nullptr), E_NOT_OK);
    EXPECT_EQ(Log_InfoMessage(nullptr), E_NOT_OK);
    EXPECT_EQ(Log_WarningMessage(nullptr), E_NOT_OK);
    EXPECT_EQ(Log_ErrorMessage(nullptr), E_NOT_OK);
}

TEST_F(LoggerTest, LogWithEmptyFormat) {
    EXPECT_EQ(Log_DebugMessage(""), E_OK);
    EXPECT_EQ(Log_InfoMessage(""), E_OK);
    EXPECT_EQ(Log_WarningMessage(""), E_OK);
    EXPECT_EQ(Log_ErrorMessage(""), E_OK);
}

TEST_F(LoggerTest, StressTestLogging) {
    Logger_setLevel(LOG_DEBUG);
    for (int i = 0; i < 10000; ++i) {
        // Just ensure no crash and valid return
        EXPECT_EQ(Log_DebugMessage("Stress test iteration %d", i), E_OK);
    }
}
