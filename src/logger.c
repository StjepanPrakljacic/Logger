#include <stdio.h>
#include <time.h>
#include "logger.h"

void _log_message(LogLevel level, const char *message) {
    const char *level_strings[] = {
        ANSI_COLOR_BLUE "LOG_DEBUG" ANSI_COLOR_RESET,
        ANSI_COLOR_GREEN "LOG_INFO" ANSI_COLOR_RESET,
        ANSI_COLOR_YELLOW "LOG_WARNING" ANSI_COLOR_RESET,
        ANSI_COLOR_RED "LOG_ERROR" ANSI_COLOR_RESET
        };

    time_t raw_time;
    struct tm *time_info;
    char time_buffer[30];

    time(&raw_time);
    time_info = localtime(&raw_time);

    strftime(
        time_buffer,
        sizeof(time_buffer),
        "[%Y-%m-%d %H:%M:%S]",
        time_info
        );

    printf("%s %s %s\n", time_buffer, level_strings[level], message);
}
