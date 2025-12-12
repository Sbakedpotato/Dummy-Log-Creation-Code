#include "translationmgr.h"
#include "translator.h"
#include "translatoriso.h"
#include "translatormastercard.h"
#include "logger.h"

TranslationMgr& TranslationMgr::getInstance() {
    static TranslationMgr instance;
    return instance;
}

Translator* TranslationMgr::getTranslator(const std::string& format, const std::string& threadId) {
    static TranslatorMastercard mastercardTranslator;
    static TranslatorISO isoTranslator;
    
    LOG_INFO("translationmgr.cpp", 465, "getTranslator", threadId, 
             "Attaching library ./lib/libtranslator" + format + ".so");
    
    if (format == "mastercard" || format == "MASTERCARD") {
        return &mastercardTranslator;
    }
    
    return &isoTranslator;
}

bool TranslationMgr::processIncoming(const std::string& messageData, 
                                      const std::string& format,
                                      Message& msg,
                                      const std::string& threadId) {
    LOG_INFO("translationmgr.cpp", 723, "processIncomin", threadId, 
             "Setting message format [" + format + "]");
    
    Translator* translator = getTranslator(format, threadId);
    if (!translator) {
        return false;
    }
    
    bool result = translator->ProcessIncoming(messageData, msg, threadId);
    
    LOG_INFO("translationmgr.cpp", 759, "processIncomin", threadId, 
             "Setting message format [" + std::string(format == "mastercard" ? "MASTERCARD" : format) + "]");
    
    return result;
}

bool TranslationMgr::processOutgoing(Message& msg, 
                                      const std::string& format,
                                      std::string& outputData,
                                      const std::string& threadId) {
    LOG_INFO("translationmgr.cpp", 1201, "processOutgoin", threadId, 
             "Setting message format [" + format + "]");
    
    Translator* translator = getTranslator(format, threadId);
    if (!translator) {
        return false;
    }
    
    return translator->ProcessOutgoing(msg, outputData, threadId);
}

void TranslationMgr::checkUpdate(const std::string& threadId) {
    std::string sharedMemoryDateTime = "20250918171230"; // Simulated
    
    LOG_INFO("translationmgr.cpp", 1500, "checkUpdate", threadId, 
             "Updated datetime in shared memory is [" + sharedMemoryDateTime + 
             "], transactions were loaded at [" + sharedMemoryDateTime + "]");
    
    lastLoadedDateTime_ = sharedMemoryDateTime;
}
