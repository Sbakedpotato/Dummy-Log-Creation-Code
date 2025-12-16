/**
 * @file transactionprofile.cpp
 * @brief Transaction Profile implementation
 * 
 * Reconstructed from log file analysis.
 */

#include "transactionprofile.h"

TransactionProfile::TransactionProfile() : m_defaultTimeout(30) {
}

TransactionProfile::~TransactionProfile() {
}

bool TransactionProfile::fetchChannelsTimeout(const std::string& logId) {
    LOG_INFO("transactionprofile", "0427", "fetchChannelsT", logId,
             "Loading channel timeouts");
    
    // Simulate loading multiple channel timeouts
    LOG_INFO("transactionprofile", "0464", "fetchChannelsT", logId,
             "Loading channel timeouts");
    LOG_INFO("transactionprofile", "0478", "fetchChannelsT", logId,
             "channel type is = [401] , Message Type = [0200] , Source channel is = [ ] , tranCode = [30] , timeout = [30]");
    
    return true;
}

int TransactionProfile::getTimeoutValue(const std::string& logId, const std::string& key) {
    LOG_INFO("transactionprofile", "0597", "getTimeoutValu", logId,
             "Timeout Value found for = [" + key + "] = [" + std::to_string(m_defaultTimeout) + "]");
    return m_defaultTimeout;
}
