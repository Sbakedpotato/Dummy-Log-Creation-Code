#include <iostream>
#include <string>
#include "transactionprocess.h"
#include "message.h"
#include "logger.h"

/**
 * Payment Switch System - Main Entry Point
 * 
 * This is a reconstructed simulation of the payment switch system
 * based on log file analysis. The code recreates the logging behavior
 * and control flow observed in the production logs.
 * 
 * Components:
 * - TransactionProcess: Entry point for message processing
 * - TranslationMgr: Manages message format translators
 * - Translator/TranslatorISO/TranslatorMastercard: Message parsing/building
 * - TransactionMgr: Business logic and rule application
 * - RuleEngine: Business rule evaluation
 * - IMD: Issuer Master Data (BIN lookup)
 * - RedisCache/RedisConnectionMgr: Caching layer
 * - DBConnMgr: Database operations
 * - SAF/SAFStore: Store and Forward mechanism
 */

int main(int argc, char* argv[]) {
    std::cout << "Payment Switch System - Simulation Started" << std::endl;
    std::cout << "===========================================" << std::endl;
    
    // Create a sample thread ID (as seen in logs)
    std::string threadId = "58197610545000";
    
    // Create the transaction processor
    TransactionProcess processor;
    
    // Simulate receiving a message
    std::string sampleMessageData = "SAMPLE_ISO8583_MESSAGE_DATA";
    int priority = 0;
    
    std::cout << "\n--- Processing Sample Transaction ---\n" << std::endl;
    
    // Process the message (this will generate logs similar to the originals)
    processor.startParsing(sampleMessageData, priority, threadId);
    
    std::cout << "\n--- Calling Sample Function ---\n" << std::endl;
    
    // Call the sample function
    processor.sampleFunction(threadId);
    
    std::cout << "\n===========================================" << std::endl;
    std::cout << "Payment Switch System - Simulation Complete" << std::endl;
    
    return 0;
}
