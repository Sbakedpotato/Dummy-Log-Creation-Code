/**
 * @file productalerts.h
 * @brief Product Alerts - Alert configuration per product
 * 
 * Reconstructed from log file analysis.
 */

#ifndef PRODUCTALERTS_H
#define PRODUCTALERTS_H

#include <string>
#include "logger.h"

class ProductAlerts {
public:
    ProductAlerts();
    ~ProductAlerts();
    
    /**
     * @brief Fetch product alerts from database
     * @param logId Transaction log ID
     * @return true if successful, false otherwise
     * 
     * Log entry: productalerts.cpp 0132 fetchFromDB - Loading Product Alerts
     * Log entry: productalerts.cpp 0163 fetchFromDB - No rows returned
     */
    bool fetchFromDB(const std::string& logId);
    
    /**
     * @brief Get alerts detail for a key
     * @param logId Transaction log ID
     * @param key Alerts key (product/tran/party type combination)
     * @return true if found, false otherwise
     * 
     * Log entry: productalerts.cpp 0260 getAlertsDetai - Alerts Record not found for Key [Key =X]
     * Log entry: productalerts.cpp 0291 getAlertsDetai - Alerts Record not found for Key [Key =X]
     */
    bool getAlertsDetail(const std::string& logId, const std::string& key);

private:
    std::string m_productId;
    std::string m_tranCode;
    std::string m_partyType;
};

#endif // PRODUCTALERTS_H
