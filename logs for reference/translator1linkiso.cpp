/**
 * @file translator1linkiso.cpp
 * @brief 1Link ISO Translator implementation
 * 
 * Reconstructed from log file analysis.
 */

#include "translator1linkiso.h"

Translator1LinkISO::Translator1LinkISO() : m_sourceChannelID("422") {
}

Translator1LinkISO::~Translator1LinkISO() {
}

std::string Translator1LinkISO::getSourceChannelID(const std::string& logId) {
    LOG_INFO("translator1linkiso", "1406", "getSourceChann", logId,
             "sourceChannelID [" + m_sourceChannelID + "]");
    
    // Second log for modified channel ID
    std::string modifiedId = "420";
    LOG_INFO("translator1linkiso", "1414", "getSourceChann", logId,
             "sourceChannelID [" + modifiedId + "]");
    
    return m_sourceChannelID;
}

bool Translator1LinkISO::setProcessingCode(const std::string& logId, const std::string& tranCode) {
    LOG_INFO("translator1linkiso", "0626", "setProcessingC", logId,
             "tranCode [" + tranCode + "]");
    
    // Some transaction codes are not supported
    if (tranCode == "30" || tranCode == "00") {
        LOG_ERROR("translator1linkiso", "0670", "setProcessingC", logId,
                  "Transaction code not supported");
        return false;
    }
    return true;
}

bool Translator1LinkISO::setOriginalDataElements(const std::string& logId) {
    LOG_ERROR("translator1linkiso", "1332", "setOriginalDat", logId,
              "Unable to make original data elements, cannot send reversal");
    return false;
}
