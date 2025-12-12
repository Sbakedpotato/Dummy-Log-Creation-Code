#ifndef SAFSTORE_H
#define SAFSTORE_H

#include <string>

// SAF Store - persistent storage for Store and Forward messages
class SAFStore {
public:
    SAFStore(const std::string& threadId);
    ~SAFStore() = default;

    // Store a message for later forwarding
    bool storeMessage(const std::string& messageData);

    // Retrieve stored messages
    bool retrieveMessages();

private:
    std::string threadId_;
};

#endif // SAFSTORE_H
