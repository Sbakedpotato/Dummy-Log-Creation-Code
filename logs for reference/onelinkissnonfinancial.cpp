/**
 * @file onelinkissnonfinancial.cpp
 * @brief 1Link Issuer Non-Financial implementation
 * 
 * Reconstructed from log file analysis.
 */

#include "onelinkissnonfinancial.h"

OneLinkIssNonFinancial::OneLinkIssNonFinancial() : m_requestProcessed(false) {
}

OneLinkIssNonFinancial::~OneLinkIssNonFinancial() {
}

bool OneLinkIssNonFinancial::processRequest(const std::string& logId) {
    LOG_INFO("onelinkissnonfinan", "0203", "processRequest", logId,
             "Proceed with REQUEST transaction processing");
    
    LOG_INFO("onelinkissnonfinan", "0216", "processRequest", logId,
             "Getting Network ID");
    
    // Simulate processing - may fail for duplicate transactions
    if (!m_requestProcessed) {
        m_requestProcessed = true;
        return true;
    } else {
        LOG_ERROR("onelinkissnonfinan", "0232", "processRequest", logId,
                  "Failed inserting transaction");
        return false;
    }
}
