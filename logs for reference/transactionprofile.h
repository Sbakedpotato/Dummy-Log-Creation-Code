/**
 * @file transactionprofile.h
 * @brief Transaction Profile - Transaction timeout and profile configuration
 * 
 * Reconstructed from log file analysis.
 */

#ifndef TRANSACTIONPROFILE_H
#define TRANSACTIONPROFILE_H

#include <string>
#include "logger.h"

class TransactionProfile {
public:
    TransactionProfile();
    ~TransactionProfile();
    
    /**
     * @brief Fetch channel timeouts from database
     * @param logId Transaction log ID
     * @return true if successful, false otherwise
     * 
     * Log entry: transactionprofile 0427 fetchChannelsT - Loading channel timeouts
     * Log entry: transactionprofile 0464 fetchChannelsT - Loading channel timeouts
     * Log entry: transactionprofile 0478 fetchChannelsT - channel type is = [X] , Message Type = [X] , Source channel is = [X] , tranCode = [X] , timeout = [X]
     */
    bool fetchChannelsTimeout(const std::string& logId);
    
    /**
     * @brief Get timeout value for channel/transaction
     * @param logId Transaction log ID
     * @param key Timeout configuration key
     * @return Timeout value in seconds
     * 
     * Log entry: transactionprofile 0597 getTimeoutValu - Timeout Value found for = [X] = [X]
     */
    int getTimeoutValue(const std::string& logId, const std::string& key);

private:
    int m_defaultTimeout;
};

#endif // TRANSACTIONPROFILE_H
