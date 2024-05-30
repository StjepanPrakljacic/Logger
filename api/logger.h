#ifndef LOGGER_H
#define LOGGER_H

/**
 * @file logger.h
 * @brief Header file for the Logger library in C.
 *
 * The Logger library provides functions for logging messages at different
 * levels of severity (DEBUG, INFO, WARNING, ERROR).
 */


typedef enum {
    DEBUG,    /**< Debug log level for detailed debugging messages. */
    INFO,     /**< Info log level for general informational messages. */
    WARNING,  /**< Warning log level for potential issues or unexpected behavior. */
    ERROR     /**< Error log level for critical errors or failures. */
} LogLevel;

#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_GREEN   "\x1b[32m"

/*Function-like macro*/
#define Log_AddMsg(level, message) _log_message(level, message)


/**
 * @brief Logs a message at the specified log level.
 *
 * This function logs a message with a specified severity level. The message
 * will be printed with an appropriate color based on the log level.
 *
 * @param[in] level The log level of the message. Can be DEBUG, INFO, WARNING,
 *            or ERROR.
 * @param[in] message The message to log.
 *
 * @return void
 */
void _log_message(LogLevel level, const char *message);

#endif
