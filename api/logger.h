/******************************************************************************
 * @file Logger.h
 * @brief Header file for the Logger in api.
 *
 * This file contains the declarations of functions and data structures
 * used for managing the Logger project in the api directory.
 *
 * The functions declared here are used for initializing and managing
 * the various modules within the Logger project.
 *****************************************************************************/

#ifndef LOGGER_H
#define LOGGER_H

/******************************************************************************
 * Includes
 *****************************************************************************/

#include "Std_Types.h"

/******************************************************************************
 * Macros
 *****************************************************************************/
/**
 * @brief Shortcut macro for logging a message.
 *
 * @details This macro wraps the internal _log_message() function to provide
 * a simpler interface for adding log messages with a specified log level.
 *
 * @param level   The log level (e.g., LOG_DEBUG, LOG_INFO).
 * @param message The message string to log.
 *
 * @return E_NOT_OK
 * @retval E_OK         The message was logged successfully.
 * @retval E_NOT_OK     The message was not logged (e.g., due to log level filtering).
 */
#ifndef Log_AddMsg
#define Log_AddMsg(level, message) _log_message(level, message)
#endif

/******************************************************************************
 * Typedefs
 *****************************************************************************/

/******************************************************************************
 * Enumerations
 *****************************************************************************/
/**
 * @enum LogLevel
 * @brief Logging severity levels.
 * @details Defines various log levels used to categorize log messages.
 */
typedef enum {
    LOG_DEBUG,    /**< Debug log level for detailed debugging messages. */
    LOG_INFO,     /**< Info log level for general informational messages. */
    LOG_WARNING,  /**< Warning log level for potential issues or unexpected behavior. */
    LOG_ERROR     /**< Error log level for critical errors or failures. */
} LogLevel;

/******************************************************************************
 * Structures
 *****************************************************************************/

/******************************************************************************
 * Global Variables (extern declarations)
 *****************************************************************************/

 /******************************************************************************
 * Function Prototypes
 *****************************************************************************/
/**
 * @brief Initializes the Logger module.
 *
 * @details Sets the default log level and prepares the Logger for use.
 *
 * @param[in] None
 *
 * @return Std_ReturnType
 * @retval E_OK         Logger initialized successfully.
 * @retval E_NOT_OK     Initialization failed.
 */
Std_ReturnType Logger_init(void);


/**
 * @brief Sets the minimum log level to be printed.
 *
 * @details Messages with a log level equal or higher than this will be logged.
 *
 * @param[in] level The minimum log level to set (e.g., LOG_DEBUG, LOG_INFO, etc.).
 *
 * @return Std_ReturnType
 * @retval E_OK         Level set successfully.
 * @retval E_NOT_OK     Invalid log level; level not set.
 */
Std_ReturnType Logger_setLevel(LogLevel level);


/**
 * @brief Gets the current log level.
 *
 * @details Returns the current minimum log level that messages must meet to be logged.
 *
 * @param[in] None
 *
 * @return LogLevel.
 * @retval Current log level.
 */
LogLevel Logger_getLevel(void);


/**
 * @brief Logs a message with a specified severity level.
 *
 * @details Prints the message with timestamp and colored log level tag if the
 *          level is equal or higher than the current log level. Messages
 *          below the current log level are filtered out and not logged.
 *
 * @param[in] level The severity level of the message.
 * @param[in] message The message string to log.
 *
 * @return Std_ReturnType
 * @retval E_OK         Message logged successfully.
 * @retval E_NOT_OK     Message filtered out due to log level.
 */
Std_ReturnType _log_message(LogLevel level, const char *message);


/******************************************************************************
 * Constants
 *****************************************************************************/

#endif // LOGGER_H
