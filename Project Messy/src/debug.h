#ifndef DEBUGGER_H
#define DEBUGGER_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// Logging levels
typedef enum {
    LOG_NONE,
    LOG_ERROR,
    LOG_WARNING,
    LOG_INFO,
    LOG_DEBUG
} LogLevel;

// Global variable to set the current logging level
extern LogLevel currentLogLevel;

// Function to set the logging level
void setLogLevel(LogLevel level);

#define clean_errno() (errno == 0 ? "None" : strerror(errno))

// Logging macros
#define LOG_ERROR(fmt, ...) \
    if (currentLogLevel >= LOG_ERROR) { \
        fprintf(stderr, "ERROR: " fmt "\n", ##__VA_ARGS__); \
    }

#define LOG_WARNING(fmt, ...) \
    if (currentLogLevel >= LOG_WARNING) { \
        fprintf(stderr, "WARNING: " fmt "\n", ##__VA_ARGS__); \
    }

#define LOG_INFO(fmt, ...) \
    if (currentLogLevel >= LOG_INFO) { \
        fprintf(stderr, "INFO: " fmt "\n", ##__VA_ARGS__); \
    }

#define LOG_DEBUG(fmt, ...) \
    if (currentLogLevel >= LOG_DEBUG) { \
        fprintf(stderr, "DEBUG: " fmt "\n", ##__VA_ARGS__); \
    }

// Memory check macros
#define CHECK_ALLOC(ptr) \
    if ((ptr) == NULL) { \
        LOG_ERROR("Memory allocation failed"); \
        exit(EXIT_FAILURE); \
    }

#define check(A,fmt,...) if(!(A)) {LOG_ERROR(fmt, ##__VA_ARGS__); errno=0; goto error; }

// Second memory check macro
#define CHECK_MEM(A) check((A), "Out of Memory.")

// Common undefined behavior checks
#define CHECK_NULL(ptr) \
    if ((ptr) == NULL) { \
        LOG_ERROR("Null pointer dereference"); \
        exit(EXIT_FAILURE); \
    }

// Common Boolean to check if condition A is true, if not, logs erroe and jumps to functions error, to clean up.
#define CHECK_CONDITION(A, fmt, ...) if(!(A)) {LOG_ERROR(fmt, ##_VA_ARGS__); errno=0; goto error; }

// Declare if wrong function is run.
#define CHECK_ENGINE(fmt, ...) { LOG_ERROR(fmt, ##__VA_ARGS__); errno=0; goto error; }



#endif // DEBUGGER_H
