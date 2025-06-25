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

static LogLevel currentLevel;

/******************************************************************************
 * Static Function Prototypes
 *****************************************************************************/

/******************************************************************************
 * Public Function Definitions
 *****************************************************************************/

Std_ReturnType Logger_init(void)
{
    return Logger_setLevel(LOG_DEBUG);
}

const char* Get_Timestamp(void)
{
    static char buffer[30];
    time_t raw_time = time(NULL);
    struct tm *time_info = localtime(&raw_time);
    strftime(buffer, sizeof(buffer), "[%Y-%m-%d %H:%M:%S]", time_info);
    return buffer;
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

Std_ReturnType _log_message(LogLevel level, const char *message)
{
    Std_ReturnType retVal = E_NOT_OK;
    const char *levelStr = "";
    const char *color = "";

    if (level < currentLevel)
    {
        return retVal;
    }

    if (NULL_PTR == message)
    {
        return retVal;
    }

    switch (level) {
        case LOG_DEBUG:
            levelStr = "DEBUG";
            color = ANSI_COLOR_CYAN;
            retVal = E_OK;
            break;
        case LOG_INFO:
            levelStr = "INFO";
            color = ANSI_COLOR_GREEN;
            retVal = E_OK;
            break;
        case LOG_WARNING:
            levelStr = "WARNING";
            color = ANSI_COLOR_YELLOW;
            retVal = E_OK;
            break;
        case LOG_ERROR:
            levelStr = "ERROR";
            color = ANSI_COLOR_RED;
            retVal = E_OK;
            break;
        default:
            retVal = E_NOT_OK;
            break;
    }

    if (E_NOT_OK != retVal)
    {
        printf("%s %s[%s]%s %s\n", Get_Timestamp(), color, levelStr, ANSI_COLOR_RESET,message);
    }

    return retVal;
}

/******************************************************************************
 * Static Function Definitions
 *****************************************************************************/


/******************************************************************************
 * End of File
 *****************************************************************************/

