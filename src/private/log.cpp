#include "../public/log.h"

void Log::SetLevel(int level) {
    m_LogLevel = level;
}
void Log::Info(std::string msg) {
    if(m_LogLevel >=  LogLevel::INFO)
        std::cout << "[INFO] : " << msg << std::endl;
}
void Log::Warn(std::string msg) {
    if(m_LogLevel >=  LogLevel::WARNING)
        std::cout << "[WARNING] : " << msg << std::endl;
}
void Log::Error(std::string msg) {
    if(m_LogLevel >=  LogLevel::ERROR)
        std::cout << "[ERROR] : " << msg << std::endl;
}
