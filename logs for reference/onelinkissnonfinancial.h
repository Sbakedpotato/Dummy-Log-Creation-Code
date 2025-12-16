/**
 * @file onelinkissnonfinancial.h
 * @brief 1Link Issuer Non-Financial - Non-financial transaction processing (balance inquiry, etc.)
 * 
 * Reconstructed from log file analysis.
 */

#ifndef ONELINKISSNONFINANCIAL_H
#define ONELINKISSNONFINANCIAL_H

#include <string>
#include "logger.h"

class OneLinkIssNonFinancial {
public:
    OneLinkIssNonFinancial();
    ~OneLinkIssNonFinancial();
    
    /**
     * @brief Process non-financial request
     * @param logId Transaction log ID
     * @return true if successful, false otherwise
     * 
     * Log entry: onelinkissnonfinan 0203 processRequest - Proceed with REQUEST transaction processing
     * Log entry: onelinkissnonfinan 0216 processRequest - Getting Network ID
     * Log entry: onelinkissnonfinan 0232 processRequest - Failed inserting transaction
     */
    bool processRequest(const std::string& logId);

private:
    bool m_requestProcessed;
};

#endif // ONELINKISSNONFINANCIAL_H
