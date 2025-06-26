/******************************************************************************
 * @file Logger.c
 * @brief Source file for the Logger project.
 *
 * This file contains the implementation of functions for managing the
 * Logger project, as well as global variables and macros.
 *****************************************************************************/

/******************************************************************************
 * Includes
 *****************************************************************************/

#include "Logger.h"
#include "Logger_priv.h"

/******************************************************************************
 * Macros
 *****************************************************************************/

/******************************************************************************
 * Constants
 *****************************************************************************/

/******************************************************************************
 * Global Variables
 *****************************************************************************/

/******************************************************************************
 * Static Variables
 *****************************************************************************/

static LogLevel currentLevel = LOG_DEBUG;

/******************************************************************************
 * Static Function Prototypes
 *****************************************************************************/

 /**
 * @brief Gets the current timestamp as a formatted string.
 *
 * @details Returns the current local time formatted as "[YYYY-MM-DD HH:MM:SS]".
 *
 * @param[in] None
 *
 * @return const char*
 * @retval Pointer to a static string containing the formatted timestamp.
 */
static const char *Get_Timestamp(void);

/**
 * @brief Logs a message with a specified severity level.
 *
 * @details Formats and logs a message according to the given log level.
 *          The message supports printf-style formatting using a va_list.
 *          Messages with a level below the current log level are ignored.
 *
 * @param[in] level  The severity level of the log message (e.g., LOG_DEBUG, LOG_INFO).
 * @param[in] format A printf-style format string for the log message.
 * @param[in] args   A va_list of arguments corresponding to the format specifiers.
 *
 * @return Std_ReturnType
 * @retval E_OK     The message was logged successfully.
 * @retval E_NOT_OK The message was not logged (e.g., due to log level filtering or invalid parameters).
 */
static Std_ReturnType Log_AddMsg(LogLevel level, const char* format, va_list args);

/******************************************************************************
 * Public Function Definitions
 *****************************************************************************/

Std_ReturnType Logger_init(void)
{
    return Logger_setLevel(LOG_DEBUG);
}

Std_ReturnType Logger_setLevel(LogLevel level)
{
    Std_ReturnType retVal = E_NOT_OK;

    if (level < LOG_DEBUG || level > LOG_ERROR)
    {
        return retVal;
    }

    currentLevel = level;
    retVal = E_OK;

    return retVal;
}

LogLevel Logger_getLevel(void)
{
    return currentLevel;
}

Std_ReturnType Log_DebugMessage(const char *format, ...)
{
    va_list args;
    Std_ReturnType retVal;
    va_start(args, format);
    retVal = Log_AddMsg(LOG_DEBUG, format, args);
    va_end(args);
    return retVal;
}

Std_ReturnType Log_InfoMessage(const char *format, ...)
{
    va_list args;
    Std_ReturnType retVal;
    va_start(args, format);
    retVal = Log_AddMsg(LOG_INFO, format, args);
    va_end(args);
    return retVal;
}

Std_ReturnType Log_WarningMessage(const char *format, ...)
{
    va_list args;
    Std_ReturnType retVal;
    va_start(args, format);
    retVal = Log_AddMsg(LOG_WARNING, format, args);
    va_end(args);
    return retVal;
}

Std_ReturnType Log_ErrorMessage(const char *format, ...)
{
    va_list args;
    Std_ReturnType retVal;
    va_start(args, format);
    retVal = Log_AddMsg(LOG_ERROR, format, args);
    va_end(args);
    return retVal;
}

/******************************************************************************
 * Static Function Definitions
 *****************************************************************************/

static const char* Get_Timestamp(void)
{
    static char buffer[30];
    time_t raw_time = time(NULL);
    struct tm *time_info = localtime(&raw_time);
    strftime(buffer, sizeof(buffer), "[%Y-%m-%d %H:%M:%S]", time_info);
    return buffer;
}

static Std_ReturnType Log_AddMsg(LogLevel level, const char* format, va_list args)
{
    Std_ReturnType retVal = E_NOT_OK;
    const char* color;
    const char* levelStr;
    char buffer[256];

    if (format == NULL || level < currentLevel)
    {
        return retVal;
    }

    switch(level)
    {
        case LOG_DEBUG:   color = ANSI_COLOR_CYAN;    levelStr = "DEBUG";   break;
        case LOG_INFO:    color = ANSI_COLOR_GREEN;   levelStr = "INFO";    break;
        case LOG_WARNING: color = ANSI_COLOR_YELLOW;  levelStr = "WARNING"; break;
        case LOG_ERROR:   color = ANSI_COLOR_RED;     levelStr = "ERROR";   break;
        default: return retVal;
    }

    vsnprintf(buffer, sizeof(buffer), format, args);

    printf("%s %s[%s]%s %s\n", Get_Timestamp(), color, levelStr, ANSI_COLOR_RESET, buffer);

    retVal = E_OK;

    return retVal;
}

/******************************************************************************
 * End of File
 *****************************************************************************/

