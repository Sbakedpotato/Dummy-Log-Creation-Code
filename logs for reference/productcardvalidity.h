/**
 * @file productcardvalidity.h
 * @brief Product Card Validity - Card validity configuration
 * 
 * Reconstructed from log file analysis.
 */

#ifndef PRODUCTCARDVALIDITY_H
#define PRODUCTCARDVALIDITY_H

#include <string>
#include "logger.h"

class ProductCardValidity {
public:
    ProductCardValidity();
    ~ProductCardValidity();
    
    /**
     * @brief Fetch from database
     * @param logId Transaction log ID
     * @return true if successful, false otherwise
     * 
     * Log entry: productcardvalidit 0132 fetchFromDB - Loading Product Validity
     * Log entry: productcardvalidit 0145 fetchFromDB - No rows returned
     */
    bool fetchFromDB(const std::string& logId);
    
    /**
     * @brief Get product card validity
     * @param logId Transaction log ID
     * @param productId Product ID
     * @return true if found, false otherwise
     * 
     * Log entry: productcardvalidit 0187 GetProductCard - Product Card Validity Record not found for Key [Key =X]
     */
    bool GetProductCardValidity(const std::string& logId, const std::string& productId);

private:
    std::string m_productId;
};

#endif // PRODUCTCARDVALIDITY_H
