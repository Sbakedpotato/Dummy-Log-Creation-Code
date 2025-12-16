#include "transactionmgr.h"
#include "ruleengine.h"
#include "imd.h"
#include "logger.h"

TransactionMgr& TransactionMgr::getInstance() {
    static TransactionMgr instance;
    return instance;
}

bool TransactionMgr::processMessage(Message& msg, const std::string& threadId) {
    std::string messageType = "0200"; // Would come from message
    
    LOG_INFO("transactionmgr.cpp", 687, "processMessage", threadId, 
             "Message type received = [" + messageType + "]");
    
    // Print message stamp
    msg.printMessageStamp(threadId);
    
    // Generate source channel key
    std::string sourceChannelKey = msg.getPan().substr(0, 6) + "**********" + 
                                   msg.getDateTime() + msg.getStan();
    LOG_INFO("transactionmgr.cpp", 716, "processMessage", threadId, 
             "Source Channel Key [" + sourceChannelKey + "]");
    
    // Apply rules
    LOG_INFO("transactionmgr.cpp", 802, "processMessage", threadId, "Applying rules");
    std::string declineCode = RuleEngine::getInstance().applyRules(msg, threadId);
    
    if (!declineCode.empty()) {
        LOG_INFO("transactionmgr.cpp", 809, "processMessage", threadId, 
                 "Declining transaction with code [" + declineCode + "] after applying rule [27]");
    }
    
    return true;
}
