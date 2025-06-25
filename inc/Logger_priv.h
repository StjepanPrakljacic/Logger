/******************************************************************************
 * @file Logger_priv.h
 * @brief Header file for the Logger in inc.
 *
 * This file contains the declarations of functions and data structures
 * used for managing the Logger project in the inc directory.
 *
 * The functions declared here are used for initializing and managing
 * the various modules within the Logger project.
 *****************************************************************************/

#ifndef LOGGER_PRIV_H
#define LOGGER_PRIV_H

/******************************************************************************
 * Includes
 *****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Logger.h"

/******************************************************************************
 * Macros
 *****************************************************************************/

#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_GREEN   "\x1b[32m"

/******************************************************************************
 * Typedefs
 *****************************************************************************/

/******************************************************************************
 * Enumerations
 *****************************************************************************/

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
 * @brief Gets the current timestamp as a formatted string.
 *
 * @details Returns the current local time formatted as "[YYYY-MM-DD HH:MM:SS]".
 *
 * @param[in] None
 *
 * @return const char*
 * @retval Pointer to a static string containing the formatted timestamp.
 */
const char *Get_Timestamp(void);


/******************************************************************************
 * Constants
 *****************************************************************************/

#endif // LOGGER_PRIV_H
