#include "transactionprocess.h"
#include "translationmgr.h"
#include "transactionmgr.h"
#include "imd.h"
#include "safstore.h"
#include "saf.h"
#include "logger.h"
#include <chrono>

void TransactionProcess::startParsing(const std::string& messageData, int priority, const std::string& threadId) {
    auto startTime = std::chrono::high_resolution_clock::now();
    
    LOG_INFO("transactionprocess", 966, "startParsing", threadId, 
             "Received message with priority [" + std::to_string(priority) + "]");
    
    // Create message and process through translation manager
    Message msg;
    TranslationMgr::getInstance().processIncoming(messageData, "mastercard", msg, threadId);
    
    // Process the message
    processMessage(msg, threadId);
    
    // Calculate thread time
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
    
    int hours = duration.count() / 3600000000;
    int minutes = (duration.count() % 3600000000) / 60000000;
    int seconds = (duration.count() % 60000000) / 1000000;
    int micros = duration.count() % 1000000;
    
    char timeBuffer[32];
    snprintf(timeBuffer, sizeof(timeBuffer), "%02d:%02d:%02d.%06d", hours, minutes, seconds, micros);
    
    LOG_INFO("transactionprocess", 1016, "startParsing", threadId, 
             "THREADTIME " + std::string(timeBuffer));
    
    // Check for updates
    checkUpdate(threadId);
    TranslationMgr::getInstance().checkUpdate(threadId);
}

void TransactionProcess::processMessage(Message& msg, const std::string& threadId) {
    LOG_INFO("transactionprocess", 814, "processMessage", threadId, "Message received");
    
    std::string messageType = "0200"; // Would come from parsed message
    LOG_INFO("transactionprocess", 816, "processMessage", threadId, 
             "Message type received =[" + messageType + "]");
    
    // Create SAF store
    SAFStore safStore(threadId);
    SAF saf(threadId);
    
    // Get IMD
    IMD::getInstance().getIMD("51606710", threadId);
    
    // Process through transaction manager
    TransactionMgr::getInstance().processMessage(msg, threadId);
}

void TransactionProcess::checkUpdate(const std::string& threadId) {
    std::string sharedMemoryDateTime = "20250918171230"; // Simulated
    
    LOG_INFO("transactionprocess", 1118, "checkUpdate", threadId, 
             "Updated datetime in shared memory is [" + sharedMemoryDateTime + 
             "], transactions were loaded at [" + sharedMemoryDateTime + "]");
    
    lastLoadedDateTime_ = sharedMemoryDateTime;
}

void TransactionProcess::sampleFunction(const std::string& threadId) {
    LOG_INFO("transactionprocess", 2222, "sampleFunction", threadId, "New line test");
}
