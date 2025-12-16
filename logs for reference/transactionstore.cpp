/**
 * @file transactionstore.cpp
 * @brief Transaction Store implementation
 * 
 * Reconstructed from log file analysis.
 */

#include "transactionstore.h"

TransactionStore::TransactionStore() : m_transactionCount(0) {
}

TransactionStore::~TransactionStore() {
}

bool TransactionStore::addTransaction(const std::string& logId, const std::string& srcChannelId,
                                       const std::string& srcChannelKey, const std::string& destChannelId,
                                       const std::string& dstChannelKey, const std::string& trxDateTime) {
    LOG_INFO("transactionstore.c", "0298", "addTransaction", logId,
             "Message as it is dumped into the internal database trxDateTime = [" + trxDateTime + "]");
    LOG_INFO("transactionstore.c", "0300", "addTransaction", logId,
             "srcChannelId =  [" + srcChannelId + "] , srcChannelKey =   [" + srcChannelKey + "]");
    LOG_INFO("transactionstore.c", "0301", "addTransaction", logId,
             "destChannelId = [" + destChannelId + "] , dstChannelKey = [" + dstChannelKey + "]");
    
    std::string txnKey = "iris:txn:" + dstChannelKey;
    LOG_INFO("transactionstore.c", "0363", "addTransaction", logId,
             "Transaction [" + txnKey + "] successfully inserted in redis");
    
    m_transactionCount++;
    return true;
}
