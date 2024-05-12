#ifndef LOGGER_H
#define LOGGER_H

/**
 * @file logger.h
 * @brief Header file for the Logger library in C.
 *
 * The Logger library provides functions for logging messages at different
 * levels of severity (DEBUG, INFO, WARNING, ERROR).
 */

// Define log levels
typedef enum {
    DEBUG,    /**< Debug log level for detailed debugging messages. */
    INFO,     /**< Info log level for general informational messages. */
    WARNING,  /**< Warning log level for potential issues or unexpected behavior. */
    ERROR     /**< Error log level for critical errors or failures. */
} LogLevel;

// Function prototypes

void log_message(LogLevel level, const char *message);

#endif