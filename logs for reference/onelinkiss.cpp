/**
 * @file onelinkiss.cpp
 * @brief 1Link Issuer implementation
 * 
 * Reconstructed from log file analysis.
 */

#include "onelinkiss.h"

OneLinkIss::OneLinkIss() : m_hostOnline(true) {
}

OneLinkIss::~OneLinkIss() {
}

void OneLinkIss::checkCustomerConsent(const std::string& logId, const std::string& tranCode,
                                       const std::string& channelType) {
    LOG_INFO("onelinkiss.cpp", "5578", "checkCustomerC", logId,
             "Checking if consent required trancode [" + tranCode + 
             "] , channel type [" + channelType + "]");
}

bool OneLinkIss::performCustomerValidations(const std::string& logId, const std::string& relationshipId) {
    LOG_INFO("onelinkiss.cpp", "2330", "performCustome", logId,
             "Populating Product Detail Record");
    LOG_INFO("onelinkiss.cpp", "2395", "performCustome", logId,
             "Validating card of relationship id = [" + relationshipId + "]");
    return true;
}

bool OneLinkIss::getDestinationNetwork(const std::string& logId, const std::string& networkId,
                                         const std::string& channelId) {
    LOG_INFO("onelinkiss.cpp", "3622", "getDestination", logId,
             "Get Network processing status network ID [" + networkId + 
             "], channelID [" + channelId + "]");
    
    if (m_hostOnline) {
        LOG_INFO("onelinkiss.cpp", "3648", "getDestination", logId, "Host is online");
        return true;
    }
    return false;
}

void OneLinkIss::processRejection(const std::string& logId) {
    LOG_INFO("onelinkiss.cpp", "1546", "processRejecti", logId,
             "Inserting transaction in database");
}

void OneLinkIss::sendToAcquirer(const std::string& logId) {
    LOG_INFO("onelinkiss.cpp", "4711", "sendToAcquirer", logId,
             "Removing transaction from in-memory database");
}
