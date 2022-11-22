#ifndef LOG_H
#define LOG_H

#include <iostream>


class Log
{

private:
    int m_LogLevel;
public:
    enum LogLevel {
         INFO = 0,
         WARNING,
         ERROR
     };
    
    void SetLevel(int level);
    void Info(std::string msg);
    void Warn(std::string msg);
    void Error(std::string msg);

};
#endif