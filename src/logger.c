#include "logger.h"
#include <stdio.h>
#include <time.h>

void log_message(LogLevel level, const char *message) {
    const char *level_strings[] = {
        ANSI_COLOR_BLUE "DEBUG" ANSI_COLOR_RESET,
        ANSI_COLOR_GREEN "INFO" ANSI_COLOR_RESET,
        ANSI_COLOR_YELLOW "WARNING" ANSI_COLOR_RESET,
        ANSI_COLOR_RED "ERROR" ANSI_COLOR_RESET
        };

    // Get current time
    time_t raw_time;
    struct tm *time_info;
    char time_buffer[30]; // Increased size to accommodate date and time

    time(&raw_time);
    time_info = localtime(&raw_time);

    // Format time as [YYYY-MM-DD HH:MM:SS]
    strftime(
        time_buffer,
        sizeof(time_buffer),
        "[%Y-%m-%d %H:%M:%S]",
        time_info
        );

    // Print log message with timestamp and colored log level
    printf("%s %s %s\n", time_buffer, level_strings[level], message);
}
