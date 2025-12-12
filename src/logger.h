#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <chrono>
#include <ctime>
#include <string>

// Log levels
enum class LogLevel {
    INFO,
    WARNING,
    ERROR,
    CRITICAL
};

// Helper to get current time formatted as HH:MM:SS.mmm
inline std::string getCurrentTimeFormatted() {
    auto now = std::chrono::system_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    std::tm tm = *std::localtime(&t);

    std::ostringstream oss;
    oss << std::put_time(&tm, "%H:%M:%S") << '.' << std::setfill('0') << std::setw(3) << ms.count();
    return oss.str();
}

// Helper to convert LogLevel to string
inline std::string logLevelToString(LogLevel level) {
    switch (level) {
        case LogLevel::INFO:     return "INFO";
        case LogLevel::WARNING:  return "WARNING";
        case LogLevel::ERROR:    return "ERROR";
        case LogLevel::CRITICAL: return "CRITICAL";
        default:                 return "UNKNOWN";
    }
}

// The main LOG macro
// Format: Time \t Level \t FileName \t LineNumber \t FunctionName \t ThreadID \t Message
#define LOG(level, fileName, lineNum, funcName, threadId, message) \
    do { \
        std::ostringstream _log_oss; \
        _log_oss << getCurrentTimeFormatted() << " \t" \
                 << logLevelToString(level) << " \t" \
                 << std::setw(18) << std::left << fileName << " \t" \
                 << std::setw(4) << std::setfill('0') << lineNum << " \t" \
                 << std::setw(14) << std::left << funcName << " \t" \
                 << threadId << " " << message; \
        std::cout << _log_oss.str() << std::endl; \
    } while(0)

// Convenience macros for each log level
#define LOG_INFO(fileName, lineNum, funcName, threadId, message) \
    LOG(LogLevel::INFO, fileName, lineNum, funcName, threadId, message)

#define LOG_ERROR(fileName, lineNum, funcName, threadId, message) \
    LOG(LogLevel::ERROR, fileName, lineNum, funcName, threadId, message)

#define LOG_CRITICAL(fileName, lineNum, funcName, threadId, message) \
    LOG(LogLevel::CRITICAL, fileName, lineNum, funcName, threadId, message)

#endif // LOGGER_H
