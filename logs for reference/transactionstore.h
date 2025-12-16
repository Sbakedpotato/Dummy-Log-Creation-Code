/**
 * @file transactionstore.h
 * @brief Transaction Store - In-memory transaction storage (Redis)
 * 
 * Reconstructed from log file analysis.
 */

#ifndef TRANSACTIONSTORE_H
#define TRANSACTIONSTORE_H

#include <string>
#include "logger.h"

class TransactionStore {
public:
    TransactionStore();
    ~TransactionStore();
    
    /**
     * @brief Add transaction to store
     * @param logId Transaction log ID
     * @param srcChannelId Source channel ID
     * @param srcChannelKey Source channel key
     * @param destChannelId Destination channel ID
     * @param dstChannelKey Destination channel key
     * @param trxDateTime Transaction datetime
     * @return true if successful, false otherwise
     * 
     * Log entry: transactionstore.c 0298 addTransaction - Message as it is dumped into the internal database trxDateTime = [X]
     * Log entry: transactionstore.c 0300 addTransaction - srcChannelId = [X] , srcChannelKey = [X]
     * Log entry: transactionstore.c 0301 addTransaction - destChannelId = [X] , dstChannelKey = [X]
     * Log entry: transactionstore.c 0363 addTransaction - Transaction [X] successfully inserted in redis
     */
    bool addTransaction(const std::string& logId, const std::string& srcChannelId,
                        const std::string& srcChannelKey, const std::string& destChannelId,
                        const std::string& dstChannelKey, const std::string& trxDateTime);

private:
    int m_transactionCount;
};

#endif // TRANSACTIONSTORE_H
