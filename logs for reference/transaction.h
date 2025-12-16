#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include "message.h"

// Transaction - represents a single financial transaction
class Transaction {
public:
    Transaction() = default;
    ~Transaction() = default;

    // Insert the transaction into the database
    bool insertTransaction(const std::string& threadId, int& transactionId);

    // Send response to the acquirer
    void sendToAcquirer(const std::string& responseCode, const std::string& threadId);

    // Get the original request message from in-memory database
    bool getRequestMessage(const std::string& threadId, Message& originalMsg);

    // Setters
    void setMessage(const Message& msg) { message_ = msg; }

private:
    Message message_;
    int transactionId_ = 0;
};

#endif // TRANSACTION_H
