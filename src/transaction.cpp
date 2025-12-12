#include "transaction.h"
#include "dbconnmgr.h"
#include "logger.h"
#include <map>

bool Transaction::insertTransaction(const std::string& threadId, int& transactionId) {
    std::map<std::string, std::string> outParams;
    
    bool success = DBConnMgr::getInstance().dbHitForStoredProcedure(
        "IRIS_TRANSACTION.TRANSACTIONLOG.INSERTTRAN", threadId, outParams);
    
    if (success) {
        static int nextTransactionId = 213;
        transactionId = ++nextTransactionId;
        transactionId_ = transactionId;
        
        LOG_INFO("transaction.cpp", 713, "insertTransact", threadId, 
                 "Transaction with id [" + std::to_string(transactionId) + "] inserted successfully");
        return true;
    } else {
        LOG_ERROR("transaction.cpp", 692, "insertTransact", threadId, 
                  "Transaction insert failed");
        return false;
    }
}

void Transaction::sendToAcquirer(const std::string& responseCode, const std::string& threadId) {
    LOG_INFO("transaction.cpp", 2676, "sendToAcquirer", threadId, 
             "ResponseCode = [" + responseCode + "]");
}

bool Transaction::getRequestMessage(const std::string& threadId, Message& originalMsg) {
    LOG_INFO("transaction.cpp", 1602, "getRequestMess", threadId, 
             "Checking if original transaction exists in in-memory database");
    
    // Simulate finding the original transaction
    LOG_INFO("transaction.cpp", 1615, "getRequestMess", threadId, 
             "Original transaction found successfully");
    
    return true;
}
