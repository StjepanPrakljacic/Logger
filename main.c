/******************************************************************************
 * @file main.c
 * @brief Entry point of the program.
 *****************************************************************************/

#include <stdio.h>
#include "Logger.h"

/******************************************************************************
 * Main Function
 *****************************************************************************/

int main(void) {
    if ((Std_ReturnType) E_OK != Logger_init())
    {
        printf("Logger initialization failed!\n");
        return 1;
    }

    Log_AddMsg(LOG_DEBUG, "This is a debug message.");
    Log_AddMsg(LOG_INFO, "Information message here.");
    Log_AddMsg(LOG_WARNING, "Warning: check this out!");
    Log_AddMsg(LOG_ERROR, "Error occurred!");

    return 0;
}
