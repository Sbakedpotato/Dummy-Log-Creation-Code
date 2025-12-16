/**
 * @file onelinkbalanceinquiry.cpp
 * @brief 1Link Balance Inquiry implementation
 * 
 * Reconstructed from log file analysis.
 */

#include "onelinkbalanceinquiry.h"

OneLinkBalanceInquiry::OneLinkBalanceInquiry() : m_processed(false) {
}

OneLinkBalanceInquiry::~OneLinkBalanceInquiry() {
}

bool OneLinkBalanceInquiry::processRequest(const std::string& logId) {
    LOG_INFO("onelinkbalanceinqu", "0040", "processRequest", logId,
             "Proceed with Balance inquiry REQUEST transaction processing");
    m_processed = true;
    return true;
}
