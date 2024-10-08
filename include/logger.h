#ifndef LOGGER_H
#define LOGGER_H

#ifndef STRINGIFY
#define STRINGIFY(variable) #variable
#endif // STRINGIFY

#ifndef NDEBUG
#define Log(level, ...) writeLog_(level, __FILE__, __func__, __LINE__, __VA_ARGS__);
#else
#define Log(level, ...) ;
#endif

#ifndef NDEBUG
#define openLogFile(path_to_file) openLogFile_(path_to_file)
#else
#define openLogFile(path_to_file) ;
#endif

static const char PATH_LOG_FILE[]  = "logfile.txt";

typedef enum LoggerInfo {
    LoggerInfo_WORKING          = 0,
    LoggerInfo_READ_FILE_ERROR  = 1,
    LoggerInfo_CLOSE_FILE_ERROR = 2,
} LoggerInfo;

typedef enum LogLevel {
    LogLevel_DEBUG    = 0,
    LogLevel_INFO     = 1,
    LogLevel_WARNING  = 2,
    LogLevel_ERROR    = 3,
    LogLevel_CRITICAL = 4,
} LogLevel;

//------------------------------------------------------------------
//! Write log into input file (look logger.h)
//!
//! @param [in] level    A level of logging
//! @param [in] file     Name of file where logging was called
//! @param [in] function Name of function where logging was called
//! @param [in] line     Line where logging was called
//! @param [in] message  Logging message
//!
//! @return State
//------------------------------------------------------------------
LoggerInfo writeLog_(LogLevel    level,
                     const char* file,
                     const char* function,
                     int         line,
                     const char* message,
                     ...);

//---------------------------------------------------
//! Opens a log file
//!
//! @param [in] path_to_file path to logging file
//!
//! @return State
//---------------------------------------------------
LoggerInfo openLogFile_(const char* path_to_file);

#endif // LOGGER_H
