#ifndef RULEENGINE_H
#define RULEENGINE_H

#include <string>
#include "message.h"

// Rule Engine - applies business rules to transactions
class RuleEngine {
public:
    static RuleEngine& getInstance();

    // Apply configured rules to the message
    // Returns the response code if a rule matches, empty string otherwise
    std::string applyRules(Message& msg, const std::string& threadId);

private:
    RuleEngine() = default;
    RuleEngine(const RuleEngine&) = delete;
    RuleEngine& operator=(const RuleEngine&) = delete;
};

#endif // RULEENGINE_H
