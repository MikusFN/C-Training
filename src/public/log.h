#ifndef LOG_H
#define LOG_H

#include <iostream>


class Log
{

public:
    enum LogLevel {
         ERROR,
         WARNING,
         INFO
     };
    
    void SetLevel(LogLevel level);
    void Info(std::string msg);
    void Warn(std::string msg);
    void Error(std::string msg);

private:
    LogLevel m_LogLevel;
};

/**
 * Use Example
 * 
 * Log log;
 * 
 * log.SetLevel(Log::LogLevel::ERROR);
 * log.Warn("Warning!");
 * log.Error("Error!");
 * log.Info("Info!");
 * 
*/
#endif