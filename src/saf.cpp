#include "saf.h"
#include "logger.h"

SAF::SAF(const std::string& threadId) : threadId_(threadId) {
    sleepIntervalRetriever_ = 2;
    sleepIntervalSender_ = 1;
    
    LOG_INFO("saf.cpp", 64, "SAF", threadId_, 
             "SAFThreadTimers values are SleepIntervalRetriever[" + 
             std::to_string(sleepIntervalRetriever_) + "] SleepIntervalSender[" + 
             std::to_string(sleepIntervalSender_) + "]");
}

void SAF::initialize(int sleepIntervalRetriever, int sleepIntervalSender) {
    sleepIntervalRetriever_ = sleepIntervalRetriever;
    sleepIntervalSender_ = sleepIntervalSender;
}
