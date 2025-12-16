/**
 * @file onelinkbalanceinquiry.h
 * @brief 1Link Balance Inquiry - Balance inquiry transaction processor
 * 
 * Reconstructed from log file analysis.
 */

#ifndef ONELINKBALANCEINQUIRY_H
#define ONELINKBALANCEINQUIRY_H

#include <string>
#include "logger.h"

class OneLinkBalanceInquiry {
public:
    OneLinkBalanceInquiry();
    ~OneLinkBalanceInquiry();
    
    /**
     * @brief Process balance inquiry request
     * @param logId Transaction log ID
     * @return true if successful, false otherwise
     * 
     * Log entry: onelinkbalanceinqu 0040 processRequest - Proceed with Balance inquiry REQUEST transaction processing
     */
    bool processRequest(const std::string& logId);

private:
    bool m_processed;
};

#endif // ONELINKBALANCEINQUIRY_H
