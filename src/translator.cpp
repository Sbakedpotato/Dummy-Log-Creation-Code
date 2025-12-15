#include "translator.h"
#include "logger.h"

bool Translator::ProcessIncoming(const std::string& messageData, 
                                  Message& msg, 
                                  const std::string& threadId) {
    LOG_INFO("translator.cpp", 78, "ProcessIncomin", threadId, 
             "STEP1: Message fields parsed successfully");
    
    // Check conditions (may fail)
    CheckCondition("condition1", threadId);
    CheckCondition("condition2", threadId);
    
    LOG_INFO("translator.cpp", 133, "ProcessIncomin", threadId, 
             "STEP 2: Mandatory fields validated successfully");
    
    LOG_INFO("translator.cpp", 142, "ProcessIncomin", threadId, 
             "STEP 3: Subfields parsed successfully");
    
    // Map fields
    std::string mappedValue;
    mapField("CAVV", "0", mappedValue, threadId);
    mapField("ECIFlag", "*", mappedValue, threadId);
    
    LOG_INFO("translator.cpp", 152, "ProcessIncomin", threadId, 
             "STEP 4: Incoming fields mapped successfully");
    
    LOG_INFO("translator.cpp", 163, "ProcessIncomin", threadId, 
             "STEP 5: Transaction specific fields parsed successfully");
    
    LOG_INFO("translator.cpp", 196, "ProcessIncomin", threadId, 
             "STEP 7: Institution based customization done successfully");
    
    LOG_INFO("translator.cpp", 198, "ProcessIncomin", threadId, 
             "Masking Message Fields");
    
    LOG_INFO("translator.cpp", 208, "ProcessIncomin", threadId, 
             "Message fields parsed successfully");
    
    return true;
}

bool Translator::ProcessOutgoing(Message& msg, 
                                  std::string& outputData, 
                                  const std::string& threadId) {
    LOG_INFO("translator.cpp", 455, "ProcessOutgoin", threadId, 
             "STEP 1: Institution based customization done successfully");
    
    // Try to map fields - some may fail
    std::string mappedValue;
    if (!mapField("CAVV", "default", mappedValue, threadId)) {
        LOG_ERROR("translator.cpp", 1531, "mapField", threadId, 
                  "Failed finding default mapping for [CAVV]");
    }
    
    if (!mapField("ECIFlag", "default", mappedValue, threadId)) {
        LOG_ERROR("translator.cpp", 1531, "mapField", threadId, 
                  "Failed finding default mapping for [ECIFlag]");
    }
    
    if (mapField("RESPONSE_CODE", "014", mappedValue, threadId)) {
        // Mapping successful
    }
    
    LOG_INFO("translator.cpp", 464, "ProcessOutgoin", threadId, 
             "STEP 2: Outgoing fields mapped successfully");
    
    LOG_INFO("translator.cpp", 486, "ProcessOutgoin", threadId, 
             "STEP 3: Transaction specific customization done successfully");
    
    buildSubFields(msg, threadId);
    
    LOG_INFO("translator.cpp", 495, "ProcessOutgoin", threadId, 
             "STEP 4: Subfields built successfully");
    
    LOG_INFO("translator.cpp", 506, "ProcessOutgoin", threadId, 
             "Message built successfully");
    
    return true;
}

bool Translator::CheckCondition(const std::string& condition, const std::string& threadId) {
    // Define valid conditions
    std::vector<std::string> validConditions = {"condition1", "condition2"};
    
    // Check if the condition is valid
    if (std::find(validConditions.begin(), validConditions.end(), condition) != validConditions.end()) {
        LOG_INFO("translator.cpp", 1654, "CheckCondition", threadId, "Condition matched");
        return true;
    } else {
        LOG_ERROR("translator.cpp", 1654, "CheckCondition", threadId, "Condition unmatched");
        return false;
    }
}

bool Translator::mapField(const std::string& fieldName, 
                          const std::string& value, 
                          std::string& mappedValue,
                          const std::string& threadId) {
    // Simulate field mapping
    if (fieldName == "CAVV" && value == "0") {
        mappedValue = "0";
        LOG_INFO("translator.cpp", 1540, "mapField", threadId, 
                 "Mapping found successfully for [CAVV] value = [0], mapped value = [0]");
        return true;
    }
    
    if (fieldName == "ECIFlag" && value == "*") {
        mappedValue = "07";
        LOG_INFO("translator.cpp", 1540, "mapField", threadId, 
                 "Mapping found successfully for [ECIFlag] value = [*], mapped value = [07]");
        return true;
    }
    
    if (fieldName == "RESPONSE_CODE") {
        if (value == "014") {
            mappedValue = "41";
        } else if (value == "00") {
            mappedValue = "000";
        } else {
            mappedValue = value;
        }
        LOG_INFO("translator.cpp", 1540, "mapField", threadId, 
                 "Mapping found successfully for [RESPONSE_CODE] value = [" + value + 
                 "], mapped value = [" + mappedValue + "]");
        return true;
    }
    
    // Default mapping not found
    return false;
}

void Translator::buildSubFields(Message& msg, const std::string& threadId) {
    LOG_INFO("translator.cpp", 603, "buildSubFields", threadId, 
             "Build sub fields, calling Base");
}
