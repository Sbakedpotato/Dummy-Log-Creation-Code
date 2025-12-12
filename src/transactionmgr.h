#ifndef TRANSACTIONMGR_H
#define TRANSACTIONMGR_H

#include <string>
#include "message.h"

// Transaction Manager - coordinates transaction processing logic
class TransactionMgr {
public:
    static TransactionMgr& getInstance();

    // Process a message and apply business rules
    bool processMessage(Message& msg, const std::string& threadId);

private:
    TransactionMgr() = default;
    TransactionMgr(const TransactionMgr&) = delete;
    TransactionMgr& operator=(const TransactionMgr&) = delete;
};

#endif // TRANSACTIONMGR_H
