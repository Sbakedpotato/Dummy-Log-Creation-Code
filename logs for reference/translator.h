#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <string>
#include "message.h"

// Base Translator class - handles message parsing and building
class Translator {
public:
    Translator() = default;
    virtual ~Translator() = default;

    // Process incoming message
    virtual bool ProcessIncoming(const std::string& messageData, 
                                  Message& msg, 
                                  const std::string& threadId);

    // Process outgoing message
    virtual bool ProcessOutgoing(Message& msg, 
                                  std::string& outputData, 
                                  const std::string& threadId);

    // Check conditions for field processing
    bool CheckCondition(const std::string& condition, const std::string& threadId);

    // Map field values between internal and external formats
    bool mapField(const std::string& fieldName, 
                  const std::string& value, 
                  std::string& mappedValue,
                  const std::string& threadId);

    // Build sub-fields for complex data elements
    virtual void buildSubFields(Message& msg, const std::string& threadId);

protected:
    std::string format_;
};

#endif // TRANSLATOR_H
