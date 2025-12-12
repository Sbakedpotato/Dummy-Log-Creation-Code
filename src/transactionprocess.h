#ifndef TRANSACTIONPROCESS_H
#define TRANSACTIONPROCESS_H

#include <string>
#include "message.h"

// Main transaction processing class - entry point for message handling
class TransactionProcess {
public:
    TransactionProcess() = default;
    ~TransactionProcess() = default;

    // Start parsing an incoming message
    void startParsing(const std::string& messageData, int priority, const std::string& threadId);

    // Process the parsed message
    void processMessage(Message& msg, const std::string& threadId);

    // Check for configuration updates in shared memory
    void checkUpdate(const std::string& threadId);

    // Sample function for testing
    void sampleFunction(const std::string& threadId);

private:
    std::string lastLoadedDateTime_;
};

#endif // TRANSACTIONPROCESS_H
