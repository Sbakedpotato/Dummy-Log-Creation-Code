#ifndef TRANSLATIONMGR_H
#define TRANSLATIONMGR_H

#include <string>
#include "message.h"

// Forward declaration
class Translator;

// Translation Manager - manages message format translators
class TranslationMgr {
public:
    static TranslationMgr& getInstance();

    // Get the appropriate translator for a message format
    Translator* getTranslator(const std::string& format, const std::string& threadId);

    // Process incoming message and translate it
    bool processIncoming(const std::string& messageData, 
                         const std::string& format,
                         Message& msg,
                         const std::string& threadId);

    // Process outgoing message and translate it
    bool processOutgoing(Message& msg, 
                         const std::string& format,
                         std::string& outputData,
                         const std::string& threadId);

    // Check for configuration updates
    void checkUpdate(const std::string& threadId);

private:
    TranslationMgr() = default;
    TranslationMgr(const TranslationMgr&) = delete;
    TranslationMgr& operator=(const TranslationMgr&) = delete;

    std::string lastLoadedDateTime_;
};

#endif // TRANSLATIONMGR_H
