#include "logger.h"
#include <stdio.h>

void log_message(LogLevel level, const char *message) {
    const char *level_strings[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    printf("[%s] %s\n", level_strings[level], message);
}


