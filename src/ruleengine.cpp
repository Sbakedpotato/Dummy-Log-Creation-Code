#include "ruleengine.h"
#include "logger.h"

RuleEngine& RuleEngine::getInstance() {
    static RuleEngine instance;
    return instance;
}

std::string RuleEngine::applyRules(Message& msg, const std::string& threadId) {
    // Simulate rule checking
    std::string processingCode = "000000"; // Would normally get from message
    
    LOG_INFO("ruleengine.cpp", 475, "applyRules", threadId, 
             "Checking rules on[PROCESSING_CODE]");
    
    // Simulate a rule match
    LOG_INFO("ruleengine.cpp", 521, "applyRules", threadId, 
             "Rule [masterTest] matched. [" + processingCode + "] = [000000]");
    
    // Return a decline code for simulation
    return "014";
}
