#ifndef TRANSLATORISO_H
#define TRANSLATORISO_H

#include <string>
#include <bitset>
#include "translator.h"

// ISO 8583 Translator - handles ISO message format parsing and building
class TranslatorISO : public Translator {
public:
    TranslatorISO() = default;
    virtual ~TranslatorISO() = default;

    // Parse an ISO 8583 message
    bool parseMessage(const std::string& messageData, 
                      Message& msg, 
                      const std::string& threadId);

    // Build an ISO 8583 message
    bool buildMessage(Message& msg, 
                      std::string& outputData, 
                      const std::string& threadId);

    // Fill the bitmap from raw message data
    bool fillBitmap(const std::string& bitmapData, const std::string& threadId);

    // Display the bitmap in binary format
    void showBitmap(const std::string& threadId);

    // Display the fields present in the bitmap
    void showBitmapFields(const std::string& threadId);

    // Parse individual fields based on bitmap
    bool parseFields(const std::string& messageData, 
                     Message& msg, 
                     const std::string& threadId);

    // Build a single field for the outgoing message
    bool buildField(const std::string& fieldName, 
                    const std::string& value,
                    const std::string& encoding,
                    int position,
                    const std::string& threadId);

    // Build the outgoing bitmap
    bool buildOutgoingBitmap(const std::string& threadId);

protected:
    std::bitset<128> bitmap_;
    std::string bitmapString_;
};

#endif // TRANSLATORISO_H
