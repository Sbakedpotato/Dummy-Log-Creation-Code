/**
 * @file cmschannel.cpp
 * @brief CMS Channel implementation
 * 
 * Reconstructed from log file analysis.
 */

#include "cmschannel.h"

CMSChannel::CMSChannel() 
    : m_channelType("1LINK")
    , m_channelCode("0007")
    , m_consentRequired(false) {
}

CMSChannel::~CMSChannel() {
}

bool CMSChannel::fetchSingleRecord(const std::string& logId) {
    LOG_INFO("cmschannel.cpp", "0349", "fetchSingleRec", logId,
             "CMSchannel loaded successfully");
    return true;
}

void CMSChannel::getCMSChannelAttributes(const std::string& logId) {
    LOG_INFO("cmschannel.cpp", "0180", "getCMSChannela", logId,
             "channelType[" + m_channelType + "]");
    LOG_INFO("cmschannel.cpp", "0181", "getCMSChannela", logId,
             "channelCode[" + m_channelCode + "]");
}

bool CMSChannel::isConsentRequired(const std::string& logId) {
    if (!m_consentRequired) {
        LOG_INFO("cmschannel.cpp", "0144", "isConsentRequi", logId,
                 "Consent Not Required");
    }
    return m_consentRequired;
}
