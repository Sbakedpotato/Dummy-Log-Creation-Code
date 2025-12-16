#include "message.h"
#include "logger.h"

void Message::printMessageStamp(const std::string& threadId) {
    LOG_INFO("message.cpp", 1675, "printMessageSt", threadId, 
             "Message Stamp = [" + messageStamp_ + "]");
    LOG_INFO("message.cpp", 1676, "printMessageSt", threadId, 
             "DateTime = [" + dateTime_ + "]");
    LOG_INFO("message.cpp", 1677, "printMessageSt", threadId, 
             "Stan [" + stan_ + "]");
    LOG_INFO("message.cpp", 1678, "printMessageSt", threadId, 
             "RRN [" + rrn_ + "]");
}

bool Message::insertException(const std::string& threadId, int& exceptionId) {
    // Simulate exception insertion
    static int nextExceptionId = 20;
    exceptionId = ++nextExceptionId;
    
    LOG_INFO("message.cpp", 721, "insertExceptio", threadId, 
             "Exception with id [" + std::to_string(exceptionId) + "] inserted successfully");
    
    return true;
}
