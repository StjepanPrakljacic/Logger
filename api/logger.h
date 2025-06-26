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
 * @brief Logs a debug-level message.
 *
 * @details Formats and logs a message with the DEBUG severity level.
 *          The message is processed like printf, supporting format specifiers.
 *          The message is logged only if the current log level allows DEBUG messages.
 *
 * @param[in] format A printf-style format string.
 * @param[in] ...    Variable arguments corresponding to the format specifiers.
 *
 * @return Std_ReturnType
 * @retval E_OK     The message was logged successfully.
 * @retval E_NOT_OK The message was not logged (e.g., due to log level filtering or invalid parameters).
 */
Std_ReturnType Log_DebugMessage(const char *format, ...);

/**
 * @brief Logs an info-level message.
 *
 * @details Formats and logs a message with the INFO severity level.
 *          The message is processed like printf, supporting format specifiers.
 *          The message is logged only if the current log level allows INFO messages.
 *
 * @param[in] format A printf-style format string.
 * @param[in] ...    Variable arguments corresponding to the format specifiers.
 *
 * @return Std_ReturnType
 * @retval E_OK     The message was logged successfully.
 * @retval E_NOT_OK The message was not logged (e.g., due to log level filtering or invalid parameters).
 */
Std_ReturnType Log_InfoMessage(const char *format, ...);

/**
 * @brief Logs a warning-level message.
 *
 * @details Formats and logs a message with the WARNING severity level.
 *          The message is processed like printf, supporting format specifiers.
 *          The message is logged only if the current log level allows WARNING messages.
 *
 * @param[in] format A printf-style format string.
 * @param[in] ...    Variable arguments corresponding to the format specifiers.
 *
 * @return Std_ReturnType
 * @retval E_OK     The message was logged successfully.
 * @retval E_NOT_OK The message was not logged (e.g., due to log level filtering or invalid parameters).
 */
Std_ReturnType Log_WarningMessage(const char *format, ...);

/**
 * @brief Logs an error-level message.
 *
 * @details Formats and logs a message with the ERROR severity level.
 *          The message is processed like printf, supporting format specifiers.
 *          The message is logged only if the current log level allows ERROR messages.
 *
 * @param[in] format A printf-style format string.
 * @param[in] ...    Variable arguments corresponding to the format specifiers.
 *
 * @return Std_ReturnType
 * @retval E_OK     The message was logged successfully.
 * @retval E_NOT_OK The message was not logged (e.g., due to log level filtering or invalid parameters).
 */
Std_ReturnType Log_ErrorMessage(const char *format, ...);

/******************************************************************************
 * Constants
 *****************************************************************************/

#endif // LOGGER_H
