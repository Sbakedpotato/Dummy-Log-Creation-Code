#ifndef TRANSLATORMASTERCARD_H
#define TRANSLATORMASTERCARD_H

#include <string>
#include "translatoriso.h"

// Mastercard-specific translator - extends ISO translator with MC-specific logic
class TranslatorMastercard : public TranslatorISO {
public:
    TranslatorMastercard() = default;
    virtual ~TranslatorMastercard() = default;

    // Get additional private data (DE-48)
    std::string getAdditionalDataPrivate(const std::string& data, const std::string& threadId);

    // Set acquiring interface fields
    void setAcquiringInterface(Message& msg, const std::string& threadId);

    // Check if the country is the default country
    bool isDefaultCountry(const std::string& countryCode, const std::string& threadId);

    // Set contactless CVM fields
    void setContactlessCvmFields(Message& msg, const std::string& threadId);

    // Customize outgoing message for Mastercard
    void customizeOutgoing(Message& msg, const std::string& threadId);

    // Map incoming fields to internal format
    bool mapIncomingFields(Message& msg, const std::string& threadId);

    // Map outgoing fields to Mastercard format
    bool mapOutgoingFields(Message& msg, const std::string& threadId);

private:
    std::string sourceChannelID_;
    std::string destinationChannelID_;
    std::string destinationChannelType_;
};

#endif // TRANSLATORMASTERCARD_H
